/*
 * uc1609.c
 *
 *  Created on: Apr 29, 2020
 *      Author: Li Jingchen
 */

#include "uc1609.h"
#include "string.h"

//定义字库
const uint8_t Font5x8[][5] =
{
//
		{ 0x00, 0x00, 0x00, 0x00, 0x00 },	//' '	0x20
		{ 0x00, 0x00, 0x4f, 0x00, 0x00 },	//'!'	0x21
		{ 0x00, 0x07, 0x00, 0x07, 0x00 },	//'"'	0x22
		{ 0x14, 0x7f, 0x14, 0x7f, 0x14 },	//'#'	0x23
		{ 0x24, 0x2a, 0x7f, 0x2a, 0x12 },
		{ 0x23, 0x13, 0x08, 0x64, 0x62 },
		{ 0x36, 0x49, 0x55, 0x22, 0x50 },
		{ 0x00, 0x05, 0x03, 0x00, 0x00 },
		{ 0x00, 0x1c, 0x22, 0x41, 0x00 },
		{ 0x00, 0x41, 0x22, 0x1c, 0x00 },
		{ 0x14, 0x08, 0x3e, 0x08, 0x14 },
		{ 0x08, 0x08, 0x3e, 0x08, 0x08 },
		{ 0x00, 0x50, 0x30, 0x00, 0x00 },
		{ 0x08, 0x08, 0x08, 0x08, 0x08 },
		{ 0x00, 0x60, 0x60, 0x00, 0x00 },
		{ 0x20, 0x10, 0x08, 0x04, 0x02 },
		{ 0x3e, 0x51, 0x49, 0x45, 0x3e },
		{ 0x00, 0x42, 0x7f, 0x40, 0x00 },
		{ 0x42, 0x61, 0x51, 0x49, 0x46 },
		{ 0x21, 0x41, 0x45, 0x4b, 0x31 },
		{ 0x18, 0x14, 0x12, 0x7f, 0x10 },
		{ 0x27, 0x45, 0x45, 0x45, 0x39 },
		{ 0x3c, 0x4a, 0x49, 0x49, 0x30 },
		{ 0x01, 0x01, 0x79, 0x05, 0x03 },
		{ 0x36, 0x49, 0x49, 0x49, 0x36 },
		{ 0x06, 0x49, 0x49, 0x29, 0x1e },
		{ 0x00, 0x36, 0x36, 0x00, 0x00 },
		{ 0x00, 0x56, 0x36, 0x00, 0x00 },
		{ 0x08, 0x14, 0x22, 0x41, 0x00 },
		{ 0x14, 0x14, 0x14, 0x14, 0x14 },
		{ 0x00, 0x41, 0x22, 0x14, 0x08 },
		{ 0x02, 0x01, 0x51, 0x09, 0x06 },
		{ 0x32, 0x49, 0x79, 0x41, 0x3e },
		{ 0x7e, 0x11, 0x11, 0x11, 0x7e },
		{ 0x41, 0x7f, 0x49, 0x49, 0x36 },
		{ 0x3e, 0x41, 0x41, 0x41, 0x22 },
		{ 0x41, 0x7f, 0x41, 0x41, 0x3e },
		{ 0x7f, 0x49, 0x49, 0x49, 0x49 },
		{ 0x7f, 0x09, 0x09, 0x09, 0x01 },
		{ 0x3e, 0x41, 0x41, 0x49, 0x7a },
		{ 0x7f, 0x08, 0x08, 0x08, 0x7f },
		{ 0x00, 0x41, 0x7f, 0x41, 0x00 },
		{ 0x20, 0x40, 0x41, 0x3f, 0x01 },
		{ 0x7f, 0x08, 0x14, 0x22, 0x41 },
		{ 0x7f, 0x40, 0x40, 0x40, 0x40 },
		{ 0x7f, 0x02, 0x0c, 0x02, 0x7f },
		{ 0x7f, 0x06, 0x08, 0x30, 0x7f },
		{ 0x3e, 0x41, 0x41, 0x41, 0x3e },
		{ 0x7f, 0x09, 0x09, 0x09, 0x06 },
		{ 0x3e, 0x41, 0x51, 0x21, 0x5e },
		{ 0x7f, 0x09, 0x19, 0x29, 0x46 },
		{ 0x26, 0x49, 0x49, 0x49, 0x32 },
		{ 0x01, 0x01, 0x7f, 0x01, 0x01 },
		{ 0x3f, 0x40, 0x40, 0x40, 0x3f },
		{ 0x1f, 0x20, 0x40, 0x20, 0x1f },
		{ 0x7f, 0x20, 0x18, 0x20, 0x7f },
		{ 0x63, 0x14, 0x08, 0x14, 0x63 },
		{ 0x07, 0x08, 0x70, 0x08, 0x07 },
		{ 0x61, 0x51, 0x49, 0x45, 0x43 },
		{ 0x00, 0x7f, 0x41, 0x41, 0x00 },
		{ 0x02, 0x04, 0x08, 0x10, 0x20 },
		{ 0x00, 0x41, 0x41, 0x7f, 0x00 },
		{ 0x04, 0x02, 0x01, 0x02, 0x04 },
		{ 0x40, 0x40, 0x40, 0x40, 0x40 },
		{ 0x01, 0x02, 0x04, 0x00, 0x00 },
		{ 0x20, 0x54, 0x54, 0x54, 0x78 },
		{ 0x7f, 0x48, 0x44, 0x44, 0x38 },
		{ 0x38, 0x44, 0x44, 0x44, 0x28 },
		{ 0x38, 0x44, 0x44, 0x48, 0x7f },
		{ 0x38, 0x54, 0x54, 0x54, 0x18 },
		{ 0x00, 0x08, 0x7e, 0x09, 0x02 },
		{ 0x3c, 0x52, 0x52, 0x4c, 0x3e },
		{ 0x7f, 0x08, 0x04, 0x04, 0x78 },
		{ 0x00, 0x44, 0x7d, 0x40, 0x00 },
		{ 0x20, 0x40, 0x44, 0x3d, 0x00 },
		{ 0x00, 0x7f, 0x10, 0x28, 0x44 },
		{ 0x00, 0x41, 0x7f, 0x40, 0x00 },
		{ 0x7c, 0x04, 0x78, 0x04, 0x78 },
		{ 0x7c, 0x08, 0x04, 0x04, 0x78 },
		{ 0x38, 0x44, 0x44, 0x44, 0x38 },
		{ 0x7e, 0x0c, 0x12, 0x12, 0x0c },
		{ 0x0c, 0x12, 0x12, 0x0c, 0x7e },
		{ 0x7c, 0x08, 0x04, 0x04, 0x08 },
		{ 0x58, 0x54, 0x54, 0x54, 0x64 },
		{ 0x04, 0x3f, 0x44, 0x40, 0x20 },
		{ 0x3c, 0x40, 0x40, 0x3c, 0x40 },
		{ 0x1c, 0x20, 0x40, 0x20, 0x1c },
		{ 0x3c, 0x40, 0x30, 0x40, 0x3c },
		{ 0x44, 0x28, 0x10, 0x28, 0x44 },
		{ 0x1c, 0xa0, 0xa0, 0x90, 0x7c },
		{ 0x44, 0x64, 0x54, 0x4c, 0x44 },
		{ 0x00, 0x08, 0x36, 0x41, 0x00 },
		{ 0x00, 0x00, 0x77, 0x00, 0x00 },
		{ 0x00, 0x41, 0x36, 0x08, 0x00 },
		{ 0x02, 0x01, 0x02, 0x04, 0x02 },
		{ 0x55, 0x2A, 0x55, 0x2A, 0x55 }, };

