#pragma once

#include "tools/bit_operations.h"


/*
 * Функция хеширования. Является чистой реализацией алгоритма MurMurHash3
 *
 * key:         Указатель на переменную(может быть строкой, числом или дробью), которое необходимо хешировать
 * sizeBytes:   Размер переменной в байтах
 */
extern int hash(void *key, int sizeBytes);