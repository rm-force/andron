#pragma once

#include <ctype.h>

#include "object.h"


/*
 * Структура динамического массива
 * array:       Массив указателей на объекты;
 * length:      Количество заполненных ячеек;
 * _size:       Размер массива (в элементах);
 * limitFactor: Коэффициент заполненности массива, при которой он будет расширяться
 *              (Массив будет расширяться по условию length / _size >= limitFactor);
 */
typedef struct {
    Object **array;
    size_t length;
    size_t _size;
    double limitFactor;
} DynArr;