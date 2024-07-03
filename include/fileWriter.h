#pragma once

#include <stdbool.h>
#include <stdio.h>

#include "bmp.h"
#include "colorList.h"

bool generateFile(BMPDATA *bmpData);
COLORLIST* scanColors(BMPDATA *bmpData);