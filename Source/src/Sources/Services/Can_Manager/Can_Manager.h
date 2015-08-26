/*~A*/
/*~+:Module Header*/
/*******************************************************************************/
/**
\file       Can_Manager.h
\brief      Provide Can Services
\author     Francisco Martinez
\version    1.0
\date       16/08/2015
*/
/*******************************************************************************/
/*~E*/
#ifndef __CAN_MANAGER
#define __CAN_MANAGER
/*~A*/
/*~+:Imports*/
#include "Can.h"
/*~E*/
/*~A*/
/*~+:Exported Interfaces*/
extern void Can_Manager_PduHandler0(CAN_MessageDataType CanMessage);
extern void Can_Manager_PduHandler6(CAN_MessageDataType CanMessage);
extern void CanManager_SendMessage_12p5ms(void);
extern void CanManager_SendMessage_25ms(void);
extern void Can_Manager_PduHandler0(CAN_MessageDataType CanMessage);
extern void Security_Seed(void);
extern void RX_Security_Access_Response(CAN_MessageDataType CanMessage);

extern void Tests(void);
/*~E*/
#endif /* __CAN_MANAGER */
