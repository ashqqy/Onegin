/// @file

#include <assert.h>

#include "PrintText.h"

//----------------------------------------------------------------

/// @brief Функция, печатающая текст из массива
/// @param text_info Структура с информацией о тексте
/// @param file_output Указатель на файл для вывода

void PrintText (const TextInfo* text_info, FILE* file_output)
    {
    assert (file_output != NULL);

    for (int i = 0; i < text_info->n_strings; i++)
        fputs (text_info->strings_data[i].ptr_str, file_output);
    }

//----------------------------------------------------------------