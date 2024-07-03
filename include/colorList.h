#pragma once

#include <stdbool.h>

#include "rgb.h"

typedef struct
{
    RGB *arrayPtr;
    int length;
    int allocatedLength;
} COLORLIST;

bool listContains(COLORLIST *list, RGB *color);
COLORLIST* createList(int lengthToPreallocate);
void addToList(COLORLIST *list, RGB element);
bool addSpaceToList(COLORLIST *list, int newLength);
void freeList(COLORLIST *list);