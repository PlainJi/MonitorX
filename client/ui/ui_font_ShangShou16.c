/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --size 16 --font E:\1.Project\DesktopBox\lvgl_proj\assets\ShangShouBiaoBangTi-2.ttf -o E:\1.Project\DesktopBox\lvgl_proj\assets\ui_font_ShangShou16.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "ui.h"

#ifndef UI_FONT_SHANGSHOU16
#define UI_FONT_SHANGSHOU16 1
#endif

#if UI_FONT_SHANGSHOU16

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xff, 0x3c,

    /* U+0022 "\"" */
    0xff, 0xf0,

    /* U+0023 "#" */
    0x1b, 0xd, 0x9f, 0xe7, 0xc3, 0x61, 0xb3, 0xfc,
    0xd8, 0x6c, 0x36, 0x0,

    /* U+0024 "$" */
    0xff, 0xcf, 0x3c, 0xfc, 0xf3, 0xcf, 0x3f, 0xf0,

    /* U+0025 "%" */
    0xf2, 0x7b, 0x3d, 0x1f, 0x8f, 0xc0, 0x40, 0x7e,
    0x2f, 0x37, 0x93, 0xc0,

    /* U+0026 "&" */
    0xfc, 0xcc, 0xcc, 0xcc, 0xd8, 0x70, 0x76, 0xde,
    0xce, 0xfe,

    /* U+0027 "'" */
    0xfc,

    /* U+0028 "(" */
    0xfb, 0x6d, 0xb6, 0xdb, 0x80,

    /* U+0029 ")" */
    0xed, 0xb6, 0xdb, 0x6f, 0x80,

    /* U+002A "*" */
    0x33, 0xf7, 0xbf, 0x30,

    /* U+002B "+" */
    0x18, 0x30, 0x67, 0xf1, 0x83, 0x6, 0x0,

    /* U+002C "," */
    0xfc,

    /* U+002D "-" */
    0xfe,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x3, 0x81, 0x81, 0xc0, 0xc0, 0xe0, 0x60, 0x60,
    0x70, 0x30, 0x38, 0x18, 0x0,

    /* U+0030 "0" */
    0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xff,

    /* U+0031 "1" */
    0xed, 0xb6, 0xdb, 0x6c,

    /* U+0032 "2" */
    0xff, 0x3, 0x3, 0x3, 0x3, 0xff, 0xc0, 0xc0,
    0xc0, 0xff,

    /* U+0033 "3" */
    0xff, 0x3, 0x3, 0x3, 0x3, 0xff, 0x3, 0x3,
    0x3, 0xff,

    /* U+0034 "4" */
    0x66, 0x33, 0x19, 0x9c, 0xcc, 0x66, 0x33, 0xfe,
    0xc, 0x6, 0x3, 0x0,

    /* U+0035 "5" */
    0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xff, 0x3, 0x3,
    0x3, 0xff,

    /* U+0036 "6" */
    0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xff, 0xc3, 0xc3,
    0xc3, 0xff,

    /* U+0037 "7" */
    0xff, 0x3, 0x7, 0x6, 0x6, 0xc, 0xc, 0xc,
    0x18, 0x18,

    /* U+0038 "8" */
    0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0x7e, 0xc3, 0xc3,
    0xc3, 0xff,

    /* U+0039 "9" */
    0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0x3, 0x3,
    0x3, 0xff,

    /* U+003A ":" */
    0xf0, 0x3c,

    /* U+003B ";" */
    0xf0, 0x3f,

    /* U+003C "<" */
    0x18, 0xe3, 0x1c, 0x61, 0x87, 0xc, 0x38, 0x60,

    /* U+003D "=" */
    0xfc, 0x0, 0x3f,

    /* U+003E ">" */
    0x61, 0xc3, 0xe, 0x18, 0x63, 0x8c, 0x71, 0x80,

    /* U+003F "?" */
    0xfe, 0xc, 0x18, 0x30, 0x67, 0xcc, 0x0, 0x30,
    0x60,

    /* U+0040 "@" */
    0xff, 0xe0, 0xff, 0xf8, 0xfd, 0xff, 0xbf, 0xdf,
    0xbf, 0xc0, 0x7f, 0xc0,

    /* U+0041 "A" */
    0x1e, 0x7, 0x81, 0xf0, 0xec, 0x33, 0xc, 0xe7,
    0xf9, 0x86, 0x61, 0x98, 0x30,

    /* U+0042 "B" */
    0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xfe, 0xc3, 0xc3,
    0xc3, 0xff,

    /* U+0043 "C" */
    0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
    0xc0, 0xff,

    /* U+0044 "D" */
    0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xff,

    /* U+0045 "E" */
    0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0,
    0xc0, 0xff,

    /* U+0046 "F" */
    0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe, 0xc0, 0xc0,
    0xc0, 0xc0,

    /* U+0047 "G" */
    0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xcf, 0xc3, 0xc3,
    0xc3, 0xff,

    /* U+0048 "H" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc3, 0xc3,
    0xc3, 0xc3,

    /* U+0049 "I" */
    0xfc, 0xc3, 0xc, 0x30, 0xc3, 0xc, 0x33, 0xf0,

    /* U+004A "J" */
    0x33, 0x33, 0x33, 0x33, 0x3f,

    /* U+004B "K" */
    0xc7, 0xce, 0xcc, 0xd8, 0xf0, 0xf0, 0xd8, 0xdc,
    0xce, 0xc7,

    /* U+004C "L" */
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
    0xc0, 0xff,

    /* U+004D "M" */
    0xe3, 0xf1, 0xfd, 0xfe, 0xff, 0x7e, 0xaf, 0x57,
    0xab, 0xdd, 0xee, 0xc0,

    /* U+004E "N" */
    0xc3, 0xe3, 0xf3, 0xf3, 0xfb, 0xdf, 0xcf, 0xcf,
    0xc7, 0xc3,

    /* U+004F "O" */
    0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xff,

    /* U+0050 "P" */
    0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc0, 0xc0,
    0xc0, 0xc0,

    /* U+0051 "Q" */
    0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xff, 0xe,

    /* U+0052 "R" */
    0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xcc, 0xce,
    0xc6, 0xc7,

    /* U+0053 "S" */
    0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xff, 0x3, 0x3,
    0x3, 0xff,

    /* U+0054 "T" */
    0xff, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18,

    /* U+0055 "U" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xff,

    /* U+0056 "V" */
    0x61, 0xd8, 0x66, 0x18, 0xce, 0x33, 0xc, 0xc3,
    0xf0, 0x78, 0x1e, 0x7, 0x80,

    /* U+0057 "W" */
    0xcc, 0xd3, 0xb6, 0xed, 0xbb, 0x7e, 0x9f, 0xe7,
    0xb9, 0xee, 0x33, 0x8c, 0xe0,

    /* U+0058 "X" */
    0x61, 0xb9, 0x8d, 0xc3, 0xc1, 0xc0, 0xe0, 0x78,
    0x6e, 0x73, 0x30, 0xc0,

    /* U+0059 "Y" */
    0xc3, 0xe7, 0x66, 0x3c, 0x3c, 0x18, 0x18, 0x18,
    0x18, 0x18,

    /* U+005A "Z" */
    0xff, 0x7, 0x6, 0xc, 0x1c, 0x38, 0x30, 0x60,
    0xe0, 0xff,

    /* U+005B "[" */
    0xfb, 0x6d, 0xb6, 0xdb, 0x80,

    /* U+005C "\\" */
    0x61, 0x86, 0x1c, 0x30, 0xc3, 0x86, 0x18, 0x70,
    0xc0,

    /* U+005D "]" */
    0xed, 0xb6, 0xdb, 0x6f, 0x80,

    /* U+005E "^" */
    0x39, 0xe7, 0x9b,

    /* U+005F "_" */
    0xff, 0xf8,

    /* U+0060 "`" */
    0x46, 0x60,

    /* U+0061 "a" */
    0xfe, 0xc, 0x1f, 0xfc, 0x78, 0xf1, 0xff,

    /* U+0062 "b" */
    0xc1, 0x83, 0xfe, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0xfc,

    /* U+0063 "c" */
    0xff, 0x83, 0x6, 0xc, 0x18, 0x30, 0x7f,

    /* U+0064 "d" */
    0x6, 0xf, 0xfe, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0xfc,

    /* U+0065 "e" */
    0xff, 0x8f, 0x1e, 0x3f, 0xf8, 0x30, 0x7f,

    /* U+0066 "f" */
    0x3e, 0x63, 0xf9, 0x83, 0x6, 0xc, 0x18, 0x30,
    0x60,

    /* U+0067 "g" */
    0xff, 0x8f, 0x1e, 0x3f, 0xe0, 0xc1, 0x83, 0xfe,

    /* U+0068 "h" */
    0xc1, 0x83, 0xfe, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8c,

    /* U+0069 "i" */
    0xf3, 0xff, 0xf0,

    /* U+006A "j" */
    0x33, 0x3, 0x33, 0x33, 0x33, 0xf0,

    /* U+006B "k" */
    0xc1, 0x83, 0x3e, 0xed, 0x9e, 0x3c, 0x6c, 0xdd,
    0x9c,

    /* U+006C "l" */
    0xff, 0xff, 0xf0,

    /* U+006D "m" */
    0xff, 0xec, 0x63, 0xc6, 0x3c, 0x63, 0xc6, 0x3c,
    0x63, 0xc6, 0x3c, 0x63,

    /* U+006E "n" */
    0xff, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3,

    /* U+006F "o" */
    0xff, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xff,

    /* U+0070 "p" */
    0xff, 0x8f, 0x1e, 0x3c, 0x7f, 0xf0, 0x60, 0xc0,

    /* U+0071 "q" */
    0xff, 0x8f, 0x1e, 0x3c, 0x7f, 0xc1, 0x83, 0x6,

    /* U+0072 "r" */
    0xfc, 0xcc, 0xcc, 0xcc,

    /* U+0073 "s" */
    0xff, 0x83, 0x6, 0xf, 0xe0, 0xc1, 0xff,

    /* U+0074 "t" */
    0x30, 0xcf, 0xcc, 0x30, 0xc3, 0xc, 0x30, 0xf0,

    /* U+0075 "u" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xff,

    /* U+0076 "v" */
    0x63, 0x63, 0x67, 0x76, 0x36, 0x36, 0x3e, 0x3c,

    /* U+0077 "w" */
    0xce, 0x66, 0xf6, 0x6f, 0x66, 0xf6, 0x6f, 0x63,
    0xbc, 0x39, 0xc3, 0x9c,

    /* U+0078 "x" */
    0x67, 0x76, 0x3c, 0x1c, 0x1c, 0x3c, 0x76, 0x67,

    /* U+0079 "y" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x7f, 0xc1, 0x83, 0xfe,

    /* U+007A "z" */
    0xfe, 0x1c, 0x70, 0xc3, 0xc, 0x38, 0x7f,

    /* U+007B "{" */
    0x76, 0x66, 0x6c, 0x66, 0x66, 0x70,

    /* U+007C "|" */
    0xff, 0xff, 0xfc,

    /* U+007D "}" */
    0xe6, 0x66, 0x63, 0x66, 0x66, 0xe0,

    /* U+007E "~" */
    0xe7, 0xbc
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 128, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 51, .box_w = 2, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 4, .adv_w = 89, .box_w = 4, .box_h = 3, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 6, .adv_w = 151, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 18, .adv_w = 124, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 26, .adv_w = 151, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 38, .adv_w = 138, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 48, .adv_w = 48, .box_w = 2, .box_h = 3, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 49, .adv_w = 66, .box_w = 3, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 54, .adv_w = 66, .box_w = 3, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 59, .adv_w = 107, .box_w = 6, .box_h = 5, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 63, .adv_w = 127, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 70, .adv_w = 53, .box_w = 2, .box_h = 3, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 71, .adv_w = 127, .box_w = 7, .box_h = 1, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 72, .adv_w = 51, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 73, .adv_w = 154, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 86, .adv_w = 175, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 96, .adv_w = 175, .box_w = 3, .box_h = 10, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 100, .adv_w = 175, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 110, .adv_w = 175, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 120, .adv_w = 175, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 132, .adv_w = 175, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 142, .adv_w = 175, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 152, .adv_w = 175, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 162, .adv_w = 175, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 172, .adv_w = 175, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 182, .adv_w = 51, .box_w = 2, .box_h = 7, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 184, .adv_w = 53, .box_w = 2, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 186, .adv_w = 97, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 194, .adv_w = 106, .box_w = 6, .box_h = 4, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 197, .adv_w = 97, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 205, .adv_w = 124, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 214, .adv_w = 151, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 226, .adv_w = 165, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 239, .adv_w = 138, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 249, .adv_w = 138, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 259, .adv_w = 138, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 269, .adv_w = 138, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 279, .adv_w = 138, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 289, .adv_w = 138, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 299, .adv_w = 138, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 309, .adv_w = 103, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 317, .adv_w = 77, .box_w = 4, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 322, .adv_w = 141, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 332, .adv_w = 138, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 342, .adv_w = 149, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 354, .adv_w = 138, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 364, .adv_w = 138, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 374, .adv_w = 138, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 384, .adv_w = 139, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 395, .adv_w = 139, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 405, .adv_w = 138, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 415, .adv_w = 138, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 425, .adv_w = 138, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 435, .adv_w = 162, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 448, .adv_w = 167, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 461, .adv_w = 157, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 473, .adv_w = 155, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 483, .adv_w = 138, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 493, .adv_w = 64, .box_w = 3, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 498, .adv_w = 103, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 507, .adv_w = 64, .box_w = 3, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 512, .adv_w = 103, .box_w = 6, .box_h = 4, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 515, .adv_w = 217, .box_w = 13, .box_h = 1, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 517, .adv_w = 63, .box_w = 4, .box_h = 3, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 519, .adv_w = 129, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 526, .adv_w = 129, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 535, .adv_w = 129, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 542, .adv_w = 129, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 551, .adv_w = 129, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 558, .adv_w = 119, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 567, .adv_w = 129, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 575, .adv_w = 129, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 584, .adv_w = 48, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 587, .adv_w = 74, .box_w = 4, .box_h = 11, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 593, .adv_w = 129, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 602, .adv_w = 48, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 605, .adv_w = 190, .box_w = 12, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 617, .adv_w = 129, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 624, .adv_w = 129, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 631, .adv_w = 129, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 639, .adv_w = 129, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 647, .adv_w = 84, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 651, .adv_w = 129, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 658, .adv_w = 109, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 666, .adv_w = 129, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 673, .adv_w = 139, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 681, .adv_w = 191, .box_w = 12, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 693, .adv_w = 137, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 701, .adv_w = 129, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 709, .adv_w = 129, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 716, .adv_w = 81, .box_w = 4, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 722, .adv_w = 48, .box_w = 2, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 725, .adv_w = 81, .box_w = 4, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 731, .adv_w = 122, .box_w = 7, .box_h = 2, .ofs_x = 1, .ofs_y = 3}
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
const lv_font_t ui_font_ShangShou16 = {
#else
lv_font_t ui_font_ShangShou16 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 12,          /*The maximum line height required by the font*/
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



#endif /*#if UI_FONT_SHANGSHOU16*/

