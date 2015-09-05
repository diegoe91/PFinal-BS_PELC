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
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void Day_Lights(T_UBYTE lub_On_Off)
{
	if(lub_On_Off == ACTIVATED)
	{
		LED_ON(FL_DAYL_R);
		LED_ON(FL_DAYL_L);
		
		LED_ON(BL_DAYL_R);
		LED_ON(BL_DAYL_L);
	}
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

/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void Low_Beam_Lights(T_UBYTE lub_On_Off)
{
	if(lub_On_Off == ACTIVATED)
	{
		LED_ON(FL_LBL_R);
		LED_ON(FL_LBL_L);
	}
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

/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void High_End_Blinker_Lights(T_UBYTE lub_Parameter, T_UBYTE lub_On_Time, T_UBYTE lub_Off_Time)
{
	rub_Parameter=lub_Parameter;
	rub_On_Time=lub_On_Time;
	rub_Off_Time=lub_Off_Time;
	rub_High_End_Flag=ACTIVATED;					
}
/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void High_End_Blinker_Lights_Task(void)
{
	static T_UBYTE lub_Parameter;
	static T_UBYTE lub_Turn_Flag=OFF;
	static T_UBYTE lub_Hazard_Flag=DEACTIVATED;
	static T_UBYTE lub_on_off_Flag=ACTIVATED;
	T_UBYTE lub_On_Timer= (T_UBYTE) Get_On_Counter();
	T_UBYTE lub_Off_Timer= (T_UBYTE) Get_Off_Counter();
	if(rub_High_End_Flag==ACTIVATED)
	{
		lub_On_Timer++;
		lub_Off_Timer++;
		switch(lub_Parameter)
		{	
			
			case BLINKER_HAZARD_OFF:
									lub_Parameter=rub_Parameter;
									break;	
			
			case BLINKER_TURN_OFF: 	
									lub_Parameter=rub_Parameter;
									break;
							
			case BLINKER_RIGHT: 
									
									if(lub_on_off_Flag == ACTIVATED)
									{
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
										}
									}
									else if(lub_on_off_Flag == DEACTIVATED)
									{
										rub_Off_Timer_flag=ACTIVATED;
										if(lub_Off_Timer >= rub_Off_Time)
										{
											rub_Off_Timer_flag=DEACTIVATED;
											lub_on_off_Flag=ACTIVATED;
											lub_Parameter=rub_Parameter;
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
									
									if(lub_on_off_Flag == ACTIVATED)
									{
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
									else if(lub_on_off_Flag == DEACTIVATED)
									{
										rub_Off_Timer_flag=ACTIVATED;
										if(lub_Off_Timer >= rub_Off_Time)
										{
											rub_Off_Timer_flag=DEACTIVATED;
											lub_on_off_Flag=ACTIVATED;
											lub_Parameter=rub_Parameter;
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
									if(lub_on_off_Flag == ACTIVATED)
									{
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
									else if(lub_on_off_Flag == DEACTIVATED)
									{
										rub_Off_Timer_flag=ACTIVATED;
										if(lub_Off_Timer >= rub_Off_Time)
										{
											rub_Off_Timer_flag=DEACTIVATED;
											lub_on_off_Flag=ACTIVATED;
											lub_Parameter=rub_Parameter;
											if(lub_Parameter == BLINKER_HAZARD_OFF)
											{
												if(lub_Turn_Flag == LEFT)
												{
													lub_Parameter=BLINKER_LEFT;
												}
												else if(lub_Turn_Flag == RIGHT)
												{
													lub_Parameter=BLINKER_LEFT;	
												}
												else
												{
													/* Do nothing */
												}
											}
											else if(lub_Parameter == BLINKER_TURN_OFF)
											{
												lub_Turn_Flag=OFF;
											}
											else if(lub_Parameter == BLINKER_LEFT)
											{
												lub_Turn_Flag=LEFT;
											}
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


/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void Luxury_Blinker_Lights(T_UBYTE lub_Parameter, T_UBYTE lub_On_Time, T_UBYTE lub_Off_Time)
{
	rub_Parameter=lub_Parameter;
	rub_On_Time=lub_On_Time;
	rub_Off_Time=lub_Off_Time;
	rub_Luxury_Flag=ACTIVATED;
}

/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void Luxury_Blinker_Lights_Task(void)
{
	static T_UBYTE lub_Parameter;
	static T_UBYTE lub_Turn_Flag=OFF;
	static T_UBYTE lub_Hazard_Flag=DEACTIVATED;
	static T_UBYTE lub_on_off_Flag=ACTIVATED;
	static T_UBYTE lub_Counter=0;
	T_UBYTE lub_On_Timer= (T_UBYTE) Get_On_Counter();
	T_UBYTE lub_Off_Timer= (T_UBYTE) Get_Off_Counter();
	if(rub_Luxury_Flag==ACTIVATED)
	{
		lub_On_Timer++;
		lub_Off_Timer++;
		switch(lub_Parameter)
		{	
			
			case BLINKER_HAZARD_OFF:
									lub_Parameter=rub_Parameter;
									break;	
			
			case BLINKER_TURN_OFF: 	
									lub_Parameter=rub_Parameter;
									break;
							
			case BLINKER_RIGHT: 
									
									if(lub_on_off_Flag == ACTIVATED)
									{
										rub_On_Timer_flag=ACTIVATED;
										if(lub_On_Timer >= rub_On_Time)
										{
											lub_Counter++;
										}
										else
										{
											switch(lub_Counter)
											{
												case 0: LED_ON(BL_BL1_R);
														LED_ON(FL_BL_R);
													break;
												case 1: LED_ON(BL_BL2_R);
														LED_OFF(FL_BL_R);
													break;
												case 2: LED_ON(BL_BL3_R);
														LED_ON(FL_BL_R);
													break;
												case 3: lub_on_off_Flag=DEACTIVATED;
														rub_On_Timer_flag=DEACTIVATED;
														lub_Counter=0;
													break;			
											}
										}
									}
									else if(lub_on_off_Flag == DEACTIVATED)
									{
										rub_Off_Timer_flag=ACTIVATED;
										if(lub_Off_Timer >= rub_Off_Time)
										{
											rub_Off_Timer_flag=DEACTIVATED;
											lub_on_off_Flag=ACTIVATED;
											lub_Parameter=rub_Parameter;
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
									
									if(lub_on_off_Flag == ACTIVATED)
									{
										rub_On_Timer_flag=ACTIVATED;
										if(lub_On_Timer >= rub_On_Time)
										{
											lub_Counter++;
										}
										else
										{	
											switch(lub_Counter)
											{
												case 0:	LED_ON(BL_BL1_L);
														LED_ON(FL_BL_L);
													break;
												case 1:	LED_ON(BL_BL2_L);
														LED_OFF(FL_BL_L);
													break;
												case 2:	LED_ON(BL_BL3_L);
														LED_ON(FL_BL_L);
													break;
												case 3:	lub_on_off_Flag=DEACTIVATED;
														rub_On_Timer_flag=DEACTIVATED;
														lub_Counter=0;
													break;			
											}
										}
									}
									else if(lub_on_off_Flag == DEACTIVATED)
									{
										rub_Off_Timer_flag=ACTIVATED;
										if(lub_Off_Timer >= rub_Off_Time)
										{
											rub_Off_Timer_flag=DEACTIVATED;
											lub_on_off_Flag=ACTIVATED;
											lub_Parameter=rub_Parameter;
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
									if(lub_on_off_Flag == ACTIVATED)
									{
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
									else if(lub_on_off_Flag == DEACTIVATED)
									{
										rub_Off_Timer_flag=ACTIVATED;
										if(lub_Off_Timer >= rub_Off_Time)
										{
											rub_Off_Timer_flag=DEACTIVATED;
											lub_on_off_Flag=ACTIVATED;
											lub_Parameter=rub_Parameter;
											if(lub_Parameter == BLINKER_HAZARD_OFF)
											{
												if(lub_Turn_Flag == LEFT)
												{
													lub_Parameter=BLINKER_LEFT;
												}
												else if(lub_Turn_Flag == RIGHT)
												{
													lub_Parameter=BLINKER_LEFT;	
												}
												else
												{
													/* Do nothing */
												}
											}
											else if(lub_Parameter == BLINKER_TURN_OFF)
											{
												lub_Turn_Flag=OFF;
											}
											else if(lub_Parameter == BLINKER_LEFT)
											{
												lub_Turn_Flag=LEFT;
											}
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

/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void Standard_Blinker_Lights(T_UBYTE lub_Parameter, T_UBYTE lub_On_Time, T_UBYTE lub_Off_Time)
{
	rub_Parameter=lub_Parameter;
	rub_On_Time=lub_On_Time;
	rub_Off_Time=lub_Off_Time;
	rub_Standard_Flag=ACTIVATED;		
}

/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void Standard_Blinker_Lights_Task(void)
{
	static T_UBYTE lub_Parameter;
	static T_UBYTE lub_Turn_Flag=OFF;
	static T_UBYTE lub_Hazard_Flag=DEACTIVATED;
	static T_UBYTE lub_on_off_Flag=ACTIVATED;
	T_UBYTE lub_On_Timer= (T_UBYTE) Get_On_Counter();
	T_UBYTE lub_Off_Timer= (T_UBYTE) Get_Off_Counter();
	if(rub_Standard_Flag==ACTIVATED)
	{
		lub_On_Timer++;
		lub_Off_Timer++;
		switch(lub_Parameter)
		{	
			
			case BLINKER_HAZARD_OFF:
									lub_Parameter=rub_Parameter;
									break;	
			
			case BLINKER_TURN_OFF: 	
									lub_Parameter=rub_Parameter;
									break;
							
			case BLINKER_RIGHT: 
									
									if(lub_on_off_Flag == ACTIVATED)
									{
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
										}
									}
									else if(lub_on_off_Flag == DEACTIVATED)
									{
										rub_Off_Timer_flag=ACTIVATED;
										if(lub_Off_Timer >= rub_Off_Time)
										{
											rub_Off_Timer_flag=DEACTIVATED;
											lub_on_off_Flag=ACTIVATED;
											lub_Parameter=rub_Parameter;
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
									
									if(lub_on_off_Flag == ACTIVATED)
									{
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
									else if(lub_on_off_Flag == DEACTIVATED)
									{
										rub_Off_Timer_flag=ACTIVATED;
										if(lub_Off_Timer >= rub_Off_Time)
										{
											rub_Off_Timer_flag=DEACTIVATED;
											lub_on_off_Flag=ACTIVATED;
											lub_Parameter=rub_Parameter;
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
									if(lub_on_off_Flag == ACTIVATED)
									{
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
									else if(lub_on_off_Flag == DEACTIVATED)
									{
										rub_Off_Timer_flag=ACTIVATED;
										if(lub_Off_Timer >= rub_Off_Time)
										{
											rub_Off_Timer_flag=DEACTIVATED;
											lub_on_off_Flag=ACTIVATED;
											lub_Parameter=rub_Parameter;
											if(lub_Parameter == BLINKER_HAZARD_OFF)
											{
												if(lub_Turn_Flag == LEFT)
												{
													lub_Parameter=BLINKER_LEFT;
												}
												else if(lub_Turn_Flag == RIGHT)
												{
													lub_Parameter=BLINKER_LEFT;	
												}
												else
												{
													/* Do nothing */
												}
											}
											else if(lub_Parameter == BLINKER_TURN_OFF)
											{
												lub_Turn_Flag=OFF;
											}
											else if(lub_Parameter == BLINKER_LEFT)
											{
												lub_Turn_Flag=LEFT;
											}
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
/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void Standard_Day_lights(T_UBYTE lub_On_Off)
{
	
	if(lub_On_Off == ACTIVATED)
	{
		rub_Standard_DayL_Flag=ACTIVATED;
		LED_ON(FL_DAYL_R);
		LED_ON(FL_DAYL_L);
		
		LED_ON(BL_DAYSL_R);
		LED_ON(BL_DAYSL_R);
	}
	else if(lub_On_Off == DEACTIVATED)
	{
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

/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 void Stop_Lights(T_UBYTE lub_On_Off)
 {
	if(lub_On_Off == ACTIVATED)
	{
		LED_ON(BL_STOPL_R);
 		LED_ON(BL_STOPL_L);
	}
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
 
 /* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 void Standard_Stop_Lights(T_UBYTE lub_On_Off)
 {
 	if(lub_On_Off == ACTIVATED)
	{
		LED_ON(BL_STOPL_R);
 		LED_ON(BL_STOPL_L);
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
	else if(lub_On_Off == DEACTIVATED)
	{
		LED_OFF(BL_STOPL_R);
 		LED_OFF(BL_STOPL_L);
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

/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
T_UBYTE TurnOnOff_OnTimer(void)
{
	return rub_On_Timer_flag;
}

/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
T_UBYTE TurnOnOff_OffTimer(void)
{
	return rub_Off_Timer_flag;
}