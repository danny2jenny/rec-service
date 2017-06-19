/**
 * 由以前的模型生成的动态代码
 */
#include "iec61850/iec61850_server.h"
#include "model.h"
/**
 * LN: SACT1 (空调控制节点)
 */
LogicalNode*
LN_SACT1_createInstance(char* lnName, LogicalDevice* parent)
{
    LogicalNode* newLn = LogicalNode_create(lnName, parent);

    DO_CN_INC_Mod_createInstance("Mod", (ModelNode*) newLn, 0);
    DO_CN_INS_Beh_createInstance("Beh", (ModelNode*) newLn, 0);
    DO_CN_INS_Health_createInstance("Health", (ModelNode*) newLn, 0);
    DO_CN_LPL_EX_createInstance("NamPlt", (ModelNode*) newLn, 0);
    DO_CN_ING_SP_createInstance("AirMode", (ModelNode*) newLn, 0);
    DO_CN_ING_SP_createInstance("AirTemp", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("AirStatus", (ModelNode*) newLn, 0);

    return newLn;
}


/**
 * LN: LPHD1 (物理设备信息)
 */
LogicalNode*
LN_LPHD1_createInstance(char* lnName, LogicalDevice* parent)
{
    LogicalNode* newLn = LogicalNode_create(lnName, parent);

    DO_CN_DPL_createInstance("PhyNam", (ModelNode*) newLn, 0);
    DO_CN_INS_Health_createInstance("PhyHealth", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Proxy", (ModelNode*) newLn, 0);

    return newLn;
}


/**
 * LN: CALH1 (开关量输入节点)
 */
LogicalNode*
LN_CALH_createInstance(char *lnName, LogicalDevice *parent)
{
    LogicalNode* newLn = LogicalNode_create(lnName, parent);

    DO_CN_INC_Mod_createInstance("Mod", (ModelNode*) newLn, 0);
    DO_CN_INS_Beh_createInstance("Beh", (ModelNode*) newLn, 0);
    DO_CN_INS_Health_createInstance("Health", (ModelNode*) newLn, 0);
    DO_CN_LPL_createInstance("NamPlt", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("GrAlm", (ModelNode*) newLn, 0);

    return newLn;
}


/**
 * LN: GGIO1 (开关量输出节点)
 */
LogicalNode*
LN_GGIO1_createInstance(char* lnName, LogicalDevice* parent)
{
    LogicalNode* newLn = LogicalNode_create(lnName, parent);

    DO_CN_INC_Mod_createInstance("Mod", (ModelNode*) newLn, 0);
    DO_CN_INS_Beh_createInstance("Beh", (ModelNode*) newLn, 0);
    DO_CN_INS_Health_createInstance("Health", (ModelNode*) newLn, 0);
    DO_CN_LPL_createInstance("NamPlt", (ModelNode*) newLn, 0);
    DO_CN_SPC_createInstance("SPCSO", (ModelNode*) newLn, 0);

    return newLn;
}


/**
 * LN: LLN01 (逻辑节点装置)
 */
LogicalNode*
LN_LLN0_createInstance(char *lnName, LogicalDevice *parent)
{
    LogicalNode* newLn = LogicalNode_create(lnName, parent);

    DO_CN_INC_Mod_createInstance("Mod", (ModelNode*) newLn, 0);
    DO_CN_INS_Beh_createInstance("Beh", (ModelNode*) newLn, 0);
    DO_CN_INS_Health_createInstance("Health", (ModelNode*) newLn, 0);
    DO_CN_LPL_LN0_createInstance("NamPlt", (ModelNode*) newLn, 0);

    return newLn;
}


/**
 * LN: MMXU1 (模拟量测量节点)
 */
LogicalNode*
LN_MMXU_createInstance(char *lnName, LogicalDevice *parent)
{
    LogicalNode* newLn = LogicalNode_create(lnName, parent);

    DO_CN_INC_Mod_createInstance("Mod", (ModelNode*) newLn, 0);
    DO_CN_INS_Beh_createInstance("Beh", (ModelNode*) newLn, 0);
    DO_CN_INS_Health_createInstance("Health", (ModelNode*) newLn, 0);
    DO_CN_LPL_createInstance("NamPlt", (ModelNode*) newLn, 0);
    DO_CN_MV_createInstance("Value", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("HighAlm", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("LowAlm", (ModelNode*) newLn, 0);

    return newLn;
}


/**
 * DO: CN_INS_Beh 
 */
DataObject*
DO_CN_INS_Beh_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DataAttribute_create("stVal", (ModelNode*) newDo, IEC61850_ENUMERATED, IEC61850_FC_ST, 1, 0, 0);
    DataAttribute_create("q", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_ST, 2, 0, 0);
    DataAttribute_create("t", (ModelNode*) newDo, IEC61850_TIMESTAMP, IEC61850_FC_ST, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_INS_Health 
 */
DataObject*
DO_CN_INS_Health_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DataAttribute_create("stVal", (ModelNode*) newDo, IEC61850_ENUMERATED, IEC61850_FC_ST, 1, 0, 0);
    DataAttribute_create("q", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_ST, 2, 0, 0);
    DataAttribute_create("t", (ModelNode*) newDo, IEC61850_TIMESTAMP, IEC61850_FC_ST, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_MV 
 */
DataObject*
DO_CN_MV_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DA_CN_AnalogueValue_createInstance("mag", (ModelNode*) newDo, IEC61850_FC_MX, 1);
    DataAttribute_create("q", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_MX, 2, 0, 0);
    DataAttribute_create("t", (ModelNode*) newDo, IEC61850_TIMESTAMP, IEC61850_FC_MX, 0, 0, 0);
    DataAttribute_create("subEna", (ModelNode*) newDo, IEC61850_BOOLEAN, IEC61850_FC_SV, 0, 0, 0);
    DA_CN_AnalogueValue_createInstance("subMag", (ModelNode*) newDo, IEC61850_FC_SV, 0);
    DataAttribute_create("subQ", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("subID", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_64, IEC61850_FC_SV, 0, 0, 0);
    DA_CN_units_createInstance("units", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DataAttribute_create("db", (ModelNode*) newDo, IEC61850_INT32U, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("zeroDb", (ModelNode*) newDo, IEC61850_INT32U, IEC61850_FC_CF, 0, 0, 0);
    DA_CN_ScaledValueConfig_createInstance("sVC", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DA_CN_RangeConfig_createInstance("rangeC", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DataAttribute_create("smpRate", (ModelNode*) newDo, IEC61850_INT32U, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_LPL_LN0 
 */
DataObject*
DO_CN_LPL_LN0_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DataAttribute_create("vendor", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("swRev", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("d", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("configRev", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("ldNs", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_EX, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_SPC 
 */
DataObject*
DO_CN_SPC_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DA_CN_SBOw_Oper_SDPC_createInstance("SBOw", (ModelNode*) newDo, IEC61850_FC_CO, 0);
    DA_CN_SBOw_Oper_SDPC_createInstance("Oper", (ModelNode*) newDo, IEC61850_FC_CO, 0);
    DA_CN_Cancel_SDPC_createInstance("Cancel", (ModelNode*) newDo, IEC61850_FC_CO, 0);
    DataAttribute_create("stVal", (ModelNode*) newDo, IEC61850_BOOLEAN, IEC61850_FC_ST, 1, 0, 0);
    DataAttribute_create("q", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_ST, 2, 0, 0);
    DataAttribute_create("t", (ModelNode*) newDo, IEC61850_TIMESTAMP, IEC61850_FC_ST, 0, 0, 0);
    DataAttribute_create("subEna", (ModelNode*) newDo, IEC61850_BOOLEAN, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("subVal", (ModelNode*) newDo, IEC61850_BOOLEAN, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("subQ", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("subID", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_64, IEC61850_FC_SV, 0, 0, 0);
    DA_CN_PulseConfig_createInstance("pulseConfig", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DataAttribute_create("ctlModel", (ModelNode*) newDo, IEC61850_ENUMERATED, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("sboTimeout", (ModelNode*) newDo, IEC61850_INT32U, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("sboClass", (ModelNode*) newDo, IEC61850_ENUMERATED, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_DPL 
 */
DataObject*
DO_CN_DPL_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DataAttribute_create("vendor", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("hwRev", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("swRev", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("serNum", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("model", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("location", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_DC, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_SPS 
 */
DataObject*
DO_CN_SPS_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DataAttribute_create("stVal", (ModelNode*) newDo, IEC61850_BOOLEAN, IEC61850_FC_ST, 1, 0, 0);
    DataAttribute_create("q", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_ST, 2, 0, 0);
    DataAttribute_create("t", (ModelNode*) newDo, IEC61850_TIMESTAMP, IEC61850_FC_ST, 0, 0, 0);
    DataAttribute_create("subEna", (ModelNode*) newDo, IEC61850_BOOLEAN, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("subVal", (ModelNode*) newDo, IEC61850_BOOLEAN, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("subQ", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("subID", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_64, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_INC_Mod 
 */
DataObject*
DO_CN_INC_Mod_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DataAttribute_create("stVal", (ModelNode*) newDo, IEC61850_ENUMERATED, IEC61850_FC_ST, 1, 0, 0);
    DataAttribute_create("q", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_ST, 2, 0, 0);
    DataAttribute_create("t", (ModelNode*) newDo, IEC61850_TIMESTAMP, IEC61850_FC_ST, 0, 0, 0);
    DataAttribute_create("ctlModel", (ModelNode*) newDo, IEC61850_ENUMERATED, IEC61850_FC_CF, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_ING_SP 
 */
DataObject*
DO_CN_ING_SP_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DataAttribute_create("setVal", (ModelNode*) newDo, IEC61850_INT32, IEC61850_FC_SP, 0, 0, 0);
    DataAttribute_create("minVal", (ModelNode*) newDo, IEC61850_INT32, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("maxVal", (ModelNode*) newDo, IEC61850_INT32, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("stepSize", (ModelNode*) newDo, IEC61850_INT32U, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_LPL_EX 
 */
DataObject*
DO_CN_LPL_EX_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DataAttribute_create("vendor", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("swRev", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("d", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("lnNs", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_EX, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_INC_EX 
 */
DataObject*
DO_CN_INC_EX_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DA_CN_SBOw_Oper_INC_createInstance("SBOw", (ModelNode*) newDo, IEC61850_FC_CO, 0);
    DA_CN_SBOw_Oper_INC_createInstance("Oper", (ModelNode*) newDo, IEC61850_FC_CO, 0);
    DA_CN_Cancel_INC_createInstance("Cancel", (ModelNode*) newDo, IEC61850_FC_CO, 0);
    DataAttribute_create("stVal", (ModelNode*) newDo, IEC61850_INT32, IEC61850_FC_ST, 1, 0, 0);
    DataAttribute_create("q", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_ST, 2, 0, 0);
    DataAttribute_create("t", (ModelNode*) newDo, IEC61850_TIMESTAMP, IEC61850_FC_ST, 0, 0, 0);
    DataAttribute_create("subEna", (ModelNode*) newDo, IEC61850_BOOLEAN, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("subVal", (ModelNode*) newDo, IEC61850_INT32, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("subQ", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("subID", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_64, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("ctlModel", (ModelNode*) newDo, IEC61850_ENUMERATED, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("sboTimeout", (ModelNode*) newDo, IEC61850_INT32U, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("sboClass", (ModelNode*) newDo, IEC61850_ENUMERATED, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("minVal", (ModelNode*) newDo, IEC61850_INT32, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("maxVal", (ModelNode*) newDo, IEC61850_INT32, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("stepSize", (ModelNode*) newDo, IEC61850_INT32U, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("dataNs", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_EX, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_LPL 
 */
DataObject*
DO_CN_LPL_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DataAttribute_create("vendor", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("swRev", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("d", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);

    return newDo;
}


/**
 * DA: CN_PulseConfig 
 */
DataAttribute*
DA_CN_PulseConfig_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions)
{
    DataAttribute* newDa = DataAttribute_create(daName, parent, IEC61850_CONSTRUCTED, fc, triggerOptions, 0, 0);

    DataAttribute_create("cmdQual", (ModelNode*) newDa, IEC61850_ENUMERATED, fc, triggerOptions, 0, 0);
    DataAttribute_create("onDur", (ModelNode*) newDa, IEC61850_INT32U, fc, triggerOptions, 0, 0);
    DataAttribute_create("offDur", (ModelNode*) newDa, IEC61850_INT32U, fc, triggerOptions, 0, 0);
    DataAttribute_create("numPls", (ModelNode*) newDa, IEC61850_INT32U, fc, triggerOptions, 0, 0);

    return newDa;
}


/**
 * DA: CN_SBOw_Oper_SDPC 
 */
DataAttribute*
DA_CN_SBOw_Oper_SDPC_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions)
{
    DataAttribute* newDa = DataAttribute_create(daName, parent, IEC61850_CONSTRUCTED, fc, triggerOptions, 0, 0);

    DataAttribute_create("ctlVal", (ModelNode*) newDa, IEC61850_BOOLEAN, fc, triggerOptions, 0, 0);
    DA_CN_Originator_createInstance("origin", (ModelNode*) newDa, fc, triggerOptions);
    DataAttribute_create("ctlNum", (ModelNode*) newDa, IEC61850_INT8U, fc, triggerOptions, 0, 0);
    DataAttribute_create("T", (ModelNode*) newDa, IEC61850_TIMESTAMP, fc, triggerOptions, 0, 0);
    DataAttribute_create("Test", (ModelNode*) newDa, IEC61850_BOOLEAN, fc, triggerOptions, 0, 0);
    DataAttribute_create("Check", (ModelNode*) newDa, IEC61850_CHECK, fc, triggerOptions, 0, 0);

    return newDa;
}


/**
 * DA: CN_units 
 */
DataAttribute*
DA_CN_units_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions)
{
    DataAttribute* newDa = DataAttribute_create(daName, parent, IEC61850_CONSTRUCTED, fc, triggerOptions, 0, 0);

    DataAttribute_create("SIUnit", (ModelNode*) newDa, IEC61850_ENUMERATED, fc, triggerOptions, 0, 0);
    DataAttribute_create("multiplier", (ModelNode*) newDa, IEC61850_ENUMERATED, fc, triggerOptions, 0, 0);

    return newDa;
}


/**
 * DA: CN_Cancel_SDPC 
 */
DataAttribute*
DA_CN_Cancel_SDPC_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions)
{
    DataAttribute* newDa = DataAttribute_create(daName, parent, IEC61850_CONSTRUCTED, fc, triggerOptions, 0, 0);

    DataAttribute_create("ctlVal", (ModelNode*) newDa, IEC61850_BOOLEAN, fc, triggerOptions, 0, 0);
    DA_CN_Originator_createInstance("origin", (ModelNode*) newDa, fc, triggerOptions);
    DataAttribute_create("ctlNum", (ModelNode*) newDa, IEC61850_INT8U, fc, triggerOptions, 0, 0);
    DataAttribute_create("T", (ModelNode*) newDa, IEC61850_TIMESTAMP, fc, triggerOptions, 0, 0);
    DataAttribute_create("Test", (ModelNode*) newDa, IEC61850_BOOLEAN, fc, triggerOptions, 0, 0);

    return newDa;
}


/**
 * DA: CN_Originator 
 */
DataAttribute*
DA_CN_Originator_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions)
{
    DataAttribute* newDa = DataAttribute_create(daName, parent, IEC61850_CONSTRUCTED, fc, triggerOptions, 0, 0);

    DataAttribute_create("orCat", (ModelNode*) newDa, IEC61850_ENUMERATED, fc, triggerOptions, 0, 0);
    DataAttribute_create("orIdent", (ModelNode*) newDa, IEC61850_OCTET_STRING_64, fc, triggerOptions, 0, 0);

    return newDa;
}


/**
 * DA: CN_RangeConfig 
 */
DataAttribute*
DA_CN_RangeConfig_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions)
{
    DataAttribute* newDa = DataAttribute_create(daName, parent, IEC61850_CONSTRUCTED, fc, triggerOptions, 0, 0);

    DA_CN_AnalogueValue_createInstance("hhLim", (ModelNode*) newDa, fc, triggerOptions);
    DA_CN_AnalogueValue_createInstance("hLim", (ModelNode*) newDa, fc, triggerOptions);
    DA_CN_AnalogueValue_createInstance("lLim", (ModelNode*) newDa, fc, triggerOptions);
    DA_CN_AnalogueValue_createInstance("llLim", (ModelNode*) newDa, fc, triggerOptions);
    DA_CN_AnalogueValue_createInstance("min", (ModelNode*) newDa, fc, triggerOptions);
    DA_CN_AnalogueValue_createInstance("max", (ModelNode*) newDa, fc, triggerOptions);

    return newDa;
}


/**
 * DA: CN_Cancel_INC 
 */
DataAttribute*
DA_CN_Cancel_INC_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions)
{
    DataAttribute* newDa = DataAttribute_create(daName, parent, IEC61850_CONSTRUCTED, fc, triggerOptions, 0, 0);

    DataAttribute_create("ctlVal", (ModelNode*) newDa, IEC61850_INT32, fc, triggerOptions, 0, 0);
    DA_CN_Originator_createInstance("origin", (ModelNode*) newDa, fc, triggerOptions);
    DataAttribute_create("ctlNum", (ModelNode*) newDa, IEC61850_INT8U, fc, triggerOptions, 0, 0);
    DataAttribute_create("T", (ModelNode*) newDa, IEC61850_TIMESTAMP, fc, triggerOptions, 0, 0);
    DataAttribute_create("Test", (ModelNode*) newDa, IEC61850_BOOLEAN, fc, triggerOptions, 0, 0);

    return newDa;
}


/**
 * DA: CN_SBOw_Oper_INC 
 */
DataAttribute*
DA_CN_SBOw_Oper_INC_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions)
{
    DataAttribute* newDa = DataAttribute_create(daName, parent, IEC61850_CONSTRUCTED, fc, triggerOptions, 0, 0);

    DataAttribute_create("ctlVal", (ModelNode*) newDa, IEC61850_INT32, fc, triggerOptions, 0, 0);
    DA_CN_Originator_createInstance("origin", (ModelNode*) newDa, fc, triggerOptions);
    DataAttribute_create("ctlNum", (ModelNode*) newDa, IEC61850_INT8U, fc, triggerOptions, 0, 0);
    DataAttribute_create("T", (ModelNode*) newDa, IEC61850_TIMESTAMP, fc, triggerOptions, 0, 0);
    DataAttribute_create("Test", (ModelNode*) newDa, IEC61850_BOOLEAN, fc, triggerOptions, 0, 0);
    DataAttribute_create("Check", (ModelNode*) newDa, IEC61850_CHECK, fc, triggerOptions, 0, 0);

    return newDa;
}


/**
 * DA: CN_ScaledValueConfig 
 */
DataAttribute*
DA_CN_ScaledValueConfig_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions)
{
    DataAttribute* newDa = DataAttribute_create(daName, parent, IEC61850_CONSTRUCTED, fc, triggerOptions, 0, 0);

    DataAttribute_create("scaleFactor", (ModelNode*) newDa, IEC61850_FLOAT32, fc, triggerOptions, 0, 0);
    DataAttribute_create("offset", (ModelNode*) newDa, IEC61850_FLOAT32, fc, triggerOptions, 0, 0);

    return newDa;
}


/**
 * DA: CN_AnalogueValue 
 */
DataAttribute*
DA_CN_AnalogueValue_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions)
{
    DataAttribute* newDa = DataAttribute_create(daName, parent, IEC61850_CONSTRUCTED, fc, triggerOptions, 0, 0);

    DataAttribute_create("f", (ModelNode*) newDa, IEC61850_FLOAT32, fc, triggerOptions, 0, 0);

    return newDa;
}


