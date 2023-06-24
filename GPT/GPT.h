/**************************************************************************************
 * File name  : GPT.h
 * Description: header file for the driver of timer module
 * Author     : Esraa Ali
 *************************************************************************************/

/* Header guard to prevent multiple inclusion*/
#ifndef GPT_H
#define GPT_H
/****************************************************************************************************************
 *            					                  Inclusion              				                         *
 ***************************************************************************************************************/
#include "Std_Types.h"

/*******************************************************************************************************************
 *                    						  User configurations				                                   *
 *********************************************************************************************************************/
#define ARR_BUFFERED
#define UPCOUNTING
#define EDGE_ALIGN_MODE
#define PRESCALLER 3500
#define TIMER2
/*******************************************************************************************************************
 *                    						  Functions Prototypes				                                   *
 *********************************************************************************************************************/

/******************************************************************************************************************
 * description : A function to initialize the GPT registers with the needed initial values to support
 * 				the needed timing actions.
 *******************************************************************************************************************/
void GPT_Init(void);

/**********************************************************************************************************************
 * description : A function to request the GPT to start and send its number of tickets before timer overflow and stop.
 *********************************************************************************************************************/
void GPT_StartTimer(uint32 OverFlowTicks);

/**********************************************************************************************************************
 * description : A function to return (1) if an overflow occurred after the last call of GPT_StartTimer and (0)
 * 				 if no overflow occurred or GPT_StartTimer is not called from the last read.
 *********************************************************************************************************************/
uint8 GPT_CheckTimeIsElapsed(void);

/**********************************************************************************************************************
 * description : A function to return number of elapsed ticks from the last call of the GPT_StartTimer,
 * 				 0 if it is not called and 0xffffffff if an overflow occurred.
 *********************************************************************************************************************/
uint32 GPT_GetElapsedTime(void);

/**********************************************************************************************************************
 * description : A function to return number of remaining ticks till the overflow ticks passed to GPT_StartTimer,
 * 				 0xffffffff if GPT_startTime is not called, 0 if an overflow occurred.
 *********************************************************************************************************************/
uint32 GPT_GetRemainingTime(void);


#endif
