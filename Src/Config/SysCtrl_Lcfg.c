/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SysCtrl_Lcfg.c
 *        \brief  peripherals activation
 *
 *      \details  configure the activated peripherals from this file & SysCtrl_cfg.h file

 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "SysCtrl_Cfg.h"
#include "SysCtrl_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA 
 *********************************************************************************************************************/

/*configrations array for the activated peripherals

available peripherals:
    GPIO_A_SysCtrl_Enable
    GPIO_B_SysCtrl_Enable
    GPIO_C_SysCtrl_Enable
    GPIO_D_SysCtrl_Enable
    GPIO_E_SysCtrl_Enable
    GPIO_F_SysCtrl_Enable
    Timer0_16_32_SysCtrl_Enable
    Timer1_16_32_SysCtrl_Enable
    Timer2_16_32_SysCtrl_Enable
    Timer3_16_32_SysCtrl_Enable
    Timer4_16_32_SysCtrl_Enable
    Timer5_16_32_SysCtrl_Enable
    Timer0_32_64_SysCtrl_Enable
    Timer1_32_64_SysCtrl_Enable
    Timer2_32_64_SysCtrl_Enable
    Timer3_32_64_SysCtrl_Enable
    Timer4_32_64_SysCtrl_Enable
    Timer5_32_64_SysCtrl_Enable

Note: When Adding/Removing peripherals to SysCtrl_Config array DO NOT FORGET to update PERIPHERALS_ACTICATED in SysCtrl_Cfg.h
*/
const SysCtrl_ConfigType SysCtrl_Config[PERIPHERALS_ACTICATED] =
{
    {GPIO_F_SysCtrl_Enable},
    {Timer1_16_32_SysCtrl_Enable}

};

/**********************************************************************************************************************
 *  END OF FILE: SysCtrl_Lcfg.c
 *********************************************************************************************************************/
