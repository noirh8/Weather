
#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "json_array.h"

#define MAX_DAYS 7
extern volatile uint8_t key1_flag;
extern uint8_t data1;
extern uint8_t data2;
extern uint16_t idx;

extern uint8_t uart_complete; // Cờ báo dữ liệu nhận xong
extern uint8_t data_ready;

extern int hour, min;
extern char date[10];

extern char daily_time[MAX_DAYS][11];   
extern char year[MAX_DAYS][5];
extern char month[MAX_DAYS][3];
extern char day[MAX_DAYS][3];

extern float temp_max[MAX_DAYS];        
extern float temp_min[MAX_DAYS];        
extern float wind_max[MAX_DAYS];  
extern float weather_code[MAX_DAYS];      
extern int humidity;

void extract_value(char *src, const char *key, char *value, int value_size);
void extract_array(char *src, const char *key, char result[][11], int *count);
void extract_float_array(char *src, const char *key, float *result, int *count, char *search_start);

void get_Temp_Max(char *src, float *result, char *search_start);
void get_Temp_Min(char *src, float *result, char *search_start);
void get_Wind_Speed_Max(char *src, float *result, char *search_start);

void get_Weather_Code(char *src, float *result, char *search_start);
int get_Humidity(char *src, char *search_start);
void split_date(const char *date, char *year, char *month, char *day);
char* convertWeatherCode(int code);
void upDateData();
void uartInit();


void get_Time(void) 	;

#endif // JSON_PARSER_H
