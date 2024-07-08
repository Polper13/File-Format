#pragma once

#include "node.h"

typedef struct
{
    int length;
    struct NODE **data;
} HASH;

HASH* createHash(int length);
int calculateHashAdress(RGB *color, int hashLength);
void addToHash(HASH *hash, RGB *color);
int countElementsInHash(HASH *hash);