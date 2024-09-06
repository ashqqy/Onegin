#include <stdio.h>

#include "./../include/StringsSwap.h"

//----------------------------------------------------------------

void StringsSwap (char str1[], char str2[]) //меняет только равные по длине строки
    {
    for (int i = 0; ;i++)
        {
        if (str1[i] == 0 && str2[i] == 0)
            break;
        char swap = str1[i];
        str1[i] = str2[i];
        str2[i] = swap;
        }
    }

//----------------------------------------------------------------