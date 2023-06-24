 /******************************************************************************
 *
 * File Name: Exti_Private.h
 *
 * Description: Private data (Register) of EXTI module
 *
 * Author: Esraa Ali
 *
 *******************************************************************************/

/*Garding to prevent multiple inclusion for the same file*/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#include "Std_Types.h"

/*Structure Hold EXTI registers */
typedef struct {
	uint32 EXTI_IMR;
	uint32 EXTI_EMR;
	uint32 EXTI_RTSR;
	uint32 EXTI_FTSR;
	uint32 EXTI_SWIER;
	uint32 EXTI_PR;
} ExtiType;

#endif
