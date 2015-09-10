/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         mssg_decoder.c
* Instance:         RPL_1
* %version:         1.2
* %created_by:      Diego Flores
* %date_created:    Tuesday Sep  1 14:38:03 2015
*=============================================================================*/
/* DESCRIPTION : C source template file                                       */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the C source template according to  */
/* the new software platform                                                  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 01/09/2015  |                               | Diego Flores     */
/* Integration under Continuus CM                                             */
/*============================================================================*/
/*  1.2      | 04/09/2015  |                               | Diego Flores     */
/* Integration under Continuus CM                                             */
/*============================================================================*/

/* Includes */
/* -------- */
#include "mssg_decoder.h"
#include "typedefs.h"
#include "Can_Manager.h"
#include "GPIO.h"

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
T_UBYTE rub_Messg_ID=0x00;
T_UBYTE rub_ON_TIME=0;
T_UBYTE rub_OFF_TIME=0;
T_UBYTE rub_Main_Lights_Mode;

/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */

extern StatusType Status=
{
	0, 0, 0, 0, 0, 0, 0
};
/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */
#define CHECKSUM_SELECTOR				SWITCH1

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
 *  Name                 :	Message_decoder
 *  Description          :	This function decodes the CAN messages
 *  Parameters           :  None
 *  Return               :	None
 *  Critical/explanation :  No
 **************************************************************/
void Message_decoder(void)
{
	
	static T_UBYTE lub_Parameter_Number=0xFF;
	static T_UBYTE lub_Parameter0=0xFF;
	static T_UBYTE lub_Parameter1=0xFF;
	static T_UBYTE lub_Parameter2=0xFF;
	static T_UBYTE lub_Checksum=0xFF;
	T_UBYTE lub_Checksum_Calc=0xFF;
	
	rub_Messg_ID=Message[0];                                /* Get first byte of the message */
	lub_Parameter_Number=Message[1];	                    /* Get second byte of the message */
	lub_Parameter0=Message[2];								/* Get third byte of the message */
	lub_Parameter1=Message[3];								/* Get fourth byte of the message */
	lub_Parameter2=Message[4];								/* Get fifth byte of the message */
	lub_Checksum=Message[5];								/* Get sixth byte of the message */
	
	/* Checks the Checksum */
	lub_Checksum_Calc=rub_Messg_ID^lub_Parameter_Number^lub_Parameter0^lub_Parameter1^lub_Parameter2;
	if((BUTTON_PRESS(CHECKSUM_SELECTOR) == ACTIVATED) || (lub_Checksum == lub_Checksum_Calc))
	{
		switch(rub_Messg_ID)
		{
			case STOP: 	   	 	
						/* Checks the parameter0 to now if Stop command is active or inactive */
	 					if(lub_Parameter0==0x0F)
				   		{
							Status.Active_Inactive=ACTIVATED;
		               	}
		           	   	else if(lub_Parameter0==0x00)
		           	   	{
			         		Status.Active_Inactive=INACTIVATED;
			     	    }
		 		   	    else 
			    	    {
			        		/* Do nothing */
		               	}		
						break;
									
			case TURN: 	    
						/* Checks Parameter0 to know the behavior of the turn command */
						if(lub_Parameter0 == 0x01)
		           		{
		           			Status.Turn_Mode=OFF;
		           		}
		           		else if(lub_Parameter0 == 0x0A)
		           		{
		           			Status.Turn_Mode=RIGHT;
		           			/* take the value of parameters 1 and 2 to know the on time and off time values */
							rub_ON_TIME=lub_Parameter1;
		           			rub_OFF_TIME=lub_Parameter2;
		           		}
		           		else if(lub_Parameter0 == 0x0B)
		           		{
		           			Status.Turn_Mode=LEFT;
		           			/* take the value of parameters 1 and 2 to know the on time and off time values */
							rub_ON_TIME=lub_Parameter1;
		           			rub_OFF_TIME=lub_Parameter2;
			           	}
			           	else
			           	{
		    	       		/* Do nothing */
		        	   	}	
					break;
						
			case HAZARD:	
						/* Checks the parameter0 to now if Hazard command is active or inactive */
						if(lub_Parameter0==0x0F)
				   		{
							Status.Active_Inactive=ACTIVATED;
							/* take the value of parameters 1 and 2 to know the on time and off time values */
		           			rub_ON_TIME=lub_Parameter1;
		           			rub_OFF_TIME=lub_Parameter2;
		           		}
		           		else if(lub_Parameter0==0x00)
		           		{
		           			Status.Active_Inactive=INACTIVATED;
		           		}
		           		else 
		           		{
		           			/* Do nothing */
		           		}	
					break;
						
			case MAIN_LIGHTS:   
							/* Checks Parameter0 to know the behavior of the Main Lights */
							rub_Main_Lights_Mode=lub_Parameter0;	
						break;
					
			default:	rub_Messg_ID=0x00;
						break;
		}	
	}
	else
	{
		rub_Messg_ID=0x00;
	}
	
}

/**************************************************************
 *  Name                 :	Get_Messag_ID
 *  Description          :  Return the value of the Message ID
 *  Parameters           :  None
 *  Return               :	T_UBYTE rub_Messg_ID
 *  Critical/explanation :  No
 **************************************************************/

T_UBYTE Get_Messag_ID(void)
{
	return rub_Messg_ID;
}


/**************************************************************
 *  Name                 :	Get_On_Time
 *  Description          :	Return the value of On Time
 *  Parameters           :  None
 *  Return               :	T_UBYTE rub_ON_TIME
 *  Critical/explanation :  No
 **************************************************************/

T_UBYTE Get_On_Time(void)
{
	return rub_ON_TIME;
}

/**************************************************************
 *  Name                 :	Get_Off_Time
 *  Description          :	Return the value of Off Time
 *  Parameters           :  None
 *  Return               :	T_UBYTE rub_OFF_TIME
 *  Critical/explanation :  No
 **************************************************************/

T_UBYTE Get_Off_Time(void)
{
	return rub_OFF_TIME;
}


/**************************************************************
 *  Name                 :	Get_Active_Inactive_Status
 *  Description          :	Return the value of the Status.Active_Inactive 
 *  Parameters           :  None
 *  Return               :	Status.Active_Inactive
 *  Critical/explanation :  No
 **************************************************************/

T_UBYTE Get_Active_Inactive_Status(void)
{
	return Status.Active_Inactive;
}


/**************************************************************
 *  Name                 :	Get_Turn_Mode_Status
 *  Description          :	Return the value of Status.Turn_Mode
 *  Parameters           :  None
 *  Return               :	Status.Turn_Mode
 *  Critical/explanation :  No
 **************************************************************/

T_UBYTE Get_Turn_Mode_Status(void)
{
	return Status.Turn_Mode;
}


/**************************************************************
 *  Name                 :	Get_Main_Lights_Mode
 *  Description          :  Return the value of rub_Main_Lights_Mode
 *  Parameters           :  None
 *  Return               :	rub_Main_Lights_Mode
 *  Critical/explanation :  No
 **************************************************************/

T_UBYTE Get_Main_Lights_Mode(void)
{
	return rub_Main_Lights_Mode;
}


