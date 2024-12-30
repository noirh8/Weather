#include "enemyPlane.h"
#include <stdlib.h>
#include <time.h>
int countYMiniBoss=0;
int countYboss=0;
int bulletx=1;
void creep(struct creepStruct *creepData, struct mainStruct *mainSpeedD)
{
    switch (creepData->life)
    {
    case 0:
        creepDeath(creepData);
        break;
    default:
        creepAlive(creepData, mainSpeedD);
        break;
    }
}

void creepDeath(struct creepStruct *creepData)
{
    if (creepData->deathCooldown == 10)
    {
        creepData->deathCooldown = 0;
        lcdFillRect(creepData->x, creepData->y, 20, 20, COLOR_BLACK);
        creepData->y = 321; // Đưa kẻ địch ra khỏi màn hình
    }
    else
    {
        if (creepData->y < 320)
        {
            lcdDrawImage(creepData->x, creepData->y, &iconPlaneEnemy);
            lcdDrawImage(creepData->x, creepData->y, &iconSmoke);
            creepData->deathCooldown += 1;
        }
    }
}
void creepCollision(struct creepStruct *creepData, struct mainStruct *mainSpeedD)
{
    // Kiểm tra va chạm giữa creep và đạn
    for (int i = 0; i < 2; i++)
    {
        if (collisionCheck(creepData->x, creepData->y, 20, 20,
                           mainSpeedD->mainBullet[i].x -mainSpeedD->mainBullet[i].w ,
                           mainSpeedD->mainBullet[i].y - mainSpeedD->mainBullet[i].w, mainSpeedD->mainBullet[i].w*2, mainSpeedD->mainBullet[i].w*2) == 1)
        {
            mainSpeedD->mainBullet[i].hit = 1;
            creepData->life -= mainSpeedD->mainBullet[i].dame;
        }
    }

    // Kiểm tra va chạm giữa creep và main
    if (collisionCheck(rTouchX, rTouchY, 30, 35, creepData->x, creepData->y, 20, 20) == 1)
    {
        creepData->life -= 2;
        mainSpeedD->hp -= 1;
        mainSpeedD->energy -= 100;
    }
}
void creepMove(struct creepStruct *creepData)
{
    if (creepData->y >= 0)
    {
        lcdFillRect(creepData->x, creepData->y, 20, 20, COLOR_BLACK);
        creepData->y += creepData->spd; // Di chuyển creep xuống
        if (creepData->y + 20 + creepData->spd < 288)
        {
            lcdDrawImage(creepData->x, creepData->y, &iconPlaneEnemy);
        }
        else
        {
            creepData->y = 0; // Đưa creep trở lại từ trên màn hình
        }
    }
    else
    {
        creepData->y += creepData->spd;
    }
}
void creepAlive(struct creepStruct *creepData, struct mainStruct *mainSpeedD)
{
    creepCollision(creepData, mainSpeedD);
    creepMove(creepData);

    // Giới hạn máu
    if (creepData->life < 0)
    {
        creepData->life = 0;
    }
}


void miniBoss(struct miniBossStruct *miniBossData, struct mainStruct *mainSpeedD)
{
    switch (miniBossData->hp)
    {
    // Xử lý khi kẻ địch chết
    	case 0:
    	{
    		miniBossDeath(miniBossData);
            break;
    	}
    //Khi kẻ địch còn sống
    	default:
		{
			miniBossAlive(miniBossData,mainSpeedD);
			if(miniBossData->hp<=0)
			{
				miniBossData->hp=0;
			}

		}

    }
}
void miniBossDeath(struct miniBossStruct *miniBossData)
{
	for(int i=0;i<3;i++)
	{
		lcdFillCircle(miniBossData->bulletData[i].x, miniBossData->bulletData[i].y, 2, COLOR_BLACK );
	}
    if (miniBossData->deathCooldown == 10)
    {
    	miniBossData->deathCooldown = 0;
        lcdFillRect(miniBossData->x, miniBossData->y, 50, 40, COLOR_BLACK);
        miniBossData->y = 321; // Đưa kẻ địch ra khỏi màn hình
    }
    else
    {
        if (miniBossData->y < 320)
        {
            lcdDrawImage(miniBossData->x, miniBossData->y, &iconPlaneMiniBoss);
            lcdDrawImage(miniBossData->x, miniBossData->y, &iconSmoke);
            lcdDrawImage(miniBossData->x+25, miniBossData->y+20, &iconSmoke);
            miniBossData-> deathCooldown += 1;
        }
    }
}

void miniBossCollision(struct miniBossStruct *miniBossData, struct mainStruct *mainSpeedD)
{
	 // Kiểm tra va chạm giữa kẻ địch và đạn
	for (int i = 0; i < 2; i++)
	{
		if (collisionCheck(miniBossData->x, miniBossData->y, 50, 40,
		mainSpeedD->mainBullet[i].x - mainSpeedD->mainBullet[i].w,
		mainSpeedD->mainBullet[i].y - mainSpeedD->mainBullet[i].w, mainSpeedD->mainBullet[i].w*2, mainSpeedD->mainBullet[i].w*2) == 1)
		{
			mainSpeedD->mainBullet[i].hit = 1;
		    miniBossData->hp -= mainSpeedD->mainBullet[i].dame;
		}
	}
	// Kiểm tra va chạm giữa kẻ địch và main
	if (collisionCheck(rTouchX,rTouchY,30,35,miniBossData->x, miniBossData->y, 50, 40)==1)
	{
		 miniBossData->hp -= 4;
		 mainSpeedD->hp -= 4;
		 mainSpeedD->energy -= 100;
		 mainSpeedD->y+=30;

		 lcdDrawImage(mainSpeedD->x+15, mainSpeedD->y, &iconSmoke);
		 lcdDrawImage(mainSpeedD->x+12, mainSpeedD->y+20, &iconSmoke);

		 if(mainSpeedD->hp <= 0)
		 {
		 HAL_Delay(10);
		 }

	}
}

void miniBossMove(struct miniBossStruct *miniBossData)
{
	if(countYMiniBoss<=360)
	{
		if(miniBossData->y>=0)
		{
			lcdFillRect(miniBossData->x, miniBossData->y, 50, 50, COLOR_BLACK);
			miniBossData->y += 1; // Di chuyển kẻ địch xuống
			lcdDrawImage(miniBossData->x, miniBossData->y, &iconPlaneMiniBoss);

		}
		else
		{
			miniBossData->y += 1;
		}
		countYMiniBoss+=1;
	}
	else
	{
		lcdDrawImage(miniBossData->x, miniBossData->y, &iconPlaneMiniBoss);

	}
}
void miniBossAlive(struct miniBossStruct *miniBossData, struct mainStruct *mainSpeedD)
{

	miniBossCollision(miniBossData,mainSpeedD);
	miniBossMove(miniBossData);
	miniBossBullet(miniBossData,mainSpeedD);
	//Giới hạn máu
	if(miniBossData->hp <=0)
	{
		miniBossData->hp =0;
	}
	// Cập nhật tọa độ


}
void miniBossBullet(struct miniBossStruct *miniBossData,struct mainStruct *mainSpeedD)
{

	miniBossBulletControl(&miniBossData->bulletData[0],miniBossData,mainSpeedD,1);
	miniBossBulletControl(&miniBossData->bulletData[1],miniBossData,mainSpeedD,0);
	miniBossBulletControl(&miniBossData->bulletData[2],miniBossData,mainSpeedD,2);


}

void miniBossBulletControl(struct bullet *bulletSub,struct miniBossStruct *miniBossData,struct mainStruct *mainSpeedD,int special)
{
	bulletSub->hit=checkMiniBossBulletHit(bulletSub);
	if(bulletSub->bulletCooldown<150)
	{
		bulletSub->bulletCooldown+=1;


			if (bulletSub->hit==0) // nếu đạn chưa bắn trúng đích
			{
				if(bulletSub->y>20&&bulletSub->y<280&&bulletSub->x<240&&bulletSub->x>0)// đạn chưa chạm biên
				{
					//cập nhật đường bay của đạn
					lcdFillCircle(bulletSub->x, bulletSub->y, 2, COLOR_BLACK );
					bulletSub->y+=2;
					if(special==1)
					{
						bulletSub->x+=1;
					}
					else if(special ==2)
					{
						bulletSub->x-=1;
					}
					lcdFillCircle(bulletSub ->x, bulletSub ->y, 2, COLOR_RED  );
					if(bulletSub->y>=280||bulletSub->x>=236||bulletSub->x<=4)// đạn chuẩn bị chạm biên
						{
						lcdFillCircle(bulletSub ->x, bulletSub->y, 2, COLOR_BLACK );// giá trị rác
						}
				}
				else// đạn chạm biên -> không vẽ nữa
				{
					bulletSub->y=999;
				}


			}



			if(bulletSub->hit==1 && bulletSub->x<240 && bulletSub->x>0 && bulletSub->y>0 && bulletSub->y<280)// cập nhật giá trị rác cho đạn sau khi trúng đích
			{

				lcdFillCircle(bulletSub->x, bulletSub->y, 2, COLOR_BLACK );
				mainSpeedD->hp-=bulletSub->dame;
				mainSpeedD->energy -= 100;

				bulletSub->x=999;
				bulletSub->y=999;
				bulletSub->hit=0;


			}

	}
	else// khởi tạo lại vị trí của đạn sau khi hết cooldown
	{
		bulletSub->y=miniBossData->y+45;
		bulletSub->x=miniBossData->x+25;

		bulletSub->bulletCooldown=0;
		bulletSub->hit=0;
	}
}
int checkMiniBossBulletHit(struct bullet *bulletSub)
{
	if (collisionCheck(bulletSub->x-2, bulletSub->y-2, 4, 4, rTouchX, rTouchY, 30, 35)==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void boss(struct bossStruct *bossData, struct mainStruct *mainSpeedD)
{
    switch (bossData->hp)
    {
    // Xử lý khi kẻ địch chết
    	case 0:
    	{
    		bossDeath(bossData);
            break;
    	}
    //Khi kẻ địch còn sống
    	default:
		{
			bossAlive(bossData,mainSpeedD);
			if(bossData->hp<=0)
			{
				bossData->hp=0;
			}

		}

    }
}
void bossDeath(struct bossStruct *bossData)
{
	for(int i=0;i<5;i++)
	{
		lcdFillCircle(bossData->bulletData[i].x, bossData->bulletData[i].y, 50, COLOR_BLACK );
	}
    if (bossData->deathCooldown == 10)
    {
    	bossData->deathCooldown = 0;
        lcdFillRect(bossData->x, bossData->y, 100, 50, COLOR_BLACK);
        bossData->y = 321; // Đưa kẻ địch ra khỏi màn hình
    }
    else
    {
        if (bossData->y < 320)
        {
            lcdDrawImage(bossData->x, bossData->y, &iconPlaneBoss);
            lcdDrawImage(bossData->x, bossData->y, &iconSmoke);
            lcdDrawImage(bossData->x+25, bossData->y+20, &iconSmoke);
            bossData-> deathCooldown += 1;
        }
    }
}

void bossCollision(struct bossStruct *bossData, struct mainStruct *mainSpeedD)
{
	 // Kiểm tra va chạm giữa kẻ địch và đạn
	for (int i = 0; i < 2; i++)
	{
		if (collisionCheck(bossData->x, bossData->y, 100, 50,
		mainSpeedD->mainBullet[i].x - mainSpeedD->mainBullet[i].w,
		mainSpeedD->mainBullet[i].y - mainSpeedD->mainBullet[i].w, mainSpeedD->mainBullet[i].w*2, mainSpeedD->mainBullet[i].w*2) == 1)
		{
			mainSpeedD->mainBullet[i].hit = 1;
		    bossData->hp -= mainSpeedD->mainBullet[i].dame;
		}
	}
	// Kiểm tra va chạm giữa kẻ địch và main
	if (collisionCheck(rTouchX,rTouchY,30,35,bossData->x, bossData->y, 100, 50)==1)
	{
		 bossData->hp -= 4;
		 mainSpeedD->hp -= 7;
		 mainSpeedD->y+=30;
		 mainSpeedD->energy -= 100;

		 lcdDrawImage(mainSpeedD->x+15, mainSpeedD->y, &iconSmoke);
		 lcdDrawImage(mainSpeedD->x+12, mainSpeedD->y+20, &iconSmoke);

		 if(mainSpeedD->hp <= 0)
		 {
		 HAL_Delay(10);
		 }

	}
}

void bossMove(struct bossStruct *bossData)
{
	if(countYboss<=100)
	{
		if(bossData->y>=0)
		{
			lcdFillRect(bossData->x, bossData->y, 100, 50, COLOR_BLACK);
			bossData->y += 1; // Di chuyển kẻ địch xuống
			lcdDrawImage(bossData->x, bossData->y, &iconPlaneBoss);

		}
		else
		{
			bossData->y += 1;
		}
		countYboss+=1;
	}
	else
	{
		lcdDrawImage(bossData->x, bossData->y, &iconPlaneBoss);

	}
}
void bossAlive(struct bossStruct *bossData, struct mainStruct *mainSpeedD)
{

	bossCollision(bossData,mainSpeedD);
	bossMove(bossData);
	bossBullet(bossData,mainSpeedD);
	//Giới hạn máu
	if(bossData->hp <=0)
	{
		bossData->hp =0;
	}
	// Cập nhật tọa độ


}
void bossBullet(struct bossStruct *bossData,struct mainStruct *mainSpeedD)
{

	switch (bulletx)
	{
		case 2:
		{
			if(bossData->bulletData[3].bulletCooldown==70)
			{
				bulletx=3;
			}
			bossBulletControl2(&bossData->bulletData[3],bossData,mainSpeedD);
			break;
		}
		case 3:
		{
			if(bossData->bulletData[4].bulletCooldown==70)
			{
				bulletx=1;
			}
			bossBulletControl3(&bossData->bulletData[4],bossData,mainSpeedD);
			break;
		}
		default:
		{
			if(bossData->bulletData[0].bulletCooldown==70)
			{
				bulletx=2;
			}
			bossBulletControl(&bossData->bulletData[0],bossData,mainSpeedD,1);
			bossBulletControl(&bossData->bulletData[1],bossData,mainSpeedD,0);
			bossBulletControl(&bossData->bulletData[2],bossData,mainSpeedD,2);

			bossBulletControl(&bossData->bulletData[5],bossData,mainSpeedD,3);
			bossBulletControl(&bossData->bulletData[6],bossData,mainSpeedD,4);


			break;
		}
	}
	lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
	lcdSetCursor( 200 , 0 );
	lcdSetTextFont( & Font8 );
	lcdPrintf( "HP:" );
	lcdSetCursor(100 , 0 );
	lcdSetTextFont( & Font8 );
	lcdPrintf( "%2u",bulletx );


}

void bossBulletControl2(struct bullet *bulletSub,struct bossStruct *bossData,struct mainStruct *mainSpeedD)
{
	bulletSub->hit=collisionCheck(bulletSub->x-20, bulletSub->y-20, 40, 40, rTouchX, rTouchY, 30, 35);
	if(bulletSub->bulletCooldown<70)
	{
		bulletSub->bulletCooldown+=1;


			if (bulletSub->hit==0) // nếu đạn chưa bắn trúng đích
			{
				if(bulletSub->y>60&&bulletSub->y<250&&bulletSub->x<200&&bulletSub->x>0)// đạn chưa chạm biên
				{
					//cập nhật đường bay của đạn

					lcdFillCircle(bulletSub->x, bulletSub->y, 20, COLOR_BLACK );
					bulletSub->y+=10;
					lcdFillCircle(bulletSub ->x, bulletSub ->y, 20, COLOR_RED  );


					if(bulletSub->y>=250||bulletSub->x>=236||bulletSub->x<=4)// đạn chuẩn bị chạm biên
						{
						lcdFillCircle(bulletSub ->x, bulletSub->y, 20, COLOR_BLACK );
						}
				}
				else// đạn chạm biên -> không vẽ nữa
				{
					bulletSub->y=999;
				}


			}



			if(bulletSub->hit==1 && bulletSub->x<200 && bulletSub->x>0 && bulletSub->y>0 && bulletSub->y<250)// cập nhật giá trị rác cho đạn sau khi trúng đích
			{

				lcdFillCircle(bulletSub->x, bulletSub->y, 20, COLOR_RED );
				HAL_Delay(10);
								lcdFillCircle(bulletSub->x, bulletSub->y, 20, COLOR_BLACK );
				mainSpeedD->hp-=bulletSub->dame;
				mainSpeedD->energy -= 100;

				bulletSub->x=999;
				bulletSub->y=999;
				bulletSub->hit=0;


			}

	}
	else// khởi tạo lại vị trí của đạn sau khi hết cooldown
	{
		bulletSub->y=bossData->y+55;
		bulletSub->x=bossData->x+45;

		bulletSub->bulletCooldown=0;
		bulletSub->hit=0;
	}
}

void bossBulletControl3(struct bullet *bulletSub,struct bossStruct *bossData,struct mainStruct *mainSpeedD)
{
	bulletSub->hit=collisionCheck(bulletSub->x-50, bulletSub->y-50, 100, 100, rTouchX, rTouchY, 30, 35);
	if(bulletSub->bulletCooldown<70)
	{
		bulletSub->bulletCooldown+=1;


			if (bulletSub->hit==0) // nếu đạn chưa bắn trúng đích
			{
				if(bulletSub->y>60&&bulletSub->y<230&&bulletSub->x<200&&bulletSub->x>0)// đạn chưa chạm biên
				{
					//cập nhật đường bay của đạn

					lcdFillCircle(bulletSub->x, bulletSub->y, 50, COLOR_BLACK );
					bulletSub->y+=6;
					lcdFillCircle(bulletSub ->x, bulletSub ->y, 50, COLOR_RED  );


					if(bulletSub->y>=230||bulletSub->x>=236||bulletSub->x<=4)// đạn chuẩn bị chạm biên
						{
						lcdFillCircle(bulletSub ->x, bulletSub->y, 50, COLOR_BLACK );
						}
				}
				else// đạn chạm biên -> không vẽ nữa
				{
					// giá trị rác
					bulletSub->y=999;
				}


			}



			if(bulletSub->hit==1 && bulletSub->x<200 && bulletSub->x>0 && bulletSub->y>0 && bulletSub->y<250)// cập nhật giá trị rác cho đạn sau khi trúng đích
			{

				lcdFillCircle(bulletSub->x, bulletSub->y, 50, COLOR_RED );
				HAL_Delay(10);
				lcdFillCircle(bulletSub->x, bulletSub->y, 50, COLOR_BLACK );
				mainSpeedD->hp-=bulletSub->dame;
				mainSpeedD->energy -= 100;

				bulletSub->x=999;
				bulletSub->y=999;
				bulletSub->hit=0;


			}

	}
	else// khởi tạo lại vị trí của đạn sau khi hết cooldown
	{
		bulletSub->y=bossData->y+55;
		bulletSub->x=bossData->x+45;

		bulletSub->bulletCooldown=0;
		bulletSub->hit=0;
	}
}
void bossBulletControl(struct bullet *bulletSub,struct bossStruct *bossData,struct mainStruct *mainSpeedD,int special)
{
	bulletSub->hit=checkbossBulletHit(bulletSub);
	if(bulletSub->bulletCooldown<70)
	{
		bulletSub->bulletCooldown+=1;


			if (bulletSub->hit==0) // nếu đạn chưa bắn trúng đích
			{
				if(bulletSub->y>20&&bulletSub->y<270&&bulletSub->x<240&&bulletSub->x>0)// đạn chưa chạm biên
				{
					//cập nhật đường bay của đạn

					lcdFillCircle(bulletSub->x, bulletSub->y, 4, COLOR_BLACK );
					bulletSub->y+=5;
					if(special==1){bulletSub->x+=5;}
					else if(special ==2){bulletSub->x-=5;}
					else if(special ==3){bulletSub->x-=3;}
					else if(special ==4){bulletSub->x+=3;}
					lcdFillCircle(bulletSub ->x, bulletSub ->y, 4, COLOR_RED  );


					if(bulletSub->y>=270||bulletSub->x>=236||bulletSub->x<=0)// đạn chuẩn bị chạm biên
						{
						lcdFillCircle(bulletSub ->x, bulletSub->y, 4, COLOR_BLACK );
						//bulletSub->y-=5;
						}
				}
				else// đạn chạm biên -> không vẽ nữa
				{
					bulletSub->y=999;
				}


			}



			if(bulletSub->hit==1 && bulletSub->x<240 && bulletSub->x>0 && bulletSub->y>0 && bulletSub->y<280)// cập nhật giá trị rác cho đạn sau khi trúng đích
			{


								lcdFillCircle(bulletSub->x, bulletSub->y, 4, COLOR_BLACK );
				mainSpeedD->hp-=bulletSub->dame;
				mainSpeedD->energy -= 100;

				bulletSub->x=999;
				bulletSub->y=999;
				bulletSub->hit=0;


			}

	}
	else// khởi tạo lại vị trí của đạn sau khi hết cooldown
	{
		bulletSub->y=bossData->y+55;
		bulletSub->x=bossData->x+45;

		bulletSub->bulletCooldown=0;
		bulletSub->hit=0;
	}
}


int checkbossBulletHit(struct bullet *bulletSub)
{
	if (collisionCheck(bulletSub->x-4, bulletSub->y-4, 8, 8, rTouchX, rTouchY, 30, 35)==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
