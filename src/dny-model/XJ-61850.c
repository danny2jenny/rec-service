#include "iec61850/iec61850_server.h"
#include "dny-model/XJ-61850.h"


/**
 * LN: XJBYQ_MMXN 
 */
LogicalNode*
LN_XJBYQ_MMXN_createInstance(char* lnName, LogicalDevice* parent)
{
    LogicalNode* newLn = LogicalNode_create(lnName, parent);

    DO_CN_INC_Mod_createInstance("Mod", (ModelNode*) newLn, 0);
    DO_CN_INS_Beh_createInstance("Beh", (ModelNode*) newLn, 0);
    DO_CN_INS_Health_createInstance("Health", (ModelNode*) newLn, 0);
    DO_CN_LPL_createInstance("NamPlt", (ModelNode*) newLn, 0);
    DO_CN_MV_createInstance("AnIn1", (ModelNode*) newLn, 0);
    DO_CN_MV_createInstance("AnIn2", (ModelNode*) newLn, 0);
    DO_CN_MV_createInstance("AnIn3", (ModelNode*) newLn, 0);
    DO_CN_MV_createInstance("AnIn4", (ModelNode*) newLn, 0);
    DO_CN_MV_I_createInstance("AnIn5", (ModelNode*) newLn, 0);
    DO_CN_MV_createInstance("AnIn6", (ModelNode*) newLn, 0);
    DO_CN_MV_createInstance("AnIn7", (ModelNode*) newLn, 0);
    DO_CN_MV_createInstance("AnIn8", (ModelNode*) newLn, 0);
    DO_CN_MV_createInstance("AnIn9", (ModelNode*) newLn, 0);
    DO_CN_MV_createInstance("AnIn10", (ModelNode*) newLn, 0);

    return newLn;
}


/**
 * LN: MONT_LPHD 
 */
