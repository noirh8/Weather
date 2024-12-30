/*
 * SkyWar.c
 *
 *  Created on: Dec 27, 2024
 *      Author: MSI MODERN 14
 */
#include "SkyWar.h"
#include "mainPlanes.h"
#include "enemyPlane.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
int passMission1;
int passMission2;
int countMission1=2000;
int bulletCooldown=0;
int rTouchX=120,rTouchY=250;
float touchX=0,touchY=0;

struct mainStruct mainPlane;
int checkMainSelected=1;


struct creepStruct creepData[50];
struct miniBossStruct miniBossData[5];
struct bossStruct bossData;


void initMainPlane()
{
	switch(checkMainSelected)
	{
		case 1:
		{
			initMainDPS(&mainPlane);
			break;
		}
		case 2:
		{
			initMainTank(&mainPlane);
			break;
		}
		default:
		{
			initMainSpeed(&mainPlane);
		}

	}
}
void mainPlaneUsed()
{
	switch(checkMainSelected)
	{
		case 1:
		{
			mainDPS(&mainPlane);
			break;
		}
		case 2:
		{
			mainTank(&mainPlane);
			break;
		}
		default:
		{
			mainSpeed(&mainPlane);
		}

	}
	if(mainPlane.energy<=0)
	{
		mainPlane.energy=0;
	}
	if(mainPlane.hp<=0)
	{
		mainPlane.hp=0;
	}
	lcdFillRect(100,0, 140, 10,COLOR_BLACK);
	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	lcdSetCursor( 200 , 0 );
	lcdSetTextFont( & Font8 );
	lcdPrintf( "HP:" );
	lcdSetCursor(210 , 0 );
	lcdSetTextFont( & Font8 );
	lcdPrintf( "%2u",mainPlane.hp );

	lcdSetCursor( 150 , 0 );
	lcdSetTextFont( & Font8 );
	lcdPrintf( "E:" );
	lcdSetCursor(160 , 0 );
	lcdSetTextFont( & Font8 );
	lcdPrintf( "%2u",mainPlane.energy );

	lcdSetTextColor(COLOR_WHITE, COLOR_BLUE);
	lcdFillCircle(220, 270, 15, COLOR_BLUE);
	lcdSetCursor( 207 , 268 );
	lcdSetTextFont( & Font8 );
	lcdPrintf( "Skill" );

}




void mission3()
{
	if(runningScreen==1)
	{
		//initMainPlane();

		lcdFillRGB(COLOR_BLACK);
		lcdPrintf( "",Button() );
		countYboss=0;
		countYMiniBoss=0;
//		miniBossData[0]=(struct miniBossStruct){0,-60,50,0,{{25,-20,0,0,2},{25,-20,0,0,2},{25,-20,0,0,2}}};

		bossData=(struct bossStruct){75,-80,200,0,{{140,-5,0,0,3} , {140,-5,0,0,3} , {140,-5,0,0,3} , {140,-5,0,0,4} , {140,-5,0,0,4}, {140,-5,0,0,3}, {140,-5,0,0,3}}};
		miniBossData[3]=(struct miniBossStruct){25,-100,100,0,{{70,40,0,0,2},{70,40,0,0,2},{70,40,0,0,2}}};

		miniBossData[4]=(struct miniBossStruct){160,-100,100,0,{{165,40,0,0,2},{165,40,0,0,2},{165,40,0,0,2}}};

//		miniBossData[2]=(struct miniBossStruct){190,-60,50,0,{{215,-20,0,0,2},{215,-20,0,0,2},{215,-20,0,0,2}}};






		runningScreen=0;

	}


	boss(&bossData,&mainPlane);
	miniBoss(&miniBossData[3],&mainPlane);
	miniBoss(&miniBossData[4],&mainPlane);

	mainPlaneUsed(&mainPlane);
	if (mainPlane.hp<=0)
	{
		lose();
		HAL_Delay(1000);
 		runningScreen=1;
 		removeLastFunction(&currentScreen);
 		removeLastFunction(&currentScreen);
 		removeLastFunction(&currentScreen);
	}
	if ( bossData.hp+miniBossData[3].hp+miniBossData[4].hp==0)
	{
		win();
		HAL_Delay(1000);
 		runningScreen=1;
 		removeLastFunction(&currentScreen);
 		removeLastFunction(&currentScreen);
 		removeLastFunction(&currentScreen);

	}



}


