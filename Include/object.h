#pragma once

#include "base_types.h"


/*
 * Структура объекта
 * value:   Указатель на произвольное значение;
 * type:    Тип значения, на которое указывает value;
 */
typedef struct {
    void *value;
    AnType type;
} Object;