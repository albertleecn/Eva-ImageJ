
//***************************************************************** 
// ������д�����˶�����ϵͳͷ�ļ�������ʱֻ��Ҫ���������ĵ�����
// "MCSystem.h"
// "PmacRuntime.h"
// "PmacRuntime.c"
// "MCSysExe.C"
// Ϊ��֧��windows������𼰺���������CVi�����а���windowͷ�ļ�
// #include <windows.h>
// Release 2011-05-19 by mjq_clint(����� mjq_clint@hotmail.com)
// Release 2011-05-23 �����豸״̬��ȡ��������أ����20110523��
//***************************************************************** 
/************************************************************************/
/*                                                                      */
/************************************************************************/
#pragma once

//////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <windows.h>

//////////////////////////////////////////////////////////////////////////
//
#include "MCAxisBase.h"

//////////////////////////////////////////////////////////////////////////
//#ifndef _PCOMM_AXS_
//#define _PCOMM_AXS_

//***************************************************************** 
// COMM Type Defines 
//***************************************************************** 
#define PMAC_RES_ERR			"err"
#define PMAC_CMD_CHMAX			256
#define MCSYS_DEV_AXS_MAX		8
//������ѡ���
#define DEV_AXS_MAX				0x08//�豸�������
#define DEV_AXS_SEL_ALL			0xFF
#define DEV_AXS_SEL_01			0x01
#define DEV_AXS_SEL_02			0x02
#define DEV_AXS_SEL_03			0x04
#define DEV_AXS_SEL_04			0x08
#define DEV_AXS_SEL_05			0x10
#define DEV_AXS_SEL_06			0x20
#define DEV_AXS_SEL_07			0x40
#define DEV_AXS_SEL_08			0x80

//����������
#define ERRO_NOERR				0x0000
#define ERRO_INIT_LINK			0x0001
#define ERRO_INIT_OPEN			0x0002
#define ERRO_RELEASE_CLOSE		0x0011
#define ERRO_RELEASE_DLINK		0x0012
#define ERRO_NORMAL_CMD			0x0100

//////////////////////////////////////////////////////////////////////////
//��������豸�ṹ
typedef struct CMCDevice {
	int m_nRWStep;//��д���
	int m_nSRType;//���ͽ������
	DWORD m_dwID;//�豸ID
	DWORD m_nDevStt;//�豸״̬
	DWORD m_dwAxisSel;//��ѡ��
	CMCAXS m_Axis[8];//�ᶨ��
} CMCDEV;

//***************************************************************** 
// Function Define
//***************************************************************** 
//����Ƿ����ӿո�
#define CMD_SEND_CHECK(chChk,chAdd)  if (strlen(chChk)) \
                                 strcat(chChk,chAdd)

//�豸�ᶯ̬��ʼ������
//CMCAXS MCAxisInit(DWORD dwAxisID);
//***************************************************************** 
// �û��ӿں�������ʹ��MCDevCmdSend����ָ��ǰ���������
// �豸����ѡ�������ָ�����
//***************************************************************** 
//��λ��������
int MCSysInit(CMCDEV * pCMCDev);
int MCSysRelease(CMCDEV * pCMCDev);

//�����Ӧ��غ���
int MCDevCmdSend(CMCDEV * pCMCDev,char *chRes,int ichLen,char *chSend);

//������Ӧ��������
int MCDevCmdResDataGet(CMCDEV * pCMCDev,char *chRes,int ichLen);
int MCDevCmdResDataGetPst(CMCAXS * pCMCAxs,char *chRes,int iDataset,int ichLen);
int MCDevCmdResDataGetVlc(CMCAXS * pCMCAxs,char *chRes,int iDataset,int ichLen);
int MCDevCmdResDataGetStt(CMCAXS * pCMCAxs,char *chRes,int iDataset,int ichLen);

//***************************************************************** 
// ���ܿ��ƺ�����������������������
//***************************************************************** 
//////////////////////////////////////////////////////////////////////////
//�豸���ƺ���
int MCDevInit(CMCDEV * pCMCDev);
int MCDevOpen(CMCDEV * pCMCDev);
int MCDevClose(CMCDEV * pCMCDev);

//������ѡ����
int MCDevAxisSelReset(CMCDEV * pCMCDev);
int MCDevAxisSelSet(CMCDEV * pCMCDev,DWORD dwAxSel,DWORD dwCmdType);

//��Ϣ���Ժ�������main��������
int MCDevCmdResShow(CMCDEV * pCMCDev,int iMsgType,char *chMsg);

//////////////////////////////////////////////////////////////////////////
//����ָ���
//��ȡ�豸��Ϣ
int MCDevAxisGetStt(CMCAXS * pCMCAxs,char *chCmd);
int MCDevAxisGetPst(CMCAXS * pCMCAxs,char *chCmd);
int MCDevAxisGetVlc(CMCAXS * pCMCAxs,char *chCmd);

//���˶�ָ��
int MCDevAxisJogVlc(CMCAXS * pCMCAxs,char *chCmd);
int MCDevAxisJogPst(CMCAXS * pCMCAxs,char *chCmd);
int MCDevAxisJogStp(CMCAXS * pCMCAxs,char *chCmd);
int MCDevAxisJogHom(CMCAXS * pCMCAxs,char *chCmd);

//��������Ϣָ��
int MCDevAxisSetVlc(CMCAXS * pCMCAxs,char *chCmd);
int MCDevAxisSetSpc(CMCAXS * pCMCAxs,char *chCmd);

//***************************************************************** 
// Function Define End
//***************************************************************** 
//#endif
//////////////////////////////////////////////////////////////////////////