void mission2()
{
	if(runningScreen==1)
	{

		//initMainPlane();
		lcdFillRGB(COLOR_BLACK);
		lcdPrintf( "",Button() );
		countYMiniBoss=0;
		miniBossData[0]=(struct miniBossStruct){0,-60,60,0,{{25,-20,0,0,2},{25,-20,0,0,2},{25,-20,0,0,2}}};

		miniBossData[1]=(struct miniBossStruct){95,-60,100,0,{{120,-20,0,0,2},{120,-20,0,0,2},{120,-20,0,0,2}}};

		miniBossData[2]=(struct miniBossStruct){190,-60,60,0,{{215,-20,0,0,2},{215,-20,0,0,2},{215,-20,0,0,2}}};

		miniBossData[3]=(struct miniBossStruct){45,0,60,0,{{70,40,0,0,2},{70,40,0,0,2},{70,40,0,0,2}}};

		miniBossData[4]=(struct miniBossStruct){140,0,60,0,{{165,40,0,0,2},{165,40,0,0,2},{165,40,0,0,2}}};




		runningScreen=0;

	}


	passMission2=miniBossData[0].hp;
	for(int i=0;i<5;i++)
	{
		miniBoss(&miniBossData[i],&mainPlane);
		passMission2+=miniBossData[i].hp;
	}

	mainPlaneUsed(&mainPlane);

	if(passMission2==0)
	{
		runningScreen=1;
		addFunction(&currentScreen, mission3);
	}

	if (mainPlane.hp<=0)
	{
		lose();
		HAL_Delay(1000);
 		runningScreen=1;
 		removeLastFunction(&currentScreen);
 		removeLastFunction(&currentScreen);
	}

}





void mission1()
{
	if(runningScreen==1)
	{
		countMission1=2000;
		lcdFillRGB(COLOR_BLACK);
		lcdPrintf( "",Button() );
		for(int i=0;i<24;i++)
		{
			if(i>=8&&i<16)
			{
				creepData[i]=(struct creepStruct){(i-8)*30,0,4,0,1};
			}
			else if(i<8)
			{
				creepData[i]=(struct creepStruct){i*30,-40,4,0,1};
			}
			else
			{
				creepData[i]=(struct creepStruct){(i-16)*30,-80,4,0,1};
			}

		}

		initMainPlane();

		runningScreen=0;

	}

	countMission1 -=1;

	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	lcdFillRect(0,0, 30, 10,COLOR_BLACK);
	lcdSetCursor( 0 , 0 );
	lcdSetTextFont( & Font8 );
	lcdPrintf( "Time:" );
	lcdSetCursor(20 , 0 );
	lcdSetTextFont( & Font8 );
	lcdPrintf( "%2u",countMission1 );






	passMission1=creepData[0].life;
	for(int i=0;i<24;i++)
	{
		creep(&creepData[i],&mainPlane);
		passMission1+=creepData[i].life;

	}

	if(countMission1<=0)
	{
		lose();
		HAL_Delay(1000);
 		runningScreen=1;
 		removeLastFunction(&currentScreen);
	}
	if(passMission1==0)
	{
		runningScreen=1;
		addFunction(&currentScreen, mission2);
	}
	mainPlaneUsed(&mainPlane);
	if (mainPlane.hp<=0)
	{
		lose();
		 lcdDrawImage(mainPlane.x+15, mainPlane.y, &iconSmoke);
		 lcdDrawImage(mainPlane.x+12, mainPlane.y+20, &iconSmoke);
		HAL_Delay(1000);
 		runningScreen=1;
 		removeLastFunction(&currentScreen);
	}
}




void displayMenuGameScreen()
{
	if(runningScreen==1)
	{
		displayMenuGame();

		runningScreen=0;
	}
	if (checkXY(0,70,240,30))
	{
		checkMainSelected=1;
		lcdFillRect(0,0, 35, 34,COLOR_GRAY_50);
		lcdDrawImage( 0, 0, & iconPlaneDPS);
	}

	else if (checkXY(0,125,240,30))
	{
		checkMainSelected=2;
		lcdFillRect(0,0, 35, 34,COLOR_GRAY_50);
		lcdDrawImage( 0 , 0, & iconPlaneTank);
	}
	else if (checkXY(0,180,240,30))
	{
		checkMainSelected=3;
		lcdFillRect(0,0, 35, 34,COLOR_GRAY_50);
		lcdDrawImage( 0 , 0, & iconPlaneSpeed);
	}

	if(checkXY(75,235,110,30))
	{
		runningScreen=1;
		addFunction(&currentScreen, mission1);

	}

}
void displayWaitingGameScreen()
{
	if(runningScreen==1)
	{
		displayWaitingGame();
		runningScreen=0;
	}
	 HAL_Delay(1000);
	 runningScreen=1;
	 addFunction(&currentScreen, displayMenuGameScreen);
}






int collisionCheck(int x1, int y1, int ngang1, int doc1, int x2, int y2, int ngang2, int doc2)
{
    if (x1 <= x2 + ngang2 && x1 + ngang1 > x2 && y1 <= y2 + doc2 && y1 + doc1 >= y2)
    {
        return 1;  // Trả về true nếu có va chạm
    }
    return 0;  // Trả về false nếu không có va chạm
}



