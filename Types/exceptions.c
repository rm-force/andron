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


void setToException(Exception *exception, const char *details, ExceptionType type) {
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
            MSG_MALLOC,
            MEMORY_ALLOC_ERROR
    );
};


void ZeroDivisionError(Exception *exception) {
    setToException(
            exception,
            MSG_ZERO_DIV,
            ZERO_DIVISION_ERROR
    );
}


void IndexError(Exception *exception) {
    setToException(
            exception,
            MSG_IDX_OUT,
            INDEX_ERROR
    );
}