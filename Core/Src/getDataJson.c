
#include "getDataJson.h"



char *daily_section = NULL;
char *current_section = NULL;
char *json_start = NULL;






int stringToInt(char *str)
{
    int num = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            num = num * 10 + (str[i] - '0');
        } else {
            return -1;
        }
    }
    return num;
}
int getDataTemp(int a)
{
    json_start = strstr(RX_buffer, "{");
    daily_section = strstr(json_start, "\"daily\":");
    current_section = strstr(json_start, "\"current\":");
	get_Temp_Max(json_start, temp_max, daily_section);
	return (int)(temp_max[a] + 0.5);
}
int getDataWind(int a)
{
    json_start = strstr(RX_buffer, "{");
    daily_section = strstr(json_start, "\"daily\":");
    current_section = strstr(json_start, "\"current\":");
	get_Wind_Speed_Max(json_start, wind_max, daily_section);
	return (int)(wind_max[a]+0.5);
}
int getDataCodeWeather(int a)
{
    json_start = strstr(RX_buffer, "{");
    daily_section = strstr(json_start, "\"daily\":");
    current_section = strstr(json_start, "\"current\":");
	get_Weather_Code(json_start, weather_code, daily_section);
	return weather_code[a];
}
void getDailyTime()
{
	 json_start = strstr(RX_buffer, "{");
	 int time_count = MAX_DAYS;
	 extract_array(json_start, "\"time\"", daily_time, &time_count);
	 for (int i = 0; i < time_count; i++) {
		 split_date(daily_time[i], year[i], month[i], day[i]);
	 }
}
int getDataDay(int a)
{
	 getDailyTime();
	 return stringToInt(day[a]);
}
char* getDataMonth(int a)
{
	 getDailyTime();
	 int num = stringToInt(month[a]);
	 switch(num)
	 {
	 	 	case 1:  return "JAN";
	        case 2:  return "FEB";
	        case 3:  return "MAR";
	        case 4:  return "APR";
	        case 5:  return "MAY";
	        case 6:  return "JUN";
	        case 7:  return "JUL";
	        case 8:  return "AUG";
	        case 9:  return "SEP";
	        case 10: return "OCT";
	        case 11: return "NOV";
	        case 12: return "DEC";
	        default: return "ERR";
	 }
}

