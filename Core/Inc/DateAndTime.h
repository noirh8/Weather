/*
 * DateAndTime.h
 *
 *  Created on: Dec 2, 2022
 *      Author: Pietia2
 */

#ifndef INC_DATEANDTIME_H_
#define INC_DATEANDTIME_H_

#include "main.h"
#include "stm32f4xx_hal_conf.h"
#include "SoftwareTimers.h"

/* RTC config */
/* ******************************************************************************** */
#define RTC_HANDLER         hrtc
extern RTC_HandleTypeDef    RTC_HANDLER;

#define RTC_READ_PERIOD     1000
/* ******************************************************************************** */

typedef enum _DateAndTime_TimeType
{
    WINTER_TIME = 1,
    SUMMER_TIME = 2,
}DateAndTime_TimeType;

void DateTime_SetNewDate(uint8_t Day, uint8_t DayWeek, uint8_t Month, uint8_t Year);
void DateTime_SetNewTime(uint8_t Hour, uint8_t Minutes, uint8_t Seconds);

void ReadDateAndTime(SoftwareTimer *SWTimer);
void CheckActualDateAfterRestart(void);

char* GetTimeString(void);
char* GetDateString(void);
char* GetDayString(void);
char* GetMonthString(void);
uint8_t GetRTCDateDay(void);
uint8_t GetRTCDateMonth(void);
uint8_t GetRTCDateYear(void);

char* GetNext_1_DayString(void);
char* GetNext_2_DayString(void);
char* GetNext_3_DayString(void);
char* GetNext_4_DayString(void);
char* GetNext_5_DayString(void);
char* GetNext_6_DayString(void);

uint8_t GetActualDay(void);
uint8_t GetActualMinutes(void);
void CalculateNextDayDate(uint8_t NextDayAmount, uint16_t *Year, uint8_t *Month, uint8_t *Day);
void RestoreDateFromBackupRegister(void);
uint8_t DateAndTime_CalculateDayInWeek(int Date, int Month, int Year);

void DateAndTime_SetTimeType(DateAndTime_TimeType NewTimeType);
DateAndTime_TimeType DateAndTime_GetTimeType(void);
uint8_t DateAndTime_GetTimeTypeOffset(void);

#endif /* INC_DATEANDTIME_H_ */
