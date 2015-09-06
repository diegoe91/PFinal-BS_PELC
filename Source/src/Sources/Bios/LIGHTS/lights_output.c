/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         lights_output.c
* Instance:         RPL_1
* version:          1.2
* created_by:       Diego Flores
* date_created:     Fri Sep  04 14:38:03 2015
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
/*  1.0      | 04/09/2015  |                               | Diego Flores     */
/* Integration under Continuus CM                                             */
/*============================================================================*/
/*  1.2      | 06/09/2015  |                               | Diego Flores     */
/* Comments addition			                                              */
/*============================================================================*/

/* Includes */
/* -------- */
#include "lights_output.h"
#include "GPIO.h"
#include "lights_control.h"

/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */

/*==================================================*/ 
/* Definition of constants                          */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */

#define ACTIVATED				1u
#define DEACTIVATED				0u
#define RESTART  				2u
/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTE RAM variables */

T_UBYTE rub_Parameter=BLINKER_TURN_OFF;
T_UBYTE rub_On_Time;
T_UBYTE rub_Off_Time;
T_UBYTE rub_High_End_Flag=DEACTIVATED;
T_UBYTE rub_Luxury_Flag=DEACTIVATED;
T_UBYTE rub_Standard_Flag=DEACTIVATED;
T_UBYTE rub_Standard_DayL_Flag=DEACTIVATED;

T_UBYTE rub_On_Timer_flag=DEACTIVATED;
T_UBYTE rub_Off_Timer_flag=DEACTIVATED;

/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */

#define FL_DAYL_R 				GPIO_PA0
#define FL_DAYL_L 				GPIO_PA1
#define FL_LBL_R 				GPIO_PA2
#define FL_LBL_L 				GPIO_PA3
#define FL_BL_R 				GPIO_PA4
#define FL_BL_L 				GPIO_PA5
#define FL_DAYBL_R 				GPIO_PA6
#define FL_DAYBL_L 				GPIO_PA7

#define BL_DAYL_R 				GPIO_PA8
#define BL_DAYL_L 				GPIO_PA9
#define BL_STOPL_R 				GPIO_PA10
#define BL_STOPL_L 				GPIO_PA11
#define BL_DAYSL_R 				GPIO_PA12
#define BL_DAYSL_L 				GPIO_PA13

#define BL_BL1_R 				GPIO_PA14
#define BL_BL2_R 				GPIO_PA15
#define BL_BL3_R 				GPIO_PC2
#define BL_BL1_L 				GPIO_PC3
#define BL_BL2_L 				GPIO_PC4
#define BL_BL3_L 				GPIO_PC5


#define OFF         0u
#define LEFT        1u
#define RIGHT       2u




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
 *  Name                 :	Day_Lights
 *  Description          :	Functions that controls Day lights
 					 		in high-end and luxury configuration
 *  Parameters           :  T_UBYTE lub_On_Off receives On, Off command
 *  Return               :	None
 *  Critical/explanation :  No
 **************************************************************/

void Day_Lights(T_UBYTE lub_On_Off)
{
	/* Checks if the command is Activated to turn On Day lights */
	if(lub_On_Off == ACTIVATED)
	{
		LED_ON(FL_DAYL_R);
		LED_ON(FL_DAYL_L);
		
		LED_ON(BL_DAYL_R);
		LED_ON(BL_DAYL_L);
	}
	/* Checks if the command is Deactivated to turn Off Day lights */
	else if(lub_On_Off == DEACTIVATED)
	{
		LED_OFF(FL_DAYL_R);
		LED_OFF(FL_DAYL_L);
		
		LED_OFF(BL_DAYL_R);
		LED_OFF(BL_DAYL_L);
	}
	else
	{
		/* Do nothing */
	}
}


/**************************************************************
 *  Name                 :	Low_Beam_Lights
 *  Description          :	Functions that controls Low beam lights
 					 		in all of the configurations
 *  Parameters           :  Input: T_UBYTE lub_On_Off receives On, Off command
 *  Return               :  None
 *  Critical/explanation :  No
 **************************************************************/

void Low_Beam_Lights(T_UBYTE lub_On_Off)
{
	/* Checks if the command is Activated to turn On Low beam lights */
	if(lub_On_Off == ACTIVATED)
	{
		LED_ON(FL_LBL_R);
		LED_ON(FL_LBL_L);
	}
	/* Checks if the command is Deactivated to turn Off Low Beam lights */
	else if(lub_On_Off == DEACTIVATED)
	{
		LED_OFF(FL_LBL_R);
		LED_OFF(FL_LBL_L);
	}
	else
	{
		/* Do nothing */
	}
}


/**************************************************************
 *  Name                 :	High_End_Blinker_Lights
 *  Description          :  Function that receives the High_End_Blinker_Lights Commands
 *  Parameters           :  Input: T_UBYTE lub_Parameter, T_UBYTE lub_On_Time, T_UBYTE lub_Off_Time
 *  Return               :	None
 *  Critical/explanation :  No
 **************************************************************/

