
/************************************************************************/
/*                                                                      */
/************************************************************************/
#include <windows.h>
#include "MCAxisBase.h"

//////////////////////////////////////////////////////////////////////////
//��ʼ���˶���
int CMCAxsInit(
			   CMCAXS * myAxs,
			   int nAxsID,/*����*/
			   int nAxsTyp,/*������:Servo/Steper*/
			   float nLead,/*����(mm) Lead*/
			   float nStpnNg,/*����� Step Angle*/
			   float nSbdvsn,/*ϸ�� Subdivision*/
			   float nDecRate,/*���ٱ�*/
			   float nVlcMax,/*�ٶ����ֵ-Pls/s*/
			   float nVlcAddMax,/*���ٶ����ֵ-Pls/s2*/
			   float nVlcDecMax,/*���ٶ����ֵ-Pls/s2*/
			   float nVlcNormal,/*�ٶ�(����ÿ��) -Pls/s*/
			   float nVlcSpecial,/*�ٶ�(����ÿ��) -Pls/s*/
			   double dfPlsMin,/*�����������Сֵ*/
			   double dfPlsMax/*�����������Сֵ*/
			   )
{
	CMCAxsInfInit(&myAxs->m_AxsInf, 
		nAxsID, nAxsTyp, nLead, nStpnNg, nSbdvsn, nDecRate, 
		nVlcMax, nVlcAddMax, nVlcDecMax, nVlcNormal, nVlcSpecial, dfPlsMin, dfPlsMax);
	CMCAxsSttInit(&myAxs->m_AxsStt);
	CMCAxsCtrInit(&myAxs->m_AxsCtr);
	CMCAxsDatInit(&myAxs->m_AxsDat);

	return TRUE;
}

//��ʼ��������Ϣ
int CMCAxsInfInit(
			  CMCAXSINF * myAxsInf,
			  int nAxsID,/*����*/
			  int nAxsTyp,/*������:Servo/Steper*/
			  float nLead,/*����(mm) Lead*/
			  float nStpnNg,/*����� Step Angle*/
			  float nSbdvsn,/*ϸ�� Subdivision*/
			  float nDecRate,/*���ٱ�*/
			  float nSpdMax,/*�ٶ����ֵ-Pls/s*/
			  float nSpdAddMax,/*���ٶ����ֵ-Pls/s2*/
			  float nSpdDecMax,/*���ٶ����ֵ-Pls/s2*/
			  float nSpdNormal,/*�ٶ�(����ÿ��) -Pls/s*/
			  float nSpdSpecial,/*�ٶ�(����ÿ��) -Pls/s*/
			  double dfPlsMin,/*�����������Сֵ*/
			  double dfPlsMax/*�����������Сֵ*/
			  )
{
	if (!myAxsInf)
	{
		return FALSE;
	}
	
	myAxsInf->m_nAxsID = nAxsID;/**/
	myAxsInf->m_nAxsTyp = nAxsTyp;/*������:Servo/Steper*/
	myAxsInf->m_fLead = nLead;/*����(mm) Lead*/
	myAxsInf->m_fStpnNg = nStpnNg;/*����� Step Angle*/
	myAxsInf->m_fSbdvsn = nSbdvsn;/*ϸ�� Subdivision*/
	myAxsInf->m_fDecRate = nDecRate;
	myAxsInf->m_fVlcCur = 1.0f;/*�ٶ�(mm/s) mm/s*/
	myAxsInf->m_fSpdMin = 0.1f;
	myAxsInf->m_fSpdMax = nSpdMax;
	myAxsInf->m_fSpdAddMax = nSpdAddMax;
	myAxsInf->m_fSpdDecMax = nSpdDecMax;
	myAxsInf->m_fSpdNormal = nSpdNormal;/*�ٶ�(mm/s) mm/s*/
	myAxsInf->m_fSpdSpecial = nSpdSpecial;/*�ٶ�(mm/s) mm/s*/
	myAxsInf->m_dfPlsMin = dfPlsMin;/*�����������Сֵ*/
	myAxsInf->m_dfPlsMax = dfPlsMax;/*�����������Сֵ*/

	return TRUE;
}
//��ʼ��״̬��Ϣ
int CMCAxsSttInit(CMCAXSSTT * myAxsStt)
{
	myAxsStt->m_nActived = 0x00;//23
	myAxsStt->m_nNgLmted = 0x00;//22
	myAxsStt->m_nPsLmted = 0x00;//21
	myAxsStt->m_nHwEnable = 0x00;//20
	myAxsStt->m_nPhasedMotor = 0x00;//19
	myAxsStt->m_nOpenLoop = 0x00;//18
	myAxsStt->m_nRunDfTime = 0x00;//17
	myAxsStt->m_nIntegration = 0x00;//16
	myAxsStt->m_nDwell = 0x00;//15
	myAxsStt->m_nDBErr = 0x00;//14
	myAxsStt->m_nDVZero = 0x00;//13
	myAxsStt->m_nArtDcl = 0x00;//12
	myAxsStt->m_nBloackRs = 0x00;//11
	myAxsStt->m_nHmSrhing = 0x00;//10
	myAxsStt->m_nPNextDB01 = 0x00;//8-9
	myAxsStt->m_nPNextDB02 = 0x00;//0-7
	//Secend DWORD Y
	myAxsStt->m_nAssCS = 0x00;//23
	myAxsStt->m_nCS01Num = 0x00;//20-22
	myAxsStt->m_nResFFU01 = 0x00;//16-19
	myAxsStt->m_nResFFU02 = 0x00;//15
	myAxsStt->m_nAmpEn = 0x00;//14
	myAxsStt->m_nResFFU03 = 0x00;//12-13
	myAxsStt->m_nStpOnPstLmt = 0x00;//11
	myAxsStt->m_nHmCmp = 0x00;//10
	myAxsStt->m_nResFFU04 = 0x00;//9
	myAxsStt->m_nPhsSErr = 0x00;//8
	myAxsStt->m_nTrgMv = 0x00;//7
	myAxsStt->m_nntFFErr = 0x00;//6
	myAxsStt->m_nI2TAmpFErr = 0x00;//5
	myAxsStt->m_nBckDrFlag = 0x00;//4
	myAxsStt->m_nAmpFErr = 0x00;//3
	myAxsStt->m_nFFErr = 0x00;//2
	myAxsStt->m_nWFErr = 0x00;//1
	myAxsStt->m_nInPst = 0x00;//0
	
	return TRUE;
}

