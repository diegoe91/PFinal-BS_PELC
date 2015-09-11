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
#include "main_lights.h"
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


/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */
#define BUTTON_PRESSED					1
#define DBNCCOUNT_CFG					3
#define DOOR_CKTIN						BUTTON_PRESS(BUTTON4)
T_UBYTE rub_Open_CktDbnc=0;
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
 *  Name                 :	Door_Debounce
 *  Description          :	Function that makes the debounce of the door
 *  Parameters           :  None
 *  Return               :	None
 *  Critical/explanation :  No
 **************************************************************/

void Door_Debounce(void)
 {  
 	 
 	static T_UBYTE 	lub_Open_DbncCount=0; 
    /* checks if the open button was pressed */
    if(DOOR_CKTIN == BUTTON_PRESSED)
	{
		lub_Open_DbncCount++;
		/* Checks if the counter is more or equal than the debounce time */
		if(lub_Open_DbncCount >= DBNCCOUNT_CFG)
		{
			/* Change the flag status to pressed */
			rub_Open_CktDbnc=DOOR_CKTIN;
		}
		else
		{
			/* Do nothing */
		}
	}
	/* Change the flag status to released and restart the counter */
	else 
	{
		lub_Open_DbncCount=0;
		rub_Open_CktDbnc=DOOR_CKTIN;
	}
 }
 
 /* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	Get_Door_Debounce_Status
 *  Description          :	Function that returns the Door status
 *  Parameters           :  None
 *  Return               :	rub_Open_CktDbnc
 *  Critical/explanation :  No
 **************************************************************/
 T_UBYTE Get_Door_Debounce_Status(void)
 {
 	return rub_Open_CktDbnc;
 }