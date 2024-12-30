/*
 * enemyPlane.h
 *
 *  Created on: Dec 28, 2024
 *      Author: MSI MODERN 14
 */

#ifndef INC_ENEMYPLANE_H_
#define INC_ENEMYPLANE_H_
#include <mainPlanes.h>
struct creepStruct
{
	int x;
	int y;
	int life;
	int deathCooldown;
	int spd;
};
struct miniBossStruct
{
	int x;
	int y;
	int hp;
	int deathCooldown;
	struct bullet bulletData[3];
};

struct bossStruct
{
	int x;
	int y;
	int hp;
	int deathCooldown;
	struct bullet bulletData[7];
};

extern int countYMiniBoss;
extern int countYboss;
void creep(struct creepStruct *creepData, struct mainStruct *mainSpeedD);
void miniBoss(struct miniBossStruct *miniBossData, struct mainStruct *mainSpeedD);


#endif /* INC_ENEMYPLANE_H_ */
