
#include "main.h"
#include "stm32f4xx_hal_conf.h"
#include "DateAndTime.h"
#include "SoftwareTimers.h"
#include <stdio.h>
#include <string.h>
#include "Common.h"

#include "json_parser.h"

static RTC_DateTypeDef RtcDate;

static char TimeString[10];

static char DayString[12];



static char Next_1_DayString[12];
static char Next_2_DayString[12];
static char Next_3_DayString[12];
static char Next_4_DayString[12];
static char Next_5_DayString[12];
static char Next_6_DayString[12];



static void NextDayString(char *NexDayString, uint8_t NextDayNumber);




char* GetTimeString(void)
{
	//fixed
    sprintf(TimeString, "%02d:%02d", hour, min);
    return TimeString;
}



char* GetDayString(void)
{
	//fixed
	Common_ArrayClean(DayString, 12);

	  if (strstr(date, "Monday") != NULL) {
	        RtcDate.WeekDay = 1;
	    } else if (strstr(date, "Tuesday") != NULL) {
	        RtcDate.WeekDay = 2;
	    } else if (strstr(date, "Wednesday") != NULL) {
	        RtcDate.WeekDay = 3;
	    } else if (strstr(date, "Thursday") != NULL) {
	        RtcDate.WeekDay = 4;
	    } else if (strstr(date, "Friday") != NULL) {
	        RtcDate.WeekDay = 5;
	    } else if (strstr(date, "Saturday") != NULL) {
	        RtcDate.WeekDay = 6;
	    } else if (strstr(date, "Sunday") != NULL) {
	        RtcDate.WeekDay = 0;
	    } else {
	        RtcDate.WeekDay = -1;  // Nếu không phải là một ngày hợp lệ
	    }

    switch(RtcDate.WeekDay)
    {
    case 0:
    	memcpy(DayString, "SUN", strlen("SUN"));
        break;
    case 1:
    	memcpy(DayString, "MON", strlen( "MON"));
        break;
    case 2:
    	memcpy(DayString, "TUE", strlen("TUE"));
        break;
    case 3:
    	memcpy(DayString, "WED", strlen("WED"));
        break;
    case 4:
    	memcpy(DayString, "THU", strlen("THU"));
        break;
    case 5:
    	memcpy(DayString, "FRI", strlen("FRI"));
        break;
    case 6:
    	memcpy(DayString, "SAT", strlen("SAT"));
        break;

    default:
    	strcpy(DayString, "ERR");
        break;
    }
    return DayString;
}


char* GetNext_1_DayString(void)
{
    NextDayString(Next_1_DayString, 1);
    return Next_1_DayString;
}

char* GetNext_2_DayString(void)
{
    NextDayString(Next_2_DayString, 2);
    return Next_2_DayString;
}

char* GetNext_3_DayString(void)
{
    NextDayString(Next_3_DayString, 3);
    return Next_3_DayString;
}
char* GetNext_4_DayString(void)
{
    NextDayString(Next_4_DayString, 4);
    return Next_4_DayString;
}
char* GetNext_5_DayString(void)
{
    NextDayString(Next_5_DayString, 5);
    return Next_5_DayString;
}
char* GetNext_6_DayString(void)
{
    NextDayString(Next_6_DayString, 6);
    return Next_6_DayString;
}
static void NextDayString(char *NexDayString, uint8_t NextDayNumber)
{
    uint8_t CalculateDay = 0;

    if(RtcDate.WeekDay + NextDayNumber <= 6)
    {
        CalculateDay = RtcDate.WeekDay + NextDayNumber;
    }
    else if(RtcDate.WeekDay + NextDayNumber > 6)
    {
        CalculateDay = ((RtcDate.WeekDay + NextDayNumber) % 6) - 1;
    }

    switch(CalculateDay)
    {
    case 0:
        memcpy(NexDayString, "SUN", strlen("SUN"));
        break;
    case 1:
        memcpy(NexDayString, "MON", strlen("MON"));
        break;
    case 2:
        memcpy(NexDayString, "TUE", strlen("TUE"));
        break;
    case 3:
        memcpy(NexDayString, "WED", strlen("WED"));
        break;
    case 4:
        memcpy(NexDayString, "THU", strlen("THU"));
        break;
    case 5:
        memcpy(NexDayString, "FRI", strlen("FRI"));
        break;
    case 6:
        memcpy(NexDayString, "SAT", strlen("SAT"));
        break;

    default:
        memcpy(NexDayString, "ERR", strlen("ERR"));
        break;
    }
    //return DayString;
}

