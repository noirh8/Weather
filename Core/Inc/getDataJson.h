/*
 * getDataJson.h
 *
 *  Created on: Dec 12, 2024
 *      Author: LENOVO
 */

#ifndef INC_GETDATAJSON_H_
#define INC_GETDATAJSON_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "WeatherApp.h"
#include "json_array.h"
#include "json_parser.h"
#include "main.h"

extern char *json_start;
extern char *daily_section ;
extern char *current_section;
int getDataWind(int a);
int getDataTemp(int a);
int getDataCodeWeather(int a);
void test();
void getDailyTime();
char* getDataMonth(int a);
int getDataDay(int a);
int stringToInt(char *str);
void get_Data_json(void);

#endif /* INC_GETDATAJSON_H_ */
