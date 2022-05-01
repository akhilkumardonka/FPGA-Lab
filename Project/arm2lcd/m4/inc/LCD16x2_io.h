#ifndef LCD16X2_IO_H_
#define LCD16X2_IO_H_

#include "PyHal_GPIO.h"

#define     LCD_D4  6
#define     LCD_D5  8
#define     LCD_D6  10
#define     LCD_D7  12
#define     LCD_RS  2
#define     LCD_EN  4

/*
 * Sets the LCD RS (RS = 1)
 */ 
static inline void LCD_SET_RS()
{
	// GPIOB->BSRR = 1;
    PyHal_GPIO_Set(LCD_RS,1);
}

/*
 * Sets the LCD Enable (E = 1)
 */
static inline void LCD_SET_E()
{
	// GPIOB->BSRR = 2;
    PyHal_GPIO_Set(LCD_EN,1);
}

/*
 * Resets the LCD RS (RS = 0)
 */
static inline void LCD_RST_RS()
{
	// GPIOB->BRR = 1;
    PyHal_GPIO_Set(LCD_RS,0);
}

/*
 * Resets the LCD Enable (E = 0)
 */
static inline void LCD_RST_E()
{
	PyHal_GPIO_Set(LCD_EN,0);
}

/*
 * Configure the IOs
 */
static inline void LcdConfigIO()
{
	// GPIOB->CRL = (GPIOB->CRL & 0xFF000000) | 0x00222222;
    PyHal_GPIO_SetDir(LCD_D4,1);
    PyHal_GPIO_SetDir(LCD_D5,1);
    PyHal_GPIO_SetDir(LCD_D6,1);
    PyHal_GPIO_SetDir(LCD_D7,1);
    PyHal_GPIO_SetDir(LCD_RS,1);
    PyHal_GPIO_SetDir(LCD_EN,1);
}

/*
 * Write a nibble to the LCD bus
 */
static inline void LcdPutNibble(char data)
{
	// GPIOB->BRR = ~(data << 2) & 0b00111100;
	// GPIOB->BSRR = (data << 2) & 0b00111100;
    
    if(data & 1)
    	PyHal_GPIO_Set( LCD_D4, 1);
    else
    	PyHal_GPIO_Set( LCD_D4, 0);
    if(data & 2)
    	PyHal_GPIO_Set( LCD_D5, 1);
    else
    	PyHal_GPIO_Set( LCD_D5, 0);
    if(data & 4)
    	PyHal_GPIO_Set( LCD_D6, 1);
    else
    	PyHal_GPIO_Set( LCD_D6, 0);
    if(data & 8)
    	PyHal_GPIO_Set( LCD_D7, 1);
    else
    	PyHal_GPIO_Set( LCD_D7, 0);

}
 
#endif 