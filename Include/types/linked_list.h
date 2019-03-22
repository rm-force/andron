#pragma once

#include <ctype.h>

#include "object.h"


/*
 * Структура ячейки для связного списка
 * value:   Указатель на хранимый в ячейке объект;
 * prev:    Указатель на предыдущую ячейку;
 * next:    Указатель на следующую ячейку;
 */
typedef struct LinkedNode_t {
    Object *value;
    struct LinkedNode_t *prev;
    struct LinkedNode_t *next;
} LinkedNode;

/*
 * Структура связного списка
 * first:   Указатель на первую ячейку;
 * last:    Указатель на последнюю ячейку;
 * length:  Количество элементов в списке (в ячейках);
 * _size:   Размер списка (в байтах);
 */
typedef struct {
    LinkedNode *first;
    LinkedNode *last;
    unsigned long length;
    size_t _size;
} LinkedList;

LinkedList* newLinkedList();
void addToLinkedList(LinkedList *linkedList, Object *newValue);
Object* getItemLinkedList(LinkedList *linkedList, long index);
void delItemLinkedList(LinkedList *linkedList, long index);