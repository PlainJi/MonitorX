/*******************************************************************************
 * Size: 14 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#include "ui.h"

#ifndef UI_FONT_SHANGSHOU14
#define UI_FONT_SHANGSHOU14 1
#endif

#if UI_FONT_SHANGSHOU14

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xfc, 0xf0,

    /* U+0022 "\"" */
    0xff, 0xf0,

    /* U+0023 "#" */
    0x16, 0x16, 0x7f, 0x3c, 0x24, 0xfe, 0x68, 0x48,

    /* U+0024 "$" */
    0xff, 0xcf, 0x3f, 0x3c, 0xf3, 0xff,

    /* U+0025 "%" */
    0xe6, 0xa4, 0xac, 0xf8, 0x1f, 0x39, 0x29, 0x6f,

    /* U+0026 "&" */
    0xf9, 0xb3, 0x63, 0x86, 0xdf, 0xb7, 0x7e,

    /* U+0027 "'" */
    0xfc,

    /* U+0028 "(" */
    0xdb, 0x6d, 0xb6, 0xe0,

    /* U+0029 ")" */
    0xed, 0xb6, 0xdb, 0x60,

    /* U+002A "*" */
    0x33, 0xf7, 0xbf, 0x30,

    /* U+002B "+" */
    0x30, 0xcf, 0xcc, 0x30, 0xc0,

    /* U+002C "," */
    0xf7,

    /* U+002D "-" */
    0xfc,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x3, 0x7, 0x6, 0xc, 0xc, 0x18, 0x38, 0x30,
    0x60, 0x60,

    /* U+0030 "0" */
    0xff, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xff,

    /* U+0031 "1" */
    0xed, 0xb6, 0xdb,

    /* U+0032 "2" */
    0xfe, 0xc, 0x1f, 0xfc, 0x18, 0x30, 0x7f,

    /* U+0033 "3" */
    0xfe, 0xc, 0x1f, 0xf0, 0x60, 0xc1, 0xff,

    /* U+0034 "4" */
    0x66, 0xcd, 0x9f, 0x3c, 0x7f, 0xc1, 0x83,

    /* U+0035 "5" */
    0xff, 0x83, 0x7, 0xf0, 0x60, 0xc1, 0xff,

    /* U+0036 "6" */
    0xff, 0x83, 0x7, 0xfc, 0x78, 0xf1, 0xff,

    /* U+0037 "7" */
    0xfe, 0xc, 0x30, 0x60, 0xc3, 0x6, 0xc,

    /* U+0038 "8" */
    0xff, 0x8f, 0x1b, 0xec, 0x78, 0xf1, 0xff,

    /* U+0039 "9" */
    0xff, 0x8f, 0x1f, 0xf0, 0x60, 0xc1, 0xff,

    /* U+003A ":" */
    0xf0, 0xf0,

    /* U+003B ";" */
    0xf3, 0xdc,

    /* U+003C "<" */
    0x19, 0x98, 0xc6, 0x30, 0xc3,

    /* U+003D "=" */
    0xf8, 0x1, 0xf0,

    /* U+003E ">" */
    0x63, 0xc, 0x31, 0x99, 0x8c,

    /* U+003F "?" */
    0xfe, 0xc, 0x18, 0x33, 0xe6, 0xc, 0x18,

    /* U+0040 "@" */
    0xff, 0xc3, 0xff, 0xff, 0xe7, 0xdf, 0xc0, 0xff,

    /* U+0041 "A" */
    0x1c, 0xa, 0xd, 0x86, 0xc3, 0xe3, 0x19, 0x8d,
    0x83,

    /* U+0042 "B" */
    0xff, 0x8f, 0x1f, 0xec, 0x78, 0xf1, 0xff,

    /* U+0043 "C" */
    0xff, 0x83, 0x6, 0xc, 0x18, 0x30, 0x7f,

    /* U+0044 "D" */
    0xff, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xff,

    /* U+0045 "E" */
    0xff, 0x83, 0x7, 0xfc, 0x18, 0x30, 0x7f,

    /* U+0046 "F" */
    0xff, 0x83, 0x7, 0xfc, 0x18, 0x30, 0x60,

    /* U+0047 "G" */
    0xff, 0x83, 0x6, 0xfc, 0x78, 0xf1, 0xff,

    /* U+0048 "H" */
    0xc7, 0x8f, 0x1f, 0xfc, 0x78, 0xf1, 0xe3,

    /* U+0049 "I" */
    0xfc, 0xc3, 0xc, 0x30, 0xc3, 0x3f,

    /* U+004A "J" */
    0x33, 0x33, 0x33, 0x3f,

    /* U+004B "K" */
    0xc7, 0x9b, 0x67, 0x8f, 0x1b, 0x33, 0x63,

    /* U+004C "L" */
    0xc1, 0x83, 0x6, 0xc, 0x18, 0x30, 0x7f,

    /* U+004D "M" */
    0xe7, 0xe7, 0xe7, 0xff, 0xff, 0xdb, 0xdb, 0xdb,

    /* U+004E "N" */
    0xc7, 0xcf, 0x9f, 0xbd, 0xf9, 0xf3, 0xe3,

    /* U+004F "O" */
    0xff, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xff,

    /* U+0050 "P" */
    0xff, 0x8f, 0x1f, 0xfc, 0x18, 0x30, 0x60,

    /* U+0051 "Q" */
    0xff, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xff, 0xc,
    0x18,

    /* U+0052 "R" */
    0xff, 0x8f, 0x1f, 0xfd, 0x99, 0xb3, 0x63,

    /* U+0053 "S" */
    0xff, 0x83, 0x7, 0xf0, 0x60, 0xc1, 0xff,

    /* U+0054 "T" */
    0xfe, 0x60, 0xc1, 0x83, 0x6, 0xc, 0x18,

    /* U+0055 "U" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xff,

    /* U+0056 "V" */
    0x43, 0x31, 0x98, 0xc4, 0xc3, 0x61, 0xb0, 0x70,
    0x38,

    /* U+0057 "W" */
    0xdd, 0xae, 0xd7, 0x4a, 0xa7, 0x53, 0xb9, 0xdc,
    0xee,

    /* U+0058 "X" */
    0x63, 0x66, 0x3c, 0x1c, 0x1c, 0x3c, 0x76, 0x63,

    /* U+0059 "Y" */
    0xc3, 0x66, 0x3c, 0x3c, 0x18, 0x18, 0x18, 0x18,

    /* U+005A "Z" */
    0xfe, 0xc, 0x30, 0xc3, 0xc, 0x38, 0x7f,

    /* U+005B "[" */
    0xfb, 0x6d, 0xb6, 0xe0,

    /* U+005C "\\" */
    0xc3, 0x18, 0xc3, 0x18, 0xc2, 0x18, 0xc0,

    /* U+005D "]" */
    0xed, 0xb6, 0xdb, 0xe0,

    /* U+005E "^" */
    0x33, 0x9e, 0xb0,

    /* U+005F "_" */
    0xff, 0xf0,

    /* U+0060 "`" */
    0x4d, 0x80,

    /* U+0061 "a" */
    0xfc, 0x3f, 0xf3, 0xcf, 0xf0,

    /* U+0062 "b" */
    0xc3, 0xf, 0xf3, 0xcf, 0x3c, 0xff,

    /* U+0063 "c" */
    0xff, 0xc, 0x30, 0xc3, 0xf0,

    /* U+0064 "d" */
    0xc, 0x3f, 0xf3, 0xcf, 0x3c, 0xff,

    /* U+0065 "e" */
    0xff, 0x3f, 0xf0, 0xc3, 0xf0,

    /* U+0066 "f" */
    0x3c, 0xcf, 0xcc, 0x30, 0xc3, 0xc,

    /* U+0067 "g" */
    0xff, 0x3c, 0xf3, 0xfc, 0x30, 0xff,

    /* U+0068 "h" */
    0xc3, 0xf, 0xf3, 0xcf, 0x3c, 0xf3,

    /* U+0069 "i" */
    0xff, 0xff,

    /* U+006A "j" */
    0x6c, 0x36, 0xdb, 0x7c,

    /* U+006B "k" */
    0xc3, 0xc, 0xf6, 0xf3, 0xcd, 0xb3,

    /* U+006C "l" */
    0xff, 0xff,

    /* U+006D "m" */
    0xff, 0xf3, 0x3c, 0xcf, 0x33, 0xcc, 0xf3, 0x30,

    /* U+006E "n" */
    0xff, 0x3c, 0xf3, 0xcf, 0x30,

    /* U+006F "o" */
    0xff, 0x3c, 0xf3, 0xcf, 0xf0,

    /* U+0070 "p" */
    0xff, 0x3c, 0xf3, 0xff, 0xc, 0x30,

    /* U+0071 "q" */
    0xff, 0x3c, 0xf3, 0xfc, 0x30, 0xc3,

    /* U+0072 "r" */
    0xfc, 0xcc, 0xcc,

    /* U+0073 "s" */
    0xff, 0x83, 0xf0, 0x70, 0xff, 0x80,

    /* U+0074 "t" */
    0x63, 0x3e, 0xc6, 0x31, 0x8f,

    /* U+0075 "u" */
    0xcf, 0x3c, 0xf3, 0xcf, 0xf0,

    /* U+0076 "v" */
    0xc6, 0xcd, 0xb3, 0x63, 0xc7, 0x0,

    /* U+0077 "w" */
    0xce, 0xd3, 0xb7, 0xe9, 0xee, 0x7b, 0x8c, 0xe0,

    /* U+0078 "x" */
    0x66, 0x78, 0xe1, 0xc3, 0xcc, 0xc0,

    /* U+0079 "y" */
    0xcf, 0x3c, 0xf3, 0xfc, 0x30, 0xff,

    /* U+007A "z" */
    0xfc, 0x73, 0x9c, 0xe3, 0xf0,

    /* U+007B "{" */
    0x76, 0x66, 0x66, 0x66, 0x67,

    /* U+007C "|" */
    0xff, 0xff, 0xc0,

    /* U+007D "}" */
    0xe6, 0x66, 0x66, 0x66, 0x6e,

    /* U+007E "~" */
    0xe6, 0x70
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 112, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 45, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 4, .adv_w = 77, .box_w = 4, .box_h = 3, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 6, .adv_w = 132, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 14, .adv_w = 108, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 20, .adv_w = 132, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 28, .adv_w = 120, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 35, .adv_w = 42, .box_w = 2, .box_h = 3, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 36, .adv_w = 58, .box_w = 3, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 40, .adv_w = 58, .box_w = 3, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 44, .adv_w = 93, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 48, .adv_w = 111, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 53, .adv_w = 47, .box_w = 2, .box_h = 4, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 54, .adv_w = 111, .box_w = 6, .box_h = 1, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 55, .adv_w = 45, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 56, .adv_w = 135, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 66, .adv_w = 153, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 73, .adv_w = 153, .box_w = 3, .box_h = 8, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 76, .adv_w = 153, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 83, .adv_w = 153, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 90, .adv_w = 153, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 97, .adv_w = 153, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 104, .adv_w = 153, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 111, .adv_w = 153, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 118, .adv_w = 153, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 125, .adv_w = 153, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 132, .adv_w = 45, .box_w = 2, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 134, .adv_w = 47, .box_w = 2, .box_h = 7, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 136, .adv_w = 85, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 141, .adv_w = 92, .box_w = 5, .box_h = 4, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 144, .adv_w = 85, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 149, .adv_w = 109, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 156, .adv_w = 132, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 164, .adv_w = 144, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 173, .adv_w = 121, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 180, .adv_w = 121, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 187, .adv_w = 121, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 194, .adv_w = 121, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 201, .adv_w = 121, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 208, .adv_w = 121, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 215, .adv_w = 121, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 222, .adv_w = 90, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 228, .adv_w = 67, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 232, .adv_w = 123, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 239, .adv_w = 121, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 246, .adv_w = 131, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 254, .adv_w = 121, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 261, .adv_w = 121, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 268, .adv_w = 121, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 275, .adv_w = 121, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 284, .adv_w = 122, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 291, .adv_w = 121, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 298, .adv_w = 121, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 305, .adv_w = 121, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 312, .adv_w = 142, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 321, .adv_w = 146, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 330, .adv_w = 137, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 338, .adv_w = 135, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 346, .adv_w = 121, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 353, .adv_w = 56, .box_w = 3, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 357, .adv_w = 90, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 364, .adv_w = 56, .box_w = 3, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 368, .adv_w = 90, .box_w = 5, .box_h = 4, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 371, .adv_w = 189, .box_w = 12, .box_h = 1, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 373, .adv_w = 55, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 375, .adv_w = 113, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 380, .adv_w = 113, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 386, .adv_w = 113, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 391, .adv_w = 113, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 397, .adv_w = 113, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 402, .adv_w = 104, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 408, .adv_w = 113, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 414, .adv_w = 113, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 420, .adv_w = 42, .box_w = 2, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 422, .adv_w = 65, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 426, .adv_w = 113, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 432, .adv_w = 42, .box_w = 2, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 434, .adv_w = 166, .box_w = 10, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 442, .adv_w = 113, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 447, .adv_w = 113, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 452, .adv_w = 113, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 458, .adv_w = 113, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 464, .adv_w = 73, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 467, .adv_w = 113, .box_w = 7, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 473, .adv_w = 95, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 478, .adv_w = 113, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 483, .adv_w = 121, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 489, .adv_w = 167, .box_w = 10, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 497, .adv_w = 120, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 503, .adv_w = 113, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 509, .adv_w = 113, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 514, .adv_w = 71, .box_w = 4, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 519, .adv_w = 42, .box_w = 2, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 522, .adv_w = 71, .box_w = 4, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 527, .adv_w = 107, .box_w = 6, .box_h = 2, .ofs_x = 1, .ofs_y = 3}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t ui_font_ShangShou14 = {
#else
lv_font_t ui_font_ShangShou14 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 11,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if UI_FONT_SHANGSHOU14*/

