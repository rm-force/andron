/*
 * Тип данных - Связный список
 */

#include <stdlib.h>
#include <types/linked_list.h>

#include "types/base_types.h"
#include "types/linked_list.h"
#include "types/object.h"


Bool addToLinkedList(LinkedList *linkedList, Object *newValue) {
    /*
     * Функция выполняющая добавление нового значения в связный список
     *
     * linkedList:  Указатель на список, в который необходимо добавить значение;
     * newValue:    Указатель на новое значение;
     *
     * return: True, если все успешно, иначе - False;
     */

    LinkedNode *newNode = (LinkedNode*)malloc(sizeof(LinkedNode));

    if (newNode != NULL) {
        newNode->value = newValue;
        newNode->prev = linkedList->last;
        newNode->next = NULL;

        linkedList->last = newNode;
        linkedList->length += 1;

        return True;
    }

    return False;
};