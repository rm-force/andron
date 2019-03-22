#pragma once

#include <ctype.h>

#include "types/linked_list.h"
#include "types/object.h"

// Коэффициент расширения динамического массива
// Характеризует во сколько раз увеличится массив при переполнении
const int DYN_ARR_EXPANSION_RATIO = 2;

// Размер динамического массива по умолчанию (В ячейках)
const int MIN_DYN_ARR_LENGTH = 8;

// Размер указателя на Object. Высчитывается заранее, т.к. много где
// используется
const size_t PTR_OBJECT_SIZE = sizeof(Object*);

// Размер узла связного списка
const size_t LINKED_NODE_SIZE = sizeof(LinkedNode);