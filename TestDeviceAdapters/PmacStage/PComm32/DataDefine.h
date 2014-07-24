/************************************************************************/
/*        �˶�����������ݼ��궨��			                            */
/************************************************************************/
#pragma once

//////////////////////////////////////////////////////////////////////////
//�ļ�����
#define PRJCT_NAME					"MCSysConfig"
#define PRJCT_MAIN_TITLE			"3-Axis Control System"
#define FILENAME_INFO				"%s.info"
#define FILENAME_DATA				"%s.data"
#define FILENAME_CNFG				".\\MCSysConfig.ini"
#define MAXSIZE_CHAR_CNFG			128

//////////////////////////////////////////////////////////////////////////
//����Ϣ����
#define AXS_SEV_LEAD				1
#define AXS_SEV_STPNNG				20000//���ٺ�
#define AXS_SEV_SBDVSN				1
#define AXS_SEV_DECRATE				1//������ٱ�
//#define AXS_SEV_DECRATE				234.77f//ʵ�ʼ��ٱ�

#define AXS_STEP_LEAD				5
#define AXS_STEP_STPNNG				200
#define AXS_STEP_SBDVSN				1
#define AXS_STEP_DECRATE			1

//////////////////////////////////////////////////////////////////////////
//��д���ƺ�
#define DEV_RWSTP_RD				0x01
#define DEV_RWSTP_WT				0x02

#define DEV_SRTYP_SD				0x01
#define DEV_SRTYP_RS				0x02

//////////////////////////////////////////////////////////////////////////
//ȫ�ֱ���
extern HINSTANCE hinsPCommLib;

//////////////////////////////////////////////////////////////////////////
//��ʱ������ʱ���趨ֵ
const int TIMER_DEVCM_EVENT =		0x01;//�豸��Ϣ����
const int TIMER_VEWUD_EVENT =		0x02;//������Ϣˢ��

const int TIMER_DEVCM_TIME =		100;//�豸��Ϣ����
const int TIMER_VEWUD_TIME =		130;//������Ϣˢ��

//�豸��Ϣ��������
const int DEVCM_STEP_RD =			0x01;//���豸��Ϣ
const int DEVCM_STEP_WT =			0x02;//д����ָ��

const int DEVCM_TYPE_SND =			0x01;//����ָ��
const int DEVCM_TYPE_RSP =			0x02;//����ָ��
