
#include <iXtypes.h>
#include <iXCauseCode.h>
#include <TPDU/BitUtil.h>
#include <TPDU/TPDU.h>
#include <TPDU/checkTpdu.h>


int checkTpdu_status(byte st, byte *fcs)
{
    if(GetBits(st, 7, 1)==0)
    {
        st = GetBits(st, 0, 6);
        if( (st>=0x03 && st<=0x0F)
            || (st>=0x10 && st<=0x1F)
            || (st>=0x26 && st<=0x2F)
            || (st>=0x4A && st<=0x4F)
            || (st>=0x66 && st<=0x6F)
            || (st>=0x10 && st<=0x1F) )
            *fcs = FCS_TPDU_NOT_SUPPORTED;
            return IXERR;
    }

    return IXOK;
}


int checkTpdu_VP(byte vpf, byte *value, byte *fcs)
{
    byte *vp = (byte*)value;
    TTimeStamp *pStamp = (TTimeStamp *)vp;

    switch(vpf)
    {
        case TPDU_VPF_NOT_PRESENT :
            break;

        case TPDU_VPF_ENHANCED :
            if(GetBits(vp[0], 0, 3) >= 4 ) //reserved value
            {
                *fcs = FCS_TP_VP_NOT_SUPPORTED;
                return IXERR;
            }
            break;

        case TPDU_VPF_RELATIVE :
            break;

        case TPDU_VPF_ABSOLUTE :
            if((pStamp->Month > 12) || (pStamp->Month < 1) ||
               (pStamp->Day > 31) || (pStamp->Hour > 24) ||
               (pStamp->Min > 60) || (pStamp->Sec > 60))
            {
                *fcs = FCS_TP_VP_NOT_SUPPORTED;
                return IXERR;
            }
            break;

        default :
            *fcs = FCS_TP_VPF_NOT_SUPPORTED;
            return IXERR;
    }

    return IXOK;
}


int checkTpdu_HeaderElement(stEI *pei)
{
    int ret;
    int tag = pei->ID;

    if( (tag==0x02)                         // Reserved 
        || ( (tag>=0x18) && (tag<=0x1F) )   // Reserved for future EMS features
        || ( (tag>=0x22) && (tag<=0x6F) )   // Reserved for future use
        || ( (tag>=0xA0) && (tag<=0xBF) )   // SC specific use
        || ( (tag>=0xC0) && (tag<=0xDF) )   // SC specific use
        || ( (tag>=0xE0) && (tag<=0xFF) ) ) // Reserved for future use
        return IXERR;


    switch(tag)
    {
        case 0x00: //concatenated short messages, 8-bit reference number 
            if(pei->Length != 3) return IXERR;
            if(pei->Data[1] == 0) return IXERR;
            if( (pei->Data[2] == 0) 
                || (pei->Data[2] > pei->Data[1]) )
                return IXERR;
            break;

        case 0x01: //Special SMS Message Indication
            if(pei->Length != 2) return IXERR;
            if(GetBits(pei->Data[0], 0, 6) > 3) return IXERR;     //reserved
            break;

        case 0x03: //Value not used to avoid misinterpretation as <LF> character
            break;
        case 0x04: //Application port addressing scheme, 8 bit address
            if(pei->Length != 2) return IXERR;
            break;
        case 0x05: //Application port addressing scheme, 16 bit address
            if(pei->Length != 4) return IXERR;
            break;
        case 0x06: //SMSC Control Parameters
            if(pei->Length != 1) return IXERR;
            break;
        case 0x07: //UDH Source Indicator
            break;
        case 0x08: //Concatenated short message, 16-bit reference number
            break;
        case 0x09: //Wireless Control Message Protocol
            break;
        case 0x0A: //Text Formatting
            if(pei->Length != 4) return IXERR;
            break;
        case 0x0B: //Predefined Sound
            break;
        case 0x0C: //User Defined Sound : max 128 bites
            break;
        case 0x0D: //Predefined Animation
            break;
        case 0x0E: //Large Animation 128 byte
            break;
        case 0x0F: //Small Animation 32 byte
            break;
        case 0x10: //Large Picture 128byte
            break;
        case 0x11: //Small Picture 32byte
            break;
        case 0x12: //Variable Picture
            break;
        case 0x20: //RFC 822 E-Mail Header
            break;
        case 0x21: //Hyperlink format element
            break;

        default :
            if( tag>=0x70 && tag<=0x7F ) // (U)SIM Toolkit Security Headers
            {
                if(pei->Length != 0) return IXERR;
            }
            break;
    }

    return IXOK;
}


