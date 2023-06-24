 /******************************************************************************
 *
 * File Name: Exti.c
 *
 * Description: Source file for EXTI module
 *
 * Author: Esraa Ali
 *
 *******************************************************************************/

#include "Exti.h"
#include "Bit_Operations.h"
#include "Gpio.h"
#include "Rcc.h"
#include "Std_Types.h"

#define SYSCFG_EXTICR1 (*(uint32 *)0x40013808)

/******************************************************************************************************************
 * description : A function to initialize the EXTI by unable its RCC
 *******************************************************************************************************************/
void Exti_Init(void){
	/*Enable SYSCFG clock*/
	Rcc_Enable(RCC_SYSCFG);
}

/******************************************************************************************************************
 * description : A function to initialize the EXTI registers with the needed initial values
 *******************************************************************************************************************/
void Exti_Enable(uint8 PortName , uint8 Interrupt_pin_ID , uint8 Pin_DefaultState ,uint8 Nvic_Isr_ID , uint8 edge_detected){

	SET_BIT(EXTI_PTR->EXTI_IMR, Interrupt_pin_ID); /*Enable interrupt on specific pin*/

	/******************************** Falling edge****************************************/
	if(edge_detected == Falling_edge){
		SET_BIT(EXTI_PTR->EXTI_FTSR, Interrupt_pin_ID); /*Enable falling edge dectection*/
	}
	/******************************** Rising edge****************************************/

	else{
		CLEAR_BIT(EXTI_PTR->EXTI_FTSR, Interrupt_pin_ID); /*Enable Rising edge dectection*/
	}

	/*enable specific line on nvic*/
	switch(Nvic_Isr_ID){
	case Nvic_Isr_ID0 :
		SET_BIT(NVIC_ISER0, (6 + Interrupt_pin_ID));
		break;
	case Nvic_Isr_ID1 :
		SET_BIT(NVIC_ISER1, (6 + Interrupt_pin_ID));

		break;
	case Nvic_Isr_ID2 :
		SET_BIT(NVIC_ISER2, (6 + Interrupt_pin_ID));

		break;
	}
	/*Configure interrupt pin as input pin*/
	Gpio_ConfigPin(PortName, Interrupt_pin_ID, GPIO_INPUT, Pin_DefaultState);

}


/******************************************************************************************************************
 * description : A function to Disable the EXTI module
 *******************************************************************************************************************/
void Exti_Disable (uint8 Interrupt_pin_ID  ,uint8 Nvic_Isr_ID){
	CLEAR_BIT(EXTI_PTR->EXTI_IMR, Interrupt_pin_ID); /*Disable interrupt on specific pin*/
	/*Disable specific line on nvic*/
	switch(Nvic_Isr_ID){
	case Nvic_Isr_ID0 :
		CLEAR_BIT(NVIC_ISER0, (6 + Interrupt_pin_ID));

		break;
	case Nvic_Isr_ID1 :
		CLEAR_BIT(NVIC_ISER1, (6 + Interrupt_pin_ID));

		break;
	case Nvic_Isr_ID2 :
		CLEAR_BIT(NVIC_ISER2, (6 + Interrupt_pin_ID));

		break;
	}
}
