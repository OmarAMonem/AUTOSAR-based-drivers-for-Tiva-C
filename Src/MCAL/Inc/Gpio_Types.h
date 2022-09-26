/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpio_Types.h
 *       Module:  GPIO
 *
 *  Description:  types used in GPIO driver
 *
 *********************************************************************************************************************/
#ifndef GPIO_TYPES_H
#define GPIO_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PlatformTypes.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
// defining pin type options in tiva c (not all pin types available here)
typedef enum{
    Digital_Port,
    Analog_Port
}Pin_ModeType;

// defining all ports and pins available in tiva c
typedef enum Port_Pins
{
    Pin_A0 = 0x40000u,
    Pin_A1 = 0x40001u,
    Pin_A2 = 0x40002u,
    Pin_A3 = 0x40003u,
    Pin_A4 = 0x40004u,
    Pin_A5 = 0x40005u,
    Pin_A6 = 0x40006u,
    Pin_A7 = 0x40007u,
    Pin_B0 = 0x50000u,
    Pin_B1 = 0x50001u,
    Pin_B2 = 0x50002u,
    Pin_B3 = 0x50002u,
    Pin_B4 = 0x50003u,
    Pin_B5 = 0x50004u,
    Pin_B6 = 0x50005u,
    Pin_B7 = 0x50007u,
    Pin_C0 = 0x60000u,
    Pin_C1 = 0x60001u,
    Pin_C2 = 0x60002u,
    Pin_C3 = 0x60003u,
    Pin_C4 = 0x60004u,
    Pin_C5 = 0x60005u,
    Pin_C6 = 0x60006u,
    Pin_C7 = 0x60006u,
    Pin_D0 = 0x70000u,
    Pin_D1 = 0x70001u,
    Pin_D2 = 0x70002u,
    Pin_D3 = 0x70003u,
    Pin_D4 = 0x70004u,
    Pin_D5 = 0x70005u,
    Pin_D6 = 0x70006u,
    Pin_D7 = 0x70007u,
    Pin_E0 = 0x240000u,
    Pin_E1 = 0x240001u,
    Pin_E2 = 0x240002u,
    Pin_E3 = 0x240003u,
    Pin_E4 = 0x240004u,
    Pin_E5 = 0x240005u,
    Pin_E6 = 0x240006u,
    Pin_E7 = 0x240007u,
    Pin_F0 = 0x250000u,
    Pin_F1 = 0x250001u,
    Pin_F2 = 0x250002u,
    Pin_F3 = 0x250003u,
    Pin_F4 = 0x250004u,
    Pin_F5 = 0x250005u,
    Pin_F6 = 0x250006u,
    Pin_F7 = 0x250007u
} Pin_Type; 

// defining pin direction/mode options in tiva c
typedef enum
{
    Port_INPUT = 0,
    Port_OUTPUT = 1
} Pin_Direction;

// defining internal resistance attach options in tiva c
typedef enum
{
    Port_Default_Resistance = 0,
    Port_OpenDrain_Resistance = 0x50Cu,
    Port_PullUp_Resistance = 0x510u,
    Port_PullDown_Resistance = 0x514u

} Pin_InternalAttach;

// defining output currents options in tiva c
typedef enum
{
    Port_Current_Default = 0,
    Port_Current_2mA = 0x500u,
    Port_Current_4mA = 0x504u,
    Port_Current_8mA = 0x508u

} Pin_OutputCurrent;

// creating a struct to take user configuration as an input from Port_Lcfg.c file
typedef struct
{
    Pin_Type pin;
    Pin_Direction direction;
    Pin_ModeType mode;
    Pin_InternalAttach internalAttach;
    Pin_OutputCurrent outputcurrent;
} Port_ConfigType;

// defining pin state options
typedef enum
{
    Gpio_LOW = 0u,
    Gpio_HIGH = 1u
} Gpio_LevelType;

typedef enum
{
    LowLevelTrigger,
    HighLevelTrigger,
    RisingEdgeTrigger,
    FallingEdgeTrigger,
    BothEdgesTrigger
} Interrupt_TriggerLevelType;

typedef void (*Interrupt_Notification)();


#endif /* GPIO_TYPES_h */

/**********************************************************************************************************************
 *  END OF FILE: Gpio_Types.h
 *********************************************************************************************************************/
