/// @file

#include "StringsCounter.h"
#include "assert.h"

//----------------------------------------------------------------

/// @brief Функция считает количество строк в массиве и заменяет '\ n' на '\ 0'
/// @param[in] text Указатель на массив с текстом
/// @param[out] n_strings Количество строк в массиве
void StringsCounter (char* text, int* n_strings)
    {
    assert (text != NULL);
    
    /// считаем количество строк (по разделителю \ n) в массиве
    char* symb_ptr = &text[0];
    while (*symb_ptr != '\0')
        {
        if (*symb_ptr == '\n')
            {
            *n_strings += 1; /// +1 строка если нашли \ n
            *symb_ptr = '\0'; /// заменяем \ n на \ 0
            }
        symb_ptr += 1;
        }
    }

//----------------------------------------------------------------