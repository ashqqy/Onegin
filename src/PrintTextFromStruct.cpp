#include <stdio.h>

#include "./../include/PrintTextFromStruct.h"
#include "./../include/Structs.h"

//----------------------------------------------------------------

void PrintTextFromStruct (PtrAndLenString* strings_data, size_t n_strings, size_t size_struct)
    {
    for (int i = 0; i < n_strings; i++)
        {
        for (int j = 0; j < strings_data[i].len_str; j++)
            {
            printf ("%c", *(strings_data[i].ptr_str + j));
            }
        }
    }

//----------------------------------------------------------------