/*~A*/
/*~+:Module Header*/
/*******************************************************************************/
/**
\file       SchM_Tasks.c
\brief      Application Tasks
\author     Francisco Martinez
\version    1.0
\date       08/07/2015
*/
/*******************************************************************************/
/*~E*/
/*~A*/
/*~+:Import*/
#include "SchM_Tasks.h"
#include "Can_Manager.h"
#include "Light_Sensor.h"
#include "ADC.h"
#include "mssg_decoder.h"
#include "timer.h"


/*~E*/
/*~A*/
/*~+:Scheduler Tasks*/
/*~A*/
/*~+:SchM_3p125ms_Task*/

void SchM_3p125ms_Task(void)
{
	Door_Debounce();	
		
}
/*~E*/
/*~A*/
/*~+:SchM_6p25ms_Task*/

void SchM_6p25ms_Task(void)
{
	High_End_Blinker_Lights_Task();
	Luxury_Blinker_Lights_Task();
	Standard_Blinker_Lights_Task();
	Main_Ligths_Auto_Mode();
}
/*~E*/
/*~A*/
/*~+:SchM_12p5ms_Task*/

void SchM_12p5ms_Task(void)
{
	Decryption_Command();
}
/*~E*/
/*~A*/
/*~+:SchM_25ms_Task*/

void SchM_25ms_Task(void)
{
	lights_control_SM();
}
/*~E*/
/*~A*/
/*~+:SchM_50ms_Task*/

void SchM_50ms_Task(void)
{
	ADC_Convertion();
	Light_Thresholds();
}
/*~E*/
/*~A*/
/*~+:SchM_100ms_Task*/

void SchM_100ms_Task(void)
{
	Off_Counter();
	On_Counter();
	Message_decoder();
	CAN_SendMessage_100ms();
}
/*~E*/
/*~E*/