const uint8_t Font816[][16] =
{
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // - -
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },

{ 0x00, 0x00, 0x38, 0xFC, 0xFC, 0x38, 0x00, 0x00,  // -!-
		0x00, 0x00, 0x00, 0x0D, 0x0D, 0x00, 0x00, 0x00 },

{ 0x00, 0x0E, 0x1E, 0x00, 0x00, 0x1E, 0x0E, 0x00,  // -"-
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },

{ 0x20, 0xF8, 0xF8, 0x20, 0xF8, 0xF8, 0x20, 0x00,  // -#-
		0x02, 0x0F, 0x0F, 0x02, 0x0F, 0x0F, 0x02, 0x00 },

{ 0x38, 0x7C, 0x44, 0x47, 0x47, 0xCC, 0x98, 0x00,  // -$-
		0x03, 0x06, 0x04, 0x1C, 0x1C, 0x07, 0x03, 0x00 },

{ 0x30, 0x30, 0x00, 0x80, 0xC0, 0x60, 0x30, 0x00,  // -%-
		0x0C, 0x06, 0x03, 0x01, 0x00, 0x0C, 0x0C, 0x00 },

{ 0x80, 0xD8, 0x7C, 0xE4, 0xBC, 0xD8, 0x40, 0x00,  // -&-
		0x07, 0x0F, 0x08, 0x08, 0x07, 0x0F, 0x08, 0x00 },