void High_End_Blinker_Lights(T_UBYTE lub_Parameter, T_UBYTE lub_On_Time, T_UBYTE lub_Off_Time)
{
	/* Receives blinker lights parameters */
	rub_Parameter=lub_Parameter;
	rub_On_Time=lub_On_Time;
	rub_Off_Time=lub_Off_Time;
	/* Activate the high end blinker light to turn it on  */
	rub_High_End_Flag=ACTIVATED;					
}


/**************************************************************
 *  Name                 :	High_End_Blinker_Lights_Task
 *  Description          :	Function that controls the blinker lights in the High end configuration
 *  Parameters           :  None
 *  Return               :	None
 *  Critical/explanation :  No
 **************************************************************/

void High_End_Blinker_Lights_Task(void)
{
	static T_UBYTE lub_Parameter=BLINKER_HAZARD_OFF;
	static T_UBYTE lub_Turn_Flag=OFF;
	static T_UBYTE lub_Hazard_Flag=DEACTIVATED;
	static T_UBYTE lub_on_off_Flag=ACTIVATED;
	/* Gets the counters of On time and Off time */
	T_UBYTE lub_On_Timer= (T_UBYTE) Get_On_Counter();
	T_UBYTE lub_Off_Timer= (T_UBYTE) Get_Off_Counter();
	/* Checks if the flag was activated to turn on the blinker lights in this mode */
	if(rub_High_End_Flag==ACTIVATED)
	{
		/* Checks the command of the blinker lights */
		switch(lub_Parameter)
		{	
			
			case BLINKER_HAZARD_OFF:
									/* Change the state to the new command */
									lub_Parameter=rub_Parameter;
									break;	
			
			case BLINKER_TURN_OFF: 	
									/* Change the state to the new command */
									lub_Parameter=rub_Parameter;
									break;
							
			case BLINKER_RIGHT: 
									/* checks if the flag is Activated to Turn on the blinker lights */
									if(lub_on_off_Flag == ACTIVATED)
									{
										/* Activates the On counter and checks if the On counter  */
										/* reached the received time  */
										rub_On_Timer_flag=ACTIVATED;
										if(lub_On_Timer >= rub_On_Time)
										{
											/* Deactivetes the On counter and the on/off flag to turn off the blinker lights */
											lub_on_off_Flag=DEACTIVATED;
											rub_On_Timer_flag=DEACTIVATED;
										}
										else
										{
											LED_ON(BL_BL1_R);
											LED_ON(BL_BL2_R);
											LED_ON(BL_BL3_R);
											LED_ON(FL_BL_R);
										}
									}
									/* checks if the flag is Deactivated to Turn off the blinker lights */
									else if(lub_on_off_Flag == DEACTIVATED)
									{
										/* Activates the Off counter and checks if the Off counter  */
										/* reached the received time  */
										rub_Off_Timer_flag=ACTIVATED;
										if(lub_Off_Timer >= rub_Off_Time)
										{
											/* Deactivates the Off counter and Activated the on/off flag */
											/* to turn on the blinker lights */
											rub_Off_Timer_flag=DEACTIVATED;
											lub_on_off_Flag=ACTIVATED;
											/* Checks if the new parameter is different to BLINKER_HAZARD_OFF*/
											/* to change the state machine */
											if(rub_Parameter == BLINKER_HAZARD_OFF)
											{
												/* Do nothing*/
											}
											else
											{
												lub_Parameter=rub_Parameter;	
											}
											/* Checks if the new command is BLINKER_HAZARD to save the turn status*/
											if(lub_Parameter == BLINKER_HAZARD)
											{
												lub_Turn_Flag=RIGHT;
											}
											else
											{
												lub_Turn_Flag=OFF;	
											}
										}
										else
										{
											LED_OFF(BL_BL1_R);
											LED_OFF(BL_BL2_R);
											LED_OFF(BL_BL3_R);
											LED_OFF(FL_BL_R);	
										}								
									}
								
							break;
							
			case BLINKER_LEFT:
									/* checks if the flag is Activated to Turn on the blinker lights */
									if(lub_on_off_Flag == ACTIVATED)
									{
										/* Activates the On counter and checks if the On counter  */
										/* reached the received time  */
										rub_On_Timer_flag=ACTIVATED;
										if(lub_On_Timer >= rub_On_Time)
										{
											lub_on_off_Flag=DEACTIVATED;
											rub_On_Timer_flag=DEACTIVATED;
										}
										else
										{	
											LED_ON(BL_BL1_L);
											LED_ON(BL_BL2_L);
											LED_ON(BL_BL3_L);
											LED_ON(FL_BL_L);
										}
									}
									/* checks if the flag is Deactivated to Turn off the blinker lights */
									else if(lub_on_off_Flag == DEACTIVATED)
									{
										/* Activates the Off counter and checks if the Off counter  */
										/* reached the received time  */
										rub_Off_Timer_flag=ACTIVATED;
										if(lub_Off_Timer >= rub_Off_Time)
										{
											/* Deactivates the Off counter and Activated the on/off flag */
											/* to turn on the blinker lights */
											rub_Off_Timer_flag=DEACTIVATED;
											lub_on_off_Flag=ACTIVATED;
											/* Checks if the new parameter is different to BLINKER_HAZARD_OFF*/
											/* to change the state machine */
											if(rub_Parameter == BLINKER_HAZARD_OFF)
											{
												/* Do nothing*/
											}
											else
											{
												lub_Parameter=rub_Parameter;	
											}
											/* Checks if the new command is BLINKER_HAZARD to save the turn status*/
											if(lub_Parameter == BLINKER_HAZARD)
											{
												lub_Turn_Flag=LEFT;
											}
											else
											{
												lub_Turn_Flag=OFF;	
											}
										}
										else
										{
											LED_OFF(BL_BL1_L);
											LED_OFF(BL_BL2_L);
											LED_OFF(BL_BL3_L);
											LED_OFF(FL_BL_L);	
										}								
									}
							break;
							
			case BLINKER_HAZARD:
									/* checks if the flag is Activated to Turn on the blinker lights */
									if(lub_on_off_Flag == ACTIVATED)
									{
										/* Activates the On counter and checks if the On counter  */
										/* reached the received time  */
										rub_On_Timer_flag=ACTIVATED;
										if(lub_On_Timer >= rub_On_Time)
										{
											lub_on_off_Flag=DEACTIVATED;
											rub_On_Timer_flag=DEACTIVATED;
										}
										else
										{	
											LED_ON(BL_BL1_R);
											LED_ON(BL_BL2_R);
											LED_ON(BL_BL3_R);
											LED_ON(FL_BL_R);
											
											LED_ON(BL_BL1_L);
											LED_ON(BL_BL2_L);
											LED_ON(BL_BL3_L);
											LED_ON(FL_BL_L);
										}
									}
									/* checks if the flag is Deactivated to Turn off the blinker lights */
									else if(lub_on_off_Flag == DEACTIVATED)
									{
										/* Activates the Off counter and checks if the Off counter  */
										/* reached the received time  */
										rub_Off_Timer_flag=ACTIVATED;
										if(lub_Off_Timer >= rub_Off_Time)
										{
											/* Deactivates the Off counter and Activated the on/off flag */
											/* to turn on the blinker lights */
											rub_Off_Timer_flag=DEACTIVATED;
											lub_on_off_Flag=ACTIVATED;
											lub_Parameter=rub_Parameter;
											/* Checks if the new command is BLINKER_HAZARD_OFF to change */
											/* the state machine to the previous state*/
											if(lub_Parameter == BLINKER_HAZARD_OFF)
											{
												/* checks if the flag is left to change the state to BLINKER_LEFT */
												if(lub_Turn_Flag == LEFT)
												{
													lub_Parameter=BLINKER_LEFT;
												}
												/* checks if the flag is right to change the state to BLINKER_RIGHT */
												else if(lub_Turn_Flag == RIGHT)
												{
													lub_Parameter=BLINKER_RIGHT;	
												}
												else
												{
													/* Do nothing */
												}
											}
											/* Checks if the new command is BLINKER_TURN_OFF to change */
											/* the turn flag to off*/
											else if(lub_Parameter == BLINKER_TURN_OFF)
											{
												lub_Turn_Flag=OFF;
											}
											/* Checks if the new command is BLINKER_LEFT to change */
											/* the turn flag to left */
											else if(lub_Parameter == BLINKER_LEFT)
											{
												lub_Turn_Flag=LEFT;
											}
											/* Checks if the new command is BLINKER_RIGHT to change */
											/* the turn flag to RIGHT */
											else if(lub_Parameter == BLINKER_RIGHT)
											{
												lub_Turn_Flag=RIGHT;
											}
											else
											{
												/* Do nothing */
											}
										}
										else
										{
											LED_OFF(BL_BL1_R);
											LED_OFF(BL_BL2_R);
											LED_OFF(BL_BL3_R);
											LED_OFF(FL_BL_R);
											
											LED_OFF(BL_BL1_L);
											LED_OFF(BL_BL2_L);
											LED_OFF(BL_BL3_L);
											LED_OFF(FL_BL_L);	
										}								
									}
							break;
						
		}
	}
	
}


