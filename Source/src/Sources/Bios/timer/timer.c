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
#include "timer.h"
#include "lights_output.h"
#include "lights_output.h"

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
T_UBYTE rub_On_Count=0;
T_UBYTE rub_Off_Count=0;
/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */
#define ACTIVATED				1u
#define DEACTIVATED				0u
#define RESET					0u

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

 void On_Counter(void)
 {	
 		/* reads the flag to turn on or turn off the counter */
 		T_UBYTE lub_OnOff_Flag=TurnOnOff_OnTimer();
 		
 		/* checks if the counter was turn on */
 		if(lub_OnOff_Flag == ACTIVATED)
 		{
 			/* checks if the counter is more or equal than 400ms */
 			if(rub_On_Count >= 21)
 			{
 				/* reset the counter and change the 400ms flag to completed */
 				rub_On_Count=RESET;
 			}
 			/* the counter increases and the 400ms flag change to no completed */
 			else
 			{
 				rub_On_Count++;
 			}
 		}
 		/* resets the counter */
 		else
 		{
 			rub_On_Count=RESET;
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

 T_UBYTE Get_On_Counter(void)
 {	
 	return rub_On_Count;
 }
 
 /* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/

 void Off_Counter(void)
 {	
 		/* reads the flag to turn on or turn off the counter */
 		T_UBYTE lub_OnOff_Flag=TurnOnOff_OffTimer();
 		
 		/* checks if the counter was turn on */
 		if(lub_OnOff_Flag == ACTIVATED)
 		{
 			/* checks if the counter is more or equal than 400ms */
 			if(rub_Off_Count >= 21)
 			{
 				/* reset the counter and change the 400ms flag to completed */
 				rub_Off_Count=RESET;
 			}
 			/* the counter increases and the 400ms flag change to no completed */
 			else
 			{
 				rub_Off_Count++;
 			}
 		}
 		/* resets the counter */
 		else
 		{
 			rub_Off_Count=RESET;
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

 T_UBYTE Get_Off_Counter(void)
 {	
 	return rub_Off_Count;
 }
 