int checkTpdu_UserData(int headerIndi, TUserData *userData, byte *fcs)
{
    boolean isConcatenatedSM;
    int i, ret;
    int elementCount = userData->udh.eiCnt;
    stEI *pei = userData->udh.ei;

    if(headerIndi != 0)
    {
        if(elementCount < 1)
        {
            *fcs = FCS_UNSPECIFIED_ERROR_CAUSE;
            return IXERR;
        }

        isConcatenatedSM = TPDU_FALSE;
        for(i=0; i<elementCount; ) 
        {
            ret = checkTpdu_HeaderElement(pei);
            if(ret < 0)
            {
                memcpy((void *)pei, 
                    (void *)&userData->udh.ei[elementCount-1], 
                    sizeof(stEI));
                elementCount--;
            }
            else
            {
                i++;
                pei++;
            }
        }
        userData->udh.eiCnt = elementCount;
    }

    return IXOK;
}


int checkTpdu(_TPDU *tpdu, byte *fcs)
{
    int ret;
    byte vpf;
    void *ptr;
    *fcs = FCS_NO_ERROR;

    switch(tpdu->MessageType)
    {
        case TPDU_SMS_DELIVER :
            ret = checkTpdu_UserData(tpdu->Union.SMSDeliver.udhId, 
                                &tpdu->Union.SMSDeliver.UserData, 
                                fcs);
            if(ret < 0) return IXERR;
            break;

        case TPDU_SMS_DELIVER_REPORT :
            if(tpdu->Union.SMSDeliverReport.ParameterID.isUDLPresent)
            {
                ret = checkTpdu_UserData(
                                tpdu->Union.SMSDeliverReport.udhId, 
                                &tpdu->Union.SMSDeliverReport.UserData, 
                                fcs);
                if(ret < 0) return IXERR;
            }

            if(tpdu->Union.SMSDeliverReport.ParameterID.isPIDPresent)
            {
                ret = checkTpdu_pid(tpdu->Union.SMSDeliverReport.pid, fcs);
                if(ret < 0)
                    return IXERR;
            }
            break;

        case TPDU_SMS_SUBMIT :
            ret = checkTpdu_pid(tpdu->Union.SMSSubmit.pid, fcs);
            if(ret < 0) return IXERR;

            if(tpdu->Union.SMSSubmit.MessageTypeID != 1)
            {
                *fcs = FCS_SC_SYSTEM_FAILURE;
                return IXERR;
            }

            ret = checkTpdu_UserData(tpdu->Union.SMSSubmit.udhId, 
                &tpdu->Union.SMSSubmit.UserData, fcs);
            if(ret < 0)
                return IXERR;
            break;

        case TPDU_SMS_SUBMIT_REPORT :
            if(tpdu->Union.SMSSubmitReport.ParameterID.isUDLPresent)
            {
                ret = checkTpdu_UserData(tpdu->Union.SMSSubmitReport.udhId, 
                    &tpdu->Union.SMSSubmitReport.UserData, fcs);
                if(ret < 0)
                    return IXERR;
            }

            if(tpdu->Union.SMSSubmitReport.ParameterID.isPIDPresent)
            {
                ret = checkTpdu_pid(tpdu->Union.SMSSubmitReport.pid, fcs);
                if(ret < 0)
                    return IXERR;
            }

            vpf = tpdu->Union.SMSSubmit.ValidityPeriodFormat;
            if(vpf==TPDU_VPF_NOT_PRESENT) 
                ptr =(void*)NULL;
            else if(vpf==TPDU_VPF_ENHANCED) 
                ptr = (void*)&tpdu->Union.SMSSubmit.ValidityPeriodEnhanced;
            else if(vpf==TPDU_VPF_RELATIVE) 
                ptr = (void*)&tpdu->Union.SMSSubmit.ValidityRelative;
            else if(vpf==TPDU_VPF_ABSOLUTE) 
                ptr = (void*)&tpdu->Union.SMSSubmit.ValidityPeriodAbsolute;
            else 
            {
                *fcs = FCS_TP_VPF_NOT_SUPPORTED;
                return IXERR;
            }
            ret = checkTpdu_VP(vpf, ptr, fcs);
            if(ret < 0)
                return IXERR;
            break;

        case TPDU_SMS_STATUS_REPORT :
            if(tpdu->Union.SMSStatusReport.ParameterID.isUDLPresent)
            {
                ret = checkTpdu_UserData(
                                tpdu->Union.SMSStatusReport.udhId, 
                                &tpdu->Union.SMSStatusReport.UserData, 
                                fcs);
                if(ret < 0) return IXERR;
            }

            if(tpdu->Union.SMSStatusReport.ParameterID.isPIDPresent)
            {
                ret = checkTpdu_pid(tpdu->Union.SMSStatusReport.pid, fcs);
                if(ret < 0) return IXERR;
            }
            break;

        case TPDU_SMS_COMMAND :
            ret = checkTpdu_commandType(tpdu->Union.SMSCommand.CommandType,
                                tpdu->Union.SMSCommand.StatusReportRequest,
                                fcs);
            if(ret < 0) return IXERR;

            ret = checkTpdu_pid(tpdu->Union.SMSCommand.pid, fcs);
            if(ret < 0) return IXERR;

            break;


        default :
            *fcs = FCS_SM_TYPE_0_NOT_SUPPORTED;
            return IXERR;
    }
    return IXOK;
}


