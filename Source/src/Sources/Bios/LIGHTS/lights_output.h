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
extern void Day_Lights(T_UBYTE lub_On_Off);
extern void Low_Beam_Lights(T_UBYTE lub_On_Off);
extern void High_End_Blinker_Lights(T_UBYTE lub_Parameter, T_UBYTE lub_On_Time, T_UBYTE lub_Off_Time);
extern void High_End_Blinker_Lights_Task(void);
extern void Luxury_Blinker_Lights(T_UBYTE lub_Parameter, T_UBYTE lub_On_Time, T_UBYTE lub_Off_Time);
extern void Luxury_Blinker_Lights_Task(void);
extern void Standard_Blinker_Lights(T_UBYTE lub_Parameter, T_UBYTE lub_On_Time, T_UBYTE lub_Off_Time);
extern void Standard_Blinker_Lights_Task(void);
extern void Standard_Day_lights(T_UBYTE lub_On_Off);
extern void Stop_Lights(T_UBYTE lub_On_Off);
extern void Standard_Stop_Lights(T_UBYTE lub_On_Off);
extern T_UBYTE TurnOnOff_OnTimer(void);
extern T_UBYTE TurnOnOff_OffTimer(void);
/* Functions macros */


/* Exported defines */


#endif


