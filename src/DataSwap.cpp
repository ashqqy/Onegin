/// @file

#include <stdio.h>
#include <assert.h>

#include "DataSwap.h"

//----------------------------------------------------------------

/// @brief Функция, меняющая местами два блока памяти
/// @param[in] data1 Указатель на первый блок памяти
/// @param[in] data2 Указатель на второй блок памяти
/// @param[in] len_data Размер в байтах блоков памяти
void DataSwap (void* data1, void* data2, size_t len_data)
    {
    assert (data1 != NULL);
    assert (data2 != NULL);
    assert (data1 != data2);

    /// Меняем сначала по 8 байт
    long long int swap_ll = 0;
    long long* data1_ll = (long long *) data1;
    long long* data2_ll = (long long *) data2;

    for (int i = 0; i < len_data / sizeof (long long); i++)
        {
        swap_ll = *(data1_ll + i);
        *(data1_ll + i) = *(data2_ll + i);
        *(data2_ll + i) = swap_ll;
        }

    // символ на котором остановились
    size_t last_unswapped = sizeof (long long) * (len_data / sizeof (long long)); 
    
    /// Меняем остаток побайтово
    char swap_c = 0;
    char* data1_c = (char*) data1;
    char* data2_c = (char*) data2;
    
    for (int i = last_unswapped; i < len_data - last_unswapped; i++)
        {
        swap_c = *(data1_c + i);
        *(data1_c + i) = *(data2_c + i);
        *(data2_c + i) = swap_c;
        }
    }

//----------------------------------------------------------------