#include "FillStringsData.h"

//----------------------------------------------------------------

/// @brief Функция, заполняющая массив структур с указателями на строки и их длинами
/// @param[out] strings_data массив структур с указателями на строки и их длинами
/// @param[in] strings_ptr массив указателей на строки
/// @param[in] n_strings количество строк 
void FillStringsData (PtrAndLenString* strings_data, char** strings_ptr, int n_strings)
    {
    for (int i = 0; i < n_strings; i++)
        {
         // считаем длину как разность соседних указателей
         *(strings_data + i) = {strings_ptr[i], (size_t) (strings_ptr[i + 1] - strings_ptr[i])}; 
        }
    }

//----------------------------------------------------------------