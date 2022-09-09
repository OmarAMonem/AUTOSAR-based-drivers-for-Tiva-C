/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Nvic_Cfg.h
 *       Module:  Inturrupt Configuration
 *
 *  Description:  configure the interrupts from this file & Nvic_LCfg.h file
 *  
 *********************************************************************************************************************/
#ifndef NVIC_CFG_H
#define NVIC_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Nvic_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*
 * xxx --> group priority (from 0 to 7) & subgroup priority (0 only)
 * xxy --> group priority (from 0 to 3) & subgroup priority (from 0 to 1)
 * xyy --> group priority (from 0 to 1) & subgroup priority (from 0 to 3)
 * yyy --> group priority (0 only) & subgroup priority (from 0 to 7)
 */
#define PRI_Group	    xxy


#define INTERRUPTs_ACTIVATED	1u  // define the number of activated Interrupts in Nvic_Config in Nvic_Lcfg.c file


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern const NVIC_ConfigType NVIC_Cofig[INTERRUPTs_ACTIVATED];

#endif /* NVIC_CFG_H */
/**********************************************************************************************************************
 *  END OF FILE: Nvic_Cfg.h
 *********************************************************************************************************************/
