#pragma once


/*
 * Перечисление допустимых базовых типов,
 * которые может использовать пользователь языка
 */
typedef enum {
    BOOL_T,
    DICT_T,
    DYN_ARR_T,
    INT_T,
    LINKED_LIST_T
} AnType;


/*
 * Тип Boolean
 */
typedef enum {
    False,
    True
} Bool;