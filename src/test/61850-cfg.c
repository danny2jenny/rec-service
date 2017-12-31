/*
 *  server_example_config_file.c
 *
 *  This example shows how to use dynamic server data model with a configuration file.
 *
 *  - How to open and parse the model configuration file
 *  - How to access data attributes by object reference strings
 *  - How to access data attributes by short addresses
 *
 *  Note: If building with cmake the vmd-filestore folder containing the configuration file
 *  (model.cfg) has to be copied to the folder where the example is executed!
 *  The configuration file can be created from the SCL(ICD) file with the Java tool genconfig.jar
 *  that is included in the source distribution of libiec61580.
 *
 */

#include "iec61850/iec61850_server.h"
#include "iec61850/hal_thread.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

#include "iec61850/hal_filesystem.h"
#include "iec61850/iec61850_config_file_parser.h"

static int running = 0;

void sigint_handler(int signalId)
{
    running = 0;
}

// 控制回调
static ControlHandlerResult
controlHandlerForBinaryOutput(void *parameter, MmsValue *value, bool test) {
    uint64_t timestamp = Hal_getTimeInMs();
    printf("Receive Control Message!!!!!%s \n", parameter);

}

int main(int argc, char** argv)
{
    int tcpPort = 102;

    if (argc > 1) {
        tcpPort = atoi(argv[1]);
    }

    /* open configuration file */
    FileHandle configFile = FileSystem_openFile("/home/danny/ivs.cfg", false);

    if (configFile == NULL) {
        printf("Error opening config file!\n");
        return 1;
    }

    /* parse the configuration file and create the data model */
    IedModel* model = ConfigFileParser_createModelFromConfigFile(configFile);

    FileSystem_closeFile(configFile);

    if (model == NULL) {
        printf("Error parsing config file!\n");
        return 1;
    }

    IedServer iedServer = IedServer_create(model);

    /* Access to data attributes by object reference */

    DataAttribute* anIn1_mag_f = (DataAttribute*)
            IedModel_getModelNodeByObjectReference(model, "TZ102MONT/MMXN1.AnIn1.mag.f");

    DataAttribute* anIn1_t = (DataAttribute*)
            IedModel_getModelNodeByObjectReference(model, "TZ102MONT/MMXN1.AnIn1.t");

    if (anIn1_mag_f == NULL)
        printf("Error getting AnIn1.mag.f data attribute!\n");



    IedServer_start(iedServer, tcpPort);

    if (!IedServer_isRunning(iedServer)) {
        printf("Starting server failed! Exit.\n");
        IedServer_destroy(iedServer);
        exit(-1);
    }

    running = 1;

    signal(SIGINT, sigint_handler);

    float val = 0.f;

    MmsValue* floatValue = MmsValue_newFloat(val);

    //--------------- 设置控制回调------------------
    DataObject* ctlNode = IedModel_getModelNodeByObjectReference(model, "TZ102MONT/CSWI1.SW1");
    IedServer_setControlHandler(iedServer, ctlNode, (ControlHandler)controlHandlerForBinaryOutput, "1");

    ctlNode = IedModel_getModelNodeByObjectReference(model, "TZ102MONT/CSWI1.SW2");
    IedServer_setControlHandler(iedServer, ctlNode, (ControlHandler)controlHandlerForBinaryOutput, "2");

    while (running) {

        if (anIn1_mag_f != NULL) {
            MmsValue_setFloat(floatValue, val);

            IedServer_lockDataModel(iedServer);

            MmsValue_setUtcTimeMs(anIn1_t->mmsValue, Hal_getTimeInMs());
            IedServer_updateAttributeValue(iedServer, anIn1_mag_f, floatValue);

            IedServer_unlockDataModel(iedServer);
        }

        val += 0.1f;

        Thread_sleep(100);
    }

    MmsValue_delete(floatValue);

    IedServer_stop(iedServer);

    IedServer_destroy(iedServer);

    IedModel_destroy(model);
} /* main() */
