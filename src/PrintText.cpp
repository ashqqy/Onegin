#include <stdio.h>

#include "./../include/PrintText.h"

//----------------------------------------------------------------

void PrintText (char* text, size_t size_x, size_t size_y)
    {
    for (int i = 0; i < size_y; i++)
        {
        printf ("%s \n", (text + i * size_x));
        }
    }

//----------------------------------------------------------------