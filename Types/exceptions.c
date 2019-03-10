/*
 * Тип даннх - Исключение
 * Исключение - это тип для информирования пользовательских
 * ошибок. Он не должен использоваться в низкоуровневых функциях для
 * отладочной информации.
 */

#include <stdlib.h>

#include "types/exceptions.h"


Exception* newException() {
    /*
     * Функция создающая новое "исключение"
     *
     * return: Указатель на "исключение";
     */

    Exception* newExceptionObject = (Exception*)malloc(sizeof(Exception));

    if (newExceptionObject == NULL) return NULL;

    newExceptionObject->isOccurred = False;
    newExceptionObject->details = "";
    newExceptionObject->type = BASE_EXCEPTION;

    return newExceptionObject;
};


void setToException(Exception *exception, char *details, ExceptionType type) {
    /*
     * Функция для установки атрибутов "исключения"
     *
     * exception:   Указатель на исключение;
     * details:     Строка с описанием;
     * type:        Тип исключения;
     */

    if (exception == NULL) return;

    exception->isOccurred = True;
    exception->details = details;
    exception->type = type;
};


/*
 * Ниже описываются функции имеющий общий шаблон
 *
 * Функции выполняют установку исключений заданного типа
 *
 * exception:   Указатель на исключение
 */

void MemoryAllocError(Exception *exception) {
    setToException(
            exception,
            "Ошибка выделения памяти. Не удалось выделить память.",
            MEMORY_ALLOC_ERROR
    );
};


void ZeroDivisionError(Exception *exception) {
    setToException(
            exception,
            "Ошибка деления на ноль.",
            ZERO_DIVISION_ERROR
    );
}


void IndexError(Exception *exception) {
    setToException(
            exception,
            "Индекс за пределами массива.",
            INDEX_ERROR
    );
}