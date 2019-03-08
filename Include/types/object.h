#pragma once

#include "ctype.h"

#include "types/base_types.h"


/*
 * Структура объекта
 * value:   Указатель на произвольное значение;
 * type:    Тип значения, на которое указывает value;
 * _size:   Размер объекта (В байтах);
 */
typedef struct {
    void *value;
    AnType type;
    size_t _size;
} Object;