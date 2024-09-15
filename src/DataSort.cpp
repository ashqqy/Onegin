#include "DataSort.h"
#include "DataSwap.h"
#include "StringsCompare.h"
#include "Structs.h"

//----------------------------------------------------------------

/// @brief Функция сортировки
/// @param text_info Структура с информацией о тексте, который нужно отсортировать
void DataSort (TextInfo text_info)
    {
    for (int i = 0; i < text_info.n_strings - 1; i++)
    {
    for (int j = i + 1; j < text_info.n_strings; j++)
        {
        if (StringsCompare (text_info.strings_data[i].ptr_str, text_info.strings_data[j].ptr_str) > 0)
            DataSwap (&text_info.strings_data[i], &text_info.strings_data[j], SIZE_PtrAndLenString);
        }
    }
    }

//----------------------------------------------------------------