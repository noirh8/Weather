#include "ControlApp.h"
#include "WeatherApp.h"
#include "json_array.h"
#include "getDataJson.h"
#include "main.h"
#include "json_parser.h"


int controlOptionScreen=1;

void optionScreenScreen()
{
	if(runningScreen == 1)
		{
			 lcdPrintf( "" , optionScreen());
			 runningScreen = 0;
		}


	if (checkXY(30, 50, 180 ,35))
		{

			while (TouchIsTouched())
				{
			 	}
			runningScreen=1;
			controlOptionScreen=1;
			removeLastFunction(&currentScreen);
			removeLastFunction(&currentScreen);
			lcdFillRGB(COLOR_WHITE);
			lcdSetTextColor(COLOR_WHITE, COLOR_BackGround_2);
			lcdFillRect(30, 50, 180 ,35 , COLOR_BackGround_2);
			lcdSetCursor( 35 , 62 );
			lcdSetTextFont( & Font16 );
			lcdPrintf( "Loading...." );
			lcdPrintf( "",Button() );
			addFunction(&currentScreen, weatherStationScreen);
		}

	if (checkXY(30, 105, 180 ,35))
		{

			while (TouchIsTouched())
				{
				}
			runningScreen=1;
			controlOptionScreen=2;
			removeLastFunction(&currentScreen);
			removeLastFunction(&currentScreen);
			lcdFillRGB(COLOR_WHITE);
			lcdSetTextColor(COLOR_WHITE, COLOR_BackGround_2);
			lcdFillRect(30, 50, 180 ,35 , COLOR_BackGround_2);
			lcdSetCursor( 35 , 62 );
			lcdSetTextFont( & Font16 );
			lcdPrintf( "Loading...." );
			lcdPrintf( "",Button() );
			addFunction(&currentScreen, weatherStationScreen);
		 }


	if (checkXY(30, 160, 180 ,35))
		{

			while (TouchIsTouched())
				{
				}
			runningScreen=1;
			controlOptionScreen=3;
			removeLastFunction(&currentScreen);
			removeLastFunction(&currentScreen);
			lcdFillRGB(COLOR_WHITE);
			lcdSetTextColor(COLOR_WHITE, COLOR_BackGround_2);
			lcdFillRect(30, 50, 180 ,35 , COLOR_BackGround_2);
			lcdSetCursor( 35 , 62 );
			lcdSetTextFont( & Font16 );
			lcdPrintf( "Loading...." );
			lcdPrintf( "",Button() );
			addFunction(&currentScreen, weatherStationScreen);
		}
}

void weatherStationScreen ()
{
	// MX_USART1_UART_Init();
	if(runningScreen == 1)
	{
		upDateData();

		switch(controlOptionScreen)
		{
			case 1:
				lcdPrintf( "" , weatherStation());
				break;
			case 2:
				lcdPrintf( "" , weatherStation1());
				break;
			case 3:
				lcdPrintf( "" , weatherStation2());
				break;
			default:
				lcdPrintf( "" , weatherStation());
		}

		 resetTim1();
		 runningScreen = 0;
	}


	if (checkXY(220, 0, 20, 20))
	{

		while (TouchIsTouched())
			{
		 	}
		runningScreen=1;
		addFunction(&currentScreen, optionScreenScreen);
	}


	switch(controlOptionScreen)
	{
		case 1:
		{
			lcdSetTextColor(COLOR_WHITE, COLOR_BackGround_1);
			lcdSetTextFont( & Font12 );
			lcdSetCursor( 30 , 65 );
			lcdPrintf( GetTimeString() );


			break;
		}
		case 2:
		{
			lcdSetTextColor(COLOR_WHITE,COLOR_BackGround_3);
			lcdSetTextFont( & Font16 );
			lcdSetCursor( 160 , 14 );
			lcdPrintf( GetTimeString() );
		}
			break;
		case 3:
		{
			lcdSetTextColor(COLOR_BLACK, COLOR_WHITE);
			lcdSetTextFont( & Font24 );
			lcdSetCursor( 20 , 86 );
			lcdPrintf( GetTimeString() );
			break;
		}
		default:
			break;


	}
	HAL_Delay(100);



}
void waitingScreenScreen()
{
	if (runningScreen == 1)
	{
		lcdPrintf("", waitingScreen());
		runningScreen = 0;

	}


	runningScreen = 1;
	addFunction(&currentScreen, weatherStationScreen);
}


