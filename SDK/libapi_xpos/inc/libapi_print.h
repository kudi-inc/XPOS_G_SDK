#ifndef __LIBAPI_PRINT_HEADER__
#define __LIBAPI_PRINT_HEADER__

#include "libapi_pub.h"

#define		UPRN_SUCCESS             0		      //Success
#define		UPRN_FAIL				-1		      //Printer unknown fault
#define		UPRN_DEV_FAIL           -2			  //Printer device failure
#define		UPRN_OUTOF_PAPER        -3            //The printer is out of paper
#define		UPRN_LOSE_COMMAND       -4            //Print handle not obtained
#define		UPRN_FILE_FAIL          -5            //Fail to open the file
#define		UPRN_HANDLE_BACK        -6            //Split machine handle is not put back
#define		UPRN_CACHE_ERR          -7            //Save cache failed





/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:LinZhu
Functions: Get version number of print class module
Input : Nothing
Output: pszVer   Module version number
return: > 0 Successfully returns module version number length
USYS_FAIL     = -1,    
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int UPrint_GetModuleVer(char *pszVer);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:LinZhu
Functions:Initialize, check the printer status (if it is out of paper), set the print font, use before printing.
Input : Nothing
Output: Nothing
return: UPRN_FILE_FAIL        = -5��          //Fail to open the file
		UPRN_OUTOF_PAPER      = -3,           //The printer is out of paper
		UPRN_DEV_FAIL         = -2,			  //Printer device failure
		UPRN_FAIL             = -1,		      //Printer unknown fault
		UPRN_SUCCESS          =  0		      //Success
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int UPrint_Init(void);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:LinZhu
Functions:String printing with automatic line break function, support \r, \n newline
Input : str:     Need to print string information
		linegap: Line spacing: unit pixels, 0 is the default value (for Pin printing use)
		newline: 0 Does not support line breaks;1 support \r, \n newline
Output : Nothing
return: UPRN_CACHE_ERR        = -7,            //Save cache failed
		UPRN_SUCCESS          =  0		       //Success
Remarks: Save the string to the printer cache and call Print Start (Print_Start) to print
*************************************************************************************/
LIB_EXPORT int UPrint_Str(char *str, int linegap, byte newline);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:LinZhu
Functions:Picture printing��UPrint_BitMap��
Input : BmpFile:   Image file name��XXX.bmp��
		pattern:   Alignment: 0 left alignment, 1 center alignment, 2 right alignment
Output: Nothing
return: UPRN_CACHE_ERR          = -7,           //Save cache failed
		UPRN_SUCCESS			=  0			//Success
Remarks: Automatic line wrap is not supported;
		Internal processing of half-word problems, no half-words appear when displayed;
		Only the font part is reversed.
*************************************************************************************/
LIB_EXPORT int UPrint_BitMap(char *BmpFile,byte pattern);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:LinZhu
Functions: Start printing��UPrint_Start��
Input : Nothing
Output: Nothing
return: UPRN_HANDLE_BACK      = -6,				//Split machine handle is not put back
		UPRN_FILE_FAIL        = -5,				//Fail to open the file
		UPRN_LOSE_COMMAND     = -4,				//Print handle not obtained
		UPRN_OUTOF_PAPER      = -3,				//The printer is out of paper
		UPRN_DEV_FAIL         = -2,				//Printer device failure
		UPRN_FAIL             = -1,				//Printer unknown fault
		UPRN_SUCCESS          =  0				//Success
Remarks: Thermal printing: no more blank lines (processed by the application layer) are required after printing is completed;
		Needle printing: automatic page change after printing is completed.
*************************************************************************************/
LIB_EXPORT int UPrint_Start(void);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:LinZhu
Functions:String printing (UPrint_StrBold) with automatic line feed function, support \r, \n newline
Input : pszStr:    Need to print string information
		cPattern:  Print position: 0 left, 1 center, 2 right
		nlinegap:  Line spacing, unit pixels, 0 is the default value (for Pin printing use)
		newline: 0 Does not support line breaks;1 support \r, \n newline
