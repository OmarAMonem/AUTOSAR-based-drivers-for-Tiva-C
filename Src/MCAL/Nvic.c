/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  NVIC driver
 *
 *      \details  NVIC driver to enable configured interrupts in Nvic_Lcfg.h file
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Nvic.h"
#include "Nvic_Cfg.h"
#include "Registers.h"
#include "PlatformTypes.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void Nvic_Init(void)                                      
* \Description     : initialize NVIC module and enabling the required interrupts with provided priorities
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Nvic_Init(void){
	
	uint8 i, IRQ, PRI_offset, EN_offset = 0;
	uint32 EN_BitMAsk, PRI_BitMask = 0;
	
    APINT = (0x05FA0000u | PRI_Group ); 					/*Set the Priority system configuration of interrupts*/

    /*Intialize the required interrupts according to user choices in Nvic_Lcfg.h*/
    for(i=0; i < INTERRUPTs_ACTIVATED; i++){
    	IRQ = NVIC_Cofig[i].vector;

		PRI_offset= IRQ / 4;								/* the n of PRI is determined by a formula: n = IRQ/4 */
		PRI_BitMask = ((IRQ - (4 * PRI_offset)) * 8) + 5 ; 	/* Fetching the corosponding bits to write the priority in */

		EN_offset = IRQ / 32;								/* the n of Enable is determined by a formula: n = IRQ/32 */
		EN_BitMAsk = (IRQ % 32);							/* Fetching thecorosponsing bit to Enable the required NVIC Interrupt*/

		/* writing in NVIC_PRIn register to enable required interrupts */
		#if	(PRI_Group == xxx)
			NVIC_PRIn(PRI_offset) |= (NVIC_Cofig[i].groupPriority << (PRI_BitMask));
    		
		#elif(PRI_Group == xxy)
			NVIC_PRIn(PRI_offset) |= (NVIC_Cofig[i].groupPriority << (PRI_BitMask+1));
			NVIC_PRIn(PRI_offset) |= (NVIC_Cofig[i].subGroupPriority << PRI_BitMask);
			
    	#elif(PRI_Group == xyy)	
			NVIC_PRIn(PRI_offset) |= (NVIC_Cofig[i].groupPriority << (PRI_BitMask+2));
			NVIC_PRIn(PRI_offset) |= (NVIC_Cofig[i].subGroupPriority << PRI_BitMask);

   		#elif	(PRI_Group == yyy)
			NVIC_PRIn(PRI_offset) |= (NVIC_Cofig[i].subGroupPriority << PRI_BitMask);
    		
    	#endif

		/* writing in NVIC_ENn register to enable required interrupts */
    	NVIC_ENn(EN_offset) |= (1 << EN_BitMAsk);
		
    }
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
