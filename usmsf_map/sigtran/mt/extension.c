#include <sigtran_util.h>

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>

#include <Config.h>
#include <iXCauseCode.h>
#include <iXConfParam.h>
#include <ASN/asn_smsc.h>
#include <SS7/ix7map.h>
#include <SS7/ss7_resq.h>
#include <SS7/links.h>
#include <SS7/map2.h>
#include <TPDU/TPDU.h>
#include <iXSriQ.h>

#include <iXss7Trace.h>
#include <iXMapOp.h>

#include <ua_log.h>
#include <ua_sysdef.h>
#include <ua_syslib.h>
#include <ua_oam_type.h>
#include <ua_mtype.h>

#include <iXMtQ.h>

extern OssBuf                param;
extern struct ossGlobal      *world;


int decodeSriExtenstion(RoutingInfoForSM_Arg_V3 *sri3, stSRI_Rcv_msg *srircv)
{
    struct PrivateExtensionList    *pPrivate;
	KTF_EXTMSISDNTYPE              *ktfMsisdn;
    KTF_EXTORIGINALNUMTYPE         *stOriginNum;
	int pduNum;
	unsigned char decBuf[1024];

    if (!(sri3->bit_mask & RoutingInfoForSM_Arg_V3_extensionContainer_present && 
		sri3->extensionContainer.bit_mask & privateExtensionList_present))
		return IXOK;

    pPrivate = sri3->extensionContainer.privateExtensionList;

    while (pPrivate != NULL)
    {
        if (pPrivate->value.extId.length == ktf_extmsisdn_id.length &&
            !memcmp(pPrivate->value.extId.value, ktf_extmsisdn_id.value, ktf_extmsisdn_id.length))
        {

			srircv->is_extension = 1;
            param.length = (long)pPrivate->value.extType.length;
            param.value = (unsigned char *)pPrivate->value.extType.encoded;
            pduNum = KTF_EXTMSISDNTYPE_PDU;
            ktfMsisdn = (KTF_EXTMSISDNTYPE *)decBuf;

            ossSetDecodingLength( world, sizeof(decBuf));
            if (ossDecode(world, &pduNum, &param, (void **)&ktfMsisdn))
            {
                uaLog(L_CRT, "ossDecode KTF Msisdn PDU\n");
                uaLog(L_CRT, "ERROR : (%s)\n", ossGetErrMsg(world));
            }
			memcpy(&srircv->msisdn, ktfMsisdn, sizeof(KTF_EXTMSISDNTYPE));
        }
        else if (pPrivate->value.extId.length == ktf_extoriginalnum_id.length &&
            !memcmp(pPrivate->value.extId.value, ktf_extoriginalnum_id.value, ktf_extoriginalnum_id.length))
        {
			srircv->is_extension = 1;
            param.length = (long)pPrivate->value.extType.length;
            param.value = (unsigned char *)pPrivate->value.extType.encoded;
            pduNum = KTF_EXTORIGINALNUMTYPE_PDU;
            stOriginNum = (KTF_EXTORIGINALNUMTYPE*)decBuf;

            ossSetDecodingLength( world, sizeof(decBuf));
            if (ossDecode(world, &pduNum, &param, (void **)&stOriginNum))
            {
                uaLog(L_CRT, "ossDecode KTF Msisdn PDU\n");
                uaLog(L_CRT, "ERROR : (%s)\n", ossGetErrMsg(world));
            }
			memcpy(&srircv->orig_number, stOriginNum, sizeof(KTF_EXTORIGINALNUMTYPE));
        }
        pPrivate = pPrivate->next;
    }
}

/* sjkim add : encoding ExtensionContainer for KTF */
int encodeSriRespExtension(struct PrivateExtensionList *privateExt, unsigned char *encBufExt, int encBufExtSize, ObjectID extId, int pduNum, void *value)
{
    OssBuf extBuf;
            
    privateExt->value.bit_mask = extType_present;
    privateExt->value.extId = extId;
    privateExt->value.extType.pduNum = 0;
    privateExt->value.extType.decoded = 0;
            
    extBuf.length = encBufExtSize;
    extBuf.value = encBufExt;
        
    if (ossEncode(world, pduNum, value, &extBuf))
    {
        uaLog(L_CRT,"ossEncode error: %s\n", ossGetErrMsg(world));
        privateExt->value.extType.length = 0;
    }
    else {
        privateExt->value.extType.length = extBuf.length;
        privateExt->value.extType.encoded = extBuf.value;
    }
    return IXOK;
}
