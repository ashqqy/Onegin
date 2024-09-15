#include <stdio.h>

#include "PrintText.h"
#include "Structs.h"

//----------------------------------------------------------------

/// @brief Функция, печатающая текст из массива
/// @param text_info Структура с информацией о тексте
void PrintText (TextInfo text_info)
    {
    for (int i = 0; i < text_info.n_strings; i++)
        puts (text_info.strings_data[i].ptr_str);
    }

//----------------------------------------------------------------