/**************************************************************
 *  Name                 :	Luxury_Blinker_Lights
 *  Description          :	Function that receives the luxury Blinker_Lights Commands
 *  Parameters           :  Input: T_UBYTE lub_Parameter, T_UBYTE lub_On_Time, T_UBYTE lub_Off_Time
 *  Return               :	None
 *  Critical/explanation :  No
 **************************************************************/
void Luxury_Blinker_Lights(T_UBYTE lub_Parameter, T_UBYTE lub_On_Time, T_UBYTE lub_Off_Time)
{
	rub_Parameter=lub_Parameter;
	rub_On_Time=lub_On_Time;
	rub_Off_Time=lub_Off_Time;
	rub_Luxury_Flag=ACTIVATED;
}


/**************************************************************
 *  Name                 :	Luxury_Blinker_Lights_Task
 *  Description          :	Function that controls the blinker lights in the Luxury configuration
 *  Parameters           :  None
 *  Return               :	None
 *  Critical/explanation :  No
 **************************************************************/
void Luxury_Blinker_Lights_Task(void)
{
	static T_UBYTE lub_Parameter;
	static T_UBYTE lub_Turn_Flag=OFF;
	static T_UBYTE lub_Hazard_Flag=DEACTIVATED;
	static T_UBYTE lub_on_off_Flag=ACTIVATED;
	static T_UBYTE lub_Counter=0;
	static T_UBYTE lub_On_Timer_Flag=0;
	/* Gets the counters of On time and Off time */
	T_UBYTE lub_On_Timer= (T_UBYTE) Get_On_Counter();
	T_UBYTE lub_Off_Timer= (T_UBYTE) Get_Off_Counter();
	/* Checks if the flag was activated to turn on the blinker lights in this mode */
	if(rub_Luxury_Flag==ACTIVATED)
	{
		/* Checks the command of the blinker lights */
		switch(lub_Parameter)
		{	
			
			case BLINKER_HAZARD_OFF:
									/* Change the state to the new command */
									lub_Parameter=rub_Parameter;
									break;	
			
			case BLINKER_TURN_OFF: 	
									/* Change the state to the new command */
									lub_Parameter=rub_Parameter;
									break;
							
			case BLINKER_RIGHT: 
									/* checks if the flag is Activated to Turn on the blinker lights */
									if(lub_on_off_Flag == ACTIVATED)
									{
										/* Activates the On counter and checks if the On counter  */
										/* reached the received time to increse the counter */
										if(rub_On_Time==0)
										{
											rub_On_Timer_flag=ACTIVATED;
											lub_On_Timer_Flag=ACTIVATED;	
										}
										else
										{
											/* Do nothing */
										}
										/* Checks if the on counter reached the received time and if it enters for first time */
										if((lub_On_Timer >= rub_On_Time) && (lub_On_Timer_Flag==ACTIVATED))
										{
											/* increse the counter to turn on the leds in a sequence */
											lub_Counter++;
											rub_On_Timer_flag=RESTART;
											lub_On_Timer_Flag=DEACTIVATED;
										}
										else
										{
											/* checks the counter to select which leds will turn on */
											switch(lub_Counter)
											{
												/* Turn on the first led */
												case 0: LED_ON(BL_BL1_R);
														LED_ON(FL_BL_R);
													break;
												/* Turn on the second led */	
												case 1: LED_ON(BL_BL2_R);
														LED_OFF(FL_BL_R);
													break;
												/* Turn on the third led */	
												case 2: LED_ON(BL_BL3_R);
														LED_ON(FL_BL_R);
													break;
												/* Restart the counters */
												case 3: lub_on_off_Flag=DEACTIVATED;
														rub_On_Timer_flag=DEACTIVATED;
														lub_Counter=0;
													break;			
											}
										}
									}
									/* checks if the flag is Deactivated to Turn off the blinker lights */
									else if(lub_on_off_Flag == DEACTIVATED)
									{
										/* Activates the Off counter and checks if the Off counter  */
										/* reached the received time  */
										rub_Off_Timer_flag=ACTIVATED;
										if(lub_Off_Timer >= rub_Off_Time)
										{
											/* Deactivates the Off counter and Activated the on/off flag */
											/* to turn on the blinker lights */
											rub_Off_Timer_flag=DEACTIVATED;
											lub_on_off_Flag=ACTIVATED;
											/* Checks if the new parameter is different to BLINKER_HAZARD_OFF*/
											/* to change the state machine */
											if(rub_Parameter == BLINKER_HAZARD_OFF)
											{
												/* Do nothing*/
											}
											else
											{
												lub_Parameter=rub_Parameter;	
											}
											/* Checks if the new command is BLINKER_HAZARD to save the turn status*/
											if(lub_Parameter == BLINKER_HAZARD)
											{
												lub_Turn_Flag=RIGHT;
											}
											else
											{
												lub_Turn_Flag=OFF;	
											}
										}
										else
										{
											LED_OFF(BL_BL1_R);
											LED_OFF(BL_BL2_R);
											LED_OFF(BL_BL3_R);
											LED_OFF(FL_BL_R);	
										}								
									}
								
							break;
							
			case BLINKER_LEFT:
									/* checks if the flag is Activated to Turn on the blinker lights */
									if(lub_on_off_Flag == ACTIVATED)
									{
										/* Activates the On counter and checks if the On counter  */
										/* reached the received time to increse the counter */
										if(rub_On_Time==0)
										{
											rub_On_Timer_flag=ACTIVATED;
											lub_On_Timer_Flag=ACTIVATED;	
										}
										else
										{
											/* Do nothing */
										}
										/* Checks if the on counter reached the received time and if it enters for first time */
										if((lub_On_Timer >= rub_On_Time) && (lub_On_Timer_Flag==ACTIVATED))
										{
											lub_Counter++;
											rub_On_Timer_flag=RESTART;
											lub_On_Timer_Flag=DEACTIVATED;
										}
										else
										{	
											/* checks the counter to select which leds will turn on */
											switch(lub_Counter)
											{
												/* Turn on the first led */
												case 0:	LED_ON(BL_BL1_L);
														LED_ON(FL_BL_L);
													break;
												/* Turn on the second led */
												case 1:	LED_ON(BL_BL2_L);
														LED_OFF(FL_BL_L);
													break;
												/* Turn on the third led */
												case 2:	LED_ON(BL_BL3_L);
														LED_ON(FL_BL_L);
													break;
												/* Restart the counters */
												case 3:	lub_on_off_Flag=DEACTIVATED;
														rub_On_Timer_flag=DEACTIVATED;
														lub_Counter=0;
													break;			
											}
										}
									}
									/* checks if the flag is Deactivated to Turn off the blinker lights */
									else if(lub_on_off_Flag == DEACTIVATED)
									{
										/* Activates the Off counter and checks if the Off counter  */
										/* reached the received time  */
										rub_Off_Timer_flag=ACTIVATED;
										if(lub_Off_Timer >= rub_Off_Time)
										{
											/* Deactivates the Off counter and Activated the on/off flag */
											/* to turn on the blinker lights */
											rub_Off_Timer_flag=DEACTIVATED;
											lub_on_off_Flag=ACTIVATED;
											/* Checks if the new parameter is different to BLINKER_HAZARD_OFF*/
											/* to change the state machine */
											if(rub_Parameter == BLINKER_HAZARD_OFF)
											{
												/* Do nothing*/
											}
											else
											{
												lub_Parameter=rub_Parameter;	
											}
											/* Checks if the new command is BLINKER_HAZARD to save the turn status*/
											if(lub_Parameter == BLINKER_HAZARD)
											{
												lub_Turn_Flag=LEFT;
											}
											else
											{
												lub_Turn_Flag=OFF;	
											}
										}
										else
										{
											LED_OFF(BL_BL1_L);
											LED_OFF(BL_BL2_L);
											LED_OFF(BL_BL3_L);
											LED_OFF(FL_BL_L);	
										}								
									}
							break;
							
			case BLINKER_HAZARD:
									/* checks if the flag is Activated to Turn on the blinker lights */
									if(lub_on_off_Flag == ACTIVATED)
									{
										/* Activates the On counter and checks if the On counter  */
										/* reached the received time  */
										rub_On_Timer_flag=ACTIVATED;
										if(lub_On_Timer >= rub_On_Time)
										{
											lub_on_off_Flag=DEACTIVATED;
											rub_On_Timer_flag=DEACTIVATED;
										}
										else
										{	
											LED_ON(BL_BL1_R);
											LED_ON(BL_BL2_R);
											LED_ON(BL_BL3_R);
											LED_ON(FL_BL_R);
											
											LED_ON(BL_BL1_L);
											LED_ON(BL_BL2_L);
											LED_ON(BL_BL3_L);
											LED_ON(FL_BL_L);
										}
									}
									/* checks if the flag is Deactivated to Turn off the blinker lights */
									else if(lub_on_off_Flag == DEACTIVATED)
									{
										/* Activates the Off counter and checks if the Off counter  */
										/* reached the received time  */
										rub_Off_Timer_flag=ACTIVATED;
										if(lub_Off_Timer >= rub_Off_Time)
										{
											/* Deactivates the Off counter and Activated the on/off flag */
											/* to turn on the blinker lights */
											rub_Off_Timer_flag=DEACTIVATED;
											lub_on_off_Flag=ACTIVATED;
											lub_Parameter=rub_Parameter;
											/* Checks if the new command is BLINKER_HAZARD_OFF to change */
											/* the state machine to the previous state*/
											if(lub_Parameter == BLINKER_HAZARD_OFF)
											{
												/* checks if the flag is left to change the state to BLINKER_LEFT */
												if(lub_Turn_Flag == LEFT)
												{
													lub_Parameter=BLINKER_LEFT;
												}
												/* checks if the flag is right to change the state to BLINKER_RIGHT */
												else if(lub_Turn_Flag == RIGHT)
												{
													lub_Parameter=BLINKER_RIGHT;	
												}
												else
												{
													/* Do nothing */
												}
											}
											/* Checks if the new command is BLINKER_LEFT to change */
											/* the turn flag to left */
											else if(lub_Parameter == BLINKER_TURN_OFF)
											{
												lub_Turn_Flag=OFF;
											}
											/* Checks if the new command is BLINKER_LEFT to change */
											/* the turn flag to left */
											else if(lub_Parameter == BLINKER_LEFT)
											{
												lub_Turn_Flag=LEFT;
											}
											/* Checks if the new command is BLINKER_RIGHT to change */
											/* the turn flag to RIGHT */
											else if(lub_Parameter == BLINKER_RIGHT)
											{
												lub_Turn_Flag=RIGHT;
											}
											else
											{
												/* Do nothing */
											}
										}
										else
										{
											LED_OFF(BL_BL1_R);
											LED_OFF(BL_BL2_R);
											LED_OFF(BL_BL3_R);
											LED_OFF(FL_BL_R);
											
											LED_OFF(BL_BL1_L);
											LED_OFF(BL_BL2_L);
											LED_OFF(BL_BL3_L);
											LED_OFF(FL_BL_L);	
										}								
									}
							break;
						
		}
	}	
}


