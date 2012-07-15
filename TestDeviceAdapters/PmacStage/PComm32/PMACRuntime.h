
//***************************************************************** 
// ������д����Pmac����ʱϵͳͷ�ļ�������ʱֻ��Ҫ���������ĵ�����
// "MCSystem.h"
// "PmacRuntime.h"
// "PmacRuntime.c"
// "MCSysExe.C"
// Ϊ��֧��windows������𼰺���������CVi�����а���windowͷ�ļ�
// #include <windows.h>
// Release 2011-05-19 by mjq_clint(����� mjq_clint@hotmail.com)
// ���η���ֻ������4�����ù��ܺ���
//***************************************************************** 
#include "stdio.h"
#include <windows.h>

//***************************************************************** 
// COMM normal Defines 
//***************************************************************** 
//
#define PMAC_DLL_NAME	TEXT("PComm32W.dll")

//////////////////////////////////////////////////////////////////////////
//***************************************************************** 
// COMM Type Defines 
//***************************************************************** 
//
typedef int (CALLBACK *pOpenPmacDevice)(DWORD dwDevID);
typedef int (CALLBACK *pClosePmacDevice)(DWORD dwDevID);
typedef long (CALLBACK *pSelectPmacDevice)(HWND hwnd );
typedef int (CALLBACK *pPmacGetResponseA)(DWORD dwDevID,char *chRes,int chLenMax,char *chSend);

//////////////////////////////////////////////////////////////////////////
//��̬�����Ӳ�����
#define DLL_LINK(var,type,name)  var=(type)GetProcAddress(hPmacLib,name); \
                                 if (var==NULL) break

//***************************************************************** 
// COMM function Defines 
//***************************************************************** 
HINSTANCE PmacRuntimeLink(void);
void PmacRuntimeClose();

//***************************************************************** 
// COMM function Defines 
//***************************************************************** 
//Ϊ������ֺ����ظ�����Ĵ���Ӧ��PMACRuntimeԴ�ļ��ж��庯��
extern pOpenPmacDevice			PmacDevOpen;
extern pClosePmacDevice			PmacDevClose;
extern pPmacGetResponseA		PmacGetResponce;
extern pSelectPmacDevice		PmacDevSelect;

// COMM Defines End
//***************************************************************** 
//////////////////////////////////////////////////////////////////////////

//#endif