/*
 * Модуль для математических функций
 */

#include "tools/math.h"


signed char sign_li(long value) {
    /*
     * Функция для проверки знака long int значения;
     *
     * return:  -1 или 1 в зависимости от знака (если передать 0, то
     *          вернется 1)
     */

    if (value < 0) return -1;

    return 1;
};