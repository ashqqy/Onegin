#include <stdio.h>
#include <stdlib.h>

#include "FreeMem.h"

//----------------------------------------------------------------

/// @brief Функция освобождения памяти и обнуления указателя
/// @param[in] ptr Указатель, который нужно освободить
void FreeMem (void* ptr)
    {
    free (ptr); ptr = NULL;
    }

//----------------------------------------------------------------