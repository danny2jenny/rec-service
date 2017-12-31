/*
 *  server_example_basic_io.c
 *
 *  - How to use simple control models
 *  - How to serve analog measurement data
 */

#include "iec61850/iec61850_server.h"
#include "iec61850/hal_thread.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "static-model/static_model.h"

/* import IEC 61850 device model created from SCL-File */
extern IedModel iedModel;

static int running = 0;
static IedServer iedServer = NULL;

void
sigint_handler(int signalId) {
    running = 0;
}

static ControlHandlerResult
controlHandlerForBinaryOutput(void *parameter, MmsValue *value, bool test) {
    if (test)
        return CONTROL_RESULT_FAILED;

    if (MmsValue_getType(value) == MMS_BOOLEAN) {
        printf("received binary control command: ");

        if (MmsValue_getBoolean(value))
            printf("on\n");
        else
            printf("off\n");
    } else
        return CONTROL_RESULT_FAILED;

    uint64_t timeStamp = Hal_getTimeInMs();



    return CONTROL_RESULT_OK;
}


static void
connectionHandler(IedServer self, ClientConnection connection, bool connected, void *parameter) {
    if (connected)
        printf("Connection opened\n");
    else
        printf("Connection closed\n");
}

int
main(int argc, char **argv) {
    printf("Using libIEC61850 version %s\n", LibIEC61850_getVersionString());

    iedServer = IedServer_create(&iedModel);

    /* Set the base path for the MMS file services */
    MmsServer mmsServer = IedServer_getMmsServer(iedServer);
    //MmsServer_setFilestoreBasepath(mmsServer, "./vmd-filestore/");



    //IedServer_setConnectionIndicationHandler(iedServer, (IedConnectionIndicationHandler) connectionHandler, NULL);

    /* MMS server will be instructed to start listening to client connections. */
    IedServer_start(iedServer, 1024);

    if (!IedServer_isRunning(iedServer)) {
        printf("Starting server failed! Exit.\n");
        IedServer_destroy(iedServer);
        exit(-1);
    }

    running = 1;

    signal(SIGINT, sigint_handler);

    float t = 0.f;

    while (running) {
        uint64_t timestamp = Hal_getTimeInMs();

        IedServer_lockDataModel(iedServer);

        Timestamp iecTimestamp;

        Timestamp_clearFlags(&iecTimestamp);
        Timestamp_setTimeInMilliseconds(&iecTimestamp, timestamp);
        Timestamp_setLeapSecondKnown(&iecTimestamp, true);

        /* toggle clock-not-synchronized flag in timestamp */
        if (((int) t % 2) == 0)
            Timestamp_setClockNotSynchronized(&iecTimestamp, true);

        IedServer_updateTimestampAttributeValue(iedServer, &iedModel_MONT_GGIO1_Ind1_t, &iecTimestamp);
        IedServer_updateBooleanAttributeValue(iedServer, &iedModel_MONT_GGIO1_Ind1_stVal, true);


        IedServer_unlockDataModel(iedServer);

        Thread_sleep(100);

        MmsServer mmsServer = IedServer_getMmsServer(iedServer);

    }

    /* stop MMS server - close TCP server socket and all client sockets */
    IedServer_stop(iedServer);

    /* Cleanup - free all resources */
    IedServer_destroy(iedServer);

} /* main() */
