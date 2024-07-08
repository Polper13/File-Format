#pragma once

#include "rgb.h"

struct NODE
{
    RGB color;
    struct NODE *next;
};

struct NODE* createNode(RGB *color);
void freeNodes(struct NODE* begining);
void addNewToNodes(struct NODE **list, RGB *color);
int countElementsInNodes(struct NODE *list);