//��ʼ��������Ϣ
int CMCAxsCtrInit(CMCAXSCTR * myAxsCtr)
{
	myAxsCtr->m_nIsSel = AXS_ISSEL_NO;//�Ƿ�ѡ��
	myAxsCtr->m_nCmdTyp = AXS_CMDTYPE_UNDEF;//ָ�����:��ȡ/����
	myAxsCtr->m_nPlsTyp = PST_PLS_TYPE_REL;//�������:���/����
	myAxsCtr->m_nCtrTyp = PST_CTR_TYPE_CLOOP;//���Ʒ�ʽ:����/�ջ�
	myAxsCtr->m_nHomTyp = PST_HOM_TYPE_RUN;//���㷽ʽ:�˶�/����
	
	return TRUE;
}

//��ʼ����������
int CMCAxsDatInit(CMCAXSDAT * myAxsDat)
{
	myAxsDat->m_dfPlsAsk = 0.0f;//Ŀ������
	myAxsDat->m_dfPlsBgn = 0.0f;//��ʼ����
	myAxsDat->m_dfPlsCur = 0.0f;//��ǰ����

	return TRUE;
}

//��ȡ��λ��ֵ
int CMCAxsGetPst(CMCAXSINF * myAxsInf, double nPls, double * nPst)
{
	double nAxPlsPr;/*ÿת������(����):puls/r*/
	double nAxPlsPmm;/*��λλ��������(���ٺ�):puls/mm*/
	
	if (!myAxsInf)
	{
		return FALSE;
	}
	//�����м�ֵ
	nAxPlsPr = (myAxsInf->m_fSbdvsn) * (myAxsInf->m_fStpnNg);/*ÿת������:puls/r*/
	nAxPlsPr = nAxPlsPr * (myAxsInf->m_fDecRate);/*ÿת������(���ٺ�):puls/r*/
	nAxPlsPmm = nAxPlsPr / (myAxsInf->m_fLead);/*��λλ��������(���ٺ�):puls/mm*/
	//���㷴��ֵ
	(* nPst) = nPls / nAxPlsPmm;
	
	return TRUE;
}

//��ȡ��������
int CMCAxsGetPls(CMCAXSINF * myAxsInf, double nPst, double * nPls)
{
	double nAxPlsPr;/*ÿת������(����):puls/r*/
	double nAxPlsPmm;/*��λλ��������(���ٺ�):puls/mm*/
	
	if (!myAxsInf)
	{
		return FALSE;
	}
	//�����м�ֵ
	nAxPlsPr = (myAxsInf->m_fSbdvsn) * (myAxsInf->m_fStpnNg);/*ÿת������:puls/r*/
	nAxPlsPr = nAxPlsPr * (myAxsInf->m_fDecRate);/*ÿת������(���ٺ�):puls/r*/
	nAxPlsPmm = nAxPlsPr / (myAxsInf->m_fLead);/*��λλ��������(���ٺ�):puls/mm*/
	//���㷴��ֵ
	(* nPls) = nPst * nAxPlsPmm;
	
	return TRUE;
}
