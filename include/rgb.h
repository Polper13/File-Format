#pragma once

#include <stdbool.h>

#include "bmp.h"

typedef struct
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
} RGB;

RGB getPixel(BMPDATA *bmpData, int x, int y);
bool compare(RGB *rgb1, RGB *rgb2);
void printRGB(RGB *rgb);