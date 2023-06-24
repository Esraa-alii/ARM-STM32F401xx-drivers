/**************************************************************************************
 * File name  : GPT.c
 * Description: source file for the driver of timer module
 * Author     : Esraa Ali
 *************************************************************************************/

#include "GPT.h"
#include "GPT_Private.h"
#include "GPIO.h"
#include "Std_Types.h"
#include "Bit_Operations.h"

#ifdef TIMER1
#define GPT_register ((GPT_REGISTER*)TIM1_BASE_ADDR)
#endif

#ifdef TIMER2
#define GPT_register ((GPT_REGISTER*)TIM2_BASE_ADDR)
#endif

#ifdef TIMER3
#define GPT_register ((GPT_REGISTER*)TIM3_BASE_ADDR)
#endif

#ifdef TIMER4
#define GPT_register ((GPT_REGISTER*)TIM4_BASE_ADDR)
#endif

#ifdef TIMER5
#define GPT_register ((GPT_REGISTER*)TIM5_BASE_ADDR)
#endif

#ifdef TIME9
#define GPT_register ((GPT_REGISTER*)TIM9_BASE_ADDR)
#endif

#ifdef TIMER10
#define GPT_register ((GPT_REGISTER*)TIM10_BASE_ADDR)
#endif

#ifdef TIMER11
#define GPT_register ((GPT_REGISTER*)TIM11_BASE_ADDR)
#endif


/******************************************************************************************************************
 * description : A function to initialize the GPT registers with the needed initial values to support
 * 				the needed timing actions.
 *******************************************************************************************************************/
void GPT_Init(void){
#ifdef EDGE_ALIGN_MODE
	CLEAR_BIT(GPT_register->TIM_CR1,CMS_FIRST_BIT);
	CLEAR_BIT(GPT_register->TIM_CR1,CMS_SECOND_BIT);
#endif
	/******************************************** Counting direction *************************************************/
	/*Case of up counting*/
#ifdef UPCOUNTING
	CLEAR_BIT(GPT_register->TIM_CR1,DIR_BIT);
#endif
	/*Case of down counting*/
#ifdef DOWNCOUNTING
	SET_BIT(GPT_register->TIM_CR1,DIR_BIT);
#endif
	/******************************************** ARR buffered or not *************************************************/
	/*Case of buffered*/
#ifdef ARR_BUFFERED
	SET_BIT(GPT_register->TIM_CR1,ARPE_BIT);
#endif
	/*Case of not buffered*/
#ifdef ARR_NOTBUFFERED
	CLEAR_BIT(GPT_register->TIM_CR1,ARPE_BIT);
#endif
	SET_BIT(GPT_register->TIM_DIER,UIE_BIT); /*Enable update interrupt bit*/

}

/**********************************************************************************************************************
 * description : A function to request the GPT to start and send its number of tickets before timer overflow and stop.
 *********************************************************************************************************************/
void GPT_StartTimer(uint32 OverFlowTicks){
	GPT_register->TIM_PSC = PRESCALLER;
	GPT_register->TIM_ARR = OverFlowTicks;
	SET_BIT(GPT_register->TIM_EGR,0);
	SET_BIT(GPT_register->TIM_CR1,CEN_BIT); /*Enable the timer*/
}

/**********************************************************************************************************************
 * description : A function to return (1) if an overflow occurred after the last call of GPT_StartTimer and (0)
 * 				 if no overflow occurred or GPT_StartTimer is not called from the last read.
 *********************************************************************************************************************/
uint8 GPT_CheckTimeIsElapsed(void){
	if(BIT_IS_SET(GPT_register->TIM_SR,UIF_BIT) && BIT_IS_SET(GPT_register->TIM_CR1,CEN_BIT)){
		CLEAR_BIT(GPT_register->TIM_SR,UIF_BIT);
		return 1;
	}
	else{
		return 0;
	}
}


/**********************************************************************************************************************
 * description : A function to return number of elapsed ticks from the last call of the GPT_StartTimer,
 * 				 0 if it is not called and 0xffffffff if an overflow occurred.
 *********************************************************************************************************************/
uint32 GPT_GetElapsedTime(void){
	uint32 elapsed_time;
	if(BIT_IS_SET(GPT_register->TIM_SR,UIF_BIT)){
		CLEAR_BIT(GPT_register->TIM_SR,UIF_BIT);
		elapsed_time =0xffffffff;
	}
	else if( !(BIT_IS_SET(GPT_register->TIM_CR1,CEN_BIT))){
		elapsed_time =0;
	}
	else{
		elapsed_time= GPT_register->TIM_CNT;
	}
	return elapsed_time;
}


/**********************************************************************************************************************
 * description : A function to return number of remaining ticks till the overflow ticks passed to GPT_StartTimer,
 * 				 0xffffffff if GPT_startTime is not called, 0 if an overflow occurred.
 *********************************************************************************************************************/
uint32 GPT_GetRemainingTime(void){
	uint32 remaining_time;
	if(BIT_IS_SET(GPT_register->TIM_SR,UIF_BIT)){
		CLEAR_BIT(GPT_register->TIM_SR,UIF_BIT);
		remaining_time =0;
	}
	else if( !(BIT_IS_SET(GPT_register->TIM_CR1,CEN_BIT))){
		remaining_time =0xffffffff;
	}
	else{
		remaining_time =(GPT_register ->TIM_ARR)-(GPT_register->TIM_CNT);
	}
	return remaining_time;
}
