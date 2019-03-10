#pragma once

#include <ctype.h>

#include "types/exceptions.h"
#include "object.h"


/*
 * Структура динамического массива
 * array:       Массив указателей на объекты;
 * length:      Количество заполненных ячеек;
 * _totalSize:  Размер всего массива (в ячейках);
 */
typedef struct {
    Object **array;
    size_t length;
    size_t totalSize;
} DynArr;

Bool dynArrWillFull(DynArr *dynArr, size_t newItemsCount);
Bool dynArrIncrease(DynArr *dynArr, size_t *size, Exception *exception);
DynArr* newDynArr(size_t *size, Exception *exception);
Bool addToDynArr(DynArr *array, Object *newValue, size_t *size, Exception *exception);