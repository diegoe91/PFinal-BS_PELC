/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        mssg_decoder.h
* Instance:         RPL_1
* version:         1.2
* created_by:      Diego Flores
* date_created:    Tuesday Sep 01 13:41:01 2015 
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
/*  1.0      | 01/09/2015  |                               | Diego Flores     */
/* Integration under Continuus CM                                             */
/*============================================================================*/
/*  1.2      | 04/09/2015  |                               | Diego Flores     */
/* Integration under Continuus CM                                             */
/*============================================================================*/

#ifndef MSSG_DECODER_H                               /* To avoid double inclusion */
#define MSSG_DECODER_H

/* Includes */
/* -------- */
#include "typedefs.h"

/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
/* typedef */
typedef enum
{
	IDLE,
	STOP,
	REVERSE,
	TURN,
	HAZARD,
	MAIN_LIGHTS	
}Command;



typedef struct
{
	T_UBYTE Active_Inactive :1;
	T_UBYTE Turn_Mode :2;
	T_UBYTE AntiPinch_CktDbnc :1;
	T_UBYTE T400ms: 1;
	T_UBYTE T500ms: 1;
	T_UBYTE T5Sec: 1;
	T_UBYTE Dummy: 1;
}StatusType;

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

extern T_UBYTE Get_Turn_Mode_Status(void);
extern void Message_decoder(void);
extern T_UBYTE Get_Messag_ID(void);
extern T_UBYTE Get_On_Time(void);
extern T_UBYTE Get_Off_Time(void);
extern T_UBYTE Get_Active_Inactive_Status(void);



/* Functions macros */


/* Exported defines */
#define ACTIVATED		1u
#define INACTIVATED    0u
#define OFF         0u
#define LEFT        1u
#define RIGHT       2u

#endif


