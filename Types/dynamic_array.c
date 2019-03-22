/*
 * Тип данных - Динамический массив
 */

#include <ctype.h>
#include <mem.h>
#include <stdlib.h>

#include "constants.h"
#include "tools/error.h"
#include "tools/math.h"
#include "types/base_types.h"
#include "types/dynamic_array.h"
#include "types/object.h"


Bool _validateDynArr(DynArr *dynArr) {
    /*
     * Функция для проверки динамического массива
     *
     * dynArr: Динамический массив, который нужно проверить;
     *
     * return: True, если массив прошел проверку, иначе - False
     */

    if (dynArr == NULL)
        return False;

    return True;
}


unsigned long _validateIndex(DynArr *dynArr, long index) {
    /*
     * Функция осуществляющая проверку индекса для данного массива
     *
     * dynArr:  Указатель на массив, для которого осуществляется проверка;
     * index:   Индекс для проверки;
     *
     * return: Обработанный индекс
     */

    Bool isMinus = (Bool)(sign_li(index) < 0);

    index = labs(index);

    if (index > dynArr->length || (!isMinus && index == dynArr->length)) {
        error("_validateIndex", IDX_ERR);
    }

    if (isMinus) index = dynArr->length - index;

    return (unsigned long)index;
}


Bool dynArrWillFull(DynArr *dynArr, unsigned long newItemsCount) {
    /*
     * Функция осуществляющая проверку будет ли массив переполнен,
     * если в него добавится указанное кол-во элементов
     *
     * dynArr:          Указатель на динамический массив, которых необходимо проверить;
     * newItemsCount:   Количество новых элементов;
     *
     * return: True, если массив будет переполнен, иначе - False;
     */

    if (!_validateDynArr(dynArr)) return False;

    if (dynArr->length + newItemsCount > dynArr->totalSize) {
        return True;
    }

    return False;
}


void dynArrIncrease(DynArr *dynArr) {
    /*
     * Функция увеличивающая размер динамического массива
     *
     * dynArr:      Указатель на массив, который необходимо увеличить;,
     */

    if (!_validateDynArr(dynArr)) return;

    size_t newTotalSize = dynArr->totalSize * DYN_ARR_EXPANSION_RATIO;
    size_t newSize = newTotalSize * PTR_OBJECT_SIZE;

    Object **tmp = (Object**)realloc(dynArr->array, newSize);

    if (tmp == NULL) {
        error("dynArrIncrease", MALLOC_ERR);
    }

    // Заполнение новой части массива нулями, чтобы он не хранил мусор
    size_t sizeMalloc = newSize - (PTR_OBJECT_SIZE * dynArr->totalSize);
    memset(tmp + (dynArr->totalSize - 1), 0, sizeMalloc);

    dynArr->array = tmp;
    dynArr->totalSize = (unsigned long)newTotalSize;
    dynArr->_size = newSize;
}


DynArr* newDynArr() {
    /*
     * Функция выполняющая создание нового динамического массива.
     *
     * return:  Указатель на струкуру динамического массива;
     */

    size_t newSize = MIN_DYN_ARR_LENGTH * PTR_OBJECT_SIZE;
    Object **newArray = (Object**)malloc(newSize);
    DynArr *newDynamicArray = (DynArr*)malloc(sizeof(DynArr));

    if (newArray == NULL || newDynamicArray == NULL) {
        // Если не удалось выделить память хотя бы на одну структуру
        // все очищается и вызывается ошибка
        free(newArray);
        free(newDynamicArray);

        error("newDynArr", MALLOC_ERR);
    } else {

        // Предварительное заполение массива нулями, чтобы он не хранил мусор и
        // в дальнейшем была возможность отличить пустое значение от мусора
        memset(newArray, 0, MIN_DYN_ARR_LENGTH * PTR_OBJECT_SIZE);

        newDynamicArray->array = newArray;
        newDynamicArray->length = 0;
        newDynamicArray->totalSize = MIN_DYN_ARR_LENGTH;
        newDynamicArray->_size = newSize;

        return newDynamicArray;
    }
}


void addToDynArr(DynArr *dynArr, Object *newValue) {
    /*
     * Функция выполняющая добавление нового значения в динамический массив
     *
     * dynArr:      Динамический массив, в который необходимо добавить значени;
     * newValue:    Указатель на новое значение;
     */

    if (!_validateDynArr(dynArr)) return;

    if (dynArrWillFull(dynArr, 1)) {
        dynArrIncrease(dynArr);
    }

    dynArr->array[dynArr->length] = newValue;
    dynArr->length += 1;
    addObjectLink(newValue);
}


void changeItemDynArr(DynArr *dynArr, long index, Object *newValue) {
    /*
     * Функция осуществляющая замену значения находящегося по индексу "index"
     * на новое значение newValue.
     * Функция не проверяет то, что индекс выходит за пределы массива
     * Данную проверку необходимо сделать до вызова функции
     *
     * dynArr:      Динамический массив, в который необходимо добавить значение;
     * index:       Индекс, по которому необходимо заменить значение;
     * newValue:    Указатель на новое значение;
     */

    if (!_validateDynArr(dynArr)) return;

    unsigned long idx = _validateIndex(dynArr, index);

    deleteObject(dynArr->array[idx]);
    dynArr->array[idx] = newValue;
    addObjectLink(newValue);
}


void dynArrInsert(DynArr *dynArr, long index, Object *newValue) {
    /*
     * Функция выполняющая вставку нового значения в произвольное место массива
     * Вставляемое значение сдвигает вправо остальные значения
     *
     * dynArr:      Динамический массив, в который необходимо вставить значение;
     * index:       Индекс, по которому необходимо выполнить вставку;
     * newValue:    Указатель на новое значение;
     */

    if (!_validateDynArr(dynArr)) return;

    unsigned long idx = _validateIndex(dynArr, index);

    if (dynArrWillFull(dynArr, 1)) {
        dynArrIncrease(dynArr);
    }

    // Сдвиг элементов массива вправо начиная с того, на место которого надо вставить
    for (unsigned long i = dynArr->length-1; i >= idx ; i--) {
        dynArr->array[i+1] = dynArr->array[i];
    }

    dynArr->array[idx] = newValue;
    addObjectLink(newValue);
}


Object* getItemDynArr(DynArr *dynArr, long index) {
    /*
     * Функция для получения эдемента массива по индексу
     *
     * dynArr:  Указатель на массив, из которого надо получить элемент;
     * index:   Индекс позиции, из которой надо получить элемент;
     *
     * return:  Указатель на объект, находящийся по указанному индексу
     *          или NULL, если массив пустой;
     */

    if (!_validateDynArr(dynArr)) return NULL;

    unsigned long idx = _validateIndex(dynArr, index);

    return dynArr->array[idx];
}


void delDynArr(DynArr *dynArr) {
    /*
     * Функция для удаления массива
     *
     * dynArr:  Указатель на массив, который надо удалить;
     */

    if (!_validateDynArr(dynArr)) return;

    while (--dynArr->length > -1) {
        deleteObject(dynArr->array[dynArr->length]);
    }

    free(dynArr->array);
    free(dynArr);
}