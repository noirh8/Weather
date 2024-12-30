#include <mainPlanes.h>
//struct mainStruct mainSpeedData={120,250,10,{{0,0,0,70},{0,0,0,70}},5};
int checkSkill=0;
int subHP=0;
void initMainSpeed(struct mainStruct *mainSpeedData)
{
    // Khởi tạo các biến toàn cục
    bulletCooldown = 0;
    rTouchX = 120;
    rTouchY = 250;
    touchX = 0;
    touchY = 0;
    checkSkill=0;

    // Khởi tạo các thuộc tính của mainSpeedData
    *mainSpeedData=(struct mainStruct){120,250,4,{{134,250,0,70,2,2},{134,250,0,70,2,2}},6,1000};


    // Vẽ máy bay lên màn hình
    lcdDrawImage(mainSpeedData->x, mainSpeedData->y, &iconPlaneSpeed);
}

void mainSpeed(struct mainStruct *mainSpeedData)
{
	int x=rTouchX,y= rTouchY;

	if (TouchGetCalibratedPoint(&rTouchX, &rTouchY))
	{
		lcdFillRect(x,y, 35, 34,COLOR_BLACK);
		touchX=rTouchX;
		touchY=rTouchY;
		mainMoveCalculator(mainSpeedData);

	}
	lcdDrawImage( rTouchX , rTouchY, & iconPlaneSpeed);
	SPDskill(mainSpeedData);
	HAL_Delay(10);

	mainBullet(mainSpeedData);


}
void mainBullet(struct mainStruct *mainSpeedData)
{


	bulletControl(&mainSpeedData->mainBullet[0],mainSpeedData);

	if(bulletCooldown>=10)
	{
		bulletControl(&mainSpeedData->mainBullet[1],mainSpeedData);
	}
	else
	{
		bulletCooldown +=1;
	}

}

void initMainDPS(struct mainStruct *mainSpeedData)
{
    // Khởi tạo các biến toàn cục
    bulletCooldown = 0;
    rTouchX = 120;
    rTouchY = 250;
    touchX = 0;
    touchY = 0;
    checkSkill=0;

    // Khởi tạo các thuộc tính của mainSpeedData
    *mainSpeedData=(struct mainStruct){120,250,2,{{134,250,0,70,3,2},{134,250,0,70,3,2}},6,1000};


    // Vẽ máy bay lên màn hình
    lcdDrawImage(mainSpeedData->x, mainSpeedData->y, &iconPlaneDPS);
}

void mainDPS(struct mainStruct *mainSpeedData)
{
	int x=rTouchX,y= rTouchY;

	if (TouchGetCalibratedPoint(&rTouchX, &rTouchY))
	{
		lcdFillRect(x,y, 35, 34,COLOR_BLACK);
		touchX=rTouchX;
		touchY=rTouchY;
		mainMoveCalculator(mainSpeedData);

	}
	lcdDrawImage( rTouchX , rTouchY, & iconPlaneDPS);
	DPSskill(mainSpeedData);
	HAL_Delay(10);

	mainBullet(mainSpeedData);


}
void initMainTank(struct mainStruct *mainSpeedData)
{
    // Khởi tạo các biến toàn cục
    bulletCooldown = 0;
    rTouchX = 120;
    rTouchY = 250;
    touchX = 0;
    touchY = 0;
    checkSkill=0;


    // Khởi tạo các thuộc tính của mainSpeedData
    *mainSpeedData=(struct mainStruct){120,250,1,{{134,250,0,70,2,3},{134,250,0,70,2,3}},12,1000};
    subHP=mainSpeedData->hp;

    // Vẽ máy bay lên màn hình
    lcdDrawImage(mainSpeedData->x, mainSpeedData->y, &iconPlaneTank);
}

void mainTank(struct mainStruct *mainSpeedData)
{
	int x=rTouchX,y= rTouchY;

	if (TouchGetCalibratedPoint(&rTouchX, &rTouchY))
	{
		lcdFillRect(x,y, 35, 34,COLOR_BLACK);
		touchX=rTouchX;
		touchY=rTouchY;
		mainMoveCalculator(mainSpeedData);

	}
	lcdDrawImage( rTouchX , rTouchY, & iconPlaneTank);
	TANKskill(mainSpeedData);
	HAL_Delay(10);

	mainBullet(mainSpeedData);


}
void bulletControl(struct bullet *bulletSub, struct mainStruct *mainSpeedData)
{
    if (bulletSub->bulletCooldown < 35)
    {
        bulletSub->bulletCooldown += 1;

        if (bulletSub->hit == 0)
        {
            bulletUpdatePosition(bulletSub);
        }
        else if (bulletOutOfBounds(bulletSub))
        {
            bulletCleanup(bulletSub);
        }
    }
    else
    {
        bulletReset(bulletSub, mainSpeedData);
    }
}

void bulletUpdatePosition(struct bullet *bulletSub)
{
    if (bulletSub->y > 20) // Đạn chưa chạm biên
    {
        lcdFillCircle(bulletSub->x, bulletSub->y, 4, COLOR_BLACK);
        bulletSub->y -= 10; // Đạn di chuyển lên
        lcdFillCircle(bulletSub->x, bulletSub->y, bulletSub->w, COLOR_THEME_LIMEGREEN_LIGHTER);

        if (bulletSub->y <= 20) // Đạn chuẩn bị chạm biên
        {
            lcdFillCircle(bulletSub->x, bulletSub->y, 4, COLOR_BLACK);
        }
    }
    else // Đạn chạm biên
    {
        bulletSub->y -= 10; // Giá trị rác
    }
}

int bulletOutOfBounds(struct bullet *bulletSub)
{
    return (bulletSub->hit == 1 && bulletSub->x < 235 && bulletSub->x >5 && bulletSub->y > 5&& bulletSub->y < 285);
}
void bulletCleanup(struct bullet *bulletSub)
{
    lcdFillCircle(bulletSub->x, bulletSub->y, 4, COLOR_BLACK);
    bulletSub->x = 999; // Đặt giá trị rác
}
void bulletReset(struct bullet *bulletSub, struct mainStruct *mainSpeedData)
{
    bulletSub->y = mainSpeedData->y;
    bulletSub->x = mainSpeedData->x + 14;

    bulletSub->bulletCooldown = 0;
    bulletSub->hit = 0;
}


void mainMoveCalculator( struct mainStruct *mains)
{
	float countDraw=0;
	countDraw = sqrtf( (touchX-mains->x)*(touchX-mains->x) + (touchY-mains->y)*(touchY-mains->y) ) / mains->spd ;

	if (countDraw>1)
	{
		mains->x =mains->x + (touchX-mains->x)/countDraw;
		mains->y = mains->y + (touchY-mains->y)/countDraw;

		countDraw-=1;
	}


		if (mains->x+30>240){mains->x=240-32;}
		if (mains->y+40>290){mains->y=290-40;}
		if (mains->y<15){mains->y=15;}

		rTouchY=round (mains->y);
		rTouchX=round (mains->x);



}

void skillControl(struct mainStruct *mainSpeedData)
{
	if(checkXY(205,255,30,30))
	{
		while (TouchIsTouched())
			{

			}
		if(checkSkill==0&&mainSpeedData->energy>0)
		{
			checkSkill=1;
			subHP=mainSpeedData->hp;
		}
		else
		{
			checkSkill=0;
		}
	}

}

void DPSskill(struct mainStruct *mainSpeedData)
{
	skillControl(mainSpeedData);
	if(checkSkill==1)
	{

		mainSpeedData->energy-=2;
		mainSpeedData->mainBullet[0].dame=6;
		mainSpeedData->mainBullet[1].dame=6;

		lcdFillCircle(rTouchX+15, rTouchY+8, 2, COLOR_THEME_LIMEGREEN_LIGHTER);
		mainSpeedData->mainBullet[0].w=4;
		mainSpeedData->mainBullet[1].w=4;
		if(mainSpeedData->energy<=0)
		{
			mainSpeedData->energy=0;
			checkSkill=0;
		}

	}
	else
	{
		mainSpeedData->mainBullet[0].w=2;
		mainSpeedData->mainBullet[0].dame=3;
		mainSpeedData->mainBullet[1].dame=3;
		mainSpeedData->mainBullet[1].w=2;
	}

}

void SPDskill(struct mainStruct *mainSpeedData)
{
	skillControl(mainSpeedData);
	if(checkSkill==1)
	{

		mainSpeedData->energy-=2;
		if(mainSpeedData->hp<=0)
		{
		mainSpeedData->hp=1;
		mainSpeedData->mainBullet[0].dame=4;
		mainSpeedData->mainBullet[1].dame=4;

		}
		mainSpeedData->spd=10;

		lcdFillRect(rTouchX+7,rTouchY+32, 2, 2,COLOR_THEME_LIMEGREEN_LIGHTER);
		lcdFillRect(rTouchX+22,rTouchY+32, 2, 2,COLOR_THEME_LIMEGREEN_LIGHTER);

		if(mainSpeedData->energy<=0)
		{
			mainSpeedData->energy=0;
			checkSkill=0;
		}

	}
	else
	{
		mainSpeedData->spd=4;

	}

}

void TANKskill(struct mainStruct *mainSpeedData)
{
	skillControl(mainSpeedData);
	if(checkSkill==1)
	{

		mainSpeedData->energy-=2;
		mainSpeedData->hp=subHP;
		lcdDrawCircle(rTouchX+15, rTouchY+17, 15, COLOR_THEME_LIMEGREEN_LIGHTER );

		if(mainSpeedData->energy<=0)
		{
			mainSpeedData->energy=0;
			checkSkill=0;
		}

	}
	else
	{


	}

}


void lose()
{

	lcdSetTextColor(COLOR_RED,COLOR_BLACK);
	lcdSetTextFont( & Font24 );
	lcdSetCursor( 55 , 135 );
	lcdPrintf( "YOU LOSE" );
}

void win()
{

	lcdSetTextColor(COLOR_BLUE,COLOR_BLACK);
	lcdSetTextFont( & Font24 );
	lcdSetCursor( 55 , 135 );
	lcdPrintf( "YOU WIN" );
}
