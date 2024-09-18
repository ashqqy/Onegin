/// @file

#include <assert.h>

#include "FillStringsData.h"

//----------------------------------------------------------------

/// @brief Функция, заполняющая массив структур указателями на строки и их длинами
/// @param[in] text_info Структура с информацией о тексте
/// @param[out] strings_data Массив структур с информацией о строках
void FillStringsData (TextInfo* text_info, PtrAndLenString* strings_data)
    {
    assert (strings_data != NULL);

    strings_data[0].ptr_str = &(*text_info).text[0]; // заполняем указатель на первую строку
    char* symb_ptr = &(*text_info).text[0];

    for (int i = 1; i < (*text_info).n_strings + 1; ++i) // +1 на указатель конца последней строки
        {
        while (*symb_ptr != '\0')
            symb_ptr += 1;
        strings_data[i].ptr_str = symb_ptr + 1;
        symb_ptr += 1;
        }

    for (int j = 0; j < (*text_info).n_strings; ++j)
        /// Считаем длину как разность соседних указателей
        strings_data[j].len_str = (size_t) (strings_data[j+1].ptr_str - strings_data[j].ptr_str);
    
    /// Добавляем массив структур в общую структуру
    (*text_info).strings_data = strings_data;
    }

//----------------------------------------------------------------