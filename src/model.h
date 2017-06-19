//
// Created by danny on 17-6-19.
//

#ifndef RY_SERVICE_MODEL_H
#define RY_SERVICE_MODEL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "iec61850/iec61850_server.h"

LogicalNode*
LN_SACT1_createInstance(char* lnName, LogicalDevice* parent);

LogicalNode*
LN_LPHD1_createInstance(char* lnName, LogicalDevice* parent);

LogicalNode*
LN_CALH_createInstance(char *lnName, LogicalDevice *parent);

LogicalNode*
LN_GGIO1_createInstance(char* lnName, LogicalDevice* parent);

LogicalNode*
LN_LLN0_createInstance(char *lnName, LogicalDevice *parent);

LogicalNode*
LN_MMXU_createInstance(char *lnName, LogicalDevice *parent);

DataObject*
DO_CN_INS_Beh_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_INS_Health_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_MV_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_LPL_LN0_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_SPC_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_DPL_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_SPS_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_INC_Mod_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_ING_SP_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_LPL_EX_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_INC_EX_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_LPL_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataAttribute*
DA_CN_PulseConfig_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions);

DataAttribute*
DA_CN_SBOw_Oper_SDPC_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions);

DataAttribute*
DA_CN_units_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions);

DataAttribute*
DA_CN_Cancel_SDPC_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions);

DataAttribute*
DA_CN_Originator_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions);

DataAttribute*
DA_CN_RangeConfig_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions);

DataAttribute*
DA_CN_Cancel_INC_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions);

DataAttribute*
DA_CN_SBOw_Oper_INC_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions);

DataAttribute*
DA_CN_ScaledValueConfig_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions);

DataAttribute*
DA_CN_AnalogueValue_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions);


#ifdef __cplusplus
}
#endif

#endif //RY_SERVICE_MODEL_H
