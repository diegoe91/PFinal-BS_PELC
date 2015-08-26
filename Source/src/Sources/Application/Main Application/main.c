/*~A*/
/*~+:Import*/
#include    "GPIO.h"
#include    "PIT.h"
#include    "bspi.h"
#include    "MemAlloc_Cfg.h"
#include    "SchM_Cfg.h"
#include    "Can.h"
#include    "Can_Cfg.h"
#include    "sysinit.h"
/*~E*/
/*~A*/
/*~+:Main Code*/
int main(void) 

{
/* Mode initializations */
sysinit_InitMode();
/* Clock initializations */
sysinit_InitSysClock();
/* Memory Allcoation Initialization */
	MemAllocInit(&MemAllocConfig);
	/*Initialize LEDs on TRK-MPC560xB board */
	vfnGPIO_LED_Init(); 
/* SBC dependencies */
	    InitDSPI_1();
	    ConfigureMZC33905DSPI_1();
/* CAN Initialization */
CAN_Initialization(&can_driver_config);
	/* Initialize Interrupts */
	INTC_InitINTCInterrupts();
	/*Initialize Exception Handlers */
	EXCEP_InitExceptionHandlers();
	/* SchM Initialization */
	SchM_Init(&SchMConfig);
    /* Enable External Interrupts*/
    enableIrq();
    /* SchM Start */
    SchM_Start();
	/* Infinite loop - Should never reach this point */
	for (;;) 
	{

	}
}
/*~E*/
