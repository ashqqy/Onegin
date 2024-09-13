#include <stdio.h>

#include "./../include/PrintText.h"
#include "./../include/Structs.h"

//----------------------------------------------------------------

void PrintText (PtrAndLenString* strings_data, size_t n_strings, size_t size_struct)
    {
    for (int i = 0; i < n_strings; i++)
        puts (strings_data[i].ptr_str);
    }

//----------------------------------------------------------------