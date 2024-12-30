#include "WeatherGraphics.h"
#include "ili9341.h"
#include "DateAndTime.h"
#include "touch.h"
#include "json_parser.h"
#include "getDataJson.h"
void getDailyTime();
unsigned long Button()
{
	lcdFillRect(0, 290, 240 ,35 , COLOR_WHITE);
	lcdDrawImage( 5 , 292, & iconBack);
	lcdDrawImage( 110 , 292, & iconHome);
	lcdDrawImage(	205  , 292, & iconRefresh);

	return 0;
}

unsigned long optionScreen()
{
	lcdFillRGB(COLOR_WHITE);
	lcdSetTextColor(COLOR_WHITE, COLOR_BackGround_2);
	lcdFillRect(30, 50, 180 ,35 , COLOR_BackGround_2);
	lcdSetCursor( 35 , 62 );
	lcdSetTextFont( & Font16 );
	lcdPrintf( "WEATHERSTATION" );
	lcdFillRect(30, 105, 180 ,35 , COLOR_BackGround_2);
	lcdSetCursor( 35 , 117 );
	lcdSetTextFont( & Font16 );
	lcdPrintf( "WEATHERSTATION1" );
	lcdFillRect(30, 160, 180 ,35 , COLOR_BackGround_2);
	lcdSetCursor( 35 , 172 );
	lcdSetTextFont( & Font16 );
	lcdPrintf( "WEATHERSTATION2" );
	lcdPrintf( "",Button() );
	return 0;
}
unsigned long waitingScreen()
{
	lcdFillRGB(COLOR_BackGround_1);
	lcdDrawImage( 65 , 35, & iconCloud);
	lcdSetCursor( 15 , 30 );
	lcdSetTextColor(COLOR_WHITE, COLOR_BackGround_1);
	lcdSetTextFont( & Font20 );
	lcdPrintf( "WEATHER STATION" );
	lcdDrawVLine(5, 180, 260, COLOR_WHITE);
	lcdDrawVLine(235, 180, 260, COLOR_WHITE);
	lcdDrawVLine(160, 180, 260, COLOR_WHITE);
	lcdDrawHLine(5, 235, 180, COLOR_WHITE);
	lcdSetTextFont( & Font16 );
	lcdSetCursor( 30 , 185 );
	lcdPrintf( "HO VA TEN" );
	lcdSetCursor( 175 , 185 );
	lcdPrintf( "MSSV" );
	lcdSetTextFont( & Font12 );
	lcdDrawHLine(5, 235, 200, COLOR_WHITE);
	lcdSetCursor( 15 , 205 );
	lcdPrintf( "NGUYEN DINH LE MANH" );
	lcdSetCursor( 170 , 205 );
	lcdPrintf( "22520848" );
	lcdDrawHLine(5, 235, 220, COLOR_WHITE);
	lcdSetCursor( 15 , 225 );
	lcdPrintf( "LE TRONG DIEN" );
	lcdSetCursor( 170 , 225 );
	lcdPrintf( "22520246" );
	lcdDrawHLine(5, 235, 240, COLOR_WHITE);
	lcdSetCursor( 15 , 245 );
	lcdPrintf( "PHAM DINH BAO HOANG" );
	lcdSetCursor( 170 , 245 );
	lcdPrintf( "22520473" );
	lcdDrawHLine(5, 235, 260, COLOR_WHITE);
	return 0;
}
unsigned long weatherStation()
{
	lcdFillRGB(COLOR_BackGround_1);
	lcdDrawImage( 0 , 0, & imageMorning);
	lcdSetTextColor(COLOR_WHITE, COLOR_BackGround_1);
	lcdSetCursor( 30 , 30 );
	lcdSetTextFont( & Font24 );
	lcdPrintf( GetDayString() );
	lcdSetCursor( 30 , 50 );
	lcdSetTextFont( & Font16 );
	lcdPrintf( getDataMonth(0) );
	lcdSetCursor( 64 , 50 );
	lcdPrintf( "%2u", getDataDay(0) );
	lcdSetCursor( 30 , 65 );
	lcdSetTextFont( & Font12 );
	lcdPrintf( GetTimeString() );
	lcdSetCursor( 67 , 65 );
	lcdSetTextFont( & Font12 );

	lcdDrawImage( 65 , 80, & iconTemp);
	lcdSetCursor( 35 , 85 );
	lcdSetTextFont( & Font20 );
	lcdPrintf( "%2u", getDataTemp(0));
	lcdDrawImage( 66 , 120, & iconWind);
	lcdSetCursor( 101 , 125 );
	lcdSetTextFont( & Font16 );
	lcdPrintf( "%2u", getDataWind(0));
	lcdSetCursor( 131 , 126 );
	lcdSetTextFont( & Font12 );
	lcdPrintf( "Km/h" );
	lcdPrintf( "" , iconWeather(95 , 20,  getDataCodeWeather(0)));
	lcdPrintf( "" , displayNextDay(8, 210,  GetNext_1_DayString(), getDataMonth(1), getDataDay(1), getDataTemp(1), getDataCodeWeather(1)));
	lcdPrintf( "" , displayNextDay(48, 210, GetNext_2_DayString(), getDataMonth(2), getDataDay(2), getDataTemp(2), getDataCodeWeather(2)));
	lcdPrintf( "" , displayNextDay(88, 210, GetNext_3_DayString(), getDataMonth(3), getDataDay(3), getDataTemp(3), getDataCodeWeather(3)));
	lcdPrintf( "" , displayNextDay(128, 210, GetNext_4_DayString(), getDataMonth(4), getDataDay(4), getDataTemp(4), getDataCodeWeather(4)));
	lcdPrintf( "" , displayNextDay(168, 210, GetNext_5_DayString(), getDataMonth(5), getDataDay(5), getDataTemp(5), getDataCodeWeather(5)));
	lcdPrintf( "" , displayNextDay(208, 210, GetNext_6_DayString(), getDataMonth(6), getDataDay(6), getDataTemp(6), getDataCodeWeather(6)));
	lcdDrawImage(	220  , 0, & iconMenu);
	lcdPrintf( "",Button() );
	return 0;
}
unsigned long weatherStation1()
{
//	lcdDrawImage( 0 , 0, & imageBackGround2);
	lcdFillRGB(COLOR_THEME_SKYBLUE_BASE);
	//lcdFillRGB(COLOR_BackGround_1);
	lcdFillRect(10, 8, 220, 23, COLOR_BackGround_3);
	lcdFillRect(10, 34, 220, 102, COLOR_WHITE);
	lcdFillRect(10, 142, 59, 15, COLOR_BackGround_3);
	lcdFillRect(10, 158, 59, 52, COLOR_WHITE);
	lcdFillRect(90, 142, 59, 15, COLOR_BackGround_3);
	lcdFillRect(90, 158, 59, 52, COLOR_WHITE);;
	lcdFillRect(170, 142, 59, 15, COLOR_BackGround_3);
	lcdFillRect(170, 158, 59, 52, COLOR_WHITE);
	lcdFillRect(10, 215, 59, 15, COLOR_BackGround_3);
	lcdFillRect(10, 231, 59, 52, COLOR_WHITE);
	lcdFillRect(90, 215, 59, 15, COLOR_BackGround_3);
	lcdFillRect(90, 231, 59, 52, COLOR_WHITE);
	lcdFillRect(170, 215, 59, 15, COLOR_BackGround_3);
	lcdFillRect(170, 231, 59, 52, COLOR_WHITE);
	lcdPrintf( "" , iconWeather(125 , 38, getDataCodeWeather(0)));
	lcdSetTextColor(COLOR_WHITE,COLOR_BackGround_3);
	lcdSetTextFont( & Font16 );
	lcdSetCursor( 25 , 14);
	lcdPrintf( GetDayString() );
	lcdSetCursor( 80 , 14 );
	lcdPrintf( getDataMonth(0));
	lcdSetCursor( 110 , 14 );
	lcdPrintf( "-%2u",  getDataDay(0));
	lcdSetCursor( 160 , 14 );
	lcdPrintf( GetTimeString() );
	lcdSetTextColor(COLOR_BLACK, COLOR_WHITE);
	lcdSetCursor( 50 , 105 );
	lcdPrintf( "%2u", getDataWind(0) );
	lcdSetCursor( 85 , 106 );
	lcdSetTextFont( & Font12 );
	lcdPrintf( "Km/h" );
	lcdSetTextFont( & Font24 );
	lcdSetCursor( 25 , 60 );
	lcdPrintf(  "%2u", getDataTemp(0) );
	lcdDrawImage( 85 , 50, & iconTemp2);
	lcdDrawImage( 15 , 100, & iconWind2);
	lcdPrintf( "" , displayNextDay1(28, 144,  GetNext_1_DayString(),  getDataMonth(1), getDataDay(1),  getDataTemp(1), getDataCodeWeather(1)));
	lcdPrintf( "" , displayNextDay1(108, 144, GetNext_2_DayString(),  getDataMonth(2), getDataDay(2),  getDataTemp(2), getDataCodeWeather(2)));
	lcdPrintf( "" , displayNextDay1(188, 144, GetNext_3_DayString(),  getDataMonth(3), getDataDay(3),  getDataTemp(3), getDataCodeWeather(3)));
	lcdPrintf( "" , displayNextDay1(28, 217, GetNext_4_DayString(),  getDataMonth(4), getDataDay(4), getDataTemp(4), getDataCodeWeather(4)));
	lcdPrintf( "" , displayNextDay1(108, 217, GetNext_5_DayString(),  getDataMonth(5), getDataDay(5), getDataTemp(5), getDataCodeWeather(5)));
	lcdPrintf( "" , displayNextDay1(188, 217, GetNext_6_DayString(),  getDataMonth(6), getDataDay(6),  getDataTemp(6), getDataCodeWeather(6)));
	lcdDrawImage(	220  , 0, & iconMenu);
	lcdPrintf( "",Button() );
	return 0;
}
unsigned long weatherStation2()
{
//	lcdDrawImage( 0 , 0, & imageBackGround3);
	lcdFillRGB(COLOR_BackGround_3);
	lcdFillRect(10, 25, 102, 85, COLOR_WHITE);
	lcdFillRect(10, 117, 102, 170, COLOR_WHITE);
	lcdFillRect(130, 25, 100, 34, COLOR_WHITE);
	lcdFillRect(130, 70, 100, 34, COLOR_WHITE);
	lcdFillRect(130, 115, 100, 34, COLOR_WHITE);
	lcdFillRect(130, 162, 100, 34, COLOR_WHITE);
	lcdFillRect(130, 208, 100, 34, COLOR_WHITE);
	lcdFillRect(130, 253, 100, 34, COLOR_WHITE);
	lcdPrintf( "" , iconWeather(10, 115, getDataCodeWeather(0)));
	lcdSetTextColor(COLOR_BLACK, COLOR_WHITE);
	lcdSetTextFont( & Font24 );
	lcdSetCursor( 33 , 30);
	lcdPrintf( GetDayString() );
	lcdSetCursor( 20 , 86 );
	lcdPrintf( GetTimeString() );
	lcdSetTextFont( & Font20 );
	lcdSetCursor( 15 , 60 );
	lcdPrintf(  getDataMonth(0) );
	lcdSetCursor( 66 , 60 );
	lcdPrintf( "-%2u",  getDataDay(0));
	lcdSetTextColor(COLOR_BLACK, COLOR_WHITE);
	lcdSetTextFont( & Font16 );
	lcdSetCursor( 28 , 227 );
	lcdPrintf(  "%2u", getDataWind(0) );
	lcdSetCursor( 67 , 227 );
	lcdSetTextFont( & Font12 );
	lcdPrintf( "Km/h" );
	lcdSetTextFont( & Font24 );
	lcdSetCursor( 30 , 257 );
	lcdPrintf( "%2u", getDataTemp(0) );
	lcdDrawImage( 75 , 249, & iconTemp2);
	lcdDrawImage( 40 , 205, & iconWind2);
	lcdPrintf( "" , displayNextDay2(135, 30,  GetNext_1_DayString(), getDataMonth(1), getDataDay(1), getDataTemp(1), getDataCodeWeather(1)));
	lcdPrintf( "" , displayNextDay2(135, 75, GetNext_2_DayString(), getDataMonth(2), getDataDay(3),  getDataTemp(2), getDataCodeWeather(2)));
	lcdPrintf( "" , displayNextDay2(135, 120, GetNext_3_DayString(), getDataMonth(3), getDataDay(3), getDataTemp(3), getDataCodeWeather(3)));
	lcdPrintf( "" , displayNextDay2(135, 167, GetNext_4_DayString(), getDataMonth(4), getDataDay(4), getDataTemp(4), getDataCodeWeather(4)));
	lcdPrintf( "" , displayNextDay2(135, 212, GetNext_5_DayString(), getDataMonth(5), getDataDay(5), getDataTemp(5), getDataCodeWeather(5)));
	lcdPrintf( "" , displayNextDay2(135, 257, GetNext_6_DayString(), getDataMonth(6), getDataDay(6), getDataTemp(6), getDataCodeWeather(6)));
	lcdDrawImage(	220  , 0, & iconMenu);
	lcdPrintf( "",Button() );
	return 0;
}
unsigned long displayNextDay2(uint16_t x, uint16_t y, const char* day, const char* month,  int date, int temp, int iconID)
{

	lcdSetTextColor(COLOR_BLACK, COLOR_WHITE);
	lcdSetTextFont( & Font12 );
	lcdSetCursor( x , y );
	lcdPrintf( day );
	lcdSetCursor( x + 65  , y + 6 );
	lcdPrintf( "%2u", temp );
	lcdDrawImage( x + 80 , y + 6, &iconTempMinor2);
	lcdSetTextFont( & Font8 );
	lcdSetCursor( x - 3 , y + 18);
	lcdPrintf( month );
	lcdSetCursor( x + 17, y + 18 );
	lcdPrintf( "%2u", date );
	lcdPrintf( "" , iconWeatherMinor(x + 35  , y + 2, iconID ));

	return 0;
}
unsigned long displayNextDay1(uint16_t x, uint16_t y, const char* day, const char* month, int date, int temp, int iconID)
{

	lcdSetTextColor(COLOR_WHITE, COLOR_BackGround_3);
	lcdSetTextFont( & Font12 );
	lcdSetCursor( x , y );
	lcdPrintf( day );
	lcdSetTextColor(COLOR_BLACK, COLOR_WHITE);
	lcdSetCursor( x  , y + 53 );
	lcdPrintf( "%2u", temp );
	lcdDrawImage( x + 13 , y + 53, &iconTempMinor2);
	lcdSetTextFont( & Font8 );
	lcdSetCursor( x - 3 , y + 18);
	lcdPrintf( month );
	lcdSetCursor( x + 17, y + 18 );
	lcdPrintf( "%2u", date );
	lcdPrintf( "" , iconWeatherMinor(x  , y + 28, iconID ));

	return 0;
}
unsigned long displayNextDay(uint16_t x, uint16_t y, const char* day, const char* month, int date, int temp, int iconID)
{

	lcdSetTextColor(COLOR_WHITE, COLOR_BackGround_2);
	lcdSetTextFont( & Font12 );
	lcdSetCursor( x , y );
	lcdPrintf( day );
	lcdSetCursor( x , y + 50 );
	lcdPrintf( "%2u", temp );
	lcdDrawImage( x + 13 , y + 50, & iconTempMinor);
	lcdSetTextFont( & Font8 );
	lcdSetCursor( x - 3 , y + 15);
	lcdPrintf( month );
	lcdSetCursor( x + 17, y + 15 );
	lcdPrintf( "%2u", date );
	lcdPrintf( "" , iconWeatherMinor(x - 3 , y + 25, iconID ));

	return 0;
}
unsigned  long  iconWeather (uint16_t x, uint16_t y, int signal)
{
		if(signal == 0 || signal == 1){
				lcdDrawImage( x , y, & iconSun);
		}else if (signal == 2 || signal == 3 || signal == 45 || signal == 48){
				lcdDrawImage( x , y, & iconCloud);
		}else if (  signal == 51 || signal == 53 || signal == 55 || signal == 61
				 || signal == 63 || signal == 65 || signal == 80 || signal == 81 || signal == 82 ){
				lcdDrawImage( x , y, & iconRain);
		}else if ( signal == 71 || signal == 73 || signal == 75 ){
				lcdDrawImage( x , y, & iconFreezing);
		}else if ( signal == 56 || signal == 57 || signal == 66 || signal == 67 ){
				lcdDrawImage( x , y, & iconFreezingRain);
		}else if ( signal == 95 || signal == 96 || signal == 99 ){
				lcdDrawImage( x , y, & iconThunder);
		}else{
				lcdDrawImage( x , y, & iconSun);
		}
		return 0;
}
unsigned  long  iconWeatherMinor (uint16_t x, uint16_t y, int signal)
{
	if(signal == 0 || signal == 1){
			lcdDrawImage( x , y, & iconSunMinor);
	}else if (signal == 2 || signal == 3 || signal == 45 || signal == 48){
			lcdDrawImage( x , y, & iconCloudMinor);
	}else if (  signal == 51 || signal == 53 || signal == 55 || signal == 61
			 || signal == 63 || signal == 65 || signal == 80 || signal == 81 || signal == 82 ){
			lcdDrawImage( x , y, & iconRainMinor);
	}else if ( signal == 71 || signal == 73 || signal == 75 ){
			lcdDrawImage( x , y, & iconFreezingMinor);
	}else if ( signal == 56 || signal == 57 || signal == 66 || signal == 67 ){
			lcdDrawImage( x , y, & iconFreezingRainMinor);
	}else if ( signal == 95 || signal == 96 || signal == 99 ){
			lcdDrawImage( x , y, & iconThunderMinor);
	}else{
			lcdDrawImage( x , y, & iconSunMinor);
	}
	return 0;
}



