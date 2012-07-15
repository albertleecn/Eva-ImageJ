/************************************************************************/
/*                                                                      */
/************************************************************************/
#pragma once
//#ifndef _AXBS_
//#define _AXBS_ 
//////////////////////////////////////////////////////////////////////////
//������
#define AXS_TYPE_UNDEF			0x00
#define AXS_TYPE_STEPER			0x01
#define AXS_TYPE_SERVO			0x02

//////////////////////////////////////////////////////////////////////////
//����˶���
//�����˶���ȡ��Ϊ�����˶�
#define AXS_DRC_NGT				0x0010

#define AXS_JOG_RUN				0x0001
#define AXS_JOG_STOP			0x0002
#define AXS_JOG_PST				0x0200

//�㶯ģʽ��ȡ��Ϊһ���˶�ģʽ
#define AXS_MOD_PST				0x0004

//////////////////////////////////////////////////////////////////////////
//��״̬
#define AXS_STAT_UNDEF			0x00
#define AXS_STAT_STOP			0x01
#define AXS_STAT_RUN			0x02
#define AXS_STAT_ERR			0x03

//�����Ƿ�ѡ����
#define AXS_ISSEL_NO			0x00
#define AXS_ISSEL_YES			0x01

//����ָ������
//δ����
#define	AXS_CMDTYPE_UNDEF		0x00
//��ȡ:״̬��λ�ơ��ٶ�
#define	AXS_CMDTYPE_GET_STT		0x01
#define	AXS_CMDTYPE_GET_PST		0x02
#define	AXS_CMDTYPE_GET_VLC		0x03
//�˶�:�ٶ�ģʽ��λ��ģʽ�������˶�����������
#define	AXS_CMDTYPE_JOG_VLC		0x11
#define	AXS_CMDTYPE_JOG_PST		0x12
#define	AXS_CMDTYPE_JOG_HM		0x13
#define	AXS_CMDTYPE_JOG_HMZ		0x14
#define	AXS_CMDTYPE_JOG_STP		0x15
#define	AXS_CMDTYPE_JOG_KLL		0x16
//����:�ٶȼ�������ָ��
#define	AXS_CMDTYPE_SET_VLC		0x21
#define	AXS_CMDTYPE_SET_SPC		0x22
//////////////////////////////////////////////////////////////////////////
//�������巽ʽ����˶�����
#define PST_PLS_TYPE_REL		0x01//���/����
#define PST_PLS_TYPE_ABS		0x02//����/����

//�������з�ʽ��
#define PST_CTR_TYPE_OLOOP		0x01//����
#define PST_CTR_TYPE_CLOOP		0x02//�ջ�

//������㷽ʽ��
#define PST_HOM_TYPE_RUN		0x01//�˶�
#define PST_HOM_TYPE_SET		0x02//����

//////////////////////////////////////////////////////////////////////////
//���˶���������
#define AXS_MINVAL_PSTASK		50
#define AXS_MAXVAL_PSTASK		65535
#define AXS_MAXVAL_VLCASK		32000
#define AXS_MAXVAL_VLCADD		1000
#define AXS_MAXVAL_VLCDEC		1000

//////////////////////////////////////////////////////////////////////////
//
//***************************************************************** 
// Struct Define
//***************************************************************** 
//�����������Ϣ
/*
����-��mmPr����������ÿת��������
�����-��plsPr����һ����׼��ϸ�ֹ�ͬ���ʵ��plsPr
ϸ��-��plsPr Rang�����ʣ����Բ���ǵõ����ʵ��plsPr
���ٱ�-��plsPr Rang�����ʣ����Բ���ǣ�����ϸ�ֵõ�����plsPr
�����ٶ�-��plsPs����λʱ���ڷ�����������
 */