{ 0x00, 0x10, 0x1E, 0x0E, 0x00, 0x00, 0x00, 0x00,  // -'-
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },

{ 0x00, 0x00, 0xF0, 0xF8, 0x0C, 0x04, 0x00, 0x00,  // -(-
		0x00, 0x00, 0x03, 0x07, 0x0C, 0x08, 0x00, 0x00 },

{ 0x00, 0x00, 0x04, 0x0C, 0xF8, 0xF0, 0x00, 0x00,  // -)-
		0x00, 0x00, 0x08, 0x0C, 0x07, 0x03, 0x00, 0x00 },

{ 0x80, 0xA0, 0xE0, 0xC0, 0xC0, 0xE0, 0xA0, 0x80,  // -*-
		0x00, 0x02, 0x03, 0x01, 0x01, 0x03, 0x02, 0x00 },

{ 0x00, 0x80, 0x80, 0xE0, 0xE0, 0x80, 0x80, 0x00,  // -+-
		0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00 },

{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // -,-
		0x00, 0x00, 0x10, 0x1E, 0x0E, 0x00, 0x00, 0x00 },

{ 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00,  // ---
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },

{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // -.-
		0x00, 0x00, 0x00, 0x0C, 0x0C, 0x00, 0x00, 0x00 },

{ 0x00, 0x00, 0x00, 0x80, 0xC0, 0x60, 0x30, 0x00,  // -/-
		0x0C, 0x06, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00 },

{ 0xF8, 0xFC, 0x04, 0xC4, 0x24, 0xFC, 0xF8, 0x00,  // -0-
		0x07, 0x0F, 0x09, 0x08, 0x08, 0x0F, 0x07, 0x00 },

{ 0x00, 0x10, 0x18, 0xFC, 0xFC, 0x00, 0x00, 0x00,  // -1-
		0x00, 0x08, 0x08, 0x0F, 0x0F, 0x08, 0x08, 0x00 },

{ 0x08, 0x0C, 0x84, 0xC4, 0x64, 0x3C, 0x18, 0x00,  // -2-
		0x0E, 0x0F, 0x09, 0x08, 0x08, 0x0C, 0x0C, 0x00 },

{ 0x08, 0x0C, 0x44, 0x44, 0x44, 0xFC, 0xB8, 0x00,  // -3-
		0x04, 0x0C, 0x08, 0x08, 0x08, 0x0F, 0x07, 0x00 },

{ 0xC0, 0xE0, 0xB0, 0x98, 0xFC, 0xFC, 0x80, 0x00,  // -4-
		0x00, 0x00, 0x00, 0x08, 0x0F, 0x0F, 0x08, 0x00 },

{ 0x7C, 0x7C, 0x44, 0x44, 0xC4, 0xC4, 0x84, 0x00,  // -5-
		0x04, 0x0C, 0x08, 0x08, 0x08, 0x0F, 0x07, 0x00 },

{ 0xF0, 0xF8, 0x4C, 0x44, 0x44, 0xC0, 0x80, 0x00,  // -6-
		0x07, 0x0F, 0x08, 0x08, 0x08, 0x0F, 0x07, 0x00 },

{ 0x0C, 0x0C, 0x04, 0x84, 0xC4, 0x7C, 0x3C, 0x00,  // -7-
		0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00 },

{ 0xB8, 0xFC, 0x44, 0x44, 0x44, 0xFC, 0xB8, 0x00,  // -8-
		0x07, 0x0F, 0x08, 0x08, 0x08, 0x0F, 0x07, 0x00 },

{ 0x38, 0x7C, 0x44, 0x44, 0x44, 0xFC, 0xF8, 0x00,  // -9-
		0x00, 0x08, 0x08, 0x08, 0x0C, 0x07, 0x03, 0x00 },

{ 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00,  // -:-
		0x00, 0x00, 0x00, 0x06, 0x06, 0x00, 0x00, 0x00 },

{ 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00,  // -;-
		0x00, 0x00, 0x08, 0x0E, 0x06, 0x00, 0x00, 0x00 },

{ 0x00, 0x80, 0xC0, 0x60, 0x30, 0x18, 0x08, 0x00,  // -<-
		0x00, 0x00, 0x01, 0x03, 0x06, 0x0C, 0x08, 0x00 },

{ 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00,  // -=-
		0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00 },

{ 0x00, 0x08, 0x18, 0x30, 0x60, 0xC0, 0x80, 0x00,  // ->-
		0x00, 0x08, 0x0C, 0x06, 0x03, 0x01, 0x00, 0x00 },

