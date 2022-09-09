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
extern void blink(void);

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
void blink_Init(uint8 on_T, uint8 off_T){

    off_Time = off_T;
    on_Time = on_T;
    Nvic_Init(); 								//initialize Interrupt
	SysCtrl_Init(); 							//enable clock
	Port_Init();    							//initialize Port
	Gpt_Init();     							//initialize General Purpose Timer
	Gpt_EnableNotification(GPT_Timer1, blink); 	//enable Inturupt callback function with a user defined function

}

/**********************************************************************************************************************
 *  END OF FILE: Blink.c
 *********************************************************************************************************************/
