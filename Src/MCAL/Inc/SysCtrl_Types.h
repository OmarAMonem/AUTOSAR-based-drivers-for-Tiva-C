/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Sysctrl_Types.h
 *       Module:  System Control
 *
 *  Description:  types used in System Controller driver
 *
 *********************************************************************************************************************/
#ifndef SYSCTRL_TYPES_H
#define SYSCTRL_TYPES_H

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

// defining the System Control Register Offsets for some tiva c Peripherals
typedef enum
{
    GPIO_A_SysCtrl_Enable = 0x080u,
    GPIO_B_SysCtrl_Enable = 0x081u,
    GPIO_C_SysCtrl_Enable = 0x082u,
    GPIO_D_SysCtrl_Enable = 0x083u,
    GPIO_E_SysCtrl_Enable = 0x084u,
    GPIO_F_SysCtrl_Enable = 0x085u,
    Timer0_16_32_SysCtrl_Enable = 0x040u,
    Timer1_16_32_SysCtrl_Enable = 0x041u,
    Timer2_16_32_SysCtrl_Enable = 0x042u,
    Timer3_16_32_SysCtrl_Enable = 0x043u,
    Timer4_16_32_SysCtrl_Enable = 0x044u,
    Timer5_16_32_SysCtrl_Enable = 0x045u,
    Timer0_32_64_SysCtrl_Enable = 0x5C0u,
    Timer1_32_64_SysCtrl_Enable = 0x5C1u,
    Timer2_32_64_SysCtrl_Enable = 0x5C2u,
    Timer3_32_64_SysCtrl_Enable = 0x5C3u,
    Timer4_32_64_SysCtrl_Enable = 0x5C4u,
    Timer5_32_64_SysCtrl_Enable = 0x5C5u
} SysCtrl_Peripheral;

// defining a struct to take from the user the required peripherals to be activated in SysCtrl_Lcfg.c file
typedef struct
{
    SysCtrl_Peripheral peripheral;

} SysCtrl_ConfigType;

#endif /* SYSCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: SysCtrl_Types.h
 *********************************************************************************************************************/
