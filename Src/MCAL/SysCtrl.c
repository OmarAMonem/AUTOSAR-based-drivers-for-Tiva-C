/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SysCtrl.c
 *        \brief  System Control Driver
 *
 *      \details  Intializing clock for the required peripherals
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Registers.h"
#include "PlatformTypes.h"
#include "SysCtrl_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : void SysCtrl_Init(void)
 * \Description     : Enable clock for the required peripherals
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : none
 * \Parameters (out): none
 * \Return value:   : none
 *******************************************************************************/
void SysCtrl_Init(void){

	uint32 i, bitOffset, regOffset = 0;

	// looping over all the required peripherals to enable the clock
	for (i = 0; i < PERIPHERALS_ACTICATED; i++){

		bitOffset = SysCtrl_Config[i].peripheral & 0xfu;			// fetch the peripheral bit in RCGC
		regOffset = (SysCtrl_Config[i].peripheral) >> 4u;		// fetch the RCGC register for the peripheral
		RCGC(regOffset) |= 1u << bitOffset;								// enable clock 
	}
}

/**********************************************************************************************************************
 *  END OF FILE: SysCtrl.c
 *********************************************************************************************************************/
