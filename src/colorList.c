#include <stdlib.h>
#include <stdio.h>

#include "colorList.h"

bool listContains(COLORLIST *list, RGB *color)
{
    for (int i = 0; i < list->length; i++)
    {
        if (compare(&list->arrayPtr[i], color))
            return true;
    }

    return false;
}

COLORLIST* createList(int lengthToPreallocate)
{
    COLORLIST *list = (COLORLIST*)malloc(sizeof(COLORLIST));
    if (list == NULL)
    {
        printf("%s", "Could not allocate COLORLIST when creating list");
        exit(EXIT_FAILURE);
    }

    list->length = 0;
    list->arrayPtr = (RGB*)malloc(lengthToPreallocate * sizeof(RGB));
    
    if (list->arrayPtr == NULL)
    {
        printf("%s", "Could not allocate COLORLIST.arrayPtr when creating list");
        exit(EXIT_FAILURE);
    }

    list->allocatedLength = lengthToPreallocate;
    return list;
}

void addToList(COLORLIST *list, RGB element)
{
    if (list->allocatedLength < list->length + 1)
    {
        bool result = addSpaceToList(list, list->allocatedLength * 2);
        if (result == false)
        {
            printf("%s", "Could not expand COLORLIST to add element");
            exit(EXIT_FAILURE);
        }
    }

    list->arrayPtr[list->length] = element;
    list->length++;
}

bool addSpaceToList(COLORLIST *list, int newLength)
{
    RGB *newPtr = (RGB*)malloc(newLength * sizeof(RGB));

    if (newPtr == NULL)
        return false;

    for (int i = 0; i < list->allocatedLength; i++)
    {
        newPtr[i] = list->arrayPtr[i];
    }

    free(list->arrayPtr);
    list->arrayPtr = newPtr;
    list->allocatedLength = newLength;

    return true;
}

void freeList(COLORLIST *list)
{
    free(list->arrayPtr);
    free(list);        
}