LogicalNode*
LN_MONT_LPHD_createInstance(char* lnName, LogicalDevice* parent)
{
    LogicalNode* newLn = LogicalNode_create(lnName, parent);

    DO_CN_DPL_createInstance("PhyNam", (ModelNode*) newLn, 0);
    DO_CN_INS_Health_createInstance("PhyHealth", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Proxy", (ModelNode*) newLn, 0);

    return newLn;
}


/**
 * LN: XJBYQ_GGIO 
 */
LogicalNode*
LN_XJBYQ_GGIO_createInstance(char* lnName, LogicalDevice* parent)
{
    LogicalNode* newLn = LogicalNode_create(lnName, parent);

    DO_CN_INC_Mod_createInstance("Mod", (ModelNode*) newLn, 0);
    DO_CN_INS_Beh_createInstance("Beh", (ModelNode*) newLn, 0);
    DO_CN_INS_Health_createInstance("Health", (ModelNode*) newLn, 0);
    DO_CN_LPL_createInstance("NamPlt", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind1", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind2", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind3", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind4", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind5", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind6", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind7", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind8", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind9", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind10", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind11", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind12", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind13", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind14", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind15", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind16", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind17", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind18", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind19", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind20", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind21", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind22", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind23", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind24", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind25", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind26", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind27", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind28", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind29", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind30", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind31", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind32", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind33", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind34", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind35", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind36", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind37", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind38", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind39", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind40", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind41", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind42", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind43", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind44", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind45", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind46", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind47", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind48", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind49", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind50", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind51", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind52", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind53", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind54", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind55", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind56", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind57", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind58", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind59", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind60", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind61", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind62", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind63", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind64", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind65", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind66", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind67", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind68", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind69", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind70", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind71", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind72", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind73", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind74", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind75", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind76", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind77", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind78", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind79", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind80", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind81", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind82", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind83", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind84", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind85", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind86", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind87", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind88", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind89", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind90", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind91", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind92", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind93", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind94", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind95", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind96", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind97", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind98", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind99", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind100", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind101", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind102", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind103", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind104", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind105", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind106", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind107", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind108", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind109", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind110", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind111", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind112", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind113", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind114", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind115", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind116", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind117", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind118", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind119", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind120", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind121", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind122", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind123", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind124", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind125", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind126", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind127", (ModelNode*) newLn, 0);
    DO_CN_SPS_createInstance("Ind128", (ModelNode*) newLn, 0);

    return newLn;
}


/**
 * LN: MONT_LLN0 
 */
LogicalNode*
LN_MONT_LLN0_createInstance(char* lnName, LogicalDevice* parent)
{
    LogicalNode* newLn = LogicalNode_create(lnName, parent);

    DO_CN_INC_Mod_createInstance("Mod", (ModelNode*) newLn, 0);
    DO_CN_INS_Beh_createInstance("Beh", (ModelNode*) newLn, 0);
    DO_CN_INS_Health_createInstance("Health", (ModelNode*) newLn, 0);
    DO_CN_LPL_LN0_createInstance("NamPlt", (ModelNode*) newLn, 0);

    return newLn;
}


/**
 * DO: JZ_SPS (单点状态信息)
 */
DataObject*
DO_JZ_SPS_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DataAttribute_create("stVal", (ModelNode*) newDo, IEC61850_BOOLEAN, IEC61850_FC_ST, 1, 0, 0);
    DataAttribute_create("q", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_ST, 2, 0, 0);
    DataAttribute_create("t", (ModelNode*) newDo, IEC61850_TIMESTAMP, IEC61850_FC_ST, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_ASG_SG (模拟定值)
 */
DataObject*
DO_CN_ASG_SG_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DA_CN_AnalogueValue_createInstance("setMag", (ModelNode*) newDo, IEC61850_FC_SG, 0);
    DA_CN_Units_createInstance("units", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DA_CN_ScaledValueConfig_createInstance("sVC", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DA_CN_AnalogueValue_createInstance("minVal", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DA_CN_AnalogueValue_createInstance("maxVal", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DA_CN_AnalogueValue_createInstance("stepSize", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_HWYE 
 */
DataObject*
DO_CN_HWYE_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DataAttribute_create("q", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_MX, 2, 0, 0);
    DataAttribute_create("t", (ModelNode*) newDo, IEC61850_TIMESTAMP, IEC61850_FC_MX, 0, 0, 0);
    DA_CN_Vector_createInstance("phsAHar", (ModelNode*) newDo, IEC61850_FC_MX, 0);
    DA_CN_Vector_createInstance("phsBHar", (ModelNode*) newDo, IEC61850_FC_MX, 0);
    DA_CN_Vector_createInstance("phsCHar", (ModelNode*) newDo, IEC61850_FC_MX, 0);
    DataAttribute_create("d", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_INS (整数状态)
 */
DataObject*
DO_CN_INS_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DataAttribute_create("stVal", (ModelNode*) newDo, IEC61850_INT32, IEC61850_FC_ST, 1, 0, 0);
    DataAttribute_create("q", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_ST, 2, 0, 0);
    DataAttribute_create("t", (ModelNode*) newDo, IEC61850_TIMESTAMP, IEC61850_FC_ST, 0, 0, 0);
    DataAttribute_create("subEna", (ModelNode*) newDo, IEC61850_BOOLEAN, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("subVal", (ModelNode*) newDo, IEC61850_INT32, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("subQ", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("subID", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_64, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_INC_Mod (可控整数状态(模式))
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
 * DO: CN_HMV (测量值)
 */
DataObject*
DO_CN_HMV_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DataAttribute_create("q", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_MX, 2, 0, 0);
    DataAttribute_create("t", (ModelNode*) newDo, IEC61850_TIMESTAMP, IEC61850_FC_MX, 0, 0, 0);
    DA_CN_AnalogueValue_createInstance("har", (ModelNode*) newDo, IEC61850_FC_MX, 1);
    DataAttribute_create("numHar", (ModelNode*) newDo, IEC61850_INT16U, IEC61850_FC_CF, 1, 0, 0);
    DataAttribute_create("numCyc", (ModelNode*) newDo, IEC61850_INT16U, IEC61850_FC_CF, 1, 0, 0);
    DataAttribute_create("evalTm", (ModelNode*) newDo, IEC61850_INT16U, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("frequency", (ModelNode*) newDo, IEC61850_FLOAT32, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("d", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_LPL (逻辑节点铭牌)
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
 * DO: CN_MV_EX (扩展测量值)
 */
DataObject*
DO_CN_MV_EX_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DA_CN_AnalogueValue_createInstance("mag", (ModelNode*) newDo, IEC61850_FC_MX, 1);
    DataAttribute_create("q", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_MX, 2, 0, 0);
    DataAttribute_create("t", (ModelNode*) newDo, IEC61850_TIMESTAMP, IEC61850_FC_MX, 0, 0, 0);
    DataAttribute_create("subEna", (ModelNode*) newDo, IEC61850_BOOLEAN, IEC61850_FC_SV, 0, 0, 0);
    DA_CN_AnalogueValue_createInstance("subMag", (ModelNode*) newDo, IEC61850_FC_SV, 0);
    DataAttribute_create("subQ", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("subID", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_64, IEC61850_FC_SV, 0, 0, 0);
    DA_CN_Units_createInstance("units", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DataAttribute_create("db", (ModelNode*) newDo, IEC61850_INT32U, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("zeroDb", (ModelNode*) newDo, IEC61850_INT32U, IEC61850_FC_CF, 0, 0, 0);
    DA_CN_ScaledValueConfig_createInstance("sVC", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DA_CN_RangeConfig_createInstance("rangeC", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DataAttribute_create("smpRate", (ModelNode*) newDo, IEC61850_INT32U, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("dataNs", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_EX, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_INS_Health (整数状态类(用于数据对象Health))
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
 * DO: CN_ING_SP (整数状态定值(取代))
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
 * DO: CN_HWYE_EX 
 */
DataObject*
DO_CN_HWYE_EX_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DataAttribute_create("q", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_MX, 2, 0, 0);
    DataAttribute_create("t", (ModelNode*) newDo, IEC61850_TIMESTAMP, IEC61850_FC_MX, 0, 0, 0);
    DA_CN_Vector_createInstance("phsAHar", (ModelNode*) newDo, IEC61850_FC_MX, 0);
    DA_CN_Vector_createInstance("phsBHar", (ModelNode*) newDo, IEC61850_FC_MX, 0);
    DA_CN_Vector_createInstance("phsCHar", (ModelNode*) newDo, IEC61850_FC_MX, 0);
    DataAttribute_create("d", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("dataNs", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_EX, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_DPL (设备铭牌)
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
 * DO: CN_ASG_SP (模拟定值(取代))
 */
DataObject*
DO_CN_ASG_SP_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DA_CN_AnalogueValue_createInstance("setMag", (ModelNode*) newDo, IEC61850_FC_SP, 0);
    DA_CN_Units_createInstance("units", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DA_CN_ScaledValueConfig_createInstance("sVC", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DA_CN_AnalogueValue_createInstance("minVal", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DA_CN_AnalogueValue_createInstance("maxVal", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DA_CN_AnalogueValue_createInstance("stepSize", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_ING_SG (整数状态定值)
 */
DataObject*
DO_CN_ING_SG_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DataAttribute_create("setVal", (ModelNode*) newDo, IEC61850_INT32, IEC61850_FC_SG, 0, 0, 0);
    DataAttribute_create("minVal", (ModelNode*) newDo, IEC61850_INT32, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("maxVal", (ModelNode*) newDo, IEC61850_INT32, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("stepSize", (ModelNode*) newDo, IEC61850_INT32U, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_ACT 
 */
DataObject*
DO_CN_ACT_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DataAttribute_create("general", (ModelNode*) newDo, IEC61850_BOOLEAN, IEC61850_FC_ST, 1, 0, 0);
    DataAttribute_create("q", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_ST, 2, 0, 0);
    DataAttribute_create("t", (ModelNode*) newDo, IEC61850_TIMESTAMP, IEC61850_FC_ST, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_WYE_EX (扩展三相对地)
 */
DataObject*
DO_CN_WYE_EX_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DataAttribute_create("angRef", (ModelNode*) newDo, IEC61850_ENUMERATED, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("dataNs", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_EX, 0, 0, 0);
    DO_CN_CMV_createInstance("phsA", (ModelNode*) newDo, 0);
    DO_CN_CMV_createInstance("phsB", (ModelNode*) newDo, 0);
    DO_CN_CMV_createInstance("phsC", (ModelNode*) newDo, 0);

    return newDo;
}


/**
 * DO: CN_DPC_EX (可控的双点)
 */
DataObject*
DO_CN_DPC_EX_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DA_CN_SBOw_Oper_SDPC_createInstance("SBOw", (ModelNode*) newDo, IEC61850_FC_CO, 0);
    DA_CN_SBOw_Oper_SDPC_createInstance("Oper", (ModelNode*) newDo, IEC61850_FC_CO, 0);
    DA_CN_Cancel_SDPC_createInstance("Cancel", (ModelNode*) newDo, IEC61850_FC_CO, 0);
    DataAttribute_create("stVal", (ModelNode*) newDo, IEC61850_CODEDENUM, IEC61850_FC_ST, 1, 0, 0);
    DataAttribute_create("q", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_ST, 2, 0, 0);
    DataAttribute_create("t", (ModelNode*) newDo, IEC61850_TIMESTAMP, IEC61850_FC_ST, 0, 0, 0);
    DataAttribute_create("stSeld", (ModelNode*) newDo, IEC61850_BOOLEAN, IEC61850_FC_ST, 1, 0, 0);
    DataAttribute_create("subEna", (ModelNode*) newDo, IEC61850_BOOLEAN, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("subVal", (ModelNode*) newDo, IEC61850_CODEDENUM, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("subQ", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("subID", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_64, IEC61850_FC_SV, 0, 0, 0);
    DA_CN_PulseConfig_createInstance("pulseConfig", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DataAttribute_create("ctlModel", (ModelNode*) newDo, IEC61850_ENUMERATED, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("sboTimeout", (ModelNode*) newDo, IEC61850_INT32U, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("sboClass", (ModelNode*) newDo, IEC61850_ENUMERATED, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("dataNs", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_EX, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_CMV (复数测量值)
 */
DataObject*
DO_CN_CMV_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DA_CN_Vector_createInstance("instcVal", (ModelNode*) newDo, IEC61850_FC_MX, 1);
    DA_CN_Vector_createInstance("cVal", (ModelNode*) newDo, IEC61850_FC_MX, 1);
    DataAttribute_create("q", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_MX, 2, 0, 0);
    DataAttribute_create("t", (ModelNode*) newDo, IEC61850_TIMESTAMP, IEC61850_FC_MX, 0, 0, 0);
    DataAttribute_create("subEna", (ModelNode*) newDo, IEC61850_BOOLEAN, IEC61850_FC_SV, 0, 0, 0);
    DA_CN_Vector_createInstance("subCVal", (ModelNode*) newDo, IEC61850_FC_SV, 0);
    DataAttribute_create("subQ", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("subID", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_64, IEC61850_FC_SV, 0, 0, 0);
    DA_CN_Units_createInstance("units", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DataAttribute_create("angRef", (ModelNode*) newDo, IEC61850_ENUMERATED, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("smpRate", (ModelNode*) newDo, IEC61850_INT32U, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_MV (测量值)
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
    DA_CN_Units_createInstance("units", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DataAttribute_create("db", (ModelNode*) newDo, IEC61850_INT32U, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("zeroDb", (ModelNode*) newDo, IEC61850_INT32U, IEC61850_FC_CF, 0, 0, 0);
    DA_CN_ScaledValueConfig_createInstance("sVC", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DA_CN_RangeConfig_createInstance("rangeC", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DataAttribute_create("smpRate", (ModelNode*) newDo, IEC61850_INT32U, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_SPC (可控的单点)
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
 * DO: CN_HDEL (三相系统相对相地测量值)
 */
DataObject*
DO_CN_HDEL_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DataAttribute_create("q", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_MX, 2, 0, 0);
    DataAttribute_create("t", (ModelNode*) newDo, IEC61850_TIMESTAMP, IEC61850_FC_MX, 0, 0, 0);
    DA_CN_Vector_createInstance("phsABHar", (ModelNode*) newDo, IEC61850_FC_MX, 0);
    DA_CN_Vector_createInstance("phsBCHar", (ModelNode*) newDo, IEC61850_FC_MX, 0);
    DA_CN_Vector_createInstance("phsCAHar", (ModelNode*) newDo, IEC61850_FC_MX, 0);
    DataAttribute_create("angRef", (ModelNode*) newDo, IEC61850_ENUMERATED, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_SPC_DC (可控的单点(复归))
 */
DataObject*
DO_CN_SPC_DC_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DA_CN_SBOw_Oper_SDPC_createInstance("Oper", (ModelNode*) newDo, IEC61850_FC_CO, 0);
    DataAttribute_create("stVal", (ModelNode*) newDo, IEC61850_BOOLEAN, IEC61850_FC_ST, 1, 0, 0);
    DataAttribute_create("q", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_ST, 2, 0, 0);
    DataAttribute_create("t", (ModelNode*) newDo, IEC61850_TIMESTAMP, IEC61850_FC_ST, 0, 0, 0);
    DataAttribute_create("subEna", (ModelNode*) newDo, IEC61850_BOOLEAN, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("subVal", (ModelNode*) newDo, IEC61850_BOOLEAN, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("subQ", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("subID", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_64, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("ctlModel", (ModelNode*) newDo, IEC61850_ENUMERATED, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_ASG_SG_EX (扩展模拟定值)
 */
DataObject*
DO_CN_ASG_SG_EX_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DA_CN_AnalogueValue_createInstance("setMag", (ModelNode*) newDo, IEC61850_FC_SG, 0);
    DA_CN_Units_createInstance("units", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DA_CN_ScaledValueConfig_createInstance("sVC", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DA_CN_AnalogueValue_createInstance("minVal", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DA_CN_AnalogueValue_createInstance("maxVal", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DA_CN_AnalogueValue_createInstance("stepSize", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("dataNs", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_EX, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_SEQ (序分量值)
 */
DataObject*
DO_CN_SEQ_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DataAttribute_create("seqT", (ModelNode*) newDo, IEC61850_ENUMERATED, IEC61850_FC_MX, 0, 0, 0);
    DataAttribute_create("phsRef", (ModelNode*) newDo, IEC61850_ENUMERATED, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DO_CN_CMV_createInstance("c1", (ModelNode*) newDo, 0);
    DO_CN_CMV_createInstance("c2", (ModelNode*) newDo, 0);
    DO_CN_CMV_createInstance("c3", (ModelNode*) newDo, 0);

    return newDo;
}


/**
 * DO: CN_DPL_EX (扩展设备铭牌)
 */
DataObject*
DO_CN_DPL_EX_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DataAttribute_create("vendor", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("hwRev", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("swRev", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("serNum", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("model", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("location", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("dataNs", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_EX, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_INS_ARST (整数状态(自动重合闸))
 */
DataObject*
DO_CN_INS_ARST_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DataAttribute_create("stVal", (ModelNode*) newDo, IEC61850_ENUMERATED, IEC61850_FC_ST, 1, 0, 0);
    DataAttribute_create("q", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_ST, 2, 0, 0);
    DataAttribute_create("t", (ModelNode*) newDo, IEC61850_TIMESTAMP, IEC61850_FC_ST, 0, 0, 0);
    DataAttribute_create("subEna", (ModelNode*) newDo, IEC61850_BOOLEAN, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("subVal", (ModelNode*) newDo, IEC61850_ENUMERATED, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("subQ", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("subID", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_64, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_HST 
 */
DataObject*
DO_CN_HST_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DA_CN_AnalogueValue_I_createInstance("hstVal", (ModelNode*) newDo, IEC61850_FC_ST, 5);
    DataAttribute_create("q", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_ST, 2, 0, 0);
    DataAttribute_create("t", (ModelNode*) newDo, IEC61850_TIMESTAMP, IEC61850_FC_ST, 0, 0, 0);
    DataAttribute_create("numPts", (ModelNode*) newDo, IEC61850_INT16U, IEC61850_FC_ST, 1, 0, 0);
    DA_CN_AnalogueValue_createInstance("hstRangeC", (ModelNode*) newDo, IEC61850_FC_CF, 1);
    DA_CN_Units_createInstance("xUnits", (ModelNode*) newDo, IEC61850_FC_CF, 1);
    DA_CN_Units_createInstance("yUnits", (ModelNode*) newDo, IEC61850_FC_CF, 1);
    DataAttribute_create("maxPts", (ModelNode*) newDo, IEC61850_INT16U, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("xD", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("d", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_SPS (单点状态信息类)
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
 * DO: CN_DEL_EX (三相系统相对相地测量值)
 */
DataObject*
DO_CN_DEL_EX_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DataAttribute_create("angRef", (ModelNode*) newDo, IEC61850_ENUMERATED, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("dataNs", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_EX, 0, 0, 0);
    DO_CN_CMV_createInstance("phsAB", (ModelNode*) newDo, 0);
    DO_CN_CMV_createInstance("phsBC", (ModelNode*) newDo, 0);
    DO_CN_CMV_createInstance("phsCA", (ModelNode*) newDo, 0);

    return newDo;
}


/**
 * DO: CN_INS_Beh (整数状态类(用于数据对象Beh))
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
 * DO: CN_LPL_LN0 (逻辑节点铭牌(LN0))
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
 * DO: CN_MV_I (测量值)
 */
DataObject*
DO_CN_MV_I_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DA_CN_AnalogueValue_I_createInstance("mag", (ModelNode*) newDo, IEC61850_FC_MX, 1);
    DataAttribute_create("q", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_MX, 2, 0, 0);
    DataAttribute_create("t", (ModelNode*) newDo, IEC61850_TIMESTAMP, IEC61850_FC_MX, 0, 0, 0);
    DataAttribute_create("subEna", (ModelNode*) newDo, IEC61850_BOOLEAN, IEC61850_FC_SV, 0, 0, 0);
    DA_CN_AnalogueValue_createInstance("subMag", (ModelNode*) newDo, IEC61850_FC_SV, 0);
    DataAttribute_create("subQ", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("subID", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_64, IEC61850_FC_SV, 0, 0, 0);
    DA_CN_Units_createInstance("units", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DataAttribute_create("db", (ModelNode*) newDo, IEC61850_INT32U, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("zeroDb", (ModelNode*) newDo, IEC61850_INT32U, IEC61850_FC_CF, 0, 0, 0);
    DA_CN_ScaledValueConfig_createInstance("sVC", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DA_CN_RangeConfig_createInstance("rangeC", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DataAttribute_create("smpRate", (ModelNode*) newDo, IEC61850_INT32U, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_DEL (三相系统相对相地测量值)
 */
DataObject*
DO_CN_DEL_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DataAttribute_create("angRef", (ModelNode*) newDo, IEC61850_ENUMERATED, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DO_CN_CMV_createInstance("phsAB", (ModelNode*) newDo, 0);
    DO_CN_CMV_createInstance("phsBC", (ModelNode*) newDo, 0);
    DO_CN_CMV_createInstance("phsCA", (ModelNode*) newDo, 0);

    return newDo;
}


/**
 * DO: CN_WYE (三相对地)
 */
DataObject*
DO_CN_WYE_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DataAttribute_create("angRef", (ModelNode*) newDo, IEC61850_ENUMERATED, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DO_CN_CMV_createInstance("phsA", (ModelNode*) newDo, 0);
    DO_CN_CMV_createInstance("phsB", (ModelNode*) newDo, 0);
    DO_CN_CMV_createInstance("phsC", (ModelNode*) newDo, 0);
    DO_CN_CMV_createInstance("neut", (ModelNode*) newDo, 0);

    return newDo;
}


/**
 * DO: CN_ACD 
 */
DataObject*
DO_CN_ACD_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DataAttribute_create("general", (ModelNode*) newDo, IEC61850_BOOLEAN, IEC61850_FC_ST, 1, 0, 0);
    DataAttribute_create("dirGeneral", (ModelNode*) newDo, IEC61850_ENUMERATED, IEC61850_FC_ST, 1, 0, 0);
    DataAttribute_create("q", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_ST, 2, 0, 0);
    DataAttribute_create("t", (ModelNode*) newDo, IEC61850_TIMESTAMP, IEC61850_FC_ST, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_SPC_EX (扩展可控的单点)
 */
DataObject*
DO_CN_SPC_EX_createInstance(char* doName, ModelNode* parent, int arrayCount)
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
    DataAttribute_create("dataNs", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_EX, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_DPC (可控的双点)
 */
DataObject*
DO_CN_DPC_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DA_CN_SBOw_Oper_SDPC_createInstance("SBOw", (ModelNode*) newDo, IEC61850_FC_CO, 0);
    DA_CN_SBOw_Oper_SDPC_createInstance("Oper", (ModelNode*) newDo, IEC61850_FC_CO, 0);
    DA_CN_Cancel_SDPC_createInstance("Cancel", (ModelNode*) newDo, IEC61850_FC_CO, 0);
    DataAttribute_create("stVal", (ModelNode*) newDo, IEC61850_CODEDENUM, IEC61850_FC_ST, 1, 0, 0);
    DataAttribute_create("q", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_ST, 2, 0, 0);
    DataAttribute_create("t", (ModelNode*) newDo, IEC61850_TIMESTAMP, IEC61850_FC_ST, 0, 0, 0);
    DataAttribute_create("stSeld", (ModelNode*) newDo, IEC61850_BOOLEAN, IEC61850_FC_ST, 1, 0, 0);
    DataAttribute_create("subEna", (ModelNode*) newDo, IEC61850_BOOLEAN, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("subVal", (ModelNode*) newDo, IEC61850_CODEDENUM, IEC61850_FC_SV, 0, 0, 0);
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
 * DO: CN_INS_EX (扩展整数状态)
 */
DataObject*
DO_CN_INS_EX_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DataAttribute_create("stVal", (ModelNode*) newDo, IEC61850_INT32, IEC61850_FC_ST, 1, 0, 0);
    DataAttribute_create("q", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_ST, 2, 0, 0);
    DataAttribute_create("t", (ModelNode*) newDo, IEC61850_TIMESTAMP, IEC61850_FC_ST, 0, 0, 0);
    DataAttribute_create("subEna", (ModelNode*) newDo, IEC61850_BOOLEAN, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("subVal", (ModelNode*) newDo, IEC61850_INT32, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("subQ", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("subID", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_64, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("dataNs", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_EX, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_SPS_EX (扩展单点状态信息类)
 */
DataObject*
DO_CN_SPS_EX_createInstance(char* doName, ModelNode* parent, int arrayCount)
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
    DataAttribute_create("dataNs", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_EX, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_ASG_SP_EX (扩展模拟定值(取代))
 */
DataObject*
DO_CN_ASG_SP_EX_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DA_CN_AnalogueValue_createInstance("setMag", (ModelNode*) newDo, IEC61850_FC_SP, 0);
    DA_CN_Units_createInstance("units", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DA_CN_ScaledValueConfig_createInstance("sVC", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DA_CN_AnalogueValue_createInstance("minVal", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DA_CN_AnalogueValue_createInstance("maxVal", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DA_CN_AnalogueValue_createInstance("stepSize", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("dataNs", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_EX, 0, 0, 0);

    return newDo;
}


/**
 * DO: CN_CMV_EX (扩展复数测量值)
 */
DataObject*
DO_CN_CMV_EX_createInstance(char* doName, ModelNode* parent, int arrayCount)
{
    DataObject* newDo = DataObject_create(doName, parent, arrayCount);

    DA_CN_Vector_createInstance("cVal", (ModelNode*) newDo, IEC61850_FC_MX, 1);
    DataAttribute_create("q", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_MX, 2, 0, 0);
    DataAttribute_create("t", (ModelNode*) newDo, IEC61850_TIMESTAMP, IEC61850_FC_MX, 0, 0, 0);
    DataAttribute_create("subEna", (ModelNode*) newDo, IEC61850_BOOLEAN, IEC61850_FC_SV, 0, 0, 0);
    DA_CN_Vector_createInstance("subCVal", (ModelNode*) newDo, IEC61850_FC_SV, 0);
    DataAttribute_create("subQ", (ModelNode*) newDo, IEC61850_QUALITY, IEC61850_FC_SV, 0, 0, 0);
    DataAttribute_create("subID", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_64, IEC61850_FC_SV, 0, 0, 0);
    DA_CN_Units_createInstance("units", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DataAttribute_create("db", (ModelNode*) newDo, IEC61850_INT32U, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("zeroDb", (ModelNode*) newDo, IEC61850_INT32U, IEC61850_FC_CF, 0, 0, 0);
    DA_CN_RangeConfig_createInstance("rangeC", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DA_CN_ScaledValueConfig_createInstance("magSVC", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DA_CN_ScaledValueConfig_createInstance("angSVC", (ModelNode*) newDo, IEC61850_FC_CF, 0);
    DataAttribute_create("angRef", (ModelNode*) newDo, IEC61850_ENUMERATED, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("smpRate", (ModelNode*) newDo, IEC61850_INT32U, IEC61850_FC_CF, 0, 0, 0);
    DataAttribute_create("dU", (ModelNode*) newDo, IEC61850_UNICODE_STRING_255, IEC61850_FC_DC, 0, 0, 0);
    DataAttribute_create("dataNs", (ModelNode*) newDo, IEC61850_VISIBLE_STRING_255, IEC61850_FC_EX, 0, 0, 0);

    return newDo;
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
 * DA: CN_Vector 
 */
DataAttribute*
DA_CN_Vector_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions)
{
    DataAttribute* newDa = DataAttribute_create(daName, parent, IEC61850_CONSTRUCTED, fc, triggerOptions, 0, 0);

    DA_CN_AnalogueValue_createInstance("mag", (ModelNode*) newDa, fc, triggerOptions);
    DA_CN_AnalogueValue_createInstance("ang", (ModelNode*) newDa, fc, triggerOptions);

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
 * DA: CN_AnalogueValue 
 */
DataAttribute*
DA_CN_AnalogueValue_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions)
{
    DataAttribute* newDa = DataAttribute_create(daName, parent, IEC61850_CONSTRUCTED, fc, triggerOptions, 0, 0);

    DataAttribute_create("f", (ModelNode*) newDa, IEC61850_FLOAT32, fc, triggerOptions, 0, 0);

    return newDa;
}


/**
 * DA: CN_SBOw_Oper_BSC 
 */
DataAttribute*
DA_CN_SBOw_Oper_BSC_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions)
{
    DataAttribute* newDa = DataAttribute_create(daName, parent, IEC61850_CONSTRUCTED, fc, triggerOptions, 0, 0);

    DataAttribute_create("ctlVal", (ModelNode*) newDa, IEC61850_CODEDENUM, fc, triggerOptions, 0, 0);
    DA_CN_Originator_createInstance("origin", (ModelNode*) newDa, fc, triggerOptions);
    DataAttribute_create("ctlNum", (ModelNode*) newDa, IEC61850_INT8U, fc, triggerOptions, 0, 0);
    DataAttribute_create("T", (ModelNode*) newDa, IEC61850_TIMESTAMP, fc, triggerOptions, 0, 0);
    DataAttribute_create("Test", (ModelNode*) newDa, IEC61850_BOOLEAN, fc, triggerOptions, 0, 0);
    DataAttribute_create("Check", (ModelNode*) newDa, IEC61850_CHECK, fc, triggerOptions, 0, 0);

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
 * DA: CN_Units 
 */
DataAttribute*
DA_CN_Units_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions)
{
    DataAttribute* newDa = DataAttribute_create(daName, parent, IEC61850_CONSTRUCTED, fc, triggerOptions, 0, 0);

    DataAttribute_create("SIUnit", (ModelNode*) newDa, IEC61850_ENUMERATED, fc, triggerOptions, 0, 0);
    DataAttribute_create("multiplier", (ModelNode*) newDa, IEC61850_ENUMERATED, fc, triggerOptions, 0, 0);

    return newDa;
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
 * DA: CN_Cancel_BSC 
 */
DataAttribute*
DA_CN_Cancel_BSC_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions)
{
    DataAttribute* newDa = DataAttribute_create(daName, parent, IEC61850_CONSTRUCTED, fc, triggerOptions, 0, 0);

    DataAttribute_create("ctlVal", (ModelNode*) newDa, IEC61850_CODEDENUM, fc, triggerOptions, 0, 0);
    DA_CN_Originator_createInstance("origin", (ModelNode*) newDa, fc, triggerOptions);
    DataAttribute_create("ctlNum", (ModelNode*) newDa, IEC61850_INT8U, fc, triggerOptions, 0, 0);
    DataAttribute_create("T", (ModelNode*) newDa, IEC61850_TIMESTAMP, fc, triggerOptions, 0, 0);
    DataAttribute_create("Test", (ModelNode*) newDa, IEC61850_BOOLEAN, fc, triggerOptions, 0, 0);

    return newDa;
}


/**
 * DA: CN_AnalogueValue_I 
 */
DataAttribute*
DA_CN_AnalogueValue_I_createInstance(char* daName, ModelNode* parent, FunctionalConstraint fc, uint8_t triggerOptions)
{
    DataAttribute* newDa = DataAttribute_create(daName, parent, IEC61850_CONSTRUCTED, fc, triggerOptions, 0, 0);

    DataAttribute_create("i", (ModelNode*) newDa, IEC61850_INT32, fc, triggerOptions, 0, 0);

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
    DataAttribute_create("Check", (ModelNode*) newDa, IEC61850_CHECK, fc, triggerOptions, 0, 0);

    return newDa;
}