typedef struct CMCAXSInfo {
	int m_nAxsID;/*����*/
	int m_nAxsTyp;/*������:Servo/Steper*/
	double m_fLead;/*����(mm) Lead*/
	double m_fStpnNg;/*����� Step Angle (Pls/r)*/
	double m_fSbdvsn;/*ϸ�� Subdivision (Pls/r Rang)*/
	double m_fDecRate;/*���ٱ�*/
	double m_fVlcCur;/*�ٶ�(����ÿ��) -Pls/s*/
	double m_fSpdMin;/*�ٶ���Сֵ-mm/s*/
	double m_fSpdMax;/*�ٶ����ֵ-mm/s*/
	double m_fSpdAddMax;/*���ٶ����ֵ-mm/s2*/
	double m_fSpdDecMax;/*���ٶ����ֵ-mm/s2*/
	double m_fSpdNormal;/*�ٶ�(����ÿ��) -mm/s*/
	double m_fSpdSpecial;/*�ٶ�(����ÿ��) -mm/s*/
	double m_dfPlsMin;/*�����������Сֵ*/
	double m_dfPlsMax;/*�����������Сֵ*/
} CMCAXSINF;

//������״̬�ṹ
typedef struct CMCAXSStat {
	//First DWORD X
 	int m_nActived;//23
	int m_nNgLmted;//22
	int m_nPsLmted;//21
	int m_nHwEnable;//20
	int m_nPhasedMotor;//19
	int m_nOpenLoop;//18
	int m_nRunDfTime;//17
	int m_nIntegration;//16
	int m_nDwell;//15
	int m_nDBErr;//14
	int m_nDVZero;//13
	int m_nArtDcl;//12
	int m_nBloackRs;//11
	int m_nHmSrhing;//10
	int m_nPNextDB01;//8-9
	int m_nPNextDB02;//0-7
	//Secend DWORD Y
	int m_nAssCS;//23
	int m_nCS01Num;//20-22
	int m_nResFFU01;//16-19
	int m_nResFFU02;//15
	int m_nAmpEn;//14
	int m_nResFFU03;//12-13
	int m_nStpOnPstLmt;//11
	int m_nHmCmp;//10
	int m_nResFFU04;//9
	int m_nPhsSErr;//8
	int m_nTrgMv;//7
	int m_nntFFErr;//6
	int m_nI2TAmpFErr;//5
	int m_nBckDrFlag;//4
	int m_nAmpFErr;//3
	int m_nFFErr;//2
	int m_nWFErr;//1
	int m_nInPst;//0
} CMCAXSSTT;

//�����������Ϣ
typedef struct CMCAXSCtrol {
	int m_nIsSel;//�Ƿ�ѡ��
	int m_nCmdTyp;//ָ�����:��ȡ/����
	int m_nPlsTyp;//�������:���/����
	int m_nCtrTyp;//���Ʒ�ʽ:����/�ջ�
	int m_nHomTyp;//���㷽ʽ:�˶�/����
} CMCAXSCTR;

//������ṹ
typedef struct CMCAXSData {
	char m_chData[32];//��������
	double m_dfPlsAsk;//Ŀ������
	double m_dfPlsBgn;//��ʼ����
	double m_dfPlsCur;//��ǰ����
} CMCAXSDAT;

//������ṹ
typedef struct CMCAxis {
	CMCAXSINF m_AxsInf;
	CMCAXSSTT m_AxsStt;
	CMCAXSCTR m_AxsCtr;
	CMCAXSDAT m_AxsDat;
} CMCAXS;

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
			   float nSpdMax,/*�ٶ����ֵ-Pls/s*/
			   float nSpdAddMax,/*���ٶ����ֵ-Pls/s2*/
			   float nSpdDecMax,/*���ٶ����ֵ-Pls/s2*/
			   float nSpdNormal,/*�ٶ�(����ÿ��) -Pls/s*/
			   float nSpdSpecial,/*�ٶ�(����ÿ��) -Pls/s*/
			   double dfPlsMin,/*�����������Сֵ*/
			   double dfPlsMax/*�����������Сֵ*/
			   );
//��ʼ������Ϣ
int CMCAxsInfInit(
				  CMCAXSINF * myAxsInf,
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
				  );
//��ʼ��״̬��Ϣ
int CMCAxsSttInit(CMCAXSSTT * myAxsStt);
//��ʼ��������Ϣ
int CMCAxsCtrInit(CMCAXSCTR * myAxsCtr);
//��ʼ���˶�����
int CMCAxsDatInit(CMCAXSDAT * myAxsDat);

//��ȡ��λ��ֵ
int CMCAxsGetPst(CMCAXSINF * myAxsInf, double nPls, double * nPst);
//��ȡ��������
int CMCAxsGetPls(CMCAXSINF * myAxsInf, double nPst, double * nPls);

//////////////////////////////////////////////////////////////////////////
//#endif
