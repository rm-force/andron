/*
 * Все, связанное с хешированием
 */

#include "tools/hashing.h"


int hash (void *key, int sizeBytes) {
    /*
     * Функция хеширования. Является чистой реализацией алгоритма MurMurHash3
     *
     * key:         Указатель на переменную(может быть строкой, числом или дробью), которое необходимо хешировать
     * sizeBytes:   Размер переменной в байтах
     */

    const unsigned char *data = (const unsigned char*)key;
    const int blocksCount = sizeBytes / 4;

    // Простое число для инициализации хеша
    unsigned hashValue = 16769023;

    // Вспомогательные константы
    const unsigned c1 = 0xcc9e2d51;
    const unsigned c2 = 0x1b873593;

    const unsigned *blocks = (const unsigned *)(data + blocksCount*4);

    // Начиная с конца 4 байтный блоков ведется перемешивание битов
    for(int i = -blocksCount; i; i++) {
        unsigned block = blocks[i];

        block *= c1;
        block = rotLeft32(block, 15);
        block *= c2;

        hashValue ^= block;
        hashValue = rotLeft32(hashValue, 13);
        hashValue = hashValue*5 + 0xe6546b64;
    }

    // Оставшийся хвост. На случай, если кол-во блоков не кратно 4
    const unsigned char *tail = data + blocksCount*4;

    unsigned hashTail = 0;

    // Оставшиеся байты свдигаются к первому и перемешиваются с основным хешем (Третий к первому и второй к первому)
    switch(sizeBytes % 4)
    {
        case 3:
            hashTail ^= tail[2] << 16u;
        case 2:
            hashTail ^= tail[1] << 8u;
        case 1:
            hashTail ^= tail[0];
            hashTail *= c1; hashTail = rotLeft32(hashTail, 15); hashTail *= c2; hashValue ^= hashTail;
        default:
            break;
    };

    // Финальное перемешивание хеша
    hashValue ^= sizeBytes;
    hashValue = murMurMix32(hashValue);

    return hashValue;
}