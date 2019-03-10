#pragma once

#include <ctype.h>

#include "types/exceptions.h"
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
    size_t length;
    size_t totalSize;
    double fullness;
} DynArr;

Bool dynArrWillFull(DynArr *dynArr, size_t newItemsCount);
Bool dynArrIncrease(DynArr *dynArr, size_t *size, Exception *exception);
DynArr* newDynArr(double fullness, size_t *size, Exception *exception);
Bool addToDynArr(DynArr *dynArr, Object *newValue, size_t *size, Exception *exception);