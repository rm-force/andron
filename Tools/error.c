/*
 * Модуль для ошибок низкого уровня
 * (Те ошибки, на которые пользователь языка не может повлиять)
 */

#include <stdio.h>
#include <stdlib.h>


void error(char *source, const char *reason) {
    /*
     * Функция для прерывания выполнения программы с выводом
     * сообщения, в котором говорится где и какая произошла ошибка
     *
     * source:  Источник (Например, имя функции, в которой произошла ошибка);
     * reason:  Причина, по которой произошла ошибка
     */

    fprintf(stderr, "%s in %s", reason, source);
    exit(EXIT_FAILURE);
}