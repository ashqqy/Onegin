/// @file

#include <stdio.h>
#include <cstdlib>
#include <assert.h>
#include <cstring>

#include "Onegin.h"

//----------------------------------------------------------------

int main (int argc, const char** argv)
    {
    /// Создаем структуру с информацией о тексте
    TextInfo text_info = {};

    /// Заполняем структуру с информацией о тексте
    FillTextInfo (&text_info, argv[1]);

    /// Открываем файл для вывода
    FILE* file_output = fopen ("Onegin_result.txt", "w");

    /// Сортируем по началу строк и выводим
    DataSort (text_info, StringsCompare);
    fputs (FIRST_SORT, file_output);
    PrintText (text_info, file_output);

    /// Сортируем по концу строк и выводим
    DataSort (text_info, StringsCompareReverse);
    fputs (SECOND_SORT, file_output);
    PrintText (text_info, file_output);

    /// Выводим оригинальный текст
    fputs (ORIGINAL_TEXT, file_output);
    PrintOriginalText (text_info, file_output);

    /// Закрываем файл для вывода
    fclose (file_output);

    /// Освобождаем память
    free (text_info.text); text_info.text = NULL;
    free (text_info.strings_data); text_info.strings_data = NULL;
    }

//----------------------------------------------------------------

// fstat
// qsort стандартный и свой

