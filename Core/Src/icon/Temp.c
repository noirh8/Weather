#include "image.h"

#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif

extern GUI_CONST_STORAGE GUI_BITMAP iconTemp;

static GUI_CONST_STORAGE unsigned short _iMage[] =
{
		0x2589, 0x2589, 0x2589, 0x2589, 0x5e2f, 0x96d4, 0x5e2f, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x3dcc, 0xf7de, 0xffff, 0xffff, 0x4e0d, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0xbf39, 0xffff, 0xffff, 0xffff, 0x96d4, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0xcf7a, 0xffff, 0xffff, 0xffff, 0x96d4, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0xcf7a, 0xffff, 0xffff, 0xffff, 0x96d4, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589,
		0x2589, 0x2589, 0x2589, 0x2589, 0xcf7a, 0xffff, 0xffff, 0xffff, 0x96d4, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0xcf7a, 0xffff, 0xffff, 0xffff, 0x96d4, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0xcf7a, 0xffff, 0xffff, 0xffff, 0x96d4, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0xcf7a, 0xffff, 0xffff, 0xffff, 0x96d4, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0xcf7a, 0xffff, 0xffff, 0xffff, 0x96d4, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589,
		0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0xcf7a, 0xffff, 0xffff, 0xffff, 0x96d4, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0xcf7a, 0xffff, 0xcf7a, 0x96d4, 0x5e2f, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0xcf7a, 0xffff, 0xffff, 0xffff, 0x96d4, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0xcf7a, 0xffff, 0xcf7a, 0x96d4, 0x5e2f, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589,
		0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0xcf7a, 0xffff, 0xffff, 0xffff, 0x96d4, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0xcf7a, 0xffff, 0xe7bd, 0xcf7a, 0x7671, 0x2589, 0x2589, 0x2589, 0x3dcc, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0xcf7a, 0xffff, 0xe7bd, 0xcf7a, 0x7671, 0x2589, 0x2589, 0xaf17, 0xf7de, 0x35aa, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0xcf7a, 0xffff, 0xffff, 0xffff, 0x96d4, 0x2589, 0x7671, 0xf7de, 0xbf39, 0xaf17, 0x2589, 0x5e2f, 0x9ef6, 0xcf7a, 0x96d4, 0x3dcc, 0x2589, 0x2589, 0x2589, 0x2589, 0xcf7a, 0xffff, 0xcf7a, 0x96d4, 0x5e2f, 0x2589, 0x2589, 0xaf17, 0xd79b, 0x35aa, 0x8693, 0xffff, 0xffff,
		0xcf7a, 0xffff, 0xf7de, 0x35aa, 0x2589, 0x2589, 0x2589, 0xcf7a, 0xffff, 0xffff, 0xffff, 0x96d4, 0x2589, 0x2589, 0x2589, 0x2589, 0x3dcc, 0xffff, 0xcf7a, 0x3dcc, 0x2589, 0x3dcc, 0x7671, 0x2589, 0x2589, 0x2589, 0x2589, 0xcf7a, 0xffff, 0xcf7a, 0x96d4, 0x5e2f, 0x2589, 0x2589, 0x2589, 0x2589, 0x8693, 0xffff, 0x6650, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0xcf7a, 0xffff, 0xffff, 0xffff, 0x96d4, 0x2589, 0x2589, 0x2589, 0x2589, 0x8693, 0xffff, 0x6650, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x3dcc, 0xe7bd, 0xffff, 0xffff, 0xffff, 0xbf39, 0x2589, 0x2589, 0x2589, 0x2589, 0x4e0d, 0xffff, 0xcf7a, 0x35aa, 0x2589, 0x3dcc, 0x6650, 0x2589, 0x2589, 0x35aa, 0xf7de, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xcf7a, 0x2589, 0x2589, 0x2589, 0x2589, 0x9ef6, 0xffff,
		0xffff, 0xcf7a, 0xf7de, 0xf7de, 0x2589, 0x2589, 0xaf17, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x7671, 0x2589, 0x2589, 0x2589, 0x2589, 0x6650, 0xbf39, 0xcf7a, 0x9ef6, 0x3dcc, 0x2589, 0x2589, 0xf7de, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xbf39, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xcf7a, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0xe7bd, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xaf17, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x96d4, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x5e2f, 0x2589, 0x2589, 0x2589, 0x2589,
		0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0xaf17, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x7671, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x7671, 0x9ef6, 0xcf7a, 0xaf17, 0x5e2f, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589
};
GUI_CONST_STORAGE GUI_BITMAP iconTemp =
{
  20, // xSize
  32, // ySize
  40, // BytesPerLine
  16, // BitsPerPixel
  (unsigned char *)_iMage,  // Pointer to picture data
//  NULL,  // Pointer to palette
//  GUI_DRAW_BMPM565
};

