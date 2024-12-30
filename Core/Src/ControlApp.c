#include "ControlApp.h"
#include "WeatherApp.h"
#include "json_parser.h"
#include "image.h"
uint16_t runningScreen=1 ;
FunctionList currentScreen;




void appScreen ()
{
	if(runningScreen == 1)
	{
		 lcdPrintf( "" , App());
		 runningScreen = 0;
		// lcdPrintf( "" , optionScreen());
	}
	if(checkXY(20, 20, 40, 40))
		{

			while (TouchIsTouched()){}
			runningScreen=1;
			addFunction(&currentScreen, waitingScreenScreen);
		}

	if(checkXY(80, 20, 40, 40))
		{

			while (TouchIsTouched()){}
			runningScreen=1;
			addFunction(&currentScreen, displayWaitingGameScreen);
		}


}


void initApp ()
{
	initFunctionList(&currentScreen, 2);
	addFunction(&currentScreen, appScreen);
}
void runScreen ()
{
	callLastFunction(&currentScreen);
}

void controlButton ()
 {
	 //Back
	 	if (checkXY(0, 295, 15, 30))
	 	{
	 		while (TouchIsTouched()){}
	 		runningScreen=1;
	 		removeLastFunction(&currentScreen);
	 	}
	 	//Refresh
	 	if (checkXY(200,295,40,30))
	 	{
	 		while (TouchIsTouched()){}
	 		lcdFillRGB(COLOR_WHITE);
	 		lcdSetTextColor(COLOR_BLUE, COLOR_WHITE);
	 		lcdSetCursor( 35 , 162 );
	 		lcdSetTextFont( & Font16 );
	 		lcdPrintf( ".............." );
	 		lcdPrintf( "",Button() );
	 		runningScreen = 1;
	 	}
	 	//Home
	 	if (checkXY(100,295,30,30))
	 	{
	 		while (TouchIsTouched()){}
	 		runningScreen = 1;
	 		clearAllFunctions(&currentScreen);
	 		addFunction(&currentScreen, appScreen);

	 	}
 }

unsigned long App()
{
	lcdFillRGB(COLOR_BackGround_2);
	lcdDrawImage( 20 , 20, & iconApp);
	lcdSetCursor( 22 , 62 );
	lcdSetTextColor(COLOR_WHITE, COLOR_BackGround_2);
	lcdSetTextFont( & Font8 );
	lcdPrintf( "Weather" );
	lcdPrintf( "",Button() );


	lcdDrawImage( 80 , 20, & iconAppGame);
	lcdSetCursor( 82 , 62 );
	lcdSetTextColor(COLOR_WHITE, COLOR_BackGround_2);
	lcdSetTextFont( & Font8 );
	lcdPrintf( "Sky War" );

	return 0;
}
