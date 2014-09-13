/*
 * helpers.c
 *
 *  Created on: 13 wrz 2014
 *      Author: pokm
 */
#include "helpers.h"

void turnOffLeds(void)
{
	/* turn on LEDs. */
	if (BSP_LED2_IS_ON())
	{
		toggleLED(2);
	}
	if (BSP_LED1_IS_ON())
	{
		toggleLED(1);
	}
}

void turnOnLeds(void)
{
	/* turn on LEDs. */
	if (!BSP_LED2_IS_ON())
	{
		toggleLED(2);
	}
	if (!BSP_LED1_IS_ON())
	{
		toggleLED(1);
	}
}

void toggleLED(uint8_t which)
{
  if (1 == which)
  {
    BSP_TOGGLE_LED1();
  }
  else if (2 == which)
  {
    BSP_TOGGLE_LED2();
  }
  return;
}
