#include "./../include/StringsCompare.h"

//----------------------------------------------------------------

int StringsCompare (char* str1, char* str2)
    {
    for (int i = 0; ; i++)
        {
        int c1 = str1[i];
        int c2 = str2[i];

        if (c1 != c2)
            return c1 - c2;

        if (c1 == 0 && c2 == 0)
            return 0;
        }
    }

//----------------------------------------------------------------