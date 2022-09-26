/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Blink.c
 *        \brief  driver to intialize and start the blink procedure
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Registers.h"
#include "Nvic.h"
#include "SysCtrl.h"
#include "Gpio.h"
#include "Gpio.h"
#include "Gpt.h"
#include "Gpio_Types.h"

/**********************************************************************************************************************
 *  GLOBAL Variables
 *********************************************************************************************************************/
uint8 off_Time;
uint8 on_Time;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void SetBlinkPeriods(void);

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : void blink_Start()
 * \Description     : start blinking the led
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : none
 * \Parameters (out): none
 * \Return value:   : none
 *******************************************************************************/
void blink_Start(){

	Gpt_StartTimer(GPT_Timer1, off_Time);
}

/******************************************************************************
 * \Syntax          : void blink_Init(void)
 * \Description     : initialize all required modules to start led blink procedure
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : none
 * \Parameters (out): none
 * \Return value:   : none
 *******************************************************************************/
void blink_Init(uint8 on_T, uint8 off_T, Gpt_Notification CallBackFunction){

    off_Time = off_T;
    on_Time = on_T;
    Nvic_Init(); 								//initialize Interrupt
	SysCtrl_Init(); 							//enable clock
	Port_Init();    							//initialize Port
	Gpt_Init();     							//initialize General Purpose Timer
	Gpt_EnableNotification(GPT_Timer1, CallBackFunction); 	//enable Inturupt callback function with a user defined function
	Gpio_InterruptsIn(Pin_F0, RisingEdgeTrigger, SetBlinkPeriods);
	Gpio_InterruptsIn(Pin_F4, RisingEdgeTrigger, SetBlinkPeriods);

}

/******************************************************************************
 * \Syntax          : void SetBlinkPeriods(void)
 * \Description     : Gpio interrupt to increase and decrease the blinking periods
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : none
 * \Parameters (out): none
 * \Return value:   : none
 *******************************************************************************/
void SetBlinkPeriods(void){
	// checking the interrupt pin
	if (( (GPIOMIS(0x40000000u | (0x250004 >> 4)) & (1 << 4)) >> 4) == 1){
		GPIOICR(0x40000000u | (0x250004 >> 4)) |= 1 << 4; 		// clear interrupt status flag
		
		on_Time++;				  								// increasing the on time period
		off_Time--;				  								// decreasing the off time period
	}
	else if (( (GPIOMIS(0x40000000u | (0x250000 >> 4u)) & (1 << 0)) >> 0) == 1){
		GPIOICR(0x40000000u | (0x250000 >> 4)) |= 1 << 0; 
		
		off_Time++;
		on_Time--;
	}
}

/**********************************************************************************************************************
 *  END OF FILE: Blink.c
 *********************************************************************************************************************/
