/*
 * This file is subject to the terms of the GFX License. If a copy of
 * the license was not distributed with this file, you can obtain one at:
 *
 *              http://ugfx.org/license.html
 */

#ifndef _GDISP_LLD_BOARD_H
#define _GDISP_LLD_BOARD_H
#include "ILI9488.h"

#include "stm32f1xx_hal.h"
static GFXINLINE void init_board(GDisplay *g) {
	(void) g;
}

static GFXINLINE void post_init_board(GDisplay *g) {
	(void) g;
}

static GFXINLINE void setpin_reset(GDisplay *g, bool_t state) {
	(void) g;
	(void) state;
	HAL_GPIO_WritePin(GPIOB, GPIO_RES,state);
}

static GFXINLINE void set_backlight(GDisplay *g, uint8_t percent) {
	(void) g;
	(void) percent;
}

static GFXINLINE void acquire_bus(GDisplay *g) {
	(void) g;
}

static GFXINLINE void release_bus(GDisplay *g) {
	(void) g;
}
 

static GFXINLINE void write_index(GDisplay *g, uint16_t index) {
	(void) g;
	(void) index;
	ILI9488WriteReg(index);
}

static GFXINLINE void write_data8(GDisplay *g, uint16_t data) {
	(void) g;
	(void) data;
	ILI9488Write8bit(data);
}


static GFXINLINE void write_data(GDisplay *g, uint16_t data) {
	(void) g;
	(void) data;
	ILI9488WriteData(data);
}

static GFXINLINE void setreadmode(GDisplay *g) {
	(void) g;
}

static GFXINLINE void setwritemode(GDisplay *g) {
	(void) g;
}

static GFXINLINE uint16_t read_data(GDisplay *g) {
	(void) g;
	return ILI9488ReadData();
}

#endif /* _GDISP_LLD_BOARD_H */
