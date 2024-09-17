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

    /// Открываем файл с входными данными
    FILE* file_input = fopen(argv[1], "rb"); //"EugeneOnegin.txt"
    assert (file_input != NULL);

    /// Читаем файл в массив text
    char* text = NULL;
    TextCreator (file_input, &text);
    assert (text != NULL);
    /// Закрываем файл с входными данными
    fclose (file_input);
    /// Добавляем указатель на text в общую структуру
    text_info.text = text; 

    /** Считаем количество строк (с разделителем \ n) в массиве
    и заменяем \ n на \ 0 */
    int n_strings = 0;
    StringsCounter (text_info.text, &n_strings);
    /// Добавиляем к-во строк в общую структуру
    text_info.n_strings = n_strings; 

    /** Создаём массив указателей на начало каждой строки
    (+1 для указателя на конец последней строки) */
    char** strings_ptr = (char**) calloc (text_info.n_strings + 1, sizeof (char*)); 
    assert (strings_ptr != NULL);
    /// Заполняем массив указателей
    FillPtrArray (strings_ptr, text, n_strings);

    /// Создаём массив структур с данными каждой строки текста
    PtrAndLenString* strings_data = (PtrAndLenString*) calloc (n_strings, SIZE_PtrAndLenString);
    /// Заполняем массив структур
    FillStringsData (strings_data, strings_ptr, n_strings);
    /// Добавляем массив структур в общую структуру
    text_info.strings_data = strings_data;

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
    free (strings_ptr); strings_ptr = NULL;
    free (text_info.strings_data); text_info.strings_data = NULL;
    }

//----------------------------------------------------------------

// fstat
// qsort стандартный и свой

