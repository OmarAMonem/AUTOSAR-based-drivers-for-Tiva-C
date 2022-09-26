/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Nvic_Types.h
 *       Module:  NVIC
 *
 *  Description:  types and constants in NVIC driver
 *
 *********************************************************************************************************************/
#ifndef NVIC_TYPES_H
#define NVIC_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Nvic.h"
#include "PlatformTypes.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
// Priority groups
#define xxx 0x400u
#define xxy 0x500u
#define xyy 0x600u
#define yyy 0x700u

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#define    NVIC_GPIO_PORT_A     0
#define    NVIC_GPIO_PORT_B     1
#define    NVIC_GPIO_PORT_C     2
#define    NVIC_GPIO_PORT_D     3
#define    NVIC_GPIO_PORT_E     4
#define    NVIC_UART_0          5
#define    NVIC_UART_1          6
#define    NVIC_SSI_0           7
#define    NVIC_I2C_0           8
#define    NVIC_PWM_0_FAULT     9
#define    NVIC_PWM_0_GEN_0     10
#define    NVIC_PWM_0_GEN_1     11
#define    NVIC_PWM_0_GEN_2     12
#define    NVIC_QEI_0           13
#define    NVIC_ADC_0_SEQ_0     14
#define    NVIC_ADC_0_SEQ_1     15
#define    NVIC_ADC_0_SEQ_2     16
#define    NVIC_ADC_0_SEQ_3     17
#define    NVIC_TIMER_WATCHDOG_0_1  18
#define    NVIC_16_32_TIMER_0_A 19
#define    NVIC_16_32_TIMER_0_B 20
#define    NVIC_16_32_TIMER_1_A 21
#define    NVIC_16_32_TIMER_1_B 22
#define    NVIC_16_32_TIMER_2_A 23
#define    NVIC_16_32_TIMER_2_B 24
#define    NVIC_ANALOG_COMPARATOR_0 25
#define    NVIC_ANALOG_COMPARATOR_1 26
#define    NVIC_SYSTEM_CONTROL  28
#define    NVIC_FLASH_EEPROM_MEMORY_CONTROL 29
#define    NVIC_GPIO_PORT_F     30
#define    NVIC_UART_2          33
#define    NVIC_SSI_1           34
#define    NVIC_16_32_TIMER_3_A 35
#define    NVIC_16_32_TIMER_3_B 36
#define    NVIC_I2C_1           37
#define    NVIC_QEI_1           38
#define    NVIC_CAN_0           39
#define    NVIC_CAN_1           40
#define    NVIC_HIBERNATION     43
#define    NVIC_USB             44
#define    NVIC_PWM_GEN_3       45
#define    NVIC_UDMA_SOFTWARE   46
#define    NVIC_UDMA_ERROR      47
#define    NVIC_ADC_1_SEQ_0     48
#define    NVIC_ADC_1_SEQ_1     49
#define    NVIC_ADC_1_SEQ_2     50
#define    NVIC_ADC_1_SEQ_3     51
#define    NVIC_SSI_2           57
#define    NVIC_SSI_3           58
#define    NVIC_UART_3          59
#define    NVIC_UART_4          60
#define    NVIC_UART_5          61
#define    NVIC_UART_6          62
#define    NVIC_UART_7          63
#define    NVIC_I2C_2           68
#define    NVIC_I2C_3           69
#define    NVIC_16_32_TIMER_4_A 70
#define    NVIC_16_32_TIMER_4_B 71
#define    NVIC_16_32_TIMER_5_A 92
#define    NVIC_16_32_TIMER_5_B 93
#define    NVIC_32_64_TIMER_0_A 93
#define    NVIC_32_64_TIMER_0_B 94
#define    NVIC_32_64_TIMER_1_A 95
#define    NVIC_32_64_TIMER_1_B 96
#define    NVIC_32_64_TIMER_2_A 97
#define    NVIC_32_64_TIMER_2_B 98
#define    NVIC_32_64_TIMER_3_A 99
#define    NVIC_32_64_TIMER_3_B 100
#define    NVIC_32_64_TIMER_4_A 101
#define    NVIC_32_64_TIMER_4_B 102
#define    NVIC_32_64_TIMER_5_A 103
#define    NVIC_32_64_TIMER_5_B 104
#define    NVIC_SYSTEM_EXCEPTION 105
#define    NVIC_PWM_1_GEN_0     134
#define    NVIC_PWM_1_GEN_1     135
#define    NVIC_PWM_1_GEN_2     136
#define    NVIC_PWM_1_GEN_3     137
#define    NVIC_PWM_1_FAULT     138


typedef struct
{
    uint32 vector;                   // interrupt name
    uint32 groupPriority;           // Group priorities 
    uint32 subGroupPriority;        // Subgroup priorities
} NVIC_ConfigType;

#endif /* NVIC_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Nvic_Types.h
 *********************************************************************************************************************/
