/// @file

#include <assert.h>

#include "FillPtrArray.h"

//----------------------------------------------------------------

/// @brief Функция, заполняющая массив указателями на начала строк
/// @param[in] strings_ptr массив указателей на строки текста
/// @param[in] text указатель на массив с текстом
/// @param[in] n_strings количество строк в тексте
void FillPtrArray (char** strings_ptr, char* text, int n_strings)
    {
    assert (text != NULL);
    assert (strings_ptr != NULL);

    strings_ptr[0] = &text[0]; 
    char* symb_ptr = &text[0];
    for (int i = 1; i < n_strings + 1; ++i) 
        {
        while (*symb_ptr != '\0')
            symb_ptr += 1;
        strings_ptr[i] = (symb_ptr + 1);
        symb_ptr += 1;
        }
    }

//----------------------------------------------------------------