#include "ILI9488.h"
#include "stm32f1xx_hal.h"
/* include for HAL_Delay */


void BUS_output(void){

  GPIO_InitTypeDef GPIO_InitStruct;
  
  /*Configure GPIO pins : PB0 PB10 PB11 PB12 
                           PB8 PB9 */
  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LCD_BUS, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3 
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

  GPIO_InitStruct.Pin =  GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3 
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;

  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(LCD_BUS, &GPIO_InitStruct);
}

void BUS_input(void){
  GPIO_InitTypeDef GPIO_InitStruct;

  /*Configure GPIO pin Output Level */
 
 GPIO_InitStruct.Pin =  GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3 
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;

  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(LCD_BUS, &GPIO_InitStruct);

  HAL_GPIO_WritePin(LCD_BUS, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3 
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

}



void ILI9488WriteReg(uint16_t data) {



  HAL_GPIO_WritePin(GPIOB, GPIO_DC,GPIO_PIN_RESET);

  WRITE_LCD(data&0xff);
  HAL_GPIO_WritePin(GPIOB, GPIO_WR,GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOB, GPIO_WR,GPIO_PIN_SET);

  HAL_GPIO_WritePin(GPIOB, GPIO_DC,GPIO_PIN_SET);

}

void ILI9488WriteData(uint16_t data) {


  WRITE_LCD(data&0xff);
  HAL_GPIO_WritePin(GPIOB, GPIO_WR,GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOB, GPIO_WR,GPIO_PIN_SET);
	if(data>255){
  WRITE_LCD(data>>8);
  HAL_GPIO_WritePin(GPIOB, GPIO_WR,GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOB, GPIO_WR,GPIO_PIN_SET);

	}



}

uint16_t ILI9488ReadData(void) {
	uint16_t data;
	BUS_input();
	HAL_GPIO_WritePin(GPIOB, GPIO_DC,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_WR,GPIO_PIN_SET);


  HAL_GPIO_WritePin(GPIOB, GPIO_RD,GPIO_PIN_RESET);
  data=READ_LCD;
  HAL_GPIO_WritePin(GPIOB, GPIO_RD,GPIO_PIN_SET);
	BUS_output();
	return data;
}
void ILI9488_Initial_Code(void)
{

	/* Hardware reset */
	HAL_GPIO_WritePin(GPIOB, GPIO_RES,GPIO_PIN_SET);
	HAL_Delay(2);
	HAL_GPIO_WritePin(GPIOB, GPIO_RES,GPIO_PIN_RESET);
	HAL_Delay(10);
	HAL_GPIO_WritePin(GPIOB, GPIO_RES,GPIO_PIN_SET);
	HAL_Delay(120);

	ILI9488WriteReg( 0xF7);
	ILI9488WriteData( 0xA9);
	ILI9488WriteData( 0x51);
	ILI9488WriteData( 0x2C);
	ILI9488WriteData( 0x82);

	ILI9488WriteReg( 0xC0);
	ILI9488WriteData( 0x11);
	ILI9488WriteData( 0x09);

	ILI9488WriteReg( 0xC1);
	ILI9488WriteData( 0x41);

	ILI9488WriteReg( 0xC5);
	ILI9488WriteData( 0x00);
	ILI9488WriteData( 0x2A);
	ILI9488WriteData( 0x80);

	ILI9488WriteReg(0XB0);      // Interface Mode Control
	ILI9488WriteData(0x00);     			 //SDO NOT USE

	ILI9488WriteReg( 0xB1);
	ILI9488WriteData( 0xB0);
//	ILI9488WriteData( 0x11);

	ILI9488WriteReg( 0xB4);
	ILI9488WriteData( 0x02);

	ILI9488WriteReg( 0xB6);
	ILI9488WriteData( 0x02);
	ILI9488WriteData( 0x22);
	ILI9488WriteData( 0x3B);

	ILI9488WriteReg( 0xB7);
	ILI9488WriteData( 0xC6);

	ILI9488WriteReg( 0xBE);
	ILI9488WriteData( 0x00);
	ILI9488WriteData( 0x04);

	ILI9488WriteReg( 0xE9);
	ILI9488WriteData( 0x00);

	ILI9488WriteReg( 0x36);// Interface Pixel Format
	ILI9488WriteData( 0x08);

	ILI9488WriteReg( 0x3A);
	ILI9488WriteData( 0x55);

	ILI9488WriteReg( 0xE0);
	ILI9488WriteData( 0x00);
	ILI9488WriteData( 0x07);
	ILI9488WriteData( 0x12);
	ILI9488WriteData( 0x0B);
	ILI9488WriteData( 0x18);
	ILI9488WriteData( 0x0B);
	ILI9488WriteData( 0x3F);
	ILI9488WriteData( 0x9B);
	ILI9488WriteData( 0x4B);
	ILI9488WriteData( 0x0B);
	ILI9488WriteData( 0x0F);
	ILI9488WriteData( 0x0B);
	ILI9488WriteData( 0x15);
	ILI9488WriteData( 0x17);
	ILI9488WriteData( 0x0F);

	ILI9488WriteReg( 0xE1);
	ILI9488WriteData( 0x00);
	ILI9488WriteData( 0x16);
	ILI9488WriteData( 0x1B);
	ILI9488WriteData( 0x02);
	ILI9488WriteData( 0x0F);
	ILI9488WriteData( 0x06);
	ILI9488WriteData( 0x34);
	ILI9488WriteData( 0x46);
	ILI9488WriteData( 0x48);
	ILI9488WriteData( 0x04);
	ILI9488WriteData( 0x0D);
	ILI9488WriteData( 0x0D);
	ILI9488WriteData( 0x35);
	ILI9488WriteData( 0x36);
	ILI9488WriteData( 0x0F);

	ILI9488WriteReg( 0x11);
  	HAL_Delay(120);
	ILI9488WriteReg( 0x29);

}


void ILI9488DisplayOn()
{
	ILI9488WriteReg(0x29);
}

void ILI9488DisplayOff()
{
	ILI9488WriteReg(0x28);
}

void ILI9488MemoryWrite(unsigned short * pData, unsigned long size)
{
	unsigned long i;
	ILI9488WriteReg(0x2C);
	for(i=0;i<size;i++)
	{
		ILI9488WriteData(*pData++);
	}
}



void ILI9488RamAddress(void)
{
	// set column address
	ILI9488WriteReg(0x2a);
	ILI9488WriteData(0x00);
	ILI9488WriteData(0x00);
	ILI9488WriteData(0x01);
	ILI9488WriteData(0x3f);

	// set page address
	ILI9488WriteReg(0x2b);
	ILI9488WriteData(0x00);
	ILI9488WriteData(0x00);
	ILI9488WriteData(0x01);
	ILI9488WriteData(0xdf);

	// send command memory write
	ILI9488WriteReg(0x2c);
}

void ILI9844NormalDisplayModeOn()
{
	ILI9488WriteReg(0x13);
}

void ILI9844AllPixelOn()
{
	ILI9488WriteReg(0x23);
}

void ILI9844AllPixelOff()
{
	ILI9488WriteReg(0x22);
}

void ILI9844ColumnAddressSet(unsigned short SC, unsigned short EC)
{
	ILI9488WriteReg(0x2A);
	ILI9488WriteData( (SC & 0xFF00) >> 8);
	ILI9488WriteData(SC & 0xFF);
	ILI9488WriteData( (EC & 0xFF00) >> 8);
	ILI9488WriteData(EC & 0xFF);
}

void Ili9844PageAddressSet(unsigned short SP, unsigned short EP)
{
	ILI9488WriteReg(0x2B);
	ILI9488WriteData( (SP & 0xFF00) >> 8);
	ILI9488WriteData(SP & 0xFF);
	ILI9488WriteData( (EP & 0xFF00) >> 8);
	ILI9488WriteData(EP & 0xFF);
}

void ILI9488MemoryRead(unsigned short * pData, unsigned short size)
{
	unsigned short i;
	ILI9488WriteReg(0x2E);
	BUS_input();
	for(i=0;i<size;i++)
	{
  		HAL_GPIO_WritePin(GPIOB, GPIO_RD,GPIO_PIN_RESET);
		*pData++ = READ_LCD;
  		HAL_GPIO_WritePin(GPIOB, GPIO_RD,GPIO_PIN_SET);
	}
	BUS_output();
}

unsigned long ILI9488ReadDisplayStatus()
{
	volatile unsigned long tmp;
	ILI9488WriteReg(0x09);
	BUS_input();

	tmp=ILI9488ReadData()<<24;
	tmp=ILI9488ReadData()<<16;
	tmp=ILI9488ReadData()<<8;
	tmp=ILI9488ReadData();

	BUS_output();
	return tmp;
}

unsigned long ILI9488_ReadID(void) {
	unsigned char buf[4];
	ILI9488WriteReg(0x04);
	BUS_input();

	buf[0] = ILI9488ReadData();

	buf[1] = ILI9488ReadData();

	buf[2] = ILI9488ReadData();

	buf[3] = ILI9488ReadData();

	BUS_output();
	return (buf[1]<<16)+(buf[2]<<8)+(buf[3]);
}

unsigned short ILI9844ReadNumberOfTheErrorsOnDsi()
{
	volatile unsigned short tmp;
	ILI9488WriteReg(0x05);
	BUS_input();

	HAL_GPIO_WritePin(GPIOB, GPIO_RD,GPIO_PIN_RESET);
	tmp = READ_LCD;
	HAL_GPIO_WritePin(GPIOB, GPIO_RD,GPIO_PIN_SET);
	BUS_output();
	return tmp;
}
