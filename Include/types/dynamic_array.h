#pragma once

#include <ctype.h>

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
    size_t _totalSize;
} DynArr;


/*
 * Функция выполняющая добавление нового значения в динамический массив
 *
 * array:       Динамический массив, в который необходимо добавить значени;
 * newValue:    Указатель на новое значение;
 */
Bool addToDynArr(DynArr *array, Object *newValue);