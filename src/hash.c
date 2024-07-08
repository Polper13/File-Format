#include <stdio.h>
#include <stdlib.h>

#include "hash.h"

HASH* createHash(int length)
{
    HASH *ptr = (HASH*)malloc(sizeof(HASH));
    if (ptr == NULL)
    {
        printf("Could not allocate memory for creating hash");
        exit(EXIT_FAILURE);
    }

    ptr->data = (struct NODE**)malloc(length * sizeof(struct NODE*));
    if (ptr->data == NULL)
    {
        printf("Could not allocate memory for creating hash data");
        exit(EXIT_FAILURE);
    }

    ptr->length = length;

    for (int i = 0; i < length; i++)
    {
        ptr->data[i] = NULL;
    }
    return ptr;
}

int calculateHashAdress(RGB *color, int hashLength)
{
    int adress = color->r + color->g + color->b;
    adress %= hashLength;

    return adress;
}

void addToHash(HASH *hash, RGB *color)
{
    int address = calculateHashAdress(color, hash->length);
    addNewToNodes(&hash->data[address], color);
}

int countElementsInHash(HASH *hash)
{
    int count = 0;

    for (int i = 0; i < hash->length; i++)
    {
        count += countElementsInNodes(hash->data[i]);
    }

    return count;
}