{ 0x18, 0x1C, 0x04, 0xC4, 0xE4, 0x3C, 0x18, 0x00,  // -?-
		0x00, 0x00, 0x00, 0x0D, 0x0D, 0x00, 0x00, 0x00 },

{ 0xF0, 0xF8, 0x08, 0xC8, 0xC8, 0xF8, 0xF0, 0x00,  // -@-
		0x07, 0x0F, 0x08, 0x0B, 0x0B, 0x0B, 0x01, 0x00 },

{ 0xE0, 0xF0, 0x98, 0x8C, 0x98, 0xF0, 0xE0, 0x00,  // -A-
		0x0F, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x00 },

{ 0x04, 0xFC, 0xFC, 0x44, 0x44, 0xFC, 0xB8, 0x00,  // -B-
		0x08, 0x0F, 0x0F, 0x08, 0x08, 0x0F, 0x07, 0x00 },

{ 0xF0, 0xF8, 0x0C, 0x04, 0x04, 0x0C, 0x18, 0x00,  // -C-
		0x03, 0x07, 0x0C, 0x08, 0x08, 0x0C, 0x06, 0x00 },

{ 0x04, 0xFC, 0xFC, 0x04, 0x0C, 0xF8, 0xF0, 0x00,  // -D-
		0x08, 0x0F, 0x0F, 0x08, 0x0C, 0x07, 0x03, 0x00 },

{ 0x04, 0xFC, 0xFC, 0x44, 0xE4, 0x0C, 0x1C, 0x00,  // -E-
		0x08, 0x0F, 0x0F, 0x08, 0x08, 0x0C, 0x0E, 0x00 },

{ 0x04, 0xFC, 0xFC, 0x44, 0xE4, 0x0C, 0x1C, 0x00,  // -F-
		0x08, 0x0F, 0x0F, 0x08, 0x00, 0x00, 0x00, 0x00 },

{ 0xF0, 0xF8, 0x0C, 0x84, 0x84, 0x8C, 0x98, 0x00,  // -G-
		0x03, 0x07, 0x0C, 0x08, 0x08, 0x07, 0x0F, 0x00 },

{ 0xFC, 0xFC, 0x40, 0x40, 0x40, 0xFC, 0xFC, 0x00,  // -H-
		0x0F, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x00 },

{ 0x00, 0x00, 0x04, 0xFC, 0xFC, 0x04, 0x00, 0x00,  // -I-
		0x00, 0x00, 0x08, 0x0F, 0x0F, 0x08, 0x00, 0x00 },

{ 0x00, 0x00, 0x00, 0x04, 0xFC, 0xFC, 0x04, 0x00,  // -J-
		0x07, 0x0F, 0x08, 0x08, 0x0F, 0x07, 0x00, 0x00 },

{ 0x04, 0xFC, 0xFC, 0xC0, 0xF0, 0x3C, 0x0C, 0x00,  // -K-
		0x08, 0x0F, 0x0F, 0x00, 0x01, 0x0F, 0x0E, 0x00 },

{ 0x04, 0xFC, 0xFC, 0x04, 0x00, 0x00, 0x00, 0x00,  // -L-
		0x08, 0x0F, 0x0F, 0x08, 0x08, 0x0C, 0x0E, 0x00 },

{ 0xFC, 0xFC, 0x38, 0x70, 0x38, 0xFC, 0xFC, 0x00,  // -M-
		0x0F, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x00 },

{ 0xFC, 0xFC, 0x38, 0x70, 0xE0, 0xFC, 0xFC, 0x00,  // -N-
		0x0F, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x00 },

{ 0xF0, 0xF8, 0x0C, 0x04, 0x0C, 0xF8, 0xF0, 0x00,  // -O-
		0x03, 0x07, 0x0C, 0x08, 0x0C, 0x07, 0x03, 0x00 },

{ 0x04, 0xFC, 0xFC, 0x44, 0x44, 0x7C, 0x38, 0x00,  // -P-
		0x08, 0x0F, 0x0F, 0x08, 0x00, 0x00, 0x00, 0x00 },

{ 0xF8, 0xFC, 0x04, 0x04, 0x04, 0xFC, 0xF8, 0x00,  // -Q-
		0x07, 0x0F, 0x08, 0x0E, 0x3C, 0x3F, 0x27, 0x00 },

{ 0x04, 0xFC, 0xFC, 0x44, 0xC4, 0xFC, 0x38, 0x00,  // -R-
		0x08, 0x0F, 0x0F, 0x00, 0x00, 0x0F, 0x0F, 0x00 },

{ 0x18, 0x3C, 0x64, 0x44, 0xC4, 0x9C, 0x18, 0x00,  // -S-
		0x06, 0x0E, 0x08, 0x08, 0x08, 0x0F, 0x07, 0x00 },

{ 0x00, 0x1C, 0x0C, 0xFC, 0xFC, 0x0C, 0x1C, 0x00,  // -T-
		0x00, 0x00, 0x08, 0x0F, 0x0F, 0x08, 0x00, 0x00 },

{ 0xFC, 0xFC, 0x00, 0x00, 0x00, 0xFC, 0xFC, 0x00,  // -U-
		0x07, 0x0F, 0x08, 0x08, 0x08, 0x0F, 0x07, 0x00 },

{ 0xFC, 0xFC, 0x00, 0x00, 0x00, 0xFC, 0xFC, 0x00,  // -V-
		0x01, 0x03, 0x06, 0x0C, 0x06, 0x03, 0x01, 0x00 },

{ 0xFC, 0xFC, 0x00, 0x80, 0x00, 0xFC, 0xFC, 0x00,  // -W-
		0x03, 0x0F, 0x0E, 0x03, 0x0E, 0x0F, 0x03, 0x00 },

{ 0x0C, 0x3C, 0xF0, 0xC0, 0xF0, 0x3C, 0x0C, 0x00,  // -X-
		0x0C, 0x0F, 0x03, 0x00, 0x03, 0x0F, 0x0C, 0x00 },

{ 0x00, 0x3C, 0x7C, 0xC0, 0xC0, 0x7C, 0x3C, 0x00,  // -Y-
		0x00, 0x00, 0x08, 0x0F, 0x0F, 0x08, 0x00, 0x00 },

{ 0x1C, 0x0C, 0x84, 0xC4, 0x64, 0x3C, 0x1C, 0x00,  // -Z-
		0x0E, 0x0F, 0x09, 0x08, 0x08, 0x0C, 0x0E, 0x00 },

{ 0x00, 0x00, 0xFC, 0xFC, 0x04, 0x04, 0x00, 0x00,  // -[-
		0x00, 0x00, 0x0F, 0x0F, 0x08, 0x08, 0x00, 0x00 },

{ 0x38, 0x70, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00,  // -\-
		0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0E, 0x00 },

{ 0x00, 0x00, 0x04, 0x04, 0xFC, 0xFC, 0x00, 0x00,  // -]-
		0x00, 0x00, 0x08, 0x08, 0x0F, 0x0F, 0x00, 0x00 },

{ 0x08, 0x0C, 0x06, 0x03, 0x06, 0x0C, 0x08, 0x00,  // -^-
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },

{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // -_-
		0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },

{ 0x00, 0x00, 0x03, 0x07, 0x04, 0x00, 0x00, 0x00,  // -`-
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },

{ 0x00, 0xA0, 0xA0, 0xA0, 0xE0, 0xC0, 0x00, 0x00,  // -a-
		0x07, 0x0F, 0x08, 0x08, 0x07, 0x0F, 0x08, 0x00 },

{ 0x04, 0xFC, 0xFC, 0x20, 0x60, 0xC0, 0x80, 0x00,  // -b-
		0x08, 0x0F, 0x07, 0x08, 0x08, 0x0F, 0x07, 0x00 },

{ 0xC0, 0xE0, 0x20, 0x20, 0x20, 0x60, 0x40, 0x00,  // -c-
		0x07, 0x0F, 0x08, 0x08, 0x08, 0x0C, 0x04, 0x00 },

{ 0x80, 0xC0, 0x60, 0x24, 0xFC, 0xFC, 0x00, 0x00,  // -d-
		0x07, 0x0F, 0x08, 0x08, 0x07, 0x0F, 0x08, 0x00 },

{ 0xC0, 0xE0, 0xA0, 0xA0, 0xA0, 0xE0, 0xC0, 0x00,  // -e-
		0x07, 0x0F, 0x08, 0x08, 0x08, 0x0C, 0x04, 0x00 },

{ 0x40, 0xF8, 0xFC, 0x44, 0x0C, 0x18, 0x00, 0x00,  // -f-
		0x08, 0x0F, 0x0F, 0x08, 0x00, 0x00, 0x00, 0x00 },

{ 0xC0, 0xE0, 0x20, 0x20, 0xC0, 0xE0, 0x20, 0x00,  // -g-
		0x27, 0x6F, 0x48, 0x48, 0x7F, 0x3F, 0x00, 0x00 },

{ 0x04, 0xFC, 0xFC, 0x40, 0x20, 0xE0, 0xC0, 0x00,  // -h-
		0x08, 0x0F, 0x0F, 0x00, 0x00, 0x0F, 0x0F, 0x00 },

{ 0x00, 0x00, 0x20, 0xEC, 0xEC, 0x00, 0x00, 0x00,  // -i-
		0x00, 0x00, 0x08, 0x0F, 0x0F, 0x08, 0x00, 0x00 },

{ 0x00, 0x00, 0x00, 0x00, 0x20, 0xEC, 0xEC, 0x00,  // -j-
		0x00, 0x30, 0x70, 0x40, 0x40, 0x7F, 0x3F, 0x00 },

{ 0x04, 0xFC, 0xFC, 0x80, 0xC0, 0x60, 0x20, 0x00,  // -k-
		0x08, 0x0F, 0x0F, 0x01, 0x03, 0x0E, 0x0C, 0x00 },

{ 0x00, 0x00, 0x04, 0xFC, 0xFC, 0x00, 0x00, 0x00,  // -l-
		0x00, 0x00, 0x08, 0x0F, 0x0F, 0x08, 0x00, 0x00 },

{ 0xE0, 0xE0, 0x60, 0xC0, 0x60, 0xE0, 0xC0, 0x00,  // -m-
		0x0F, 0x0F, 0x00, 0x0F, 0x00, 0x0F, 0x0F, 0x00 },

{ 0x20, 0xE0, 0xC0, 0x20, 0x20, 0xE0, 0xC0, 0x00,  // -n-
		0x00, 0x0F, 0x0F, 0x00, 0x00, 0x0F, 0x0F, 0x00 },

{ 0xC0, 0xE0, 0x20, 0x20, 0x20, 0xE0, 0xC0, 0x00,  // -o-
		0x07, 0x0F, 0x08, 0x08, 0x08, 0x0F, 0x07, 0x00 },

{ 0x20, 0xE0, 0xC0, 0x20, 0x20, 0xE0, 0xC0, 0x00,  // -p-
		0x40, 0x7F, 0x7F, 0x48, 0x08, 0x0F, 0x07, 0x00 },

{ 0xC0, 0xE0, 0x20, 0x20, 0xC0, 0xE0, 0x20, 0x00,  // -q-
		0x07, 0x0F, 0x08, 0x48, 0x7F, 0x7F, 0x40, 0x00 },

{ 0x20, 0xE0, 0xC0, 0x60, 0x20, 0x60, 0xC0, 0x00,  // -r-
		0x08, 0x0F, 0x0F, 0x08, 0x00, 0x00, 0x00, 0x00 },

{ 0x40, 0xE0, 0xA0, 0x20, 0x20, 0x60, 0x40, 0x00,  // -s-
		0x04, 0x0C, 0x09, 0x09, 0x0B, 0x0E, 0x04, 0x00 },

{ 0x20, 0x20, 0xF8, 0xFC, 0x20, 0x20, 0x00, 0x00,  // -t-
		0x00, 0x00, 0x07, 0x0F, 0x08, 0x0C, 0x04, 0x00 },

{ 0xE0, 0xE0, 0x00, 0x00, 0xE0, 0xE0, 0x00, 0x00,  // -u-
		0x07, 0x0F, 0x08, 0x08, 0x07, 0x0F, 0x08, 0x00 },

{ 0x00, 0xE0, 0xE0, 0x00, 0x00, 0xE0, 0xE0, 0x00,  // -v-
		0x00, 0x03, 0x07, 0x0C, 0x0C, 0x07, 0x03, 0x00 },

{ 0xE0, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0x00,  // -w-
		0x07, 0x0F, 0x0C, 0x07, 0x0C, 0x0F, 0x07, 0x00 },

{ 0x20, 0x60, 0xC0, 0x80, 0xC0, 0x60, 0x20, 0x00,  // -x-
		0x08, 0x0C, 0x07, 0x03, 0x07, 0x0C, 0x08, 0x00 },

{ 0xE0, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0x00,  // -y-
		0x47, 0x4F, 0x48, 0x48, 0x68, 0x3F, 0x1F, 0x00 },

{ 0x60, 0x60, 0x20, 0xA0, 0xE0, 0x60, 0x20, 0x00,  // -z-
		0x0C, 0x0E, 0x0B, 0x09, 0x08, 0x0C, 0x0C, 0x00 },

{ 0x00, 0x40, 0x40, 0xF8, 0xBC, 0x04, 0x04, 0x00,  // -{-
		0x00, 0x00, 0x00, 0x07, 0x0F, 0x08, 0x08, 0x00 },

{ 0x00, 0x00, 0x00, 0xBC, 0xBC, 0x00, 0x00, 0x00,  // -|-
		0x00, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x00 },

{ 0x00, 0x04, 0x04, 0xBC, 0xF8, 0x40, 0x40, 0x00,  // -}-
		0x00, 0x08, 0x08, 0x0F, 0x07, 0x00, 0x00, 0x00 },

{ 0x08, 0x0C, 0x04, 0x0C, 0x08, 0x0C, 0x04, 0x00,  // -~-
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },

{ 0x80, 0xC0, 0x60, 0x30, 0x60, 0xC0, 0x80, 0x00,  // --
		0x07, 0x07, 0x04, 0x04, 0x04, 0x07, 0x07, 0x00 }, };

uint8_t disp_buf[1536];

#ifdef USE_LCDPRINT
#ifdef __GNUC__
/* With GCC, small printf (option LD Linker->Libraries->Small printf
 set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

PUTCHAR_PROTOTYPE
{
	static uint8_t x, y;

	switch (ch)
	{
	case '\r':
		x = 0;
		break;
	case '\n':
		y++;
		if (y > 7)
		{
			memcpy(disp_buf, &disp_buf[192], 1536 - 192);
			memset(&disp_buf[192 * 7 - 1], 0, 192);
			y = 7;
		}
		break;
	default:
		display_one_char(x, y, (char) ch, 0);
		x += 6;
		if (x > (192 - 6))
		{
			x = 0;
			y++;
			if (y > 7)
			{
				memcpy(disp_buf, &disp_buf[192], 1536 - 192);
				memset(&disp_buf[192 * 7 - 1], 0, 192);
				y = 7;
			}
		}
	}

	return ch;
}
#endif

//发送OLED命令
void lcd_sendcmd(uint8_t cmd)
{
	HAL_GPIO_WritePin(LCD_CD_GPIO_Port, LCD_CD_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi1, &cmd, 1, 200);
	HAL_GPIO_WritePin(LCD_CD_GPIO_Port, LCD_CD_Pin, GPIO_PIN_SET);
}

//OLED初始化函数
void lcd_init(void)
{
	//拉低复位脚0.2秒完成复位
	HAL_Delay(200);
	HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_SET);
	HAL_Delay(20);

	//初始化OLED
	lcd_sendcmd(0xe2);	//显示屏复位指令
	lcd_sendcmd(0xa3);//设置帧速率[A0: 76fps, A1b: 95fps, A2b: 132fps, A3b: 168fps(fps: frame-per-second)]
	lcd_sendcmd(0xeb);	//设置LCD偏置比(亮度设置)
	lcd_sendcmd(0x2f);	//显示屏功耗设置
	lcd_sendcmd(0xc2);	//设置LCD映射控制
	lcd_sendcmd(0x81);	//设置SEG偏置电压(对比度) 双字节指令
	lcd_sendcmd(180);	//设置SEG偏置电压(对比度) 双字节指令
	lcd_sendcmd(0xaf);	//开启显示指令

	//启动定时器10，开始定时DMA刷新
	HAL_TIM_Base_Start_IT(&htim10);
}

//清屏
void lcd_cls(uint8_t rev)
{
	for (uint16_t i = 0; i < 1536; i++)
		disp_buf[i] = rev ? 0xff : 0x00;
}

//在指定坐标显示一个6*8点阵ASCII字符
void display_one_char(uint8_t x, uint8_t y, char char_data, uint8_t rev)
{
	uint8_t i;
	uint16_t ptr = y * 192 + x + 1;		//显示偏移指针

	//写入5字节点阵数据
	for (i = 0; i < 5; i++)
	{
		disp_buf[ptr + i] =
				rev ? ~Font5x8[char_data - 0x20][i] : Font5x8[char_data - 0x20][i];
	}
}

//指定坐标显示一个6*8字符串
void display_list_char(uint8_t x, uint8_t y, char *data_s, uint8_t rev)
{
	while (*data_s)
	{
		display_one_char(x, y, *data_s, rev);  //显示单个字符
		data_s++;
		x += 6;

		if (x >= 186)
		{
			x = 0;
			y++;
			if (y > 7)
				return;
		}
	}
}

//显示8*16点阵ASCII字符函数
void display_816_char(uint8_t x, uint8_t y, char char_data, uint8_t rev)
{
	uint8_t i;
	uint16_t ptr = y * 192 + x;		//显示偏移指针
	//写入16字节点阵数字
	for (i = 0; i < 8; i++)
	{
		disp_buf[ptr + i] =
				rev ? ~Font816[char_data - 0x20][i] : Font816[char_data - 0x20][i];
	}
	ptr += 192;
	for (i = 0; i < 8; i++)
	{
		disp_buf[ptr + i] =
				rev ? ~Font816[char_data - 0x20][i + 8] : Font816[char_data
								- 0x20][i + 8];
	}
}

//指定坐标显示一个6*8字符串
void display_list_816(uint8_t x, uint8_t y, char *data_s, uint8_t rev)
{
	while (*data_s)
	{
		display_816_char(x, y, *data_s, rev);  //显示单个字符
		data_s++;
		x += 8;
		if (x >= 184)
		{
			x = 0;
			y += 2;
			if (y > 7)
				return;
		}
	}
}

/****************************************************************************
 * 名称：gui_point()
 * 功能：画点。
 * 入口参数：X		点所在列的位置
 *           Y		点所在行的位置
 *			左下角坐标为0,0
 *           DRAW_MODE	显示模式(1 画点     0 清点     2  反色）
 * 出口参数：无
 * 说明：操作失败原因是指定地址超出缓冲区范围。
 *
 ****************************************************************************/
void gui_point(uint8_t X, uint8_t Y, uint8_t draw_mode)
{

	if ((X >= 192) || (Y >= 64))
		return;

	uint8_t PAGE_Y = 7 - Y / 8;		//列换算成PAGE
	uint8_t char_Y = Y % 8;		//算出要操作的位
	uint16_t ptr = PAGE_Y * 192 + X;	//计算当前坐标在缓存中的偏移

	switch (draw_mode %= 3)
	{
	case 0:
		disp_buf[ptr % 1536] = disp_buf[ptr] &= ~(1 << (7 - char_Y));
		break;
	case 1:
		disp_buf[ptr % 1536] = disp_buf[ptr] |= 1 << (7 - char_Y);
		break;
	case 2:
		disp_buf[ptr % 1536] = disp_buf[ptr] ^= 1 << (7 - char_Y);
		break;

	default:
		break;
	}
}

/***********************************************************************
 画一条x1,y1到x2,y2的直线
 (show=1画点，show=0清点)
 ***********************************************************************/
void glcd_line(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint8_t show)
{
	int16_t dy;
	int16_t dx;
	int16_t stepx, stepy, fraction;
	dy = y2 - y1;
	dx = x2 - x1;
	if (dy < 0)
	{
		dy = -dy;
		stepy = -1;
	}
	else
	{
		stepy = 1;
	}
	if (dx < 0)
	{
		dx = -dx;
		stepx = -1;
	}
	else
	{
		stepx = 1;
	}
	dy <<= 1;
	dx <<= 1;
	gui_point(x1, y1, show);
	if (dx > dy)
	{
		fraction = dy - (dx >> 1);
		while (x1 != x2)
		{
			if (fraction >= 0)
			{
				y1 += stepy;
				fraction -= dx;
			}
			x1 += stepx;
			fraction += dy;
			gui_point(x1, y1, show);
		}
	}
	else
	{
		fraction = dx - (dy >> 1);
		while (y1 != y2)
		{
			if (fraction >= 0)
			{
				x1 += stepx;
				fraction -= dy;
			}
			y1 += stepy;
			fraction += dx;
			gui_point(x1, y1, show);
		}
	}
}

/***********************************************************************
 以x,y为圆心，以radius为半径画贺
 (show=1画点，show=0清点)
 ***********************************************************************/
void glcd_circle(int16_t x, int16_t y, int16_t radius, uint8_t show)
{
	int16_t xc = 0;
	int16_t yc;
	int16_t p;
	yc = radius;
	p = 3 - (radius << 1);
	while (xc <= yc)
	{
		gui_point(x + xc, y + yc, show);
		gui_point(x + xc, y - yc, show);
		gui_point(x - xc, y + yc, show);
		gui_point(x - xc, y - yc, show);
		gui_point(x + yc, y + xc, show);
		gui_point(x + yc, y - xc, show);
		gui_point(x - yc, y + xc, show);
		gui_point(x - yc, y - xc, show);
		if (p < 0)
			p += (xc++ << 2) + 6;
		else
			p += ((xc++ - yc--) << 2) + 10;
	}
}