Output: Nothing
return: UPRN_CACHE_ERR        = -7,             //Save cache failed
		UPRN_SUCCESS          =  0				//Success
Remarks: Save the string to the printer cache and call Print Start (Print_Start) to print
*************************************************************************************/
LIB_EXPORT int UPrint_StrBold(char *pszStr, byte cPattern,int nLinegap, byte newline);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:LinZhu
Functions:Printer paper��UPrint_Feed��
Input : nFeedLines   Paper length (pixels)
Output : Nothing
return: UPRN_CACHE_ERR        = -7,           //Save cache failed
		UPRN_SUCCESS          =  0		      //Success
Remarks: Thermal printing: can only support paper feeding
		Needle printing: support for paper withdrawal and paper feeding
*************************************************************************************/
LIB_EXPORT int UPrint_Feed(int nFeedLines);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:LinZhu
Functions:Print QR code��UPrint_MatrixCode��,Convert incoming data to QR code and print
Input : psMatrixCode: QR code data
		nLen:     QR code data length
		cSize:    QR code size, 0-small, 1-medium, 2-large
		cPattern: Alignment, 0 left alignment, 1 center alignment, 2 right alignment
Output : Nothing
return: UPRN_CACHE_ERR        = -7,           //Save cache failed
		UPRN_SUCCESS          =  0		      //Success
Remarks: Convert data to QR code and print
*************************************************************************************/
LIB_EXPORT int UPrint_MatrixCode(const char *psMatrixCode, int nLen,byte cSize,byte cPattern);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:LinZhu
Functions:Set print font
Input : size: Set print English font size(0--8)
		zoom_w: Set the horizontal magnification of English(1--5)
		zoom_h: Set the vertical magnification of English(1--5)
Output : Nothing
return: UPRN_CACHE_ERR        = -7,            //Save cache failed
		UPRN_SUCCESS          =  0		       //Success
Remarks: 
*************************************************************************************/
LIB_EXPORT int UPrint_SetFont(int size, int zoom_w, int zoom_h);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:LinZhu
Functions:Set print font
Input : size: Set print other font size(0--1)
		zoom_w: Set the horizontal magnification of English(1--5)
		zoom_h: Set the vertical magnification of English(1--5)
Output : Nothing
return: UPRN_CACHE_ERR        = -7,            //Save cache failed
		UPRN_SUCCESS          =  0		       //Success
Remarks: 
*************************************************************************************/
LIB_EXPORT int UPrint_SetFontcn(int size, int zoom_w, int zoom_h);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:LinZhu
Functions:Set print density
Input : v: Set print density (1--5, 3 is normal)
Output : Nothing
return: UPRN_CACHE_ERR        = -7,            //Save cache failed
		UPRN_SUCCESS          =  0		       //Success
Remarks: 
*************************************************************************************/
LIB_EXPORT int UPrint_SetDensity(int v);

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:George
Functions:set the follow print buffer align format
Input : nAlign:  0 left, 1 center, 2 right
Output: Nothing
return: Nothing
Remarks:
*************************************************************************************/
LIB_EXPORT void UPrint_Set_Align(int nAlign);
/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:George
Functions:set the line print buffer align format,will not affect next line
Input : nAlign:  0 left, 1 center, 2 right
Output: Nothing
return: Nothing
Remarks:
*************************************************************************************/
LIB_EXPORT void UPrint_Set_LineAlign(int nAlign);
/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:George
Functions:String printing (UPrint_StrBold) with automatic line feed function, support \r, \n newline
Input : sLeft:   left align string
		sRight:  right align string
		nlinegap:  Line spacing, unit pixels, 0 is the default value (for Pin printing use)
Output: Nothing
return: Nothing
Remarks: For Persian print
*************************************************************************************/
LIB_EXPORT void UPrint_str_line(char*sLeft,char*sRight,int nLinegap);


#endif /*__LIBAPI_PRINT_HEADER__*/
