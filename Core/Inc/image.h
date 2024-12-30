/*
 * image.h
 *
 *  Created on: 31 ����. 2019 �.
 *      Author: tabur
 */

#ifndef IMAGE_H_
#define IMAGE_H_

#include <stdint.h>

typedef struct _tImage
{
  uint16_t 					xSize;
  uint16_t 					ySize;
  uint16_t 					bytesPerLine;
  uint8_t					bitsPerPixel;
  const unsigned char* 		pData;
} sImage;

#define GUI_BITMAP			sImage
#define GUI_CONST_STORAGE	const

extern GUI_CONST_STORAGE GUI_BITMAP bitMapImage;

extern GUI_CONST_STORAGE GUI_BITMAP icon_Sun;

extern GUI_CONST_STORAGE GUI_BITMAP imageMorning;
extern GUI_CONST_STORAGE GUI_BITMAP imageEvening;
extern GUI_CONST_STORAGE GUI_BITMAP imageNight;
extern GUI_CONST_STORAGE GUI_BITMAP imageBackGround2;
extern GUI_CONST_STORAGE GUI_BITMAP imageBackGround3;
extern GUI_CONST_STORAGE GUI_BITMAP iconFreezing;
extern GUI_CONST_STORAGE GUI_BITMAP iconFreezingMinor;
extern GUI_CONST_STORAGE GUI_BITMAP iconFreezingRain;
extern GUI_CONST_STORAGE GUI_BITMAP iconFreezingRainMinor;
extern GUI_CONST_STORAGE GUI_BITMAP iconSun;
extern GUI_CONST_STORAGE GUI_BITMAP iconSunMinor;
extern GUI_CONST_STORAGE GUI_BITMAP iconCloud;
extern GUI_CONST_STORAGE GUI_BITMAP iconCloud2;
extern GUI_CONST_STORAGE GUI_BITMAP iconCloud3;
extern GUI_CONST_STORAGE GUI_BITMAP iconCloudMinor;
extern GUI_CONST_STORAGE GUI_BITMAP iconCloudMinor2;
extern GUI_CONST_STORAGE GUI_BITMAP iconRain;
extern GUI_CONST_STORAGE GUI_BITMAP iconRain2;
extern GUI_CONST_STORAGE GUI_BITMAP iconRain3;
extern GUI_CONST_STORAGE GUI_BITMAP iconRainMinor;
extern GUI_CONST_STORAGE GUI_BITMAP iconRainMinor2;
extern GUI_CONST_STORAGE GUI_BITMAP iconThunder;
extern GUI_CONST_STORAGE GUI_BITMAP iconThunder2;
extern GUI_CONST_STORAGE GUI_BITMAP iconThunder3;
extern GUI_CONST_STORAGE GUI_BITMAP iconThunderMinor;
extern GUI_CONST_STORAGE GUI_BITMAP iconThunderMinor2;
extern GUI_CONST_STORAGE GUI_BITMAP iconTemp;
extern GUI_CONST_STORAGE GUI_BITMAP iconTemp2;
extern GUI_CONST_STORAGE GUI_BITMAP iconTempMinor;
extern GUI_CONST_STORAGE GUI_BITMAP iconTempMinor2;
extern GUI_CONST_STORAGE GUI_BITMAP iconApp;
extern GUI_CONST_STORAGE GUI_BITMAP iconWind;
extern GUI_CONST_STORAGE GUI_BITMAP iconWind2;
extern GUI_CONST_STORAGE GUI_BITMAP iconBack;
extern GUI_CONST_STORAGE GUI_BITMAP iconHome;
extern GUI_CONST_STORAGE GUI_BITMAP iconRefresh;
extern GUI_CONST_STORAGE GUI_BITMAP iconMenu;
extern GUI_CONST_STORAGE GUI_BITMAP bmSTLogo;
extern GUI_CONST_STORAGE GUI_BITMAP iconPlaneDPS;
extern GUI_CONST_STORAGE GUI_BITMAP iconPlaneSpeed;
extern GUI_CONST_STORAGE GUI_BITMAP iconPlaneTank;
extern GUI_CONST_STORAGE GUI_BITMAP iconPlaneEnemy;
extern GUI_CONST_STORAGE GUI_BITMAP iconPlaneMiniBoss;
extern GUI_CONST_STORAGE GUI_BITMAP iconPlaneBoss;
extern GUI_CONST_STORAGE GUI_BITMAP iconAppGame;
extern GUI_CONST_STORAGE GUI_BITMAP iconSmoke;
#endif /* IMAGE_H_ */
