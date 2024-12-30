/*
 * WeatherGraphics.h
 *
 *  Created on: Dec 8, 2024
 *      Author: MSI MODERN 14
 */

#ifndef INC_WEATHERGRAPHICS_H_
#define INC_WEATHERGRAPHICS_H_
#include <stdint.h>
#include <stdbool.h>
unsigned long Button();
unsigned long App();

unsigned long optionScreen();

unsigned long waitingScreen();

unsigned long weatherStation();
unsigned long weatherStation1();
unsigned long weatherStation2();



unsigned long displayNextDay2(uint16_t x, uint16_t y, const char* day, const char* month, int date,int temp, int iconID);
unsigned long displayNextDay1(uint16_t x, uint16_t y, const char* day, const char* month, int date, int temp, int iconID);
unsigned long displayNextDay(uint16_t x, uint16_t y, const char* day, const char* month, int date, int temp, int iconID);

unsigned  long  iconWeather3 (uint16_t x, uint16_t y, int signal);
unsigned  long  iconWeather2 (uint16_t x, uint16_t y, int signal);
unsigned  long  iconWeather (uint16_t x, uint16_t y, int signal);
unsigned  long  iconWeatherMinor (uint16_t x, uint16_t y, int signal);
unsigned  long  iconWeatherMinor2 (uint16_t x, uint16_t y, int signal);




#endif /* INC_WEATHERGRAPHICS_H_ */
