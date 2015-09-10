/*******************************************************************************/
/**
\file       GPIO.c
\brief      General purpose IO functions
\author     Abraham Tezmol
\version    1.0
\date       31/10/2008
*/
/****************************************************************************************************/

/*****************************************************************************************************
* Include files
*****************************************************************************************************/

/** Core modules */
/** MCU derivative information */
#include "MCU_derivative.h"
/** Variable types and common definitions */
#include "typedefs.h"

/** Own headers */
/* GPIO routines prototypes */ 
#include "GPIO.h"

/** Used modules */


/*****************************************************************************************************
* Definition of module wide VARIABLEs 
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of module wide FUNCTIONs 
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide MACROs / #DEFINE-CONSTANTs 
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of module wide TYPEs 
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide (CONST-) CONSTANTs 
*****************************************************************************************************/

/*****************************************************************************************************
* Code of module wide FUNCTIONS
*****************************************************************************************************/


/****************************************************************************************************/
/**
* \brief    Configures individual GPIO pins to either input or output functionality.  
* \author   Abraham Tezmol
* \param    uint8_t channel - GPIO channel to be configured
* \param    uint8_t input_output - selection of input/output functionality (has impact on output impedance selection)
* \param    uint8_t Open_drain - Push pull or open drain selection modes 
* \return   void
*/

void vfnGPIO_Init_channel(uint8_t channel, uint8_t input_output, uint8_t Open_drain)
{
    if (input_output == GPIO_OUTPUT)
    {
    	SIU.PCR[channel].B.PA  = 0;  				/* GPIO */
    	SIU.PCR[channel].B.OBE = 1;					/* Output buffer enable */
    	if (Open_drain == GPIO_OPEN_DRAIN_ENABLE)
    	{
    		SIU.PCR[channel].B.ODE = 1;				/* Open drain option enable */	
    	}
    	else
    	{	
    		SIU.PCR[channel].B.ODE = 0;				/* Push-pull option enable */	
    	}
    }
    else if (input_output == GPIO_INPUT)
    {
    	SIU.PCR[channel].B.PA  = 0;  				/* GPIO */
    	SIU.PCR[channel].B.IBE = 1;					/* Input buffer enable */	
    }

}

/****************************************************************************************************/
/**
* \brief    Configures individual GPIO pins to either input or output functionality.  
* \author   Abraham Tezmol
* \param    uint8_t channel - GPIO channel to be configured
* \param    uint8_t input_output - selection of input/output functionality (has impact on output impedance selection)
* \param    uint8_t Open_drain - Push pull or open drain selection modes 
* \return   void
*/
void vfnGPIO_Output(uint8_t channel, uint8_t logical_value)
{
    SIU.GPDO[channel].B.PDO  = logical_value;  		/* Drive the logical output value to the pin */

}



/****************************************************************************************************/
/**
* \brief    Turn a combination of 3 LEDs with a unique blinking pattern, this funcation shall be 
* \brief    called periodically to operate. 
* \author   Abraham Tezmol
* \param    void
* \return   void
*/
void vfnGPIO_FlashMainLED(void)
{
    static uint8_t u8Counter = 0;
    
    u8Counter++;
    switch (u8Counter)
    {
    case  1:
            LED_ON(LED1);
            LED_ON(LED2);
            break;
    case  11:
            LED_ON(LED3);
            LED_ON(LED4);                     
            break;
    case  21:
            LED_ON(LED2);
            LED_ON(LED3);                     
            break;        
    case  3:
            LED_OFF(LED1);
            LED_OFF(LED2);
            break;
    case  13:
            LED_OFF(LED3);
            LED_OFF(LED4);
            break;                          
    case  23:
            LED_OFF(LED2);
            LED_OFF(LED3);
            break;        
	case 100:
		u8Counter = 0;
		break;
    }
}


/****************************************************************************************************/
/**
* \brief    Initialize GPIO port connected to LEDs on eval board
* \author   Abraham Tezmol
* \param    void 
* \return   void
*/
void vfnGPIO_LED_Init(void)
{
    /* Data Port A initialization */
	vfnGPIO_Init_channel(GPIO_PA0,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PA0 --> output*/
	vfnGPIO_Output (GPIO_PA0, 0);
	vfnGPIO_Init_channel(GPIO_PA1,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PA1 --> output*/
	vfnGPIO_Output (GPIO_PA1, 0);
	vfnGPIO_Init_channel(GPIO_PA2,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PA2 --> output*/
	vfnGPIO_Output (GPIO_PA2, 0);
	vfnGPIO_Init_channel(GPIO_PA3,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PA3 --> output*/
	vfnGPIO_Output (GPIO_PA3, 0);
	vfnGPIO_Init_channel(GPIO_PA4,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PA4 --> output*/
	vfnGPIO_Output (GPIO_PA4, 0);
	vfnGPIO_Init_channel(GPIO_PA5,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PA5 --> output*/
	vfnGPIO_Output (GPIO_PA5, 0);
	vfnGPIO_Init_channel(GPIO_PA6,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PA6 --> output*/
	vfnGPIO_Output (GPIO_PA6, 0);
	vfnGPIO_Init_channel(GPIO_PA7,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PA7 --> output*/
	vfnGPIO_Output (GPIO_PA7, 0);
	vfnGPIO_Init_channel(GPIO_PA8,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PA8 --> output*/
	vfnGPIO_Output (GPIO_PA8, 0);
	vfnGPIO_Init_channel(GPIO_PA9,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PA9 --> output*/
	vfnGPIO_Output (GPIO_PA9, 0);
	vfnGPIO_Init_channel(GPIO_PA10,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PA10 --> output*/
	vfnGPIO_Output (GPIO_PA10, 0);
	vfnGPIO_Init_channel(GPIO_PA11,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PA11 --> output*/
	vfnGPIO_Output (GPIO_PA11, 0);
	vfnGPIO_Init_channel(GPIO_PA12,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PA12 --> output*/
	vfnGPIO_Output (GPIO_PA12, 0);
	vfnGPIO_Init_channel(GPIO_PA13,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PA13 --> output*/
	vfnGPIO_Output (GPIO_PA13, 0);
	vfnGPIO_Init_channel(GPIO_PA14,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PA14 --> output*/
	vfnGPIO_Output (GPIO_PA14, 0);
	vfnGPIO_Init_channel(GPIO_PA15,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PA15 --> output*/
	vfnGPIO_Output (GPIO_PA15, 0);
	vfnGPIO_Init_channel(GPIO_PC2,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PC2 --> output*/
	vfnGPIO_Output (GPIO_PC2, 0);
	vfnGPIO_Init_channel(GPIO_PC3,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PC3 --> output*/
	vfnGPIO_Output (GPIO_PC3, 0);
	vfnGPIO_Init_channel(GPIO_PC4,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PC4 --> output*/
	vfnGPIO_Output (GPIO_PC4, 0);
	vfnGPIO_Init_channel(GPIO_PC5,GPIO_OUTPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PC5 --> output*/
	vfnGPIO_Output (GPIO_PC5, 0);		
	
	vfnGPIO_Init_channel(GPIO_PC6,GPIO_INPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PC6 --> input*/
	vfnGPIO_Init_channel(GPIO_PC7,GPIO_INPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PC7 --> input*/
	vfnGPIO_Init_channel(GPIO_PC8,GPIO_INPUT,GPIO_OPEN_DRAIN_DISABLE);  /* PC8 --> input*/
	vfnGPIO_Init_channel(BUTTON4,GPIO_INPUT,GPIO_OPEN_DRAIN_DISABLE);  /*  BUTTON4--> input*/
	vfnGPIO_Init_channel(SWITCH1,GPIO_INPUT,GPIO_OPEN_DRAIN_DISABLE);  /* SWITCH1 --> input*/
}

/****************************************************************************************************/
