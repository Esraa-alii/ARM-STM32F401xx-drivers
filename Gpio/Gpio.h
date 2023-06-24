/**************************************************************************************
 * File name  : Gpio.h
 * Description: header file for the driver of GPIO module
 * Author     : Esraa Ali
 *************************************************************************************/

/* Header guard to prevent multiple inclusion*/
#ifndef GPIO_H_
#define GPIO_H_

/****************************************************************************************************************
 *            					                  Inclusion              				                         *
 ***************************************************************************************************************/
#include "Std_Types.h"

/*PortName*/
#define GPIO_A          'A'
#define GPIO_B          'B'
#define GPIO_C          'C'
#define GPIO_D          'D'
#define GPIO_E          'E'
#define GPIO_PORTH      'H'

/*PinMode*/
#define GPIO_INPUT      0x00
#define GPIO_OUTPUT     0x01
#define GPIO_AF         0x02
#define GPIO_ANALOG     0x03

/*DefaultState case of output pin*/
#define GPIO_PUSH_PULL  0x00
#define GPIO_OPEN_DRAIN 0x01

/*DefaultState case of input pin*/
#define GPIO_NOT_PU_PD  0x00
#define GPIO_PULL_UP    0X01
#define GPIO_PULL_DOWN  0x10
#define GPIO_RESERVED   0X01


/*Data*/
#define LOW             0x00
#define HIGH            0x01

#define OK              (1)
#define NOK             (0)

/*******************************************************************************************************************
 *                    						  Functions Prototypes				                                   *
 *********************************************************************************************************************/
void Gpio_init(uint8 PortName);
void Gpio_ConfigPin(uint8 PortName, uint8 PinNum, uint8 PinMode, uint8 DefaultState);
void Gpio_WritePin(uint8 PortName, uint8 PinNum, uint8 Data);
uint8 Gpio_ReadPin(uint8 PortName, uint8 PinNum);


#endif /* GPIO_H */
