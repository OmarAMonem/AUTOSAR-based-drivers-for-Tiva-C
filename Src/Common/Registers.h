/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Registers.h
 *       Module:  Register Mapping
 *
 *  Description:  Register offsets for TM4C123GH6PM 
 *
 *********************************************************************************************************************/
#ifndef REGISTERS_H
#define REGISTERS_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PlatformTypes.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

//GPIO registers
typedef enum{
    GPIODATA = 0x038u,
    GPIODIR = 0x400u,
    GPIOIS = 0x404u,
    GPIOIBE = 0x408u,
    GPIOIEV = 0x40Cu,
    GPIOIM = 0x410u,
    GPIORIS = 0x414u,
    GPIOMIS = 0x418u,
    GPIOICR = 0x41Cu,
    GPIOAFSEL = 0x420u,
    GPIODR2R = 0x500u,
    GPIODR4R = 0x504u,
    GPIODR8R = 0x508u,
    GPIOODR = 0x50Cu,
    GPIOPUR = 0x510u,
    GPIOPDR = 0x514u,
    GPIODEN = 0x51Cu,
    GPIOLOCK = 0x520u,
    GPIOCR = 0x524u,
    GPIOAMSEL = 0x528u,
    GPIOPCTL = 0x52Cu

}GPIO_REG_OFFSET;


// NVIC registers
typedef enum{
    EN0 = 0x100,
    DIS0 = 0x180,
    PEND0 = 0x200,
    UNPEND0 = 0x280,
    ACTIVE0 = 0x300,
    PRI0 = 0x400

}NVIC_REG_OFFSET;
 

// General Purpose Timers registers
typedef enum{
    GPT_Timer0 = 0x40030000u,
    GPT_Timer1 = 0x40031000u,
    GPT_Timer2 = 0x40032000u,
    GPT_Timer3 = 0x40033000u,
    GPT_Timer4 = 0x40034000u,
    GPT_Timer5 = 0x40035000u,
    GPT_WTimer0 = 0x40036000u,
    GPT_WTimer1 = 0x40037000u,
    GPT_WTimer2 = 0x4004C000u,
    GPT_WTimer3 = 0x4004D000u,
    GPT_WTimer4 = 0x4004E000u,
    GPT_WTimer5 = 0x4004F000u
}Timer_BASE;

typedef enum{
    GPTMCFG = 0x000,
    GPTMTAMR = 0x004,
    GPTMCTL = 0x00C,
    GPTMIMR = 0x018,
    GPTMICR = 0x024,
    GPTMTAILR = 0x028,
}TIMER_REG;

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

// SysCtrl Base addresses
#define SysCtrl_BASE 0x400FE000u
#define RCGCx_OFFSET 0x600u

// Run Mode Clock Gating Control
#define RCGC(REG_OFFSET)                    *((volatile uint32*)(SysCtrl_BASE + RCGCx_OFFSET + REG_OFFSET))


// private peripherals addresses
#define CORTEXM4_CORE_PERIPHERALS_BASE 0xE000E000u
#define APINT_OFFSET 0xD0Cu

//NVIC
#define NVIC_ENn(n)             *((volatile uint32*)(CORTEXM4_CORE_PERIPHERALS_BASE + EN0 + (0x4*n)))
#define NVIC_DISn(n)            *((volatile uint32*)(CORTEXM4_CORE_PERIPHERALS_BASE + DIS0 + (0x4*n)))
#define NVIC_PENDn(n)           *((volatile uint32*)(CORTEXM4_CORE_PERIPHERALS_BASE + PEND0 + (0x4*n)))
#define NVIC_UNPENDn(n)         *((volatile uint32*)(CORTEXM4_CORE_PERIPHERALS_BASE + UNPEND0 + (0x4*n)))
#define NVIC_ACTIVEn(n)         *((volatile uint32*)(CORTEXM4_CORE_PERIPHERALS_BASE + ACTIVE0 + (0x4*n)))
#define NVIC_PRIn(n)            *((volatile uint32*)(CORTEXM4_CORE_PERIPHERALS_BASE + PRI0 + (0x4*n)))
#define APINT                   *((volatile uint32*)(CORTEXM4_CORE_PERIPHERALS_BASE + APINT_OFFSET))


// GPIO
#define GPIODATA(GPIO_BASE)     (*((volatile uint32*)(GPIO_BASE + GPIODATA)))
#define GPIODIR(GPIO_BASE)      *((volatile uint32*)(GPIO_BASE + GPIODIR))
#define GPIOIS(GPIO_BASE)       *((volatile uint32*)(GPIO_BASE + GPIOIS))
#define GPIOIBE(GPIO_BASE)      *((volatile uint32*)(GPIO_BASE + GPIOIBE))
#define GPIOIEV(GPIO_BASE)      *((volatile uint32*)(GPIO_BASE + GPIOIEV))
#define GPIOIM(GPIO_BASE)       *((volatile uint32*)(GPIO_BASE + GPIOIM))
#define GPIORIS(GPIO_BASE)      *((volatile uint32*)(GPIO_BASE + GPIORIS))
#define GPIOMIS(GPIO_BASE)      *((volatile uint32*)(GPIO_BASE + GPIOMIS))
#define GPIOICR(GPIO_BASE)      *((volatile uint32*)(GPIO_BASE + GPIOICR))
#define GPIOAFSEL(GPIO_BASE)    *((volatile uint32*)(GPIO_BASE + GPIOAFSEL))
#define GPIODR2R(GPIO_BASE)     *((volatile uint32*)(GPIO_BASE + GPIODR2R))
#define GPIODR4R(GPIO_BASE)     *((volatile uint32*)(GPIO_BASE + GPIODR4R))
#define GPIODR8R(GPIO_BASE)     *((volatile uint32*)(GPIO_BASE + GPIODR8R))
#define GPIOODR(GPIO_BASE)      *((volatile uint32*)(GPIO_BASE + GPIOODR))
#define GPIOPUR(GPIO_BASE)      *((volatile uint32*)(GPIO_BASE + GPIOPUR))
#define GPIOPDR(GPIO_BASE)      *((volatile uint32*)(GPIO_BASE + GPIOPDR))
#define GPIODEN(GPIO_BASE)      *((volatile uint32*)(GPIO_BASE + GPIODEN))
#define GPIOLOCK(GPIO_BASE)     *((volatile uint32*)(GPIO_BASE + GPIOLOCK))
#define GPIOCR(GPIO_BASE)       *((volatile uint32*)(GPIO_BASE + GPIOCR))
#define GPIOAMSEL(GPIO_BASE)    *((volatile uint32*)(GPIO_BASE + GPIOAMSEL))
#define GPIOPCTL(GPIO_BASE)     *((volatile uint32*)(GPIO_BASE + GPIOPCTL))


// General Purpose Timer
#define Timer_GPTMCFG(TIMER_BASE)       *((volatile uint32*)(TIMER_BASE + GPTMCFG))
#define Timer_GPTMTAMR(TIMER_BASE)      *((volatile uint32*)(TIMER_BASE + GPTMTAMR))
#define Timer_GPTMCTL(TIMER_BASE)       *((volatile uint32*)(TIMER_BASE + GPTMCTL))
#define Timer_GPTMIMR(TIMER_BASE)       *((volatile uint32*)(TIMER_BASE + GPTMIMR))
#define Timer_GPTMICR(TIMER_BASE)       *((volatile uint32*)(TIMER_BASE + GPTMICR))
#define Timer_GPTMTAILR(TIMER_BASE)     *((volatile uint32*)(TIMER_BASE + GPTMTAILR))


#endif /* REGISTERS_H */

/**********************************************************************************************************************
 *  END OF FILE: Registers.h
 *********************************************************************************************************************/