/**************************************************************
 *  Name                 :	Standard_Blinker_Lights
 *  Description          :	Function that receives the High_End_Blinker_Lights Commands
 *  Parameters           :  Input: T_UBYTE lub_Parameter, T_UBYTE lub_On_Time, T_UBYTE lub_Off_Time
 *  Return               :	None
 *  Critical/explanation :  No
 **************************************************************/
void Standard_Blinker_Lights(T_UBYTE lub_Parameter, T_UBYTE lub_On_Time, T_UBYTE lub_Off_Time)
{
	/* Receives blinker lights parameters */
	rub_Parameter=lub_Parameter;
	rub_On_Time=lub_On_Time;
	rub_Off_Time=lub_Off_Time;
	/* Activate the high end blinker light to turn it on  */
	rub_Standard_Flag=ACTIVATED;		
}


/**************************************************************
 *  Name                 :	Standard_Blinker_Lights_Task
 *  Description          :	Function that controls the blinker lights in the Standard configuration
 *  Parameters           :  None
 *  Return               :	None
 *  Critical/explanation :  No
 **************************************************************/
void Standard_Blinker_Lights_Task(void)
{
	static T_UBYTE lub_Parameter;
	static T_UBYTE lub_Turn_Flag=OFF;
	static T_UBYTE lub_Hazard_Flag=DEACTIVATED;
	static T_UBYTE lub_on_off_Flag=ACTIVATED;
	/* Gets the counters of On time and Off time */
	T_UBYTE lub_On_Timer= (T_UBYTE) Get_On_Counter();
	T_UBYTE lub_Off_Timer= (T_UBYTE) Get_Off_Counter();
	/* Checks if the flag was activated to turn on the blinker lights in this mode */
	if(rub_Standard_Flag==ACTIVATED)
	{
		/* Checks the command of the blinker lights */
		switch(lub_Parameter)
		{	
			
			case BLINKER_HAZARD_OFF:
									/* Change the state to the new command */
									lub_Parameter=rub_Parameter;
									break;	
			
			case BLINKER_TURN_OFF: 	
									/* Change the state to the new command */
									lub_Parameter=rub_Parameter;
									break;
							
			case BLINKER_RIGHT: 
									/* checks if the flag is Activated to Turn on the blinker lights */
									if(lub_on_off_Flag == ACTIVATED)
									{
										/* Activates the On counter and checks if the On counter  */
										/* reached the received time  */
										rub_On_Timer_flag=ACTIVATED;
										if(lub_On_Timer >= rub_On_Time)
										{
											/* Deactivetes the On counter and the on/off flag to turn off the blinker lights */
											lub_on_off_Flag=DEACTIVATED;
											rub_On_Timer_flag=DEACTIVATED;
										}
										else
										{
											LED_ON(BL_BL1_R);
											LED_ON(BL_BL2_R);
											LED_ON(BL_BL3_R);
											LED_ON(FL_DAYBL_R);
										}
									}
									/* checks if the flag is Deactivated to Turn off the blinker lights */
									else if(lub_on_off_Flag == DEACTIVATED)
									{
										/* Activates the Off counter and checks if the Off counter  */
										/* reached the received time  */
										rub_Off_Timer_flag=ACTIVATED;
										if(lub_Off_Timer >= rub_Off_Time)
										{
											/* Deactivates the Off counter and Activated the on/off flag */
											/* to turn on the blinker lights */
											rub_Off_Timer_flag=DEACTIVATED;
											lub_on_off_Flag=ACTIVATED;
											/* Checks if the new parameter is different to BLINKER_HAZARD_OFF*/
											/* to change the state machine */
											if(rub_Parameter == BLINKER_HAZARD_OFF)
											{
												/* Do nothing*/
											}
											else
											{
												lub_Parameter=rub_Parameter;	
											}
											/* Checks if the new command is BLINKER_HAZARD to save the turn status*/
											if(lub_Parameter == BLINKER_HAZARD)
											{
												lub_Turn_Flag=RIGHT;
											}
											else
											{
												lub_Turn_Flag=OFF;	
											}
										}
										else
										{
											LED_OFF(BL_BL1_R);
											LED_OFF(BL_BL2_R);
											LED_OFF(BL_BL3_R);
											LED_OFF(FL_DAYBL_R);	
										}								
									}
								
							break;
							
			case BLINKER_LEFT:
									/* checks if the flag is Activated to Turn on the blinker lights */
									if(lub_on_off_Flag == ACTIVATED)
									{
										/* Activates the On counter and checks if the On counter  */
										/* reached the received time  */
										rub_On_Timer_flag=ACTIVATED;
										if(lub_On_Timer >= rub_On_Time)
										{
											lub_on_off_Flag=DEACTIVATED;
											rub_On_Timer_flag=DEACTIVATED;
										}
										else
										{	
											LED_ON(BL_BL1_L);
											LED_ON(BL_BL2_L);
											LED_ON(BL_BL3_L);
											LED_ON(FL_DAYBL_L);
										}
									}
									/* checks if the flag is Deactivated to Turn off the blinker lights */
									else if(lub_on_off_Flag == DEACTIVATED)
									{
										/* Activates the Off counter and checks if the Off counter  */
										/* reached the received time  */
										rub_Off_Timer_flag=ACTIVATED;
										if(lub_Off_Timer >= rub_Off_Time)
										{
											/* Deactivates the Off counter and Activated the on/off flag */
											/* to turn on the blinker lights */
											rub_Off_Timer_flag=DEACTIVATED;
											lub_on_off_Flag=ACTIVATED;
											/* Checks if the new parameter is different to BLINKER_HAZARD_OFF*/
											/* to change the state machine */
											if(rub_Parameter == BLINKER_HAZARD_OFF)
											{
												/* Do nothing*/
											}
											else
											{
												lub_Parameter=rub_Parameter;	
											}
											/* Checks if the new command is BLINKER_HAZARD to save the turn status*/
											if(lub_Parameter == BLINKER_HAZARD)
											{
												lub_Turn_Flag=LEFT;
											}
											else
											{
												lub_Turn_Flag=OFF;	
											}
										}
										else
										{
											LED_OFF(BL_BL1_L);
											LED_OFF(BL_BL2_L);
											LED_OFF(BL_BL3_L);
											LED_OFF(FL_DAYBL_L);	
										}								
									}
							break;
							
			case BLINKER_HAZARD:
									/* checks if the flag is Activated to Turn on the blinker lights */
									if(lub_on_off_Flag == ACTIVATED)
									{
										/* Activates the On counter and checks if the On counter  */
										/* reached the received time  */
										rub_On_Timer_flag=ACTIVATED;
										if(lub_On_Timer >= rub_On_Time)
										{
											lub_on_off_Flag=DEACTIVATED;
											rub_On_Timer_flag=DEACTIVATED;
										}
										else
										{	
											LED_ON(BL_BL1_R);
											LED_ON(BL_BL2_R);
											LED_ON(BL_BL3_R);
											LED_ON(FL_DAYBL_R);
											
											LED_ON(BL_BL1_L);
											LED_ON(BL_BL2_L);
											LED_ON(BL_BL3_L);
											LED_ON(FL_DAYBL_L);
										}
									}
									/* checks if the flag is Deactivated to Turn off the blinker lights */
									else if(lub_on_off_Flag == DEACTIVATED)
									{
										/* Activates the Off counter and checks if the Off counter  */
										/* reached the received time  */									
										rub_Off_Timer_flag=ACTIVATED;
										if(lub_Off_Timer >= rub_Off_Time)
										{
											/* Deactivates the Off counter and Activated the on/off flag */
											/* to turn on the blinker lights */
											rub_Off_Timer_flag=DEACTIVATED;
											lub_on_off_Flag=ACTIVATED;
											lub_Parameter=rub_Parameter;
											/* Checks if the new command is BLINKER_HAZARD_OFF to change */
											/* the state machine to the previous state*/
											if(lub_Parameter == BLINKER_HAZARD_OFF)
											{
												/* checks if the flag is left to change the state to BLINKER_LEFT */
												if(lub_Turn_Flag == LEFT)
												{
													lub_Parameter=BLINKER_LEFT;
												}
												/* checks if the flag is right to change the state to BLINKER_RIGHT */
												else if(lub_Turn_Flag == RIGHT)
												{
													lub_Parameter=BLINKER_LEFT;	
												}
												else
												{
													/* Do nothing */
												}
											}
											/* Checks if the new command is BLINKER_TURN_OFF to change */
											/* the turn flag to off*/
											else if(lub_Parameter == BLINKER_TURN_OFF)
											{
												lub_Turn_Flag=OFF;
											}
											/* Checks if the new command is BLINKER_LEFT to change */
											/* the turn flag to left */
											else if(lub_Parameter == BLINKER_LEFT)
											{
												lub_Turn_Flag=LEFT;
											}
											/* Checks if the new command is BLINKER_RIGHT to change */
											/* the turn flag to RIGHT */
											else if(lub_Parameter == BLINKER_RIGHT)
											{
												lub_Turn_Flag=RIGHT;
											}
											else
											{
												/* Do nothing */
											}
										}
										else
										{
											LED_OFF(BL_BL1_R);
											LED_OFF(BL_BL2_R);
											LED_OFF(BL_BL3_R);
											LED_OFF(FL_DAYBL_R);
											
											LED_OFF(BL_BL1_L);
											LED_OFF(BL_BL2_L);
											LED_OFF(BL_BL3_L);
											LED_OFF(FL_DAYBL_L);	
										}								
									}
							break;
						
		}
	}	
}


