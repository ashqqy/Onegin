#include <assert.h>

#include "./../include/TextStrLen.h"

//----------------------------------------------------------------

int TextStrLen (char* str_ptr) // вычисляет длину строки до \n или \0 включительно
    {
    assert (str_ptr != NULL);

    int len = 1; // 1 потому что \n или \0 тоже считаем
    char* symb = str_ptr;

    while (*symb != '\n' && *symb != '\0')
        {
        len += 1;
        symb += 1;
        }

    return len;
    }

//----------------------------------------------------------------