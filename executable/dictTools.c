#include <stdlib.h>
#include "dictTools.h"

int addDictValue(FirstLink *dict[], char *key, ptrdiff_t *value) {
    int i;
    ChainLink *lastValue;
    // i = hash(key);
    i = 1;
    if (dict[i]->emptyFlag) {
        // Если значение пустое
        dict[i]->firstElement = makeListElement(value);
        if (dict[i]->firstElement != NULL) {
            dict[i]->emptyFlag = FALSE;
            dict[i]->count++;
            return TRUE;
        }
    } 
    else if (dict[i]->count < MAX_CONFLICT) {
        lastValue = dict[i]->firstElement;
        while(lastValue->next != NULL) {
            lastValue = lastValue->next;
        };
        lastValue->next = makeListElement(value);
        dict[i]->count++;
        return TRUE;
    } else
        return FALSE;
}

ChainLink *makeListElement(ptrdiff_t *value) {
    ChainLink *chainPointer = (ChainLink*) malloc(sizeof(ChainLink));
    if (chainPointer != NULL) {
        // Если удачно выделена память
        chainPointer->next = NULL;
        chainPointer->value = value;
        return chainPointer;
    } else {
        // Если память не удалось выделить
        return NULL;
    }
}