/*
 * Тип данных - Связный список
 */

#include <ctype.h>
#include <stdlib.h>

#include "constants.h"
#include "tools/math.h"
#include "types/base_types.h"
#include "tools/error.h"
#include "types/linked_list.h"
#include "types/object.h"


// Тип для указателя на функции поиска элемента связного списка
typedef LinkedNode* (*FindFunction)(LinkedList *linkedList, unsigned long index);


LinkedNode* _findItemFromStart(LinkedList *linkedList, unsigned long index) {
    /*
     * Функция выполняющая поиск узла по указанному индексу
     * (обход списка начинается с начала)
     *
     * linkedList:  Указатель на список, в котором надо осуществить поиск;
     * index:       Индекс, по которому расположен необходимый узел;
     *
     * return:      Указатель на узел связного списка,
     *              который находится по указанному индексу;
     */

    LinkedNode *currentNode = linkedList->first;

    while (index--) {
        currentNode = currentNode->next;
    }

    return currentNode;
}


LinkedNode* _findItemFromEnd(LinkedList *linkedList, unsigned long index) {
    /*
     * Функция выполняющая поиск узла по указанному индексу
     * (обход списка начинается с конца)
     *
     * linkedList:  Указатель на список, в котором надо осуществить поиск;
     * index:       Индекс, по которому расположен необходимый узел;
     *
     * return:      Указатель на узел связного списка,
     *              который находится по указанному индексу;
     */

    LinkedNode *currentNode = linkedList->last;

    index = linkedList->length - 1 - index;

    while (index--) {
        currentNode = currentNode->prev;
    }

    return currentNode;
}


unsigned long _validateIndexLinkedList(LinkedList *linkedList, long index) {
    /*
     * Функция осуществляющая проверку индекса для данного списка
     *
     * linkedList:  Указатель на список, для которого осуществляется проверка;
     * index:       Индекс для проверки;
     *
     * return:      Обработанный индекс;
     */

    Bool isMinus = (Bool)(sign_li(index) < 0);

    unsigned long idx = (unsigned long)labs(index);

    if (idx > linkedList->length || (!isMinus && idx == linkedList->length)) {
        error("_validateIndexLinkedList", IDX_ERR);
    }

    if (isMinus) idx = linkedList->length - idx;

    return idx;
}


Bool _validateLinkedList(LinkedList *linkedList) {
    /*
     * Функция для проверки связного списка
     *
     * linkedList: Указатель на связный список, который нужно проверить;
     *
     * return: True, если массив прошел проверку, иначе - False
     */

    if (linkedList == NULL)
        return False;

    return True;
}


LinkedNode* _getNodeLinkedList(LinkedList *linkedList, long index) {
    /*
     * Функция для получения узла связного списка по указанному индексу
     *
     * linkedList:  Указатель на список, из которого необходимо получить узел;
     * index:       Индекс, по которому находится необходимый узел;
     *
     * return:      Указатель на узел, находящийся по заданному индексу;
     */

    unsigned long idx = _validateIndexLinkedList(linkedList, index);

    FindFunction find = _findItemFromStart;

    if (linkedList->length - 1 - idx < idx) { // Если обходить с конца быстрее, чем с начала
        find = _findItemFromEnd;
    }

    return find(linkedList, idx);
}


LinkedList* newLinkedList() {
    /*
     * Функция выполняющая создание нового связного списка
     *
     * return:  Указатель на структуру связного списка;
     */

    LinkedList *newList = (LinkedList*)malloc(sizeof(LinkedList));

    if (newList == NULL) {
        error("newLinkedList", MALLOC_ERR);
    } else {
        newList->first = NULL;
        newList->last = NULL;
        newList->length = 0;
        newList->_size = 0;

        return newList;
    }
}


void addToLinkedList(LinkedList *linkedList, Object *newValue) {
    /*
     * Функция выполняющая добавление нового значения в связный список
     *
     * linkedList:  Указатель на список, в который необходимо добавить значение;
     * newValue:    Указатель на новое значение;
     */

    if (!_validateLinkedList(linkedList)) return;

    LinkedNode *newNode = (LinkedNode*)malloc(LINKED_NODE_SIZE);

    if (newNode == NULL) {
        error("addToLinkedList", MALLOC_ERR);
    }

    if (linkedList->last != NULL) {
        linkedList->last->next = newNode;
    } else { // Значит список еще пуст и first указывает на NULL
        linkedList->first = newNode;
    }

    newNode->value = newValue;
    newNode->prev = linkedList->last;
    newNode->next = NULL;

    linkedList->last = newNode;
    linkedList->length += 1;
    linkedList->_size += LINKED_NODE_SIZE;

    addObjectLink(newValue);
}


Object* getItemLinkedList(LinkedList *linkedList, long index) {
    /*
     * Функция для получения элемента связного списка по указанному индексу
     *
     * linkedList:  Указатель на список, из которого необходимо получить элемент;
     * index:       Индекс, по которому находится необходимый элемент;
     *
     * return:      Указатель на объект, находящийся по заданному индексу;
     */

    if (!_validateLinkedList(linkedList)) return NULL;

    LinkedNode *node = _getNodeLinkedList(linkedList, index);

    return node->value;
}


void delItemLinkedList(LinkedList *linkedList, long index) {
    /*
     * Функция для удаления элемента связного списка
     *
     * linkedList:  Указатель на список, из которого необходимо удалить элемент;
     * index:       Индекс, по которому находится элемент, который
     *              необходимо удалить;
     */

    if (!_validateLinkedList(linkedList)) return;

    LinkedNode *node = _getNodeLinkedList(linkedList, index);
    LinkedNode *prev = node->prev;
    LinkedNode *next = node->next;

    if (prev != NULL) {
        prev->next = next;
    } else { // Значит это первый элемент
        linkedList->first = next;
    }

    if (next != NULL) {
        next->prev = prev;
    } else { // Значит это последний элемент
        linkedList->last = prev;
    }

    deleteObject(node->value);
    free(node);

    linkedList->length -= 1;
    linkedList->_size -= LINKED_NODE_SIZE;
}