/*
  =============================================================================
 * Name			:application.c
 * Author		:Menna Saeed
 * Description 	:A system to measure the distance using ultrasonic sensor HC-SR04
 * Created on	:March 1, 2022
 ==============================================================================
 */

#include "lcd.h"
#include "ultrasonic.h"
#include "avr/io.h" /* To use the SREG register */
#include "avr/delay.h" /*To use the delay functions*/
/*==========================================================================*/

int main()
{

	SREG|=(1<<7); /* Enable Global Interrupt I-Bit */

	/* Initialize both the LCD and Ultrasonic driver */
	LCD_init();
	Ultrasonic_init();
	LCD_displayString("Distance=    cm ");

	uint16 distance=0; /*Distance to be measured and displayed on LCD*/


	while (1)
	{
		distance=Ultrasonic_readDistance();

		LCD_moveCursor(0, 10);
		LCD_intgerToString(distance);
				if(distance<100)
				{
					/* In case the digital value is two or one digits print space in the next digit place */
					LCD_displayCharacter(' ');
				}
		_delay_ms(100);
	}
}
