#include "gfx.h"
#include "stm32f1xx_hal.h"

void raw32Init(void)
{
//handled by hal
}

systemticks_t gfxSystemTicks(void)
{
    // We use a counter with a 1kHz clock source
	return HAL_GetTick();
}
 
systemticks_t gfxMillisecondsToTicks(delaytime_t ms)
{
    // We use a counter with a 1kHz clock source
	return ms;
}
