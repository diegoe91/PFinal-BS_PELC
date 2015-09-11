/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         lights_control.c
* Instance:         RPL_1
* version:          1.2
* created_by:       David Rosales
* date_created:     Tues Sept  1  2015 
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
/*  1.2      | 09/09/2015  |                               | Diego Flores     */
/* Bugs correction				                                              */
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
T_UBYTE rub_Auto_Mode_Flag=0;

/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */

#define HWCONFIG_STD  		BUTTON_PRESS(GPIO_PC6)
#define HWCONFIG_HE	 		BUTTON_PRESS(GPIO_PC7)
#define HWCONFIG_LUX	 	BUTTON_PRESS(GPIO_PC8)
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
 *  Name                 : Light_Ctrl_HwConfig
 *  Description          : Main function will select a configuration with hardware
 *  Parameters           : void
 *  Return               : void
 *  Critical/explanation :   No
 **************************************************************/
 
 
 void Light_Ctrl_HwConfig(void)
 {
    /*If Standard signal has been selected with hardware selection*/
 	if (HWCONFIG_STD==ACTIVATED)
 	{
 	/*Global Variable receives Standard Config*/
 		rub_HW_Config = STANDARD;
 	}
 	/*If High_End signal has been selected with hardware selection*/
 	else if (HWCONFIG_HE==ACTIVATED)
 	{ 
 	 /*Global Variable receives High-End Config*/
 		rub_HW_Config = HIGH_END;
 	}
 	else
 	{
 	  /*Global Variable receives Luxury Config*/
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

/*SM default state is IDLE*/

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
 *  Name                 :	Command_Stop
 *  Description          :  Logial Functions when Stop command is received
 *  Parameters           :  void
 *  Return               :  SM Status IDlE
 *  Critical/explanation :    NO
 **************************************************************/
 
 
 T_UBYTE Command_Stop (void)
 {
  /*Get active or inactive status from the CAN parameter*/
  T_UBYTE lub_Parameter_Stop = Get_Active_Inactive_Status();
  
  		/*If Hardware Configuration was selected as Standard*/
  		if (rub_HW_Config == STANDARD)
   		{
   		    /*Activate stop lights assigned to Standard version*/
   			Standard_Stop_Lights(lub_Parameter_Stop); 
   		}
   		else 
   		{ 
   		/*Activate stop lights assigned to all other versions*/
   			Stop_Lights(lub_Parameter_Stop);
   		}   		
  return (IDLE); 
  }
  
 
 /* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 : Command_Hazard
 *  Description          :  Logial Functions when Hazard command is received
 *  Parameters           :  Void
 *  Return               :  SM Status IDlE
 *  Critical/explanation :   No
 **************************************************************/
 
  
 T_UBYTE Command_Hazard (void)
 {
 /*Get active or inactive status from the CAN parameter*/
 T_UBYTE lub_Parameter_Hazard = Get_Active_Inactive_Status();
 /*Get active or inactive status from the CAN parameter*/
 T_UBYTE lub_Parameter_OnTime = Get_On_Time();
 /*Get active or inactive status from the CAN parameter*/
 T_UBYTE lub_Parameter_OffTime = Get_Off_Time();
 
	 /*If the hazard parameter is ACTIVATED*/
	 if (lub_Parameter_Hazard == ACTIVATED)
	 {
	 /*Send the correct ON Hazard Parameter for GPO*/
	 	lub_Parameter_Hazard = BLINKER_HAZARD;
	 }
	 else
	 {  /*Send the correct OFF Hazard Parameter for GPO  */
	 	lub_Parameter_Hazard = BLINKER_HAZARD_OFF;
	 }
     	/*If Hardware Configuration was selected as Standard*/
   		if (rub_HW_Config == STANDARD)
   		{
   	      /*Send Hacard instruction to GPO*/
   			Standard_Blinker_Lights(lub_Parameter_Hazard, lub_Parameter_OnTime , lub_Parameter_OffTime);			
       	}
       	/*If Hardware Configuration was selected as High-End*/
   		else if (rub_HW_Config == HIGH_END)
   		{
   		 /*Send Hacard instruction to GPO*/
   			High_End_Blinker_Lights(lub_Parameter_Hazard, lub_Parameter_OnTime , lub_Parameter_OffTime);
   		}   
   		else
   		{
   		 /*Send Hacard instruction to GPO*/
   			Luxury_Blinker_Lights(lub_Parameter_Hazard, lub_Parameter_OnTime , lub_Parameter_OffTime);
   		}		
   
  return (IDLE); 
}
   
   
   
 /* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	Command_Turn
 *  Description          : Logial Functions when Turn command is received
 *  Parameters           :  Void
 *  Return               :  SM Status IDlE
 *  Critical/explanation :    No
 **************************************************************/
 
  
 T_UBYTE Command_Turn (void)
 {
 /*Get  status from the CAN parameter*/
 T_UBYTE lub_Parameter_Turn = Get_Turn_Mode_Status();
 /*Get ON time status from the CAN parameter*/
 T_UBYTE lub_Parameter_OnTime = Get_On_Time();
 /*Get OFF time status from the CAN parameter*/
 T_UBYTE lub_Parameter_OffTime = Get_Off_Time();
     /*if parameter right is received, change right light to BLINKER right light*/
	 if (lub_Parameter_Turn == RIGHT)
	 {
	 	lub_Parameter_Turn = BLINKER_RIGHT;
	 }
	 /*if parameter left is received, change left light to BLINKER left light*/
	 else if (lub_Parameter_Turn == LEFT)
	 {
	 	lub_Parameter_Turn = BLINKER_LEFT;
	 }
	 else
	 {
	 /*if parameter Inactive is received, change to deactivate  light parameter*/
	 	lub_Parameter_Turn = BLINKER_TURN_OFF;
	 }
   	/*If Hardware Configuration was selected as Standard*/
   		if (rub_HW_Config == STANDARD)
   		{
   	  /*send command to light on standard version*/
   			Standard_Blinker_Lights(lub_Parameter_Turn, lub_Parameter_OnTime , lub_Parameter_OffTime);			
       	}
   		else if (rub_HW_Config == HIGH_END)
   		{
   		/*send command to light on high-end version*/
   			High_End_Blinker_Lights(lub_Parameter_Turn, lub_Parameter_OnTime , lub_Parameter_OffTime);
   		}   
   		else
   		{
   		/*send command to light on luxury version*/
   			Luxury_Blinker_Lights(lub_Parameter_Turn, lub_Parameter_OnTime , lub_Parameter_OffTime);
   		}		
   
  return (IDLE); 
}



   
 /* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	Command_MainLight
 *  Description          :  Logial Functions when Main Light command is received
 *  Parameters           :  void
 *  Return               :SM Status IDlE
 *  Critical/explanation :    No
 **************************************************************/
 
  
 T_UBYTE Command_Mainlight (void)
 {
 /*Get  status from the CAN parameter*/
 T_UBYTE lub_Parameter_Mainlight = (T_UBYTE)Get_Main_Lights_Mode();
 
 /*If parameter received is main lights*/
	 if (lub_Parameter_Mainlight == MAIN_LIGHTS_DAY)
	 {
	  	rub_Auto_Mode_Flag=INACTIVATED;
	  /*if the configuration is standard*/
	 		if (rub_HW_Config == STANDARD)
	 	      {
	 	      /*Turn the standard day lights*/
	 	      	Standard_Day_lights(ACTIVATED);
	 	      	Low_Beam_Lights(INACTIVATED);
	 	      }
	 	      else
	 	      {
	 	      /*Turn the rest of versions day lights*/
			 	Day_Lights(ACTIVATED);
			 	Low_Beam_Lights(INACTIVATED);
	 	      }
	 }
	 /*if the parameter recived is full*/
	 else if (lub_Parameter_Mainlight == MAIN_LIGHTS_FULL)
	 {
	 	rub_Auto_Mode_Flag=INACTIVATED;
	    /* and if the config is standard*/
	 		if (rub_HW_Config == STANDARD)
	 	      {
	 	      /*Turn the standard day and low beam lights*/
	 	      	Standard_Day_lights(ACTIVATED);
	 	      	Low_Beam_Lights(ACTIVATED);
	 	      }
	 	      else
	 	      {
	 	      /*Turn all versions low beam and day light*/
		 	Low_Beam_Lights(ACTIVATED);
		 	Day_Lights(ACTIVATED);
		   	}
	 }
	 /*If the parameter is automatic*/
	 else if (lub_Parameter_Mainlight == MAIN_LIGHTS_AUTO)
	 {
	    rub_Auto_Mode_Flag=ACTIVATED;
	 }
	 else
	 {
	 	rub_Auto_Mode_Flag=INACTIVATED;
	 	Day_Lights(INACTIVATED);
	 	Low_Beam_Lights(INACTIVATED);
	 	Standard_Day_lights(INACTIVATED);
	 }
   return (IDLE); 
}

/**************************************************************
 *  Name                 :	  Main_Ligths_Auto_Mode
 *  Description          :    Logial Functions when Mainlights is in 
 							  Auto mode
 *  Parameters           :    void
 *  Return               :	  None	
 *  Critical/explanation :    No
 **************************************************************/

void Main_Ligths_Auto_Mode(void)
{
	T_UBYTE lub_Threshold;
	T_UBYTE lub_Standard_Blinker_Status= (T_UBYTE) Get_Standard_Blinker_Status();
	static T_UBYTE lub_Day_Flag=INACTIVATED;
	if(rub_Auto_Mode_Flag==ACTIVATED)
	{
		/*Get Light sensor value*/
	 	lub_Threshold = Get_Threshold();
	 	
	 	/*If the sensor value indicates it is day light, do not turn on lights*/
	 	if (lub_Threshold == DAY )
	 	{
	 	Low_Beam_Lights(INACTIVATED);
	 		if (rub_HW_Config == STANDARD)
	 	    {
	 	    	
	 	    	if((lub_Standard_Blinker_Status==INACTIVATED) || (lub_Day_Flag==ACTIVATED))
	 	    	{
	 	    		Standard_Day_lights(INACTIVATED);
	 	    		lub_Day_Flag=INACTIVATED;
	 	    		
	 	    	}
	 	    	else
	 	    	{
	 	    		/* Do nothing */
	 	    	}
	 			
	 	    }
	 	    else
	 	    {
	 	    	Day_Lights(INACTIVATED);
	 	    		
	 	    }	
	 	}
	 	/*If the sensor value indicates it is sunset light, turn on day and low beam lights*/
	 	else if (lub_Threshold == SUNSET_SUNRISE )
	 	{
	 	      if (rub_HW_Config == STANDARD)
	 	      {
	 	      	
	 	      	Standard_Day_lights(ACTIVATED);
	 	      	Low_Beam_Lights(INACTIVATED);
	 	      	lub_Day_Flag=ACTIVATED;
	 	      }
	 	      else
	 	      {
	 	      	
	 			Day_Lights(ACTIVATED);
	 			Low_Beam_Lights(INACTIVATED);
	 	      }
	 			
	 	}
	 	/*If sensor detects it is night, turn all main lights*/
	 	else if (lub_Threshold == NIGHT )
	 	{
	 		if (rub_HW_Config == STANDARD)
	 	      {
	 	      	Standard_Day_lights(ACTIVATED);
	 	      	Low_Beam_Lights(ACTIVATED);
	 	      	lub_Day_Flag=ACTIVATED;
	 	      }
	 	      else
	 	      {
	 			Day_Lights(ACTIVATED);
	 			Low_Beam_Lights(ACTIVATED);
	 	      }
	 	}
	}
  	else
  	{
  		/* Do nothing */
  	}
	 
}