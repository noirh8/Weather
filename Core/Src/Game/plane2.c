
#include "image.h"

#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif

extern GUI_CONST_STORAGE GUI_BITMAP iconPlaneSpeed;

static GUI_CONST_STORAGE unsigned short _iMage[] =
{
		0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x3404, 0x3425, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x3a60, 0x3a60, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2d07, 0x31c0, 0x31c0, 0x2d07, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589,
		0x2589, 0x2589, 0x2589, 0x2589, 0x3bc4, 0x31c0, 0x31c0, 0x3bc4, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x3ac1, 0x31c0, 0x31c0, 0x3ac1, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x42e1, 0x3a00, 0x3a00, 0x42e1, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x5320, 0x4aa0, 0x4aa0, 0x5320, 0x2589,
		0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x5320, 0x4aa0, 0x4aa0, 0x5320, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x5320, 0x4aa0, 0x4aa0, 0x5320, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2528, 0x5300, 0x4280, 0x4aa0, 0x5300, 0x2528, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589,
		0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2528, 0x3a40, 0x52e0, 0x4240, 0x4240, 0x52e0, 0x3a40, 0x2528, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2528, 0x3a40, 0x31e0, 0x52e0, 0x4240, 0x4240, 0x52e0, 0x31e0, 0x3a40, 0x2528, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x3a60, 0x31e0, 0x5b60, 0x52e0, 0x4240, 0x4240, 0x52e0, 0x5b60, 0x31e0, 0x3a60, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589,
		0x2589, 0x2589, 0x2589, 0x2528, 0x31c0, 0x5320, 0x63a0, 0x52e0, 0x4240, 0x4240, 0x52e0, 0x63a0, 0x5320, 0x31c0, 0x2528, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x3ba3, 0x31c0, 0x63c0, 0x6380, 0x52e0, 0x3a20, 0x3a20, 0x52e0, 0x6380, 0x63a0, 0x31c0, 0x3404, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x3ac1, 0x4240, 0x63c0, 0x6380, 0x52e0, 0x3a00, 0x3a00, 0x52e0, 0x6380, 0x63c0, 0x3a20, 0x3ac1, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x3486, 0x31e0, 0x4aa0, 0x63c0, 0x5b40, 0x52e0, 0x3a00,
		0x3a00, 0x52e0, 0x5b40, 0x63c0, 0x4aa0, 0x31e0, 0x3486, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x3486, 0x31e0, 0x3a20, 0x63a0, 0x63c0, 0x5b40, 0x52e0, 0x3a00, 0x3a00, 0x52e0, 0x5b40, 0x63c0, 0x63a0, 0x3a20, 0x31e0, 0x3486, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x3486, 0x31e0, 0x3a20, 0x63a0, 0x63c0, 0x63c0, 0x5b20, 0x52e0, 0x3a00, 0x3a00, 0x52e0, 0x5b40, 0x63c0, 0x63c0, 0x63a0, 0x3a20, 0x31e0, 0x3486, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x3ba3, 0x31c0, 0x4260, 0x63a0, 0x63c0, 0x63c0, 0x63c0, 0x5300, 0x52e0, 0x31c0, 0x31c0, 0x52e0, 0x5300, 0x63c0, 0x63c0, 0x63c0, 0x63a0, 0x4260, 0x31e0,
		0x3ba3, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x3ba3, 0x31c0, 0x4280, 0x63c0, 0x63c0, 0x63c0, 0x63c0, 0x63c0, 0x5300, 0x52e0, 0x31c0, 0x31c0, 0x52e0, 0x5300, 0x63c0, 0x63c0, 0x63c0, 0x63c0, 0x63c0, 0x4280, 0x31c0, 0x3ba3, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x3ba3, 0x31c0, 0x4280, 0x63c0, 0x63c0, 0x63c0, 0x63c0, 0x63c0, 0x5b40, 0x4aa0, 0x52e0, 0x31c0, 0x31c0, 0x52e0, 0x4aa0, 0x5b40, 0x63c0, 0x63c0, 0x63c0, 0x63c0, 0x63c0, 0x4280, 0x31c0, 0x3ba3, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x3ba3, 0x31c0, 0x5300, 0x63c0, 0x63c0, 0x63c0, 0x63c0, 0x63c0, 0x52e0, 0x31c0, 0x4aa0, 0x52e0, 0x31c0, 0x31c0, 0x52e0, 0x4aa0, 0x31c0, 0x52e0, 0x63c0, 0x63c0, 0x63c0, 0x63c0, 0x63c0, 0x5300, 0x31c0, 0x3ba3, 0x2589, 0x2589, 0x2589, 0x2589, 0x3a60,
		0x52e0, 0x63c0, 0x9ca0, 0xf600, 0x8440, 0x63c0, 0x4ac0, 0x31c0, 0x31c0, 0x4aa0, 0x4ac0, 0x31c0, 0x31c0, 0x4ac0, 0x4aa0, 0x31c0, 0x31c0, 0x4ac0, 0x63c0, 0x8440, 0xf600, 0x9ca0, 0x63c0, 0x52e0, 0x3a60, 0x2589, 0x2589, 0x2589, 0x2589, 0x3a60, 0x5b40, 0x63c0, 0xddc0, 0xfe20, 0xbd20, 0x63c0, 0x4ac0, 0x31c0, 0x31c0, 0x4ac0, 0x4aa0, 0x31c0, 0x31c0, 0x4aa0, 0x4ac0, 0x31c0, 0x31c0, 0x4ac0, 0x63c0, 0xbd20, 0xfe20, 0xddc0, 0x63c0, 0x5b40, 0x3a60, 0x2589, 0x2589, 0x2589, 0x2589, 0x3a80, 0x5b40, 0x63c0, 0x73e0, 0xb500, 0x63c0, 0x63c0, 0x5320, 0x31c0, 0x31c0, 0x52e0, 0x4aa0, 0x31c0, 0x31c0, 0x4aa0, 0x52e0, 0x31c0, 0x31c0, 0x5320, 0x63c0, 0x63c0, 0xb500, 0x73e0, 0x63c0, 0x5b40, 0x3a80, 0x2589, 0x2589, 0x2589, 0x2589, 0x2528, 0x5422, 0x63e0, 0x63c0, 0x63c0, 0x63c0, 0x63c0, 0x5b60, 0x31c0, 0x31c0,
		0x52e0, 0x4aa0, 0x31c0, 0x31c0, 0x4aa0, 0x52e0, 0x31c0, 0x31c0, 0x5b60, 0x63c0, 0x63c0, 0x63c0, 0x63c0, 0x63e0, 0x4c43, 0x2528, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2d27, 0x44a4, 0x4c84, 0x63e0, 0x63c0, 0x31c0, 0x3a20, 0x52e0, 0x4aa0, 0x31c0, 0x31c0, 0x4aa0, 0x52e0, 0x3a20, 0x31c0, 0x63c0, 0x63e0, 0x4c84, 0x44a4, 0x2d27, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x3ce6, 0x63e0, 0x63c0, 0x63c0, 0x3a20, 0x3a20, 0x52e0, 0x4240, 0x31c0, 0x31c0, 0x4240, 0x52e0, 0x3a20, 0x3a20, 0x63c0, 0x63c0, 0x63e0, 0x3ce6, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x3ce5, 0x63c0, 0x63c0, 0xbd20, 0x8440, 0x63c0, 0x5300, 0x52e0, 0x4280, 0x31c0, 0x31c0, 0x4280, 0x52e0, 0x5300, 0x63c0, 0x8440,
		0xbd20, 0x63c0, 0x63c0, 0x3ce5, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x44a4, 0x63c0, 0x73e0, 0xddc0, 0x9ca0, 0x63c0, 0x4b81, 0x4240, 0x4321, 0x31c0, 0x31c0, 0x4321, 0x4240, 0x4b81, 0x63c0, 0x9ca0, 0xddc0, 0x73e0, 0x63c0, 0x44a4, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2568, 0x63e0, 0x63c0, 0x63c0, 0x63c0, 0x63c0, 0x3424, 0x3a20, 0x3b83, 0x3a20, 0x3a20, 0x3b83, 0x3a20, 0x3424, 0x63c0, 0x63c0, 0x63c0, 0x63c0, 0x63e0, 0x2568, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2d27, 0x3ce6, 0x44a4, 0x4c63, 0x4c63, 0x2589, 0x2589, 0x2589, 0x3aa0, 0x3ac1, 0x2589, 0x2589, 0x2589, 0x4c63, 0x4c63, 0x44a4, 0x3ce6, 0x2d27, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589,
		0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x3b83, 0x3425, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589
};
GUI_CONST_STORAGE GUI_BITMAP iconPlaneSpeed =
{
  30, // xSize
  35, // ySize
  60, // BytesPerLine
  16, // BitsPerPixel
  (unsigned char *)_iMage,  // Pointer to picture data
//  NULL,  // Pointer to palette
//  GUI_DRAW_BMPM565
};





