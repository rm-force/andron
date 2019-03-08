#pragma once

#include <ctype.h>

#include "object.h"


/*
 * Структура ячейки для связного списка
 * value:   Указатель на хранимый в ячейке объект;
 * prev:    Указатель на предыдущую ячейку;
 * next:    Указатель на следующую ячейку;
 */
typedef struct linkedNode_t {
    Object *value;
    struct linkedNode_t *prev;
    struct linkedNode_t *next;
} LinkedNode;


/*
 * Структура связного списка
 * first:   Указатель на первую ячейку;
 * last:    Указатель на последнюю ячейку;
 * length:  Количество элементов в списке;
 */
typedef struct {
    LinkedNode *first;
    LinkedNode *last;
    size_t length;
} LinkedList;


/*
 * Функция выполняющая добавлени нового значения в связный список
 *
 * linkedList:  Указатель на список, в который необходимо добавить значение;
 * newValue:    Указатель на новое значение;
 *
 * return: True, если все успешно, иначе - False;
 */
Bool addToLinkedList(LinkedList *linkedList, Object *newValue);