/*
 * Операции с битами
 */

#include "tools/bit_operations.h"


/*
 * Функция для циклического сдвига 4 байтных блоков
 *
 * block: Блок, который необходимо сдвинуть
 * shift: Значение сдвига
 */
unsigned rotLeft32 (unsigned block, unsigned char shift) {
    return (block << shift) | (block >> (32u - shift));
}


/*
 * Функция для перемешивания бит 4 байтного блока по алгоритму MurMurHash3
 *
 * block: Блок, который необходимо перемешать
 */
unsigned murMurMix32 (unsigned block) {
    block ^= block >> 16u;
    block *= 0x85ebca6b;
    block ^= block >> 13u;
    block *= 0xc2b2ae35;
    block ^= block >> 16u;

    return block;
}