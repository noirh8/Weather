/*
 * ControlApp.h
 *
 *  Created on: Dec 8, 2024
 *      Author: MSI MODERN 14
 */

#ifndef INC_CONTROLAPP_H_
#define INC_CONTROLAPP_H_

#include "ili9341.h"
#include "DateAndTime.h"
#include "touch.h"
#include "WeatherGraphics.h"
#include "FunctionPointer.h"
#include "SkyWar.h"





extern uint16_t runningScreen ;
extern FunctionList currentScreen;


void appScreen ();

void initApp ();
void runScreen ();

void controlButton ();

#endif /* INC_CONTROLAPP_H_ */
