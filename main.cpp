#include <stdio.h>

//----------------------------------------------------------------

int StringsCompare (char str1[], char str2[]);
void StringsSwap (char str1[], char str2[]);

//----------------------------------------------------------------

int main ()
    {
    char str1[] = "bcd";
    char str2[] = "abc";
    int ans = StringsCompare (str1, str2);
    if (ans == 1)
        StringsSwap (str1, str2);
    }

//----------------------------------------------------------------

int StringsCompare (char* str1, char* str2)
    {
    for (int i = 0; ; i++)
        {
        int c1 = str1[i];
        int c2 = str2[i];

        if (c1 != c2)
            {
            if (c1 > c2)
                return 1;
            if (c1 < c2)
                return -1;
            }

        if (c1 == 0 && c2 == 0)
            return 0;
        }
    }

//----------------------------------------------------------------

void StringsSwap (char str1[], char str2[]) //меняет только равные по длине строки
    {
    for (int i = 0; ;i++)
        {
        if (str1[i] == 0 || str2[i] == 0)
            break;
        char swap = str1[i];
        str1[i] = str2[i];
        str2[i] = swap;
        }
    printf ("str1 = %s \n", str1);
    printf ("str2 = %s \n", str2);
    }

//----------------------------------------------------------------