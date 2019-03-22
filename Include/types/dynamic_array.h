#pragma once

#include <ctype.h>

#include "object.h"


/*
 * Структура динамического массива
 * array:       Массив указателей на объекты;
 * length:      Количество заполненных ячеек;
 * totalSize:   Размер всего массива (в ячейках);
 * _size:       Размер массива (в байтах);
 */
typedef struct {
    Object **array;
    unsigned long length;
    unsigned long totalSize;
    size_t _size;
} DynArr;

Bool dynArrWillFull(DynArr *dynArr, unsigned long newItemsCount);
void dynArrIncrease(DynArr *dynArr);
DynArr* newDynArr();
void addToDynArr(DynArr *dynArr, Object *newValue);
void changeItemDynArr(DynArr *dynArr, long index, Object *newValue);
void dynArrInsert(DynArr *dynArr, long index, Object *newValue);
Object* getItemDynArr(DynArr *dynArr, long index);
void delDynArr(DynArr *dynArr);