/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         Light_Sensor.c
* Instance:         RPL_1
* version:         	1.0
* created_by:      	Diego Flores
* date_created:    	Tuesday Sep  08 09:28:03 2015
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
/*  1.0      | 08/09/2015  |                               | Diego Flores     */
/* Integration under Continuus CM                                             */
/*============================================================================*/

/* Includes */
/* -------- */
#include "Light_Sensor.h"
#include "ADC.h"

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
T_UBYTE rub_Threshold=DAY;

/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */
#define LIGHT_63PERCENT				654
#define LIGHT_60PERCENT				614
#define LIGHT_33PERCENT				450
#define LIGHT_30PERCENT				409

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
 *  Name                 : 	Light_Thresholds
 *  Description          :	Function that checks the differents ADC values
 							to change the differents Thresholds 
 *  Parameters           :  None
 *  Return               :	None
 *  Critical/explanation :  No
 **************************************************************/
void Light_Thresholds(void)
{
	static T_ULONG lul_ADC=0;
	
	lul_ADC=Get_ADC_Value(); /* Variable that gets ADC value */
	
	
	switch(rub_Threshold)
	{
		case DAY:	
					/* Checks if the light is less than 60 percent */
					/* to change to the state SUNSET_SUNRISE */
					if(lul_ADC <= LIGHT_60PERCENT)
					{
						rub_Threshold=SUNSET_SUNRISE;
					}
					else
					{
						rub_Threshold=DAY;
					}
			break;
			
		case SUNSET_SUNRISE:
								/* Checks if the light is more than 63 percent */
								/* to change to the state DAY */
								if(lul_ADC >= LIGHT_63PERCENT)
								{
									rub_Threshold=DAY;
								}
								/* Checks if the light is less than 30 percent */
								/* to change to the state NIGHT */
								else if(lul_ADC <= LIGHT_30PERCENT)
								{
									rub_Threshold=NIGHT;
								}
								else
								{
									rub_Threshold=SUNSET_SUNRISE;
								}
			break;
			
		case NIGHT:
					/* Checks if the light is more than 33 percent */
					/* to change to the state SUNSET_SUNRISE */
					if(lul_ADC >= LIGHT_33PERCENT)
					{
						rub_Threshold=SUNSET_SUNRISE;
					}
					else
					{
						rub_Threshold=NIGHT;
					}
			break;
		
		default:
					rub_Threshold=DAY;
			break;
	}	
}


/**************************************************************
 *  Name                 :	Get_Threshold
 *  Description          :	Function that returns the state of the Threshold
 *  Parameters           :  None
 *  Return               :	rub_Threshold
 *  Critical/explanation :  No
 **************************************************************/
 
T_UBYTE Get_Threshold(void)
{
	return rub_Threshold;
}
