/// @file

#include <assert.h>

#include "DataSort.h"
#include "DataSwap.h"

//----------------------------------------------------------------

/// @brief Функция сортировки
/// @param[in] text_info Структура с информацией о тексте, который нужно отсортировать
/// @param[in] CompareFunc Указатель на функцию компарации

void DataSort (TextInfo text_info, compare_func_t CompareFunc)
    {
    assert (CompareFunc != NULL);

    for (int i = 0; i < text_info.n_strings - 1; i++)
        {
        for (int j = i + 1; j < text_info.n_strings; j++)
            {
            if (CompareFunc (text_info.strings_data[i], text_info.strings_data[j]) > 0)
                DataSwap (&text_info.strings_data[i], &text_info.strings_data[j], SIZE_PtrAndLenString);
            }
        }
    }

//----------------------------------------------------------------