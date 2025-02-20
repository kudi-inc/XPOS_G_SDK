#ifndef __LIBAPI_SYSTEM_HEADER__
#define __LIBAPI_SYSTEM_HEADER__

#include "libapi_pub.h"

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions: Get version number of system class module
Input : Nothing
Output : pszVer   Module version number
return: > 0 Successfully returns module version number length
		USYS_FAIL     = -1,    
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_GetModuleVer(char *pszVer);


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:Initialization of system and initialization of application layer Nothing
Input : Argc�� Reusing main function parameter Argc
		Argv�� Reusing main function parameter Argv
		AppName��Application name

Output : Nothing
return: USYS_FAIL     = -1,  Fail
		USYS_FIRST    = 1,   for the first time since the program was updated.
		USYS_NOFIRST  = 2    Program is not run for the first time.

Remarks: Not to be processed without access to ginseng
		Inside the function calls the private API of the manufacturer.
		The API returns to the first operation only when the program is newly installed, 
		and the update is not the first operation.
*************************************************************************************/
LIB_EXPORT int Sys_Init(int Argc,char **Argv,char *AppName);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:The manufacturer sets the individual parameter settings and 
		invokes the individual settings function of each manufacturer.
Input : Nothing
Output : Nothing
return: Nothing
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT void Sys_Config(void);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:Get terminal information
Input : Nothing
Output : terminal  Reference TERMINALINFO
return: USYS_FAIL     = -1,  Fail
		USYS_SUCCES   = 0��Success
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_GetTerminalInfo(TERMINALINFO *terminal);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:Get SysTime
Input : Nothing
Output : DateTime��"YYYYMMDDHHMMSS" 14�ֽ�
return: USYS_FAIL     = -1,  Fail
		USYS_SUCCES   = 0��Success
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_GetDateTime(byte *DateTime);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:Set SysTime
Input : DateTime��"YYYYMMDDHHMMSS" 14Byte
Output : Nothing
return: USYS_PARAERROR = -2,   //Parameter Error
		USYS_FAIL     = -1,  Fail
		USYS_SUCCES   = 0��Success
Remarks: Internal judgment of time format in API
*************************************************************************************/
LIB_EXPORT int Sys_SetDateTime(byte *DateTime);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:Scan button, non blocking
Input : Nothing
Output : Nothing
return: KEY_VALUE
		0 No key
		USYS_FAIL     = -1,  Fail
Remarks: Non enumKEY_VALUE defined keys return uniformly to 0
*************************************************************************************/
LIB_EXPORT int Sys_CheckKey(void);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:Clear key buffer
Input : Nothing
Output : Nothing
return: Nothing
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT void Sys_ClrKey(void);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:Open timer and set timer time.
Input : TimerMs�� 
Output : Nothing
return: Return timer handle successfully
		USYS_FAIL           = -1,    Fail
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_TimerOpen(uint TimerMs);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:Check whether the timing time is up to
Input : iHandle��Timer
Output : Nothing
return: Successfully returned, remaining time, unit milliseconds (0 indicates timed time).
		USYS_FAIL           = -1,    Fail
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_TimerCheck(int iHandle);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:Off Timer
Input : iHandle��Timer
Output : Nothing
return: USYS_FAIL           = -1,    Fail
		USYS_SUCCESS        =  0	 Success
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_TimerClose(int iHandle);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:Delay blocking
Input : uiMs��Delay time unit MS
Output : Nothing
return: Nothing
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT void Sys_Delay(uint uiMs);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions: Get battery power
Input : void
Output : Nothing
return: Successful  0-5 (5 indicates maximum).
		USYS_FAIL           = -1,    Fail
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_GetBatter(void);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:George
Functions: charging state
Input : void
Output : Nothing
return: 0			Charging with charger.
		-1          
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_Batter_Charge(void);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:Terminal goes to sleep state
Input : Time: Entering dormancy time, unit seconds
Output : Nothing
return: USYS_FAIL           = -1,    Fail
		USYS_SUCCESS        =  0	 Success
Remarks: The application needs to detect the status of 
		wireless network registration after wakeup.
*************************************************************************************/
LIB_EXPORT int Sys_Sleep(uint Time);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:Terminal reboot
Input : Nothing
Output : Nothing
return: USYS_FAIL           = -1,    Fail
		USYS_SUCCESS        =  0	 Success
Remarks: 
*************************************************************************************/
LIB_EXPORT int Sys_Reboot(void);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:Leo
Functions:Set screen backlight mode
Input : mode Backlight mode
			0- system automatically controls
			1- backlight is always bright
Output : Nothing
return: USYS_FAIL           = -1,    Fail
		USYS_SUCCESS        =  0	 	Success
Remarks: Mode=0 indicates that the backlight is automatically 
				controlled by the system, with a default of 0.
*************************************************************************************/
LIB_EXPORT int Sys_SetScrBackLight(byte mode);


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:Get terminal serial number
Input : Nothing
Output : Sn Serial number
return: USYS_SUCCESS        =  0	 	Success
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_GetTermSn(char *Sn);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lxz
Functions:Open Scan
Input : Nothing
Output :
return: USYS_SUCCESS        =  0	 	Success
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_scaner_open();


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lxz
Functions:Start scanning
Input : Nothing
Output :
return: USYS_SUCCESS        =  0	 	Success
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_scaner_start();


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lxz
Functions:stop scanning
Input : pfun
Output :
return: USYS_SUCCESS        =  0	 	Success
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_scaner_stop();


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lxz
Functions:Close Scan
Input : pfun
Output :
return: USYS_SUCCESS        =  0	 	Success
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_scaner_close();



/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:luoxizhu
Functions:Setting Application Version Number
Input : appvision Application Version Number
Output : Nothing 
return: USYS_SUCCESS        =  0	 	Success
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_SetAppVer(char *pszVer);


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:luoxizhu
Functions:Initialization driver
Input : Nothing
Output : Nothing 
return: none
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT void Sys_driverlib_init();


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:luoxizhu
Functions:Judging whether there is a secondary liquid crystal
Input : Nothing
Output : Nothing 
return: Return 1 has a secondary liquid crystal
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int  Sys_get_sublcd_probe();


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:luoxizhu
Functions:Switching liquid crystal
Input : index=0 Main liquid crystal  ,index =1 Paraliquid crystal
Output : Nothing 
return: Return 1 has a secondary liquid crystal
Remarks: Nothing
*************************************************************************************/

LIB_EXPORT void Sys_lcd_set_index(int index);


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:luoxizhu
Functions:Brighten the backlight by pressing the key
Input : Nothing
Output : Nothing 
return: Return 1 has a secondary liquid crystal
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT void  Sys_power_key_set_light();


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:luoxizhu
Functions:Get the shutdown time
Input : Nothing
Output : Nothing 
return: Return shutdown time
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT  int Sys_lcd_PowerDownTime();


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:luoxizhu
Functions:Set the shutdown time
Input : ntime  shutdown time
Output : Nothing 
return: 
Remarks: Nothing
*************************************************************************************/

LIB_EXPORT  void Sys_lcd_SetPowerDownTime(int ntime);


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:luoxizhu
Functions:Get  Backlight time
Input : Nothing
Output : Nothing 
return: Return Backlight time
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT  int Sys_lcd_BackLightTime();

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:luoxizhu
Functions:Set Backlight time
Input : ntime  Backlight time
Output : Nothing 
return: 
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT  void Sys_lcd_SetBackLightTime(int ntime);
/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:Leo
Functions:Get app version
Input : 
Output :
return: the app version
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT const char * Sys_GetAppVer();

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions: create system task
Input : pfun:processing function of task
		prio:task priority
		stk:stack of task
		task_size:stack size
Output : Nothing
return: 0 Successfully create
		else FAIL    
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_TaskCreate( void *pfun , int prio, char * stk, int task_size );

#define SYS_DEVICE_TYPE_H9G		18
#define SYS_DEVICE_TYPE_M70G    20
/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:Get Device Type
Input : 
Output :
return: Device Type H9 or MP70
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_GetDeviceType();

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:George
Functions:Set TMS state
Input : nBusyState:1 app busy, not deal TMS; 0 app not busy, can deal TMS
Output :
return: 
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT void Sys_tms_AppBusy(int nBusyState);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:George
Functions:run tms update task
Input : 
Output :
return: 
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT void Sys_tms_update();

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:Leo
Functions:Disable check time from tms server
Input : 
Output :
return: 
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT void Sys_tms_CheckTime_disable();

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:George
Functions:unpack /mf/app/data/mf.zip and upgrade, then reboot
Input : 
Output :
return: 
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT void Sys_zip_update();
/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:George
Functions:set device language;must set the right font priority
Input :nLanguageType; 0,Chinese;1,English;2,Persian 
Output :
return: 
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT void Sys_set_language(int nLanguageType);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:Leo
Functions:Get current system timestamp
Input :
Output :
return: Current system timestamp
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int Sys_getTick();

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author: Leo
Functions:Terminal power off
Input : Nothing
Output : Nothing
return: Nothing
Remarks: 
*************************************************************************************/
LIB_EXPORT void Sys_power_off();
#define Sys_PowerOff Sys_power_off

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author: Leo
Functions: Turn on track detection
Input : Nothing
Output : Nothing
return: Nothing
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT void Sys_magtek_open();

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author: Leo
Functions: Turn off track detection
Input : Nothing
Output : Nothing
return: Nothing
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT void Sys_magtek_close();

#define SYS_TRACE( ...)	osl_log( "app", 2 , __VA_ARGS__ )
#define SYS_TRACE_BUFF(buff,size,tip) 	osl_log_buff_tip("app",2,buff, size , tip ,1 );

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:Leo
Functions:Screen Calibration
Input : Nothing
Output : Nothing 
return: 
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT  void Sys_lcd_calibration();

#endif /*__LIBAPI_SYSTEM_HEADER__*/
