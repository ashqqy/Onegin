/// @file

#ifndef STRUCTS
#define STRUCTS

#include <stdio.h>

/// @brief Структура с указателем на строку и её длиной
struct PtrAndLenString
    {
    /// @brief указатель на строку
    char* ptr_str;

    /// @brief длина строки
    size_t len_str;
    };

/// @brief Размер структуры PtrAndLenString в байтах
const size_t SIZE_PtrAndLenString = sizeof (PtrAndLenString);

/// @brief Структура с информацией про текст
struct TextInfo
    {
    /// @brief указатель на начало текста
    char* text;

    /// @brief количество строк в тексте
    int n_strings;

    /// @brief Указатель на каждую строку и её размер
    PtrAndLenString* strings_data;
    };

#endif //STRUCTS