/*
 * mainPlane.h
 *
 *  Created on: Dec 28, 2024
 *      Author: MSI MODERN 14
 */

#ifndef INC_MAINPLANES_H_
#define INC_MAINPLANES_H_

#include "SkyWar.h"
struct bullet
{
	int x;
	int y;


	int hit;

	int bulletCooldown;
	int dame;
	int w;
};
struct mainStruct
{
	float x;
	float y;
	float spd;
	struct bullet mainBullet[2];
	int hp;
	int energy;
    // ...
};
extern int checkSkill;
extern int subHP;
//extern struct mainStruct mainSpeedData;
#endif /* INC_MAINPLANES_H_ */
