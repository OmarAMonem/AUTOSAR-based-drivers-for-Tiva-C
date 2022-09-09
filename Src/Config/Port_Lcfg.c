/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port_Lcfg.c
 *        \brief  GPIO Port/Pin Configuration
 *
 *      \details  configure the GPIO pin direction, internal attach and output driving current from this file & Port_Cfg.h file
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Port_Cfg.h"
#include "Gpio_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/


/* Port/Pins configration array

Available options:
- pin: Pin_X# -> Where X is replaced by (A,B,C,D,E or F) and # is replaced an integer number from 0 to 7
- direction: Port_OUTPUT / Port_INPUT
- function: Digital_Port / Analog_Port
- internal attach: Port_Default_Resistance / Port_OpenDrain_Resistance / Port_PullUp_Resistance / Port_PullDown_Resistance
- ouptut current: Port_Current_Default / Port_Current_2mA / Port_Current_4mA / Port_Current_8mA

Note: When Adding/Removing configuration to Port_Config array DO NOT FORGET to update PINS_ACTIVATED in Port_Cfg.h
*/
const Port_ConfigType Port_Config[PINS_ACTIVATED]=
{                  
    {Pin_F2,                        // pin
    Port_OUTPUT,                    // direction      
    Digital_Port,                   // function  
    Port_Default_Resistance,        // internal attach 
    Port_Current_4mA                // ouptut current
    },
};

/**********************************************************************************************************************
 *  END OF FILE: Port_Lcfg.c
 *********************************************************************************************************************/
