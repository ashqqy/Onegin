#include <stdio.h>

#include "./../include/PrintText.h"

//----------------------------------------------------------------

void PrintText (char text[][10])
    {
    for (int i = 0; i < 5; i++)
        {
        printf ("%s \n", text[i]);
        }
    }

//----------------------------------------------------------------