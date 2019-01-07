#include <stddef.h>

#define TRUE 1
#define FALSE 0
#define MAX_CONFLICT 2

typedef struct {
    /* 
    Значение словаря
    value - само значение
    next - ссылка на следующее значение, если NULL - следующего значения нет
    */
    ptrdiff_t *value;
    struct ChainLink *next;
}ChainLink;

typedef struct {
    /* 
    Первый элемент словаря
    count - количество значений в ячейке (подсчет числа коллизий)
    ChainLink - указатель на первое значение
    emptyFlag - флаг пустого значения
    */
    char count;
    ChainLink *firstElement;
    char emptyFlag;
}FirstLink;

int addDictValue(FirstLink *dict[], char *key, ptrdiff_t *value);
ChainLink *makeListElement(ptrdiff_t *value);