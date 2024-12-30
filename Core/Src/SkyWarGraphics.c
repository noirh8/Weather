#include "SkyWarGraphics.h"

void displayWaitingGame()
{

		lcdFillRGB(COLOR_GRAY_50);
		lcdDrawImage( 65 , 80, & iconPlaneBoss);
		lcdSetCursor( 30 , 30 );
		lcdSetTextColor(COLOR_WHITE, COLOR_GRAY_50);
		lcdSetTextFont( & Font24 );
		lcdPrintf( "BAN MAY BAY" );
		lcdSetTextColor(COLOR_WHITE, COLOR_GRAY_50);
		lcdSetTextFont( & Font16 );
		lcdSetCursor( 60 , 145 );
		lcdPrintf( "LOADING...." );

}

void displayMenuGame()
{

		lcdFillRGB(COLOR_GRAY_50);
		lcdSetTextColor(COLOR_GRAY_50,COLOR_WHITE);
		lcdSetTextFont( & Font24 );
		lcdSetCursor( 75 , 235 );
		lcdPrintf( "START" );
		lcdSetCursor( 85 , 25 );
		lcdSetTextColor(COLOR_WHITE, COLOR_GRAY_50);
		lcdPrintf( "MENU" );

	//Plane 1
		lcdDrawImage( 15 , 70, & iconPlaneDPS);
		lcdSetCursor( 60 , 73 );
		lcdSetTextFont( & Font12 );
		lcdPrintf( "PLANE 1" );
		lcdSetCursor( 60 , 85 );
		lcdSetTextFont( & Font8 );
		lcdPrintf( "Dame: Cao, HP: Thap, Speed: Vua " );
		lcdSetCursor( 60 , 93 );
		lcdPrintf( "Skill: Ban dan sieu to khong lo " );

	//Plane 2
		lcdDrawImage( 15 , 125, & iconPlaneTank);
		lcdSetCursor( 60 , 128 );
		lcdSetTextFont( & Font12 );
		lcdPrintf( "PLANE 2" );
		lcdSetCursor( 60 , 140 );
		lcdSetTextFont( & Font8 );
		lcdPrintf( "Dame: Vua, HP: Cao, Speed: Thap " );
		lcdSetCursor( 60 , 148 );
		lcdPrintf( "Skill: Tao khien sieu cung" );

	//Plane 3
		lcdDrawImage( 15 , 180, & iconPlaneSpeed);
		lcdSetCursor( 60 , 183 );
		lcdSetTextFont( & Font12 );
		lcdPrintf( "PLANE 3" );
		lcdSetCursor( 60 , 195 );
		lcdSetTextFont( & Font8 );
		lcdPrintf( "Dame: Vua, HP: Thap, Speed: Cao " );
		lcdSetCursor( 60 , 203 );
		lcdPrintf( "Skill: Tang toc do bay" );

		lcdPrintf( "",Button() );


}