/**************************************************************
 *  Name                 :	Standard_Day_lights
 *  Description          :	Function that control the Day ligths in the Satandard configuration
 *  Parameters           :  Input: T_UBYTE lub_On_Off receives On, Off command
 *  Return               :	None
 *  Critical/explanation :  No
 **************************************************************/
void Standard_Day_lights(T_UBYTE lub_On_Off)
{
	/* if the command is ACTIVATED Turn the Standard day lights on  */
	/* and activates rub_Standard_DayL_Flag to control the stop lights */
	if(lub_On_Off == ACTIVATED)
	{
			
		rub_Standard_DayL_Flag=ACTIVATED;
		LED_ON(FL_DAYL_R);
		LED_ON(FL_DAYL_L);
		
		LED_ON(BL_DAYSL_R);
		LED_ON(BL_DAYSL_R);
	}
	/* if the command is DEACTIVATED Turn the Standard day lights off  */
	else if(lub_On_Off == DEACTIVATED)
	{
		/* and deactivates rub_Standard_DayL_Flag to control the stop lights */
		rub_Standard_DayL_Flag=DEACTIVATED;
		LED_OFF(FL_DAYL_R);
		LED_OFF(FL_DAYL_L);
		
		LED_OFF(BL_DAYSL_R);
		LED_OFF(BL_DAYSL_R);
	}
	else
	{
		/* Do nothing */
	}		
}


