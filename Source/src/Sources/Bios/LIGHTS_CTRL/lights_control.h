/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %template.h%
* Instance:         RPL_1
* %version:         1 %
* %created_by:      uid02495 %
* %date_created:    Fri Feb 28 13:41:01 2003 %
*=============================================================================*/
/* DESCRIPTION : Header file template                                         */
/*============================================================================*/
/* FUNCTION COMMENT : contains only symbols which are exported to internal    */
/* platform modules. This will not be delivered with the library              */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | DD/MM/YYYY  | SAR/SIF/SCN_xxx               | Mr. Template     */
/* Integration under Continuus CM                                             */
/*============================================================================*/

#ifndef LIGHTSCONTROL_H                               /* To avoid double inclusion */
#define LIGHTSCONTROL_H

/* Includes */
/* -------- */
#include "typedefs.h"

/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
/* typedef */


/*==================================================*/ 
/* Declaration of exported constants                */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */

enum Blinker_Functions 
{
	BLINKER_HAZARD,
	BLINKER_RIGHT,
	BLINKER_LEFT,
	BLINKER_HAZARD_OFF,
	BLINKER_TURN_OFF
};

enum HW_Configuration
{
	STANDARD,
	HIGH_END,
	LUXURY
	
};

/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTES */

/* WORDS */


/* LONGS and STRUCTURES */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Exported functions prototypes and macros */
/* ---------------------------------------- */

/* Functions prototypes */

extern void lights_control_SM (void);
extern T_UBYTE Command_Stop(void);
extern T_UBYTE Command_Turn(void);
extern T_UBYTE Command_Hazard(void);
extern T_UBYTE Command_Mainlight(void);
extern void lights_control_SM(void);
extern void Main_Ligths_Auto_Mode(void);
/* Functions macros */


/* Exported defines */


#endif


