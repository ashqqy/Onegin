#include <stdio.h>

#include "./../include/StringsCompare.h"
#include "./../include/StringsSwap.h"
#include "./../include/PrintText.h"
#include "./../include/Constants.h"

//----------------------------------------------------------------

int main ()
    {
    FILE* file = fopen ("./../EugeneOnegin.txt", "r");
    char text[N_STRINGS_IN_ONEGIN][MAX_LENGHT_STRING] = {};
    for (int i = 0; i < N_STRINGS_IN_ONEGIN; i++)
        {
        fgets (text[i], MAX_LENGHT_STRING, file);
        }

    size_t size_x = sizeof (text[0]) / sizeof (text[0][0]);
    size_t size_y = sizeof (text) / sizeof (text[0]);

    for (int i = 0; i < size_y - 1; i++)
        {
        for (int j = i + 1; j < size_y; j++)
            {
            if (StringsCompare (text[i], text[j]) == 1)
                {
                StringsSwap(text[i], text[j]);
                }
            }
        }
        PrintText (&text[0][0], size_x, size_y);
    }


//----------------------------------------------------------------

    // char text[5][10] = {"fooo",
    //                     "fuu",
    //                     "oooof",
    //                     "uf",
    //                     "auf"};