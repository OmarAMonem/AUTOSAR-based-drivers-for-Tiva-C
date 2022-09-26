/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Gpio.c
 *        \brief  GPIO driver
 *
 *      \details  GPIO driver to Intialize, Write, Read and Flip the I/O Pins
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
 
#include "PlatformTypes.h"
#include "Registers.h"
#include "Gpio_Types.h"
#include "Port_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
Interrupt_Notification callbacksArray[6] = {NULL};

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : void Port_Init()
 * \Description     : Initialize and configre the required ports and pins
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Port_Init(){


    uint32 i, bitOffset, portBase, regOffset = 0;

    for (i = 0; i < PINS_ACTIVATED; i++){
        
        bitOffset = (Port_Config[i].pin & 0xfu);         
        portBase = (0x40000000 | (Port_Config[i].pin >> 4));

        // Enabling Register commit
        GPIOLOCK(portBase) = 0x4C4F434B;
        GPIOCR(portBase) |= (1 << bitOffset);
        
        // set Pin mode
        if (Port_Config[i].mode == Digital_Port){
            GPIOAFSEL(portBase) &= ~(1 << bitOffset);
            GPIODEN(portBase) |= 1 << bitOffset;
        }else{
            GPIOAFSEL(portBase) &= ~(1 << bitOffset);
            GPIOPCTL(portBase) &= ~(0xF << (bitOffset * 4));
            GPIOPCTL(portBase) |= (Port_Config[i].mode << (bitOffset * 4));
        }


        // set pin direction
        if (Port_Config[i].direction == Port_INPUT){
            GPIODIR(portBase) &= ~(1 << bitOffset);

        }else if (Port_Config[i].direction == Port_OUTPUT){
            GPIODIR(portBase) |= (1 << bitOffset);
        }

        // set pin internal attach
        if (Port_Config[i].internalAttach != Port_Default_Resistance){
            regOffset = Port_Config[i].internalAttach;
            *((volatile uint32 *)(portBase + regOffset)) = 1 << bitOffset;
        }

        // set output driving current
        if (Port_Config[i].outputcurrent != Port_Current_Default){
            regOffset = Port_Config[i].outputcurrent;
            *((volatile uint32 *)(portBase + regOffset)) = 1 << bitOffset;
        }
    }
}

/******************************************************************************
 * \Syntax          : void Gpio_WritePin(Pin_Type PinId, Gpio_LevelType Level)
 * \Description     : write data to a certain Pin in GPIO Port
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : Pin_Type          
 *                    Gpio_LevelType    
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Gpio_WritePin(Pin_Type PinId, Gpio_LevelType Level){

    uint32 bitOffset = (PinId & 0xfu);
    uint32 portBase = (0x40000000u | (PinId >> 4u));

    GPIODATA(portBase) |= (Level << bitOffset);
}

/******************************************************************************
 * \Syntax          : Gpio_LevelType Gpio_ReadPin(Pin_Type PinId)
 * \Description     : reads the level of a GPIO Pin
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : Pin_Type   
 * \Parameters (out): None
 * \Return value:   : Gpio_LevelType     
 *******************************************************************************/
Gpio_LevelType Gpio_ReadPin(Pin_Type PinId){

    uint32 bitOffset = (PinId & 0xf);                   //fetch the required pin
    uint32 portBase = (0x40000000u | (PinId >> 4u));    //fetch the required Port

    if (GPIODATA(portBase) >> bitOffset)
        return Gpio_HIGH;
    else
        return Gpio_LOW;
} 

/******************************************************************************
 * \Syntax          : void Gpio_WritePin(Pin_Type PinId, Gpio_LevelType Level)
 * \Description     : write data to a certain Pin in gpio
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : Pin_Type          
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Gpio_FlipPin(Pin_Type PinId){

    uint32 bitOffset = (PinId & 0xfu);
    uint32 portBase = (0x40000000u | (PinId >> 4u));
    GPIODATA(portBase) ^= (1 << bitOffset);
    
}

/******************************************************************************
 * \Syntax          : void Gpio_InterruptsIn(Pin_Type PinId, Interrupt_TriggerLevelType level, Interrupt_Notification callbackPtr)
 * \Description     : enable external interrupt for a GPIO channel with edge or level detection
 * 
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * 
 * \Parameters (in) : Pin_Type                       the Pin requred to enable interrupt
 *                  : Interrupt_TriggerLevelType     the level to trigger interrupt
 *                  : Interrupt_Notification         Pointer to callback function 
 * 
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Gpio_InterruptsIn(Pin_Type PinId, Interrupt_TriggerLevelType level, Interrupt_Notification callbackPtr)
{
    uint32 bitOffset = (PinId & 0xf);                   //fetch the required pin
    uint32 portBase = (0x40000000u | (PinId >> 4u));    //fetch the required Port

    //interrupt level trigger 
    if(level == HighLevelTrigger){
        GPIOIS(portBase) |= 1 << bitOffset;
        GPIOIEV(portBase) |= 1 << bitOffset;
    }else if(level == LowLevelTrigger){
        GPIOIS(portBase) |= 1 << bitOffset;
        GPIOIEV(portBase) &= ~(1 << bitOffset);
     }else if(level == BothEdgesTrigger){
        GPIOIS(portBase) &= ~(1 << bitOffset);
        GPIOIBE(portBase) |= 1 << bitOffset;
    }else if (level == RisingEdgeTrigger){
        GPIOIS(portBase) &= ~(1 << bitOffset);
        GPIOIBE(portBase) &= ~(1 << bitOffset);
        GPIOIEV(portBase) |= 1 << bitOffset;
    }else if(level == FallingEdgeTrigger){
        GPIOIS(portBase) &= ~(1 << bitOffset);
        GPIOIBE(portBase) &= ~(1 << bitOffset);
        GPIOIEV(portBase) &= ~(1 << bitOffset);
    }
    

    //set callback
    if((PinId > Pin_A0) && (PinId < Pin_A7)){
        callbacksArray[0] = callbackPtr;
    }else if((PinId > Pin_B0) && (PinId < Pin_B7)){
        callbacksArray[1] = callbackPtr;
    }else if((PinId > Pin_C0) && (PinId < Pin_C7)){
        callbacksArray[2] = callbackPtr;
    }else if((PinId > Pin_D0) && (PinId < Pin_D7)){
        callbacksArray[3] = callbackPtr;
    }else if((PinId > Pin_E0) && (PinId < Pin_E7)){
        callbacksArray[4] = callbackPtr;
    }else if((PinId > Pin_F0) && (PinId < Pin_F7)){
        callbacksArray[5] = callbackPtr;
    }
    
    
    GPIOICR(portBase) |= 1 << bitOffset;    //clear interrupt flag
    GPIOIM(portBase) |= 1 << bitOffset;     //enable the interrupt
}



void GPIOF_Handler()
{
    callbacksArray[5]();
}

/**********************************************************************************************************************
 *  END OF FILE: Gpio.c 
 *********************************************************************************************************************/
