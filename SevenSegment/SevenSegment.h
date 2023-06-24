/**************************************************************************************
 * File name  : SevenSegment.h
 * Description: header file for the driver of Seven Segment
 * Author     : Esraa Ali
 *************************************************************************************/

/* Header guard to prevent multiple inclusion*/
#ifndef SEVEN_SEGMENT_H
#define SEVEN_SEGMENT_H
/****************************************************************************************************************
 *            					                  Inclusion              				                         *
 ***************************************************************************************************************/
#include "Std_Types.h"

void SevenSegment_Init(uint8 Port_ID,uint8 startbin);
void display_seven_segment(uint8 counter);

#endif

