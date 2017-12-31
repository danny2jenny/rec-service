//
// Created by danny on 17-12-29.
//

#ifndef RY_SERVICE_XJ_61850_H
#define RY_SERVICE_XJ_61850_H

#ifdef __cplusplus
extern "C" {
#endif

#include "iec61850/iec61850_server.h"

/**
 * 许继的标准模型
 * update: 2017.12.29
 * @param lnName
 * @param parent
 * @return
 */

LogicalNode*
LN_XJBYQ_MMXN_createInstance(char* lnName, LogicalDevice* parent);

LogicalNode*
LN_MONT_LPHD_createInstance(char* lnName, LogicalDevice* parent);

LogicalNode*
LN_XJBYQ_GGIO_createInstance(char* lnName, LogicalDevice* parent);

LogicalNode*
LN_MONT_LLN0_createInstance(char* lnName, LogicalDevice* parent);

DataObject*
DO_JZ_SPS_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_ASG_SG_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_HWYE_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_INS_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_INC_Mod_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_HMV_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_LPL_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_MV_EX_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_INS_Health_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_ING_SP_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_HWYE_EX_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_DPL_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_ASG_SP_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_ING_SG_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_ACT_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_WYE_EX_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_DPC_EX_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_CMV_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_MV_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_SPC_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_HDEL_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_SPC_DC_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_JZ_CSD_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_ASG_SG_EX_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_SEQ_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_DPL_EX_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_INS_ARST_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_HST_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_SPS_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_DEL_EX_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_INS_Beh_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_LPL_LN0_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_MV_I_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_DEL_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_WYE_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_ACD_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_SPC_EX_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_DPC_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_INS_EX_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_SPS_EX_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_ASG_SP_EX_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataObject*
DO_CN_CMV_EX_createInstance(char* doName, ModelNode* parent, int arrayCount);

DataAttribute*
DA_CN_Cancel_INC_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions);

DataAttribute*
DA_CN_Vector_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions);

DataAttribute*
DA_CN_Originator_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions);

DataAttribute*
DA_CN_SBOw_Oper_SDPC_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions);

DataAttribute*
DA_CN_ScaledValueConfig_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions);

DataAttribute*
DA_CN_RangeConfig_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions);

DataAttribute*
DA_CN_AnalogueValue_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions);

DataAttribute*
DA_CN_SBOw_Oper_BSC_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions);

DataAttribute*
DA_CN_SBOw_Oper_INC_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions);

DataAttribute*
DA_CN_Units_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions);

DataAttribute*
DA_CN_PulseConfig_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions);

DataAttribute*
DA_CN_Cancel_BSC_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions);

DataAttribute*
DA_CN_AnalogueValue_I_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions);

DataAttribute*
DA_CN_Cancel_SDPC_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions);


#ifdef __cplusplus
}
#endif

#endif //RY_SERVICE_XJ_61850_H
