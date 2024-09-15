#include "StringsCompare.h"

//----------------------------------------------------------------

const int EQUAL_STRINGS = 0;

/// @brief Функция сравнения строк
/// @param[in] str1 Указатель на первую строку
/// @param[in] str2 Указатель на вторую строку
/// @return если строки равны - 0, если строки не равны - разность ASCII кодов первых различающихся символов
int StringsCompare (char* str1, char* str2)
    {
    for (int i = 0; ; i++)
        {
        int c1 = str1[i];
        int c2 = str2[i];

        if (c1 != c2)
            return c1 - c2;

        if (c1 == 0) // если предыдущий if не сработал, то c1 = c2
            return EQUAL_STRINGS;
        }
    }

//----------------------------------------------------------------