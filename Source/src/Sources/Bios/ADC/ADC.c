/*============================================================================*/
/*                        Continental AEP 2015                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:       	ADC.c
* Instance:         RPL_1
* version:         	1.1
* created_by:      	Diego Flores
* date_created:    	Monday, Sep 07, 2015
*=============================================================================*/
/* DESCRIPTION : C source init file                                           */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the initialization routines         */
/*                                                  						  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.1      | 07/09/2015  |C file template implementation | Diego Flores     */
/*============================================================================*/

/* Includes */
/* -------- */
#include "ADC.h"
#include "MPC5606B.h"
 

/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */

/*==================================================*/ 
/* Definition of constants                          */
/*==================================================*/ 
/* BYTE constants */
T_ULONG rul_ADC_Result = 0;

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
#define Output (uint16_t)0x200	//PCR_GPIO_OutputConfiguration
#define Input  (uint16_t)0x100	//PCR_GPIO_InputConfiguration
#define Analog (uint16_t)0x2000	//PCR_AnalogConfiguration

	/* ADC Pins */
#define PortB4 SIU.PCR[20].R	//ADC0_P0 

#define ADC_EOC_IRQ				62

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
 *  Name                 :	init_ADC0_P0
 *  Description          :	Initialize ADC0_P0
 *  Parameters           :	None
 *  Return               :	None
 *  Critical/explanation :	No
 **************************************************************/
void init_ADC0_P0(void)
{
  	PortB4 = Analog;				/* Initialize PB[4] as ADC0_P0 */
  	ADC_0.MCR.R = 0x00000000;   	/* Initialize ADC0 for scan mode */
  	ADC_0.NCMR0.R = 1;            /* Select ADC0_P0 input for conversion */
  	ADC_0.CTR0.R = 0x00008606;    /* Conversion times for 32MHz ADClock */
}

/**************************************************************
 *  Name                 : 	ADC_Convertion
 *  Description          :	Function that makes the ADC convertion
 *  Parameters           :  None
 *  Return               :	None
 *  Critical/explanation :  No
 **************************************************************/

void ADC_Convertion(void)
{
	ADC_0.MCR.B.NSTART = 1;
	while (ADC_0.CDR[0].B.VALID != 1)		/* Wait for last scan to complete */
    {}
   	rul_ADC_Result = ADC_0.CDR[0].B.CDATA;
}


/**************************************************************
 *  Name                 : 	Get_ADC_Value
 *  Description          :	Function that returnd the ADC result
 *  Parameters           :  None
 *  Return               :	rul_ADC_Result
 *  Critical/explanation :  No
 **************************************************************/
 
 T_ULONG Get_ADC_Value(void)
 {
 	return rul_ADC_Result;
 }