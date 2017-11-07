#ifndef _ILI9488_H
#define _ILI9488_H
#include "stm32f1xx_hal.h"


//GPIOA first 8 pins for data
#define GPIO_DC GPIO_PIN_0 //this pin is called rs on my dev board
#define GPIO_WR GPIO_PIN_8
#define GPIO_RD GPIO_PIN_9
#define GPIO_RES GPIO_PIN_10
  
#define LCD_BUS GPIOA
#define WRITE_LCD(data) LCD_BUS->BSRR = (LCD_BUS->BSRR & 0xff00ff00) | (uint32_t)(((0x00ff & ~data) << 16u)| (0x00ff & data));
#define READ_LCD (LCD_BUS->IDR & 0b0000000011111111)

void BUS_output(void);
void BUS_input(void);
void ILI9488DisplayOn(void);
void ILI9488DisplayOff(void);
void ILI9844NormalDisplayModeOn(void);
unsigned long ILI9488_ReadID(void);
unsigned long ILI9488ReadDisplayStatus(void);
void ILI9844AllPixelOn(void);
void ILI9844AllPixelOff(void);

void ILI9488_Initial_Code(void);
void ILI9488MemoryRead(unsigned short * pData, unsigned short size);
void ILI9488WriteReg(uint16_t data) ;
void ILI9488WriteData(uint16_t data) ;
uint16_t ILI9488ReadData(void) ;

#endif
