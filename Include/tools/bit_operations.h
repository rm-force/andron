#pragma once


/*
 * Функция для циклического сдвига 4 байтных блоков
 *
 * block: Блок, который необходимо сдвинуть
 * shift: Значение сдвига
 */
extern unsigned rotLeft32 (unsigned block, unsigned char shift);


/*
 * Функция для перемешивания бит 4 байтного блока по алгоритму MurMurHash3
 *
 * block: Блок, который необходимо перемешать
 */
extern unsigned murMurMix32 (unsigned block);