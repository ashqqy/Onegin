/// @mainpage ЕВГЕНИЙ ОНЕГИН 

#include <stdio.h>
#include <cstdlib>
#include <assert.h>
#include <cstring>

#include "Onegin.h"

//----------------------------------------------------------------

int main (int argc, char** argv) // передавать файл как аргумент !!!!!!!!!!!!!!!!!!!!
    {
    // создаем структуру с информацией о тексте
    TextInfo text_info = {};

    FILE* file_input = fopen(argv[1], "rb"); //"EugeneOnegin.txt"
    assert (file_input != NULL);

    // читаем файл в массив text
    char* text = NULL;
    TextCreator (file_input, &text);
    assert (text != NULL);
    fclose (file_input);
    // добавляем указатель в общую структуру
    text_info.text = text; 

    /* считаем количество строк (с разделителем \n) в массиве
    и заменяем \n на \0 */
    int n_strings = 0;
    StringsCounter (text_info.text, &n_strings);
    // добавиляем к-во строк в общую структуру
    text_info.n_strings = n_strings; 

    /* создаём массив указателей на начало каждой строки
    +1 для указателя на конец последней строки */
    char** strings_ptr = (char**) calloc (text_info.n_strings + 1, sizeof (char*)); 
    assert (strings_ptr != NULL);
    // заполняем массив указателей
    FillPtrArray (strings_ptr, text, n_strings);

    // создаём массив структур с данными каждой строки текста
    PtrAndLenString* strings_data = (PtrAndLenString*) calloc (n_strings, SIZE_PtrAndLenString);
    // заполняем массив структур
    FillStringsData (strings_data, strings_ptr, n_strings);
    text_info.strings_data = strings_data;

    // открываем файл для вывода
    FILE* file_output = fopen ("Onegin_result.txt", "w");

    // сортируем по началу строк
    DataSort (text_info, StringsCompare);
    fputs (FIRST_SORT, file_output);
    PrintText (text_info, file_output);

    // сортируем по концу строк
    DataSort (text_info, StringsCompareReverse);
    fputs (SECOND_SORT, file_output);
    PrintText (text_info, file_output);

    // выводим оригинальный текст
    fputs (ORIGINAL_TEXT, file_output);
    PrintOriginalText (text_info, file_output);

    // Закрываем файл
    fclose (file_output);

    // освобождаем память
    FreeMem (text_info.text);
    FreeMem (strings_ptr);
    FreeMem (text_info.strings_data);
    }

//----------------------------------------------------------------

// fstat
// сделать документацию
// qsort
