/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %template.c%
* Instance:         RPL_1
* %version:         2 %
* %created_by:      uid02495 %
* %date_created:    Fri Jan  9 14:38:03 2004 %
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
/*  1.0      | DD/MM/YYYY  |                               | Mr. Template     */
/* Integration under Continuus CM                                             */
/*============================================================================*/

/* Includes */
/* -------- */
#include "mssg_decoder.h"
#include "typedefs.h"
#include "Can_Manager.h"

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
T_UBYTE rub_Messg_ID=0xFF;
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
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void Message_decoder(void)
{
	
	static T_UBYTE lub_Parameter_Number=0xFF;
	static T_UBYTE lub_Parameter0=0xFF;
	static T_UBYTE lub_Parameter1=0xFF;
	static T_UBYTE lub_Parameter2=0xFF;
	static T_UBYTE lub_Checksum=0xFF;
	T_UBYTE lub_Checksum_Calc=0xFF;
	
	rub_Messg_ID=Message[0];
	lub_Parameter_Number=Message[1];	
	lub_Parameter0=Message[2];
	lub_Parameter1=Message[3];
	lub_Parameter2=Message[4];
	lub_Checksum=Message[5];
	
	switch(rub_Messg_ID)
	{
		case STOP: 	   	lub_Checksum_Calc=rub_Messg_ID^lub_Parameter_Number^lub_Parameter0;
						if(lub_Checksum == lub_Checksum_Calc)
						{
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
						}
						else
						{
							rub_Messg_ID=0xFF;
						}
		               	
						break;
						
		case TURN: 	    lub_Checksum_Calc=rub_Messg_ID^lub_Parameter_Number^lub_Parameter0^lub_Parameter1^lub_Parameter2;
						if(lub_Checksum == lub_Checksum_Calc)
						{
							if(lub_Parameter0 == 0x01)
		           			{
		           				Status.Turn_Mode=OFF;
		           			}
		           			else if(lub_Parameter0 == 0x0A)
		           			{
		           				Status.Turn_Mode=LEFT;
		           			}
		           			else if(lub_Parameter0 == 0x0B)
		           			{
		           				Status.Turn_Mode=RIGHT;
			           		}
			           		else
			           		{
		    	       			/* Do nothing */
		        	   		}
							rub_ON_TIME=lub_Parameter1;
		           			rub_OFF_TIME=lub_Parameter2;	
						}
						else
						{
							rub_Messg_ID=0xFF;
						}
		           		
						
						break;
						
		case HAZARD:	lub_Checksum_Calc=rub_Messg_ID^lub_Parameter_Number^lub_Parameter0^lub_Parameter1^lub_Parameter2;
						if(lub_Checksum == lub_Checksum_Calc)
						{
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
		           		 
		           			rub_ON_TIME=lub_Parameter1;
		           			rub_OFF_TIME=lub_Parameter2;	
						}
						else
						{
							rub_Messg_ID=0xFF;
						}
								        
		           		
						break;
						
						
		case MAIN_LIGHTS:   lub_Checksum_Calc=rub_Messg_ID^lub_Parameter_Number^lub_Parameter0;
							if(lub_Checksum == lub_Checksum_Calc)
							{
								rub_Main_Lights_Mode=lub_Parameter0;	
							}
							else
							{
								rub_Messg_ID=0xFF;
							} 
						  
		
					break;
					
		default:	rub_Messg_ID=0xFF;
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

T_UBYTE Get_Messag_ID(void)
{
	return rub_Messg_ID;
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

T_UBYTE Get_On_Time(void)
{
	return rub_ON_TIME;
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

T_UBYTE Get_Off_Time(void)
{
	return rub_OFF_TIME;
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

T_UBYTE Get_Active_Inactive_Status(void)
{
	return Status.Active_Inactive;
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

T_UBYTE Get_Turn_Mode_Status(void)
{
	return Status.Turn_Mode;
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

T_UBYTE Get_Main_Lights_Mode(void)
{
	return rub_Main_Lights_Mode;
}
