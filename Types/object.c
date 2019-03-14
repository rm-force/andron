/*
 * Тип данных - Объект
 * Абстрактное представление любой переменной
 */

#include <stdlib.h>

#include "types/object.h"


void addObjectLink(Object *object) {
    /*
     * Функция выполняющая увеличения счетчика ссылок на
     * данный объект
     *
     * object: Указатель на объект, для которого добавилась ссылка;
     */

    if (object == NULL) return;

    object->links_count += 1;
}


void deleteObject(Object *object) {
    /*
     * Функция выполняющая удаление объекта
     * (Очистку памяти, занимаемую объектом)
     *
     * object: Указатель на объект, который необходимо удалить;
     */

    if (object == NULL) return;

    object->links_count -= 1;

    if (object->links_count <= 0) {
        free(object->value);
        free(object);
    }
}