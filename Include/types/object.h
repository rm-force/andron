#pragma once

#include "ctype.h"

#include "types/base_types.h"


/*
 * Структура объекта
 * value:       Указатель на произвольное значение;
 * type:        Тип значения, на которое указывает value;
 * size:        Размер объекта (В байтах);
 * links_count: Количество ссылок на объект;
 */
typedef struct {
    void *value;
    AnType type;
    size_t size;
    size_t links_count;
} Object;

void addObjectLink(Object *object);
void deleteObject(Object *object);