//***************************************************************** 
// ������д����Pmac����ʱϵͳ�ļ�������ʱֻ��Ҫ���������ĵ�����
// "MCSystem.h"
// "PmacRuntime.h"
// "PmacRuntime.c"
// "MCSysExe.C"
// Ϊ��֧��windows������𼰺���������CVi�����а���windowͷ�ļ�
// #include <windows.h>
// Release 2011-05-19 by mjq_clint(����� mjq_clint@hotmail.com)
// ���η���ֻ������4�����ù��ܺ���
// ͬʱʵ����PmacRuntimeLink��PmacRuntimeClose����
//***************************************************************** 
#include "PMACRuntime.h"

//***************************************************************** 
// COMM function Defines 
//***************************************************************** 
//
pOpenPmacDevice			PmacDevOpen;
pClosePmacDevice		PmacDevClose;
pPmacGetResponseA		PmacGetResponce;
pSelectPmacDevice		PmacDevSelect;

//////////////////////////////////////////////////////////////////////////
//
HINSTANCE hinsPCommLib;

//////////////////////////////////////////////////////////////////////////
HINSTANCE PmacRuntimeLink()
{
	int nDllIm = 0;
	//���ض�̬��
	HINSTANCE hPmacLib;
	hPmacLib = LoadLibrary(PMAC_DLL_NAME);
	//������̬�⺯��
	for (nDllIm = 0; nDllIm < 1; nDllIm++)
	{
		DLL_LINK(PmacDevOpen,pOpenPmacDevice,"OpenPmacDevice");
		DLL_LINK(PmacDevClose,pClosePmacDevice,"ClosePmacDevice");
		DLL_LINK(PmacGetResponce,pPmacGetResponseA,"PmacGetResponseA");
		DLL_LINK(PmacDevSelect,pSelectPmacDevice,"PmacSelect");
	}
	//�жϼ��ؽ��
	if (nDllIm < 1)
	{
		FreeLibrary(hPmacLib);
		hPmacLib = NULL;
		return NULL;
	}
	else
	{
		return hPmacLib;
	}
}

void PmacRuntimeClose()
{
	if (hinsPCommLib) 
	{
		FreeLibrary(hinsPCommLib);
		hinsPCommLib = NULL;
	}
}
//////////////////////////////////////////////////////////////////////////
