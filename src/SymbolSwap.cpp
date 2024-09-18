/// @file

#include "SymbolSwap.h"
#include "assert.h"

//----------------------------------------------------------------

/// @brief Функция, обменивающая символы в строке
/// @param[in] str Указатель на строку
/// @param[in] str_size  Количество символов строки
/// @param[in] symb1 Символ, который нужно поменять
/// @param[in] symb2 Символ, на которой нужно поменять
/// @return n_swapped - количество обмененных символов

size_t SymbolSwap (char* str, size_t str_size, const char symb1, const char symb2)
    {
    assert (str != NULL);
    
    size_t n_swapped = 0;
    char* symb_ptr = &str[0];
    for (int i = 0; i < str_size + 2; i++) // +2 так каллочили на 2 байта больше для \ r \ n
        {
        if (*symb_ptr == symb1)
            {
            n_swapped += 1; /// Если нашли symb1, то +1 к к-ву измененных символов 
            *symb_ptr = symb2; /// Заменяем symb1 на symb2
            }
        symb_ptr += 1;
        }
    return n_swapped;
    }

//----------------------------------------------------------------