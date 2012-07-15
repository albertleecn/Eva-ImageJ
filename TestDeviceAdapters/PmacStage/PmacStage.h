#ifndef __HHPMACSTAGE__HH__
#define __HHPMACSTAGE__HH__
#include <atlstr.h>
#include "../../MMDevice/DeviceBase.h"

#include ".\\PComm32\\PCommAxis.h"
#include ".\\PComm32\\MCAxisBase.h"
//////////////////////////////////////////////////////////////////////////////
// Error codes
//
#define ERR_UNKNOWN_MODE         102
#define ERR_UNKNOWN_POSITION     103
#define ERR_IN_SEQUENCE          104
#define ERR_SEQUENCE_INACTIVE    105
#define ERR_STAGE_MOVING         106
#define SIMULATED_ERROR          200

//////////////////////////////////////////////////////////////////////////////
// PmacStage class
// Simulation of the single axis stage
//////////////////////////////////////////////////////////////////////////////
using namespace std;
class PmacXYStage : public CXYStageBase<PmacXYStage>
{
public:
   PmacXYStage();
   ~PmacXYStage();

   bool Busy();
   void GetName(char* pszName) const;
	enum InfoType{ InfoType_position= AXS_CMDTYPE_GET_PST, InfoType_status = AXS_CMDTYPE_GET_STT,InfoType_velocity = AXS_CMDTYPE_GET_VLC };
   int Initialize();
   int Shutdown();
     
   // XYStage API
   virtual double GetStepSize();
   virtual int SetPositionSteps(long x, long y);
   virtual int GetPositionSteps(long& x, long& y);
   virtual int Home();
   virtual int Stop();
   virtual int SetOrigin();
   virtual int GetLimits(double& lower, double& upper);
   virtual int GetLimitsUm(double& xMin, double& xMax, double& yMin, double& yMax);
   virtual int GetStepLimits(long &xMin, long &xMax, long &yMin, long &yMax);
   virtual double GetStepSizeXUm();
   virtual double GetStepSizeYUm();
   virtual int SetRelativePositionUm(double dx, double dy);
   virtual int IsXYStageSequenceable(bool& isSequenceable) const; 
   

   // Action interface
   int OnPositionXmm(MM::PropertyBase* pProp, MM::ActionType eAct);
   int OnPositionYmm(MM::PropertyBase* pProp, MM::ActionType eAct);
   int OnSetOriginHere(MM::PropertyBase* pProp, MM::ActionType eAct);
   int OnCalibrate(MM::PropertyBase* pProp, MM::ActionType eAct);
   int OnReturnToOrigin(MM::PropertyBase* pProp, MM::ActionType eAct);
   int OnPositionXYmm(MM::PropertyBase* pProp, MM::ActionType eAct);
   int OnVelocityX(MM::PropertyBase* pProp, MM::ActionType eAct);
   int OnVelocityY(MM::PropertyBase* pProp, MM::ActionType eAct);
public:
	//��Ա����
	int getAxisInfo(InfoType infoT);//��ȡ���״̬��Ϣ
	int OnTimerSetView();//���û���״̬��Ϣ
	int OnAxsSetPara(int nAxsID, int nCmdTyp, int nPlsTyp,double value);//�������˶�������Ϣ
	//�ļ�����
	int OnFileRdInf();//����������
	int OnFileWtInf();//д��������
	int OnFileRdDat();//����ʷ����
	int OnFileWtDat();//д��ʷ����
	//���ʼ��,ʹ�����ϵͳ���
	//�豸��ʼ����ʹ���豸���
	//��ȡ�豸�����ļ�
	void OnGetCnfgAxs(CMCAxis * theAxs);

	int DEV_AXS_SEL[8];
public:	
	//��Ա����
	CMCDEV m_PCommDev;//PComm�豸ʵ��
	char m_chRes[1024], m_chSnd[1024];//����/�����ַ�������
	int m_nChResLen, m_nChSndLen;//����/�����ַ�������
	LPWSTR m_csFNameIni, m_csSctName, m_csKeyName, m_csStrDfut, m_csTitleFont;

	//�ļ�ָ��
	FILE * m_pfInf;//��Ϣ�ļ�ָ��
	FILE * m_pfDat;//�����ļ�ָ��


public:
	int Init_Pmac();
	int StatusChk_Pmac();
	int EnableAll_Pmac();
	int Close_Pmac();
	int Open_Pmac();
	int DeviceSelect_Pmac();

	int OnPmacLink(MM::PropertyBase* pProp, MM::ActionType eAct);
	int OnxAxisID(MM::PropertyBase* pProp, MM::ActionType eAct);
	int OnyAxisID(MM::PropertyBase* pProp, MM::ActionType eAct);
	int OnDeviceID(MM::PropertyBase* pProp, MM::ActionType eAct);


private:

   double stepSize_mm_;
   int CreatePmacXYProperties();
      // Set positions
   int SetPositionMm(double x, double y);
   int GetPositionMm(double& x, double& y);
   int SetRelativePositionMm(double x, double y);
   int SetPositionXSteps(long x);
   int SetPositionYSteps(long y);
   int SetPositionUm(double x, double y);
   int GetPositionUm(double& x, double& y);

      // Calibration & origin methods
   int Calibrate();
   int MoveToForwardLimits();
   int ReturnToOrigin();

      // Pause devices
   void PauseDevice();

   // Check if blocked
   bool XMoveBlocked(double possNewPos);
   bool YMoveBlocked(double possNewPos);

   void GetOrientation(bool& mirrorX, bool& mirrorY);


   bool busy_;
   MM::TimeoutMs* timeOutTimer_;
   double velocityX_;
   double velocityY_;
   bool initialized_;
   double lowerLimit_;
   double upperLimit_;

   double maxVelocityX_;
   double maxVelocityY_;

   double positionMin_[8];
   double positionMax_[8];

   int rounding_;
   int yAxisID_;
   int xAxisID_;
   std::string pmacLink_;
   int deviceId_;
};

#endif