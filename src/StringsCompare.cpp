/// @file

#include <assert.h>
#include <ctype.h>

#include "StringsCompare.h"
#include "Constants.h"

//----------------------------------------------------------------

/// @brief Функция сравнения строк
/// @param[in] str1 Структура с информацией о первой строке
/// @param[in] str2 Структура с информацией о второй строке
/// @return если строки равны - 0, если строки не равны - разность ASCII кодов первых различающихся символов

int StringsCompare (PtrAndLenString str1, PtrAndLenString str2)
    {
    assert (str1.ptr_str != NULL);
    assert (str2.ptr_str != NULL);

    char* str1_ptr = str1.ptr_str;
    char* str2_ptr = str2.ptr_str;
    int str1_len = str1.len_str;
    int str2_len = str2.len_str;
    int i = 0;
    int j = 0;

    while ( i < str1_len  && j < str2_len )
        {
        int c1 = tolower (str1_ptr[i]);
        int c2 = tolower (str2_ptr[j]);

        while ( isalpha (c1) == 0 || i == str1_len - 1) // проверяем что символ первой строки - буква 
            {
            ++i;
            c1 = tolower (str1_ptr[i]);
            }

        while ( isalpha (c2) == 0 || j == str2_len - 1) // проверяем что символ второй строки - буква 
            {
            ++j;
            c2 = tolower (str2_ptr[j]);
            }

        if (c1 != c2)
            return c1 - c2;

        if (c1 == 0) // если предыдущий if не сработал, то c1 = c2 = 0
            return EQUAL_STRINGS;

        ++i;
        ++j;
        }
    return COMPARE_ERROR;
    }

//----------------------------------------------------------------

/// @brief Функция сравнения строк с конца
/// @param[in] str1 Структура с информацией о первой строке
/// @param[in] str2 Структура с информацией о второй строке
/// @return разность ASCII кодов первых различающихся символов (разность = 0, если строки равны)

int StringsCompareReverse (PtrAndLenString str1, PtrAndLenString str2)
    {
    assert (str1.ptr_str != NULL);
    assert (str2.ptr_str != NULL);

    int str1_len = str1.len_str - 1; // последний символ строки
    int str2_len = str2.len_str - 1;
    char* str1_ptr = str1.ptr_str;
    char* str2_ptr = str2.ptr_str;
    int c1 = -1;
    int c2 = -1;

    while ( str1_len >= 0 && str2_len >= 0 )
        {
        c1 = tolower (str1_ptr[str1_len]);
        c2 = tolower (str2_ptr[str2_len]);

        while ( isalpha (c1) == 0 || str1_len == 0 ) // проверяем что символ первой строки - буква
            {
            str1_len -= 1;
            c1 = tolower (str1_ptr[str1_len]);
            }

        while ( isalpha (c2) == 0 || str2_len == 0 ) // проверяем что символ второй строки - буква
            {
            str2_len -= 1;
            c2 = tolower (str2_ptr[str2_len]);
            }

        if (c1 != c2)
            return c1 - c2;

        str1_len -= 1;
        str2_len -= 1;
        }
    return c1 - c2;
    }

//----------------------------------------------------------------
