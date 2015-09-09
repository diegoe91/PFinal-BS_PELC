/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        lights_output.h
* Instance:         RPL_1
* version:          1.2
* created_by:       Diego Flores
* date_created:     Fri Sep 04 13:41:01 2015
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
/*  1.0      | 04/09/2015  |                               | Diego Flores     */
/* Integration under Continuus CM                                             */
/*============================================================================*/
/*  1.2      | 06/09/2015  |                               | Diego Flores     */
/* Comments addition			                                              */
/*============================================================================*/

#ifndef LIGHTSOUT_H                               /* To avoid double inclusion */
#define LIGHTSOUT_H

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
extern void Day_Lights(T_UBYTE lub_On_Off);		/* High-End and Luxury configurations */
extern void Low_Beam_Lights(T_UBYTE lub_On_Off); /* All configurations */
extern void High_End_Blinker_Lights(T_UBYTE lub_Parameter, T_UBYTE lub_On_Time, T_UBYTE lub_Off_Time); /* High-End configuration */
extern void High_End_Blinker_Lights_Task(void);
extern void Luxury_Blinker_Lights(T_UBYTE lub_Parameter, T_UBYTE lub_On_Time, T_UBYTE lub_Off_Time); /* Luxury configuration */
extern void Luxury_Blinker_Lights_Task(void);
extern void Standard_Blinker_Lights(T_UBYTE lub_Parameter, T_UBYTE lub_On_Time, T_UBYTE lub_Off_Time); /* Standard configuration */
extern void Standard_Blinker_Lights_Task(void);
extern void Standard_Day_lights(T_UBYTE lub_On_Off); /* Standard configuration */
extern void Stop_Lights(T_UBYTE lub_On_Off); /* High-End and Luxury configurations */
extern void Standard_Stop_Lights(T_UBYTE lub_On_Off); /* Standard configuration */
extern T_UBYTE TurnOnOff_OnTimer(void);
extern T_UBYTE TurnOnOff_OffTimer(void);
extern T_UBYTE Get_Low_Beam_Lights_Status(void);
extern T_UBYTE Get_Stop_Lights_Status(void);

/* Functions macros */


/* Exported defines */


#endif


