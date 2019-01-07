#pragma once

#include "ctype.h"

#include "dynamic_array.h"

/*
 * Структура словаря
 * array:   Динамический массив;
 * length:  Количество заполненных ячеек;
 * _size:   Размер массива (в элементах);
 */
typedef struct {
    DynArr *array;
    size_t length;
    size_t _size;
} Dict;