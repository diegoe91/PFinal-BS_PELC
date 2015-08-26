/*~A*/
/*~+:Module Header*/
/*******************************************************************************/
/**
\file       Can_Manager.c
\brief      Provide Can Services
\author     Francisco Martinez
\version    1.0
\date       16/08/2015
*/
/*******************************************************************************/
/*~E*/
/*~A*/
/*~+:Import*/
#include "Can_Manager.h"
#include "GPIO.h"
/*~E*/
/*~A*/
/*~+:Defines*/

/*~E*/
/*~A*/
/*~+:Variables*/
struct CanTest
{
	uint8_t     can_test_enable;
}CanTestStruct;
/* Temporary CAN Messages */
uint8_t dummy_msg0[8] = {0xCA,0x83,0x15,0x77,0x19,0x56,0x65,0x00};
uint8_t dummy_msg1[8] = {0x00,0x65,0x56,0x19,0x77,0x15,0x83,0xCA};
uint8_t dummy_msg2[2] = {0x01, 0x27};
uint8_t dummy_msg3[8] = {0x06, 0x27, 0x00,0x00,0x00,0x00,0x00,0x00};
CAN_PduType    pdu_handler4 = { 4, 8, dummy_msg0};
CAN_PduType    pdu_handler5 = { 1, 6, dummy_msg1};
CAN_PduType    pdu_handler6 = { 4, 2, dummy_msg2};
CAN_PduType    pdu_handler7 = { 6, 8, dummy_msg3};
CAN_PduType    pdu_handler1 = { 7, 1, dummy_msg2};
uint32_t PduHandlerCnt0 = 0;
uint32_t PduHandlerCnt6 = 0;
uint8_t SecurityAccessFlag=0;
uint8_t ResponceFlag=0;
/*~E*/
/*~A*/
/*~+:Private Operations*/

/*~E*/
/*~A*/
/*~+:Public Operations*/
/*~A*/
/*~+:Can Manager Callbacks*/
CAN_MessageDataType CanMessage_PduHandler0;
CAN_MessageDataType CanMessage_PduHandler3;
CAN_MessageDataType CanMessage_PduHandler6;
void Can_Manager_PduHandler0(CAN_MessageDataType CanMessage)
{
	CanMessage_PduHandler0 = CanMessage;
	CAN_SendFrame(pdu_handler1);
	PduHandlerCnt0++;
}

void Security_Seed(void)
{
	uint8_t i=0;
	uint8_t suma_resta=1;
	if(SecurityAccessFlag==1)
	{	
		for(i=2; i<8; i++)
		{
			
			if(suma_resta == 1)
			{
				dummy_msg3[i]=CanMessage_PduHandler3.msg_data_field[i]+1;
				suma_resta=0;		
			}
			else
			{
				dummy_msg3[i]=CanMessage_PduHandler3.msg_data_field[i]-1;
				suma_resta=1;
			}
		}
		SecurityAccessFlag=0;
		ResponceFlag=1;
	}
}

void RX_Security_Access_Response(CAN_MessageDataType CanMessage)
{
	CanMessage_PduHandler3 = CanMessage;
	SecurityAccessFlag=1;
	LED_ON(LED2);
}

void Can_Manager_PduHandler6(CAN_MessageDataType CanMessage)
{
	CanMessage_PduHandler6 = CanMessage;
	PduHandlerCnt6++;
}
/*~E*/
/*~A*/
/*~+:Can Manager Periodic Functions*/
/*~A*/
/*~+:CanManager_SendMesage_12p5ms*/
void CanManager_SendMessage_12p5ms(void)
{
	if(ResponceFlag==1)
	{
		CAN_SendFrame(pdu_handler7);
		ResponceFlag=0;
	}
}
/*~E*/
/*~A*/
uint8_t ButtonPressFlag=0;
/*~+:CanManager_SendMesage_25ms*/
void CanManager_SendMessage_25ms(void)
{
	if(BUTTON_PRESS(BUTTON4) == 1)
	{
		if(ButtonPressFlag==0)
		{
			ButtonPressFlag=1;
			CAN_SendFrame(pdu_handler6);
			LED_ON(LED1);	
		}
			
	}
	else
	{
		ButtonPressFlag=0;
		LED_OFF(LED1);
	}	
}

void Tests(void)
{
//	CAN_SendFrame(pdu_handler6);
}
/*~E*/
/*~E*/
/*~E*/