/**************************************************************
 *  Name                 :	Stop_Lights
 *  Description          :	Function that control the Stop ligths in High end and luxury configurations
 *  Parameters           :  Input: T_UBYTE lub_On_Off receives On, Off command
 *  Return               :	None
 *  Critical/explanation :  No
 **************************************************************/

 void Stop_Lights(T_UBYTE lub_On_Off)
 {
	/* if the command is ACTIVATED Turn the Stop lights on  */
	if(lub_On_Off == ACTIVATED)
	{
		LED_ON(BL_STOPL_R);
 		LED_ON(BL_STOPL_L);
	}
	/* if the command is DEACTIVATED Turn the Stop lights off  */
	else if(lub_On_Off == DEACTIVATED)
	{
		LED_OFF(BL_STOPL_R);
 		LED_OFF(BL_STOPL_L);
	}
	else
	{
		/* Do nothing */
	}
 }
 
 
/**************************************************************
 *  Name                 :	Standard_Stop_Lights
 *  Description          :	Function that control the Stop ligths in Standard configuration
 *  Parameters           :  Input: T_UBYTE lub_On_Off receives On, Off command
 *  Return               :	none
 *  Critical/explanation :  No
 **************************************************************/
 
 void Standard_Stop_Lights(T_UBYTE lub_On_Off)
 {
 	/* if the command is ACTIVATED Turn the Stop lights on  */
 	if(lub_On_Off == ACTIVATED)
	{
		LED_ON(BL_STOPL_R);
 		LED_ON(BL_STOPL_L);
 		/* if the Day lights flag is ACTIVATED it turn day lights off */
 		if(rub_Standard_DayL_Flag == ACTIVATED)
 		{
 			LED_OFF(BL_DAYSL_R);
 			LED_OFF(BL_DAYSL_L);
 		}
 		else
 		{
 			/* Do nothing */
 		}	
	}
	/* if the command is DEACTIVATED Turn the Stop lights off  */
	else if(lub_On_Off == DEACTIVATED)
	{
		LED_OFF(BL_STOPL_R);
 		LED_OFF(BL_STOPL_L);
 		/* if the Day lights flag is ACTIVATED it turn day lights on */
 		if(rub_Standard_DayL_Flag == ACTIVATED)
 		{
 			LED_ON(BL_DAYSL_R);
 			LED_ON(BL_DAYSL_L);
 		}
	}
	else
	{
		/* Do nothing */
	}
 }


/**************************************************************
 *  Name                 :	TurnOnOff_OnTimer
 *  Description          :	Return the flag to activate the on counter
 *  Parameters           :  None
 *  Return               :	rub_On_Timer_flag
 *  Critical/explanation :  No
 **************************************************************/

T_UBYTE TurnOnOff_OnTimer(void)
{
	return rub_On_Timer_flag;
}


/**************************************************************
 *  Name                 :	TurnOnOff_OffTimer
 *  Description          :	Return the flag to activate the on counter
 *  Parameters           :  None
 *  Return               :	rub_Off_Timer_flag
 *  Critical/explanation :  No
 **************************************************************/

T_UBYTE TurnOnOff_OffTimer(void)
{
	return rub_Off_Timer_flag;
}