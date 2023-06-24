/**************************************************************************
 * File name  : keypad.h
 * Description: header file for keypad module
 * Author     : Esraa Ali
 ***************************************************************************/

#ifndef STD_TYPES_H_ // Header guard to prevent multiple inclusion
#define STD_TYPES_H_

/*******************************************************************************
 *                              Inclusion                                       *
 *******************************************************************************/
#include "Gpio.h"        // Include the Gpio header file
#include "Std_Types.h"  // Include the Standard Types header file


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Column configurations */
#define KEYPAD_COLUMNS_PORT       GPIO_B   // Set the GPIO port for the keypad columns
#define KEYPAD_COLUMNS_START_PIN  0        // Set the starting pin for the keypad columns
#define KEYPAD_NUMBER_OF_COLUMNS  3        // Set the number of keypad columns

/* Row configurations */
#define KEYPAD_ROWS_PORT          GPIO_B  // Set the GPIO port for the keypad rows
#define KEYPAD_ROWS_START_PIN     5       // Set the starting pin for the keypad rows
#define KEYPAD_NUMBER_OF_ROWS     4       // Set the number of keypad rows

typedef enum{
	BUTTON_PRESSED , BUTTON_RELEASED
}button_state;



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/* Initialize the keypad module */
void keypad_Init(void);

/* Manage the keypad */
void keypad_Manage(void);

/* Get the currently pressed key */
uint8 keypad_GetKey(void);

/* Function to be called when a key is pressed */
void KeypadCallouts_KeyPressNotificaton(void);

#endif // End of header guard
