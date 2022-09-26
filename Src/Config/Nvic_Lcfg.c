/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Nvic_Lcfg.c
 *        \brief  Inturrupt Configuration
 *
 *      \details  configure the interrupts from this file & Nvic_Cfg.h file

 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Nvic_Cfg.h"
#include "Nvic_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/* Interrupt configrations array

available options: 	
	-Peripheral: see the available Peripheral interrupts available in tiva c documentation
	-group priority: a number defined by a range according to PRI_Group defined in Nvic_Cfg.h file
	-subgroup priority: a number defined by a range according to PRI_Group defined in Nvic_Cfg.h file

Note: When Adding/Removing configuration to NVIC_Cofig array DO NOT FORGET to update INTERRUPTs_ACTIVATED in Nvic_Cfg.h
*/
const NVIC_ConfigType NVIC_Cofig[INTERRUPTs_ACTIVATED]=
{
				 	
	{
		NVIC_16_32_TIMER_1_A,		//Peripheral
		1u,							// group priority
		0u							// subgroup priority
	},
	{
		NVIC_GPIO_PORT_F,
		0u,
		0u
	},

};
/**********************************************************************************************************************
 *  END OF FILE: Nvic_Lcfg.c
 *********************************************************************************************************************/
