/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %lights_control.c%
* Instance:         RPL_1
* %version:         1 %
* %created_by:      ID 734144
* %date_created:    Tues Sept  1  2015 %
*=============================================================================*/
/* DESCRIPTION : Main file for lights control        c                        */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the C source lights control         */
/* according to the messages received by the CAN messenger                    */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 07/09/2015  |                               | David Rosales    */
/* Integration under Continuus CM                                             */
/*============================================================================*/

/* Includes */
/* -------- */
#include "lights_control.h"
#include "mssg_decoder.h"
#include "GPIO.h"
#include  "Light_Sensor.h"
/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */

/*==================================================*/ 
/* Definition of constants                          */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */

/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTE RAM variables */
T_UBYTE rub_DAY_STOP_Light=INACTIVATED;
T_UBYTE rub_STOP_Light=INACTIVATED;
T_UBYTE rub_HW_Config= STANDARD;

/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */

#define HWCONFIG_STD  		GPIO_PC6
#define HWCONFIG_HE	 		GPIO_PC7
#define HWCONFIG_LUX	 	GPIO_PC8
/* Private functions prototypes */
/* ---------------------------- */



/* Exported functions prototypes */
/* ----------------------------- */

/* Inline functions */
/* ---------------- */
/**************************************************************
 *  Name                 : inline_func	2
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/


/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : private_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/

/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	lights_control_SM
 *  Description          :  Once a CAN  valid command is received, this state machine will take control of the cossponding light actions
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 
 void Light_Ctrl_HwConfig(void)
 {
 	if (HWCONFIG_STD==ACTIVATED)
 	{
 		rub_HW_Config = STANDARD;
 	}
 	else if (HWCONFIG_HE==ACTIVATED)
 	{
 		rub_HW_Config = HIGH_END;
 	}
 	else
 	{
 		rub_HW_Config = LUXURY;
 	}
 }
 
 

/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	lights_control_SM
 *  Description          :  Once a CAN  valid command is received, this state machine will take control of the cossponding light actions
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/

void lights_control_SM (void)
{

static T_UBYTE lub_Command_ID = IDLE;
	
	switch (lub_Command_ID)
	{
		case  IDLE :	lub_Command_ID = Get_Messag_ID();
						break;	  
		          
		case  STOP :    lub_Command_ID = Command_Stop();	
		          		break;
		          
		case  TURN :    lub_Command_ID = Command_Turn();
				  		break;
				  
		case  HAZARD :  lub_Command_ID = Command_Hazard();
		        	     break;
		          
		case  MAIN_LIGHTS : lub_Command_ID = Command_Mainlight();
			        	  break;
			 	  
	    default: 		 lub_Command_ID = IDLE;
	              break;
	}
	
}



/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 
 
 T_UBYTE Command_Stop (void)
 {
  T_UBYTE lub_Parameter_Stop = Get_Active_Inactive_Status();
  
  		if (rub_HW_Config == STANDARD)
   		{
   			Standard_Stop_Lights(lub_Parameter_Stop); 
   		}
   		else 
   		{
   			Stop_Lights(lub_Parameter_Stop);
   		}   		
  return (IDLE); 
  }
  
 
 /* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 
  
 T_UBYTE Command_Hazard (void)
 {
 T_UBYTE lub_Parameter_Hazard = Get_Active_Inactive_Status();
 T_UBYTE lub_Parameter_OnTime = Get_On_Time();
 T_UBYTE lub_Parameter_OffTime = Get_Off_Time();
 
	 if (lub_Parameter_Hazard == ACTIVATED)
	 {
	 	lub_Parameter_Hazard = BLINKER_HAZARD;
	 }
	 else
	 {
	 	lub_Parameter_Hazard = BLINKER_HAZARD_OFF;
	 }
   
   		if (rub_HW_Config == STANDARD)
   		{
   	
   			Standard_Blinker_Lights(lub_Parameter_Hazard, lub_Parameter_OnTime , lub_Parameter_OffTime);			
       	}
   		else if (rub_HW_Config == HIGH_END)
   		{
   			High_End_Blinker_Lights(lub_Parameter_Hazard, lub_Parameter_OnTime , lub_Parameter_OffTime);
   		}   
   		else
   		{
   			Luxury_Blinker_Lights(lub_Parameter_Hazard, lub_Parameter_OnTime , lub_Parameter_OffTime);
   		}		
   
  return (IDLE); 
}
   
   
   
 /* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 
  
 T_UBYTE Command_Turn (void)
 {
 T_UBYTE lub_Parameter_Turn = Get_Turn_Mode_Status();
 T_UBYTE lub_Parameter_OnTime = Get_On_Time();
 T_UBYTE lub_Parameter_OffTime = Get_Off_Time();
 
	 if (lub_Parameter_Turn == RIGHT)
	 {
	 	lub_Parameter_Turn = BLINKER_RIGHT;
	 }
	 else if (lub_Parameter_Turn == LEFT)
	 {
	 	lub_Parameter_Turn = BLINKER_LEFT;
	 }
	 else
	 {
	 	lub_Parameter_Turn = BLINKER_TURN_OFF;
	 }
   
   		if (rub_HW_Config == STANDARD)
   		{
   	
   			Standard_Blinker_Lights(lub_Parameter_Turn, lub_Parameter_OnTime , lub_Parameter_OffTime);			
       	}
   		else if (rub_HW_Config == HIGH_END)
   		{
   			High_End_Blinker_Lights(lub_Parameter_Turn, lub_Parameter_OnTime , lub_Parameter_OffTime);
   		}   
   		else
   		{
   			Luxury_Blinker_Lights(lub_Parameter_Turn, lub_Parameter_OnTime , lub_Parameter_OffTime);
   		}		
   
  return (IDLE); 
}



   
 /* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 
  
 T_UBYTE Command_Mainlight (void)
 {
 T_UBYTE lub_Parameter_Mainlight = (T_UBYTE)Get_Main_Lights_Mode();
 T_UBYTE lub_Threshold;
 
	 if (lub_Parameter_Mainlight == MAIN_LIGHTS_DAY)
	 {
	 	Day_Lights(ACTIVATED);
	 }
	 else if (lub_Parameter_Mainlight == MAIN_LIGHTS_FULL)
	 {
	 	Low_Beam_Lights(ACTIVATED);
	 	Day_Lights(ACTIVATED);
	 }
	 else if (lub_Parameter_Mainlight == MAIN_LIGHTS_AUTO)
	 {
	 	lub_Threshold = Get_Threshold();
	 	if (lub_Threshold == DAY )
	 	{
	 			Day_Lights(INACTIVATED);
	 			Low_Beam_Lights(INACTIVATED);
	 	}
	 	else if (lub_Threshold == SUNSET_SUNRISE )
	 	{
	 			Day_Lights(ACTIVATED);
	 			Low_Beam_Lights(INACTIVATED);
	 	}
	 	else if (lub_Threshold == NIGHT )
	 	{
	 			Day_Lights(ACTIVATED);
	 			Low_Beam_Lights(ACTIVATED);
	 	}
	 }
	 else
	 {
	 	Day_Lights(INACTIVATED);
	 	Low_Beam_Lights(INACTIVATED);
	 }
   return (IDLE); 
}