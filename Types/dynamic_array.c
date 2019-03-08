/*
 * Тип данных - Динамический массив
 */

#include <stdlib.h>
#include <types/dynamic_array.h>

#include "constants.h"
#include "types/base_types.h"
#include "types/dynamic_array.h"
#include "types/object.h"


Bool addToDynArr(DynArr *array, Object *newValue) {
    /*
     * Функция выполняющая добавление нового значения в динамический массив
     *
     * array:       Динамический массив, в который необходимо добавить значени;
     * newValue:    Указатель на новое значение;
     */

    if (array->_totalSize == 0) return False;

    // Проверка заполненности массива c учетом нового элемента
    double fullness = (double)(array->length + 1) / array->_totalSize;

    if (fullness >= DYN_ARR_LIMIT) {
        // Попытка выделить память, если превышен лимит заполненности
        size_t newSize = array->_totalSize * DYN_ARR_EXPANSION_RATIO * sizeof(Object);
        Object **tmp = (Object**)realloc(array->array, newSize);

        if (tmp != NULL) {
            array->array = tmp;
            array->length += 1;
            array->_totalSize = newSize;
        }

        return False;
    }

    array->array[array->length - 1] = newValue;

    return True;
};