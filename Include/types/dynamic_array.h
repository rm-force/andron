#pragma once

#include <ctype.h>

#include "object.h"


/*
 * Структура динамического массива
 * array:       Массив указателей на объекты;
 * length:      Количество заполненных ячеек;
 * totalSize:   Размер всего массива (в ячейках);
 * fullness:    Коэффициент допустимой заполненности массива, превысив которую
 *              массив необходимо расширять;
 */
typedef struct {
    Object **array;
    unsigned long length;
    unsigned long totalSize;
    double fullness;
} DynArr;

Bool dynArrWillFull(DynArr *dynArr, unsigned long newItemsCount);
void dynArrIncrease(DynArr *dynArr, size_t *size);
DynArr* newDynArr(double fullness, size_t *size);
void addToDynArr(DynArr *dynArr, Object *newValue, size_t *size);
void changeItemDynArr(DynArr *dynArr, long index, Object *newValue);
void dynArrInsert(DynArr *dynArr, long index, Object *newValue, size_t *size);
Object* getItemDynArr(DynArr *dynArr, long index);
void delDynArr(DynArr *dynArr);