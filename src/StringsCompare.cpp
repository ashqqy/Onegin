#include "./../include/StringsCompare.h"

//----------------------------------------------------------------

int StringsCompare (char* str1, char* str2)
    {
    for (int i = 0; ; i++)
        {
        int c1 = str1[i];
        int c2 = str2[i];

        if (c1 != c2)
            return c2 - c1;

        if (c1 == 0)
            return 0;
        }
    }

//----------------------------------------------------------------