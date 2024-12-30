/*
 * SkyWar.h
 *
 *  Created on: Dec 27, 2024
 *      Author: MSI MODERN 14
 */

#ifndef INC_SKYWAR_H_
#define INC_SKYWAR_H_
#include "touch.h"
#include "image.h"
#include "stdio.h"
#include "ili9341.h"
#include "ConTrolApp.h"
#include "SkyWarGraphics.h"
#include <math.h>
#include "stdio.h"
#include "stdbool.h"

extern float touchX,touchY;
extern int rTouchX,rTouchY;
extern int bulletCooldown;

void displayWaitingGameScreen();

#endif /* INC_SKYWAR_H_ */