int checkTpdu_pid(byte pid, byte *causeCode)
{
    int temp;
    int ret;

    temp = GetBits(pid, 6, 2);

    if(temp == 0x00) //00
    {
        temp = GetBits(pid, 5, 1);
        if(temp ==0)
        {
            ret = IXOK;
        }
        else //if(temp ==1)
        {
            temp = GetBits(pid, 0, 5);
            if( (temp>=0x0E && temp<=0x0F) 
                || (temp>=0x13 && temp<=0x17) )
            {
                ret = IXERR;
                *causeCode = FCS_TELEMATIC_NOT_SUPPORTED;
            }
            else
            {
                ret = IXOK;
            }
        }
    }
    else if(temp == 0x01) //01
    {
        temp = GetBits(pid, 0, 6);
        if( (temp>=0x08 && temp<=0x1D) 
            || (temp>=0x20 && temp<=0x3B) )
        {
            ret = IXERR;
            *causeCode = FCS_TELEMATIC_NOT_SUPPORTED;
        }
        else
        {
            ret = IXOK;
        }

    }
    else if(temp == 0x02) //10
    {
        ret = IXERR;
        *causeCode = FCS_UNSPECIFIED_TP_PID_ERROR;
    }
    else if(temp == 0x03) //11
    {
        ret = IXERR;
        *causeCode = FCS_UNSPECIFIED_TP_PID_ERROR;
    }
    else 
    {
        ret = IXERR;
        *causeCode = FCS_UNSPECIFIED_TP_PID_ERROR;
    }

    return ret;
}


int checkTpdu_dcs(byte *dcs, byte *causeCode)
{
    return IXOK;
}


int checkTpdu_commandType(byte commandType, byte srr, byte *causeCode)
{
    int ret;

    switch(commandType)
    {
        case 0x0 : //CMD_TYPE_ENQUIRY:
                if(srr != 1)
                {
                    *causeCode = FCS_UNSPECIFIED_TP_CMD_ERROR;
                    ret = IXERR;
                }
                else
                    ret = IXOK;

                break;

        case 0x1 : //CMD_TYPE_CANCEL:
                if(srr != 0)
                {
                    *causeCode = FCS_UNSPECIFIED_TP_CMD_ERROR;
                    ret = IXERR;
                }
                else
                    ret = IXOK;

                break;

        case 0x2 : //CMD_TYPE_DELETE:
                if(srr != 0)
                {
                    *causeCode = FCS_UNSPECIFIED_TP_CMD_ERROR;
                    ret = IXERR;
                }
                else
                    ret = IXOK;

                break;

        case 0x3 : //CMD_TYPE_ENABLE:
                if(srr != 0)
                {
                    *causeCode = FCS_UNSPECIFIED_TP_CMD_ERROR;
                    ret = IXERR;
                }
                else
                    ret = IXOK;

                break;

        default :
                if((commandType >= 0x04)
                && (commandType <= 0x1F) )
                {
                    *causeCode = FCS_CMD_UNSUPPORTED;
                    ret = IXERR;
                }
                else if(commandType > 0xE0)
                {
                    *causeCode = FCS_UNSPECIFIED_TP_CMD_ERROR;
                    ret = IXERR;
                }
                break;
    } 

    return ret;
}


char convGsmToAscii(unsigned char ch)
{
    if(ch == 0x00)
	    return 0x40;
    else if(ch == 0x02)
	    return 0x24;
    else
	    return ch;
}

char convAsciiToGsm(unsigned char ch)
{
    if(ch == 0x40)
	    return 0x00;
    else if(ch == 0x24)
	    return 0x02;
    else 
	    return ch;
}


