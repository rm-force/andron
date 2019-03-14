#pragma once

#include "types/base_types.h"


const char *MSG_IDX_OUT = "Index outside";
const char *MSG_MALLOC = "Could not allocate memory";
const char *MSG_ZERO_DIV = "Error dividing by zero";


/*
 * Типы исключений
 */
typedef enum {
    BASE_EXCEPTION,     // Базовый тип, который присваевается исключению при его созданиии;
    INDEX_ERROR,        // Ошибки индексов в итерируемых структурах
                        // (например, выход за пределы массива);
    MEMORY_ALLOC_ERROR, // Ошибки выделения памяти;
    ZERO_DIVISION_ERROR // Ошибки деления на ноль;
} ExceptionType;


/*
 * Структура базового исключения
 *
 * isOccurred:  Признак того, что исключение было вызвано;
 * details:     Описание ошибки;
 * type:        Тип ошибки;
 */
typedef struct {
    Bool isOccurred;
    const char *details;
    ExceptionType type;
} Exception;


Exception* newException();
void setToException(Exception *exception, const char *details, ExceptionType type);
void MemoryAllocError(Exception *exception);
void ZeroDivisionError(Exception *exception);
void IndexError(Exception *exception);