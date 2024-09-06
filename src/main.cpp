#include <stdio.h>

#include "./../include/StringsCompare.h"
#include "./../include/StringsSwap.h"
#include "./../include/PrintText.h"

//----------------------------------------------------------------

int main ()
    {
    char text[5][10] = {"fooo",
                        "fuu",
                        "oooof",
                        "uf",
                        "auf"};

    for (int i = 0; i < sizeof (text) / sizeof (text[0]) - 1; i++)
        {
        for (int j = i + 1; j < sizeof (text) / sizeof (text[0]); j++)
            {
            if (StringsCompare (text[i], text[j]) == 1)
                {
                StringsSwap(text[i], text[j]);
                }
            }
        }
    PrintText (text);
    }


//----------------------------------------------------------------