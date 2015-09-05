/*******************************************************************************/
/**

\file       GPIO.h
\brief      Macro definitions for registers access and I/O handling
\author     Abraham Tezmol
\version    0.2
\date       09/05/2013
*/
/*******************************************************************************/

#ifndef _GPIO_H        /*prevent duplicated includes*/
#define _GPIO_H

/*-- Includes ----------------------------------------------------------------*/

/** Core modules */
/** MCU derivative information */
#include "MCU_derivative.h"
/** Variable types and common definitions */
#include "typedefs.h"

/*-- Variables ---------------------------------------------------------------*/

/*-- Types Definitions -------------------------------------------------------*/

/*-- Defines -----------------------------------------------------------------*/

#define LED1      					68
#define LED2       					69
#define LED3       					70
#define LED4        				71
#define BUTTON4						67

#define GPIO_PA0					0
#define GPIO_PA1					1
#define GPIO_PA2					2
#define GPIO_PA3				    3
#define GPIO_PA4					4
#define GPIO_PA5					5
#define GPIO_PA6					6
#define GPIO_PA7					7
#define GPIO_PA8					8
#define GPIO_PA9					9
#define GPIO_PA10					10
#define GPIO_PA11					11
#define GPIO_PA12					12
#define GPIO_PA13					13
#define GPIO_PA14					14
#define GPIO_PA15					15
#define GPIO_PC2					34
#define GPIO_PC3					35
#define GPIO_PC4					36
#define GPIO_PC5					37
#define GPIO_PC6					38
#define GPIO_PC7					39
#define GPIO_PC8					40



#define GPIO_INPUT					0
#define GPIO_OUTPUT					1

#define GPIO_OPEN_DRAIN_DISABLE		0
#define GPIO_OPEN_DRAIN_ENABLE		1

/*-- Macros ------------------------------------------------------------------*/
/* Indicator LEDs handling */

/** Set LED */ 
#define LED_ON(channel)                     (SIU.GPDO[channel].B.PDO =  1)
/** Clear LED */ 
#define LED_OFF(channel)                    (SIU.GPDO[channel].B.PDO =  0)
/** Toggle LED */ 
#define LED_TOGGLE(channel)                 (SIU.GPDO[channel].B.PDO ^= 1) 


#define BUTTON_PRESS(channel)				(SIU.GPDI[channel].B.PDI)

/*-- Function Prototypes -----------------------------------------------------*/

void vfnGPIO_Init_channel(uint8_t channel, uint8_t input_output, uint8_t Open_drain);
void vfnGPIO_Output(uint8_t channel, uint8_t logical_value);
void vfnGPIO_FlashMainLED(void);
void vfnGPIO_LED_Init(void);


#endif /* _GPIO_H */

/*******************************************************************************/
