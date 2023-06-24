/**************************************************************************************
 * File name  : SevenSegment.c
 * Description: source file for the driver of Seven Segment
 * Author     : Esraa Ali
 *************************************************************************************/

#include "SevenSegment.h"
#include "GPIO.h"
#include "Std_Types.h"

void SevenSegment_Init(uint8 Port_ID,uint8 startbin){
	uint8 seven_segment_init_counter = 0;
		/* initialize the 7 pins of the 7 segment as output ,push pull pins*/
		for (seven_segment_init_counter = startbin; seven_segment_init_counter < (7+startbin); seven_segment_init_counter++) {
			Gpio_ConfigPin(Port_ID, seven_segment_init_counter, GPIO_OUTPUT, GPIO_PUSH_PULL);
		}
}

void display_seven_segment(uint8 counter){
	switch (counter)
	{
	/***************************** Case of Number 0 *************************/
	case 0:
		Gpio_WritePin(GPIO_B, 0, HIGH);
		Gpio_WritePin(GPIO_B, 1, HIGH);
		Gpio_WritePin(GPIO_B, 2, HIGH);
		Gpio_WritePin(GPIO_B, 3, HIGH);
		Gpio_WritePin(GPIO_B, 4, HIGH);
		Gpio_WritePin(GPIO_B, 5, HIGH);
		Gpio_WritePin(GPIO_B, 6, LOW);
		break;

		/***************************** Case of Number 1 *************************/
	case 1:
		Gpio_WritePin(GPIO_B, 0, LOW);
		Gpio_WritePin(GPIO_B, 1, HIGH);
		Gpio_WritePin(GPIO_B, 2, HIGH);
		Gpio_WritePin(GPIO_B, 3, LOW);
		Gpio_WritePin(GPIO_B, 4, LOW);
		Gpio_WritePin(GPIO_B, 5, LOW);
		Gpio_WritePin(GPIO_B, 6, LOW);
		break;

		/***************************** Case of Number 2 *************************/
	case 2:
		Gpio_WritePin(GPIO_B, 0, HIGH);
		Gpio_WritePin(GPIO_B, 1, HIGH);
		Gpio_WritePin(GPIO_B, 2, LOW);
		Gpio_WritePin(GPIO_B, 3, HIGH);
		Gpio_WritePin(GPIO_B, 4, HIGH);
		Gpio_WritePin(GPIO_B, 5, LOW);
		Gpio_WritePin(GPIO_B, 6, HIGH);
		break;

		/***************************** Case of Number 3 *************************/
	case 3:
		Gpio_WritePin(GPIO_B, 0, HIGH);
		Gpio_WritePin(GPIO_B, 1, HIGH);
		Gpio_WritePin(GPIO_B, 2, HIGH);
		Gpio_WritePin(GPIO_B, 3, HIGH);
		Gpio_WritePin(GPIO_B, 4, LOW);
		Gpio_WritePin(GPIO_B, 5, LOW);
		Gpio_WritePin(GPIO_B, 6, HIGH);
		break;

		/***************************** Case of Number 4 *************************/
	case 4:
		Gpio_WritePin(GPIO_B, 0, LOW);
		Gpio_WritePin(GPIO_B, 1, HIGH);
		Gpio_WritePin(GPIO_B, 2, HIGH);
		Gpio_WritePin(GPIO_B, 3, LOW);
		Gpio_WritePin(GPIO_B, 4, LOW);
		Gpio_WritePin(GPIO_B, 5, HIGH);
		Gpio_WritePin(GPIO_B, 6, HIGH);
		break;

		/***************************** Case of Number 5 *************************/
	case 5:
		Gpio_WritePin(GPIO_B, 0, HIGH);
		Gpio_WritePin(GPIO_B, 1, LOW);
		Gpio_WritePin(GPIO_B, 2, HIGH);
		Gpio_WritePin(GPIO_B, 3, HIGH);
		Gpio_WritePin(GPIO_B, 4, LOW);
		Gpio_WritePin(GPIO_B, 5, HIGH);
		Gpio_WritePin(GPIO_B, 6, HIGH);
		break;

		/***************************** Case of Number 6 *************************/
	case 6:
		Gpio_WritePin(GPIO_B, 0, HIGH);
		Gpio_WritePin(GPIO_B, 1, LOW);
		Gpio_WritePin(GPIO_B, 2, HIGH);
		Gpio_WritePin(GPIO_B, 3, HIGH);
		Gpio_WritePin(GPIO_B, 4, HIGH);
		Gpio_WritePin(GPIO_B, 5, HIGH);
		Gpio_WritePin(GPIO_B, 6, HIGH);
		break;

		/***************************** Case of Number 7 *************************/
	case 7:
		Gpio_WritePin(GPIO_B, 0, HIGH);
		Gpio_WritePin(GPIO_B, 1, HIGH);
		Gpio_WritePin(GPIO_B, 2, HIGH);
		Gpio_WritePin(GPIO_B, 3, LOW);
		Gpio_WritePin(GPIO_B, 4, LOW);
		Gpio_WritePin(GPIO_B, 5, LOW);
		Gpio_WritePin(GPIO_B, 6, LOW);
		break;

		/***************************** Case of Number 8 *************************/
	case 8:
		Gpio_WritePin(GPIO_B, 0, HIGH);
		Gpio_WritePin(GPIO_B, 1, HIGH);
		Gpio_WritePin(GPIO_B, 2, HIGH);
		Gpio_WritePin(GPIO_B, 3, HIGH);
		Gpio_WritePin(GPIO_B, 4, HIGH);
		Gpio_WritePin(GPIO_B, 5, HIGH);
		Gpio_WritePin(GPIO_B, 6, HIGH);
		break;

		/***************************** Case of Number 9 *************************/
	case 9:
		Gpio_WritePin(GPIO_B, 0, HIGH);
		Gpio_WritePin(GPIO_B, 1, HIGH);
		Gpio_WritePin(GPIO_B, 2, HIGH);
		Gpio_WritePin(GPIO_B, 3, HIGH);
		Gpio_WritePin(GPIO_B, 4, LOW);
		Gpio_WritePin(GPIO_B, 5, HIGH);
		Gpio_WritePin(GPIO_B, 6, HIGH);
		;
		break;
	default:
		break;
	}
}
