/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Gpt.c
 *        \brief  General Purpose Timer driver
 *
 *      \details  GPT driver to enable Timer modules defined in in Gpt_Lcfg.h file
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Registers.h"
#include "Gpt_Cfg.h"
#include "Gpt_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
Gpt_Notification FunctionArray[12] = {NULL};

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : void Gpt_Init()
 * \Description     : Initialize the General Purpose Timers module
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Gpt_Init()
{

    uint8 i;
    uint32 timerBase = 0;

    for (i = 0; i < TIMERS_ACTIVATED; i++)
    {
        timerBase = gpt_config[i].TimerID;

        Timer_GPTMCTL(timerBase) = 0;             // Disabling timer module
        Timer_GPTMCFG(timerBase) = 0x0u;          // selecting concatenated register mode
        Timer_GPTMTAMR(timerBase) &= ~(1u << 4u); // selecting countdown mode

        // selecting timer mode
        if (gpt_config[i].TimerMode == Gpt_OneShot){
            Timer_GPTMTAMR(timerBase) |= 1u << 0u;
        }
        else if (gpt_config[i].TimerMode == Gpt_Periodic){
            Timer_GPTMTAMR(timerBase) |= 1u << 1u;
        }
    }
}

/******************************************************************************
 * \Syntax          : void Gpt_StartTimer(Timer_BASE TimerID, uint32 loadValue)
 * \Description     : start the counting process with the load value
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Timer_BASE        required timer module
 *                  : uint32     required time interval value
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Gpt_StartTimer(Timer_BASE TimerID, uint32 loadValue)
{

    Timer_GPTMTAILR(TimerID) = loadValue * 0xF423FF; // Converting from sec to ticks and loading the value to GPTMTAILR Register
    Timer_GPTMCTL(TimerID) |= 0x1u;
}

/******************************************************************************
 * \Syntax          : void Gpt_EnableNotification(Timer_BASE TimerID, Gpt_Notification callbackPtr)
 * \Description     : enable the interrupt when time out and set the callback function
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Timer_BASE   The GPt required channel from Gpt_Types.h
 *                  : Gpt_Notification     Pointer to the required callback function
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/

void Gpt_EnableNotification(Timer_BASE TimerID, Gpt_Notification callbackPtr)
{

    // set call back to global array
    if (TimerID == GPT_Timer0){

        FunctionArray[0] = callbackPtr;

    }else if (TimerID == GPT_Timer1){

        FunctionArray[1] = callbackPtr;

    }else if (TimerID == GPT_Timer2){

        FunctionArray[2] = callbackPtr;

    }else if (TimerID == GPT_Timer3){

        FunctionArray[3] = callbackPtr;

    }else if (TimerID == GPT_Timer4){

        FunctionArray[4] = callbackPtr;

    }else if (TimerID == GPT_Timer5){

        FunctionArray[5] = callbackPtr;

    }else if (TimerID == GPT_WTimer0){

        FunctionArray[6] = callbackPtr;

    }else if (TimerID == GPT_WTimer1){

        FunctionArray[7] = callbackPtr;

    }else if (TimerID == GPT_WTimer2){

        FunctionArray[8] = callbackPtr;

    }else if (TimerID == GPT_WTimer3){

        FunctionArray[9] = callbackPtr;

    }else if (TimerID == GPT_WTimer4){

        FunctionArray[10] = callbackPtr;
        
    }else if (TimerID == GPT_WTimer5){

        FunctionArray[11] = callbackPtr;
    }

    Timer_GPTMIMR(TimerID) |= 0x1u; // enable time out interrupt
}

/******************************************************************************
 * \Syntax          : void Gpt_DisableNotification(Timer_BASE TimerID, Gpt_Notification callbackPtr)
 * \Description     : disable timer module interrupt
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Timer_BASE   The GPt required channel from Gpt_Types.h
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Gpt_DisableNotification(Timer_BASE TimerID)
{

    Timer_GPTMICR(TimerID) = 0x10F1F;           // disable interrupts
}

/******************************************************************************
 * \Syntax          : void TIMER1A_Handler(void)
 * \Description     : handle the interrupt of timer1A module
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : none
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void TIMER1A_Handler(void)
{

    Gpt_Notification handlerFunction = FunctionArray[1];

    if (handlerFunction != NULL)
    {
        Timer_GPTMICR(GPT_Timer1) |= 1 << 0;    // clear status flag
        handlerFunction();                      // calling the interrupt handler function
    }
}

/**********************************************************************************************************************
 *  END OF FILE: Gpt.c
 *********************************************************************************************************************/