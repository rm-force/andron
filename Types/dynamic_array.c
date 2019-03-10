/*
 * Тип данных - Динамический массив
 */

#include <stdlib.h>
#include <ctype.h>

#include "constants.h"
#include "types/base_types.h"
#include "types/dynamic_array.h"
#include "types/exceptions.h"
#include "types/object.h"


Bool dynArrWillFull(DynArr *dynArr, size_t newItemsCount) {
    /*
     * Функция осуществляющая проверку будет ли массив переполнен,
     * если в него добавится указанное кол-во элементов
     *
     * dynArr:          Указатель на динамический массив, которых необходимо проверить;
     * newItemsCount:   Количество новых элементов;
     *
     * return: True, если массив будет переполнен, иначе - False;
     */

    double currentFullness = (double)(dynArr->length + newItemsCount) / dynArr->totalSize;

    if (currentFullness >= dynArr->fullness) {
        return True;
    }

    return False;
};


Bool dynArrIncrease(DynArr *dynArr, size_t *size, Exception *exception) {
    /*
     * Функция увеличивающая размер динамического массива
     *
     * dynArr:      Указатель на массив, который необходимо увеличить;
     * size:        Указатель на переменную, в которую будет записан размер массива (в байтах),
     *              если массив не удастся создать переменная не изменится;
     * exception:   Указатель на структуру исключения, в которую будет записана информация,
     *              если оно возникнет;
     *
     * return: True, если увеличение прошло успешно, иначе - False;
     */

    size_t newTotalSize = dynArr->totalSize * DYN_ARR_EXPANSION_RATIO;
    size_t newSize = newTotalSize * sizeof(Object*);

    Object **tmp = (Object**)realloc(dynArr->array, newSize);

    if (tmp == NULL) {
        MemoryAllocError(exception);
        return False;
    }

    dynArr->array = tmp;
    dynArr->totalSize = newTotalSize;
    *size = newSize;

    return True;
};


DynArr* newDynArr(double fullness, size_t *size, Exception *exception) {
    /*
     * Функция выполняющая создание нового динамического массива.
     *
     * fullness:    Коэффициент допустимой заполненности массива, превысив которую
     *              массив необходимо расширять (Значение по умолчанию будет присвоено,
     *              если передать 0 (ноль));
     * size:        Указатель на переменную, в которую будет записан размер массива (в байтах),
     *              если массив не удастся создать переменная не изменится;
     * exception:   Указатель на структуру исключения, в которую будет записана информация,
     *              если оно возникнет;
     *
     * return:      Указатель на струкуру динамического массива,
     *              если все успешно, иначе - NULL;
     */

    size_t newSize = MIN_DYN_ARR_LENGTH * sizeof(Object*);
    Object **newArray = (Object**)malloc(newSize);
    DynArr *newDynamicArray = (DynArr*)malloc(sizeof(DynArr));

    if (newArray == NULL || newDynamicArray == NULL) {
        // Если не удалось выделить память хотя бы на одну структуру
        // все очищается и возвращается NULL
        free(newArray);
        free(newDynamicArray);
        MemoryAllocError(exception);

        return NULL;
    }

    if (fullness == 0) fullness = DYN_ARR_LIMIT;

    newDynamicArray->array = newArray;
    newDynamicArray->length = 0;
    newDynamicArray->totalSize = MIN_DYN_ARR_LENGTH;
    newDynamicArray->fullness = fullness;
    *size = newSize;

    return newDynamicArray;
};


Bool addToDynArr(DynArr *dynArr, Object *newValue, size_t *size, Exception *exception) {
    /*
     * Функция выполняющая добавление нового значения в динамический массив
     *
     * array:       Динамический массив, в который необходимо добавить значени;
     * newValue:    Указатель на новое значение;
     * size:        Указатель на переменную, в которую будет записан новый размер массива (в байтах)
     *              при его рассширении, если расширения не было переменная не изменится;
     * exception:   Указатель на структуру исключения, в которую будет записана информация,
     *              если оно возникнет;
     *
     * return:      return: True, если все успешно, иначе - False;
     */

    if (dynArrWillFull(dynArr, 1)) {
        if (!dynArrIncrease(dynArr, size, exception)) {
            return False;
        }
    }

    dynArr->array[dynArr->length - 1] = newValue;
    dynArr->length += 1;

    return True;
};