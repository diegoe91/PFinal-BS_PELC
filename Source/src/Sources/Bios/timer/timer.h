/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        timer.h
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
/*----------------------------------------------------------------------------*/
/*  1.2      | 06/09/2015  |                               | Diego Flores     */
/* Comments addition                                                          */
/*============================================================================*/

#ifndef TIMER_H                               /* To avoid double inclusion */
#define TIMER_H

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
extern T_UBYTE Get_Off_Counter(void);
extern void Off_Counter(void);
extern T_UBYTE Get_On_Counter(void);
extern void On_Counter(void);

/* Functions macros */


/* Exported defines */


#endif


