#pragma once

#include <ctype.h>

#include "dynamic_array.h"

/*
 * Структура словаря
 * array:  Динамический массив;
 * length: Количество элементов (Суммарное кол-во объектов с учетом коллизий);
 */
typedef struct {
    DynArr *array;
    size_t length;
} Dict;