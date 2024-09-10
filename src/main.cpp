#include <stdio.h>
#include <cstdlib>
#include <assert.h>
#include <cstring>

#include "./../include/StringsCompare.h"
#include "./../include/StringsSwap.h"
#include "./../include/PrintText.h"
#include "./../include/Constants.h"
#include "./../include/TextStrLen.h"
#include "./../include/Structs.h"
#include "./../include/PrintTextFromStruct.h"

//----------------------------------------------------------------

void StructSwap (PtrAndLenString* struct1, PtrAndLenString* struct2);

int main ()
    {
// ФАЙЛ И МАССИВ С ТЕКСОМ ФАЙЛА

    // создаем указатель на файл
    FILE* file_input = fopen("./../SmallOnegin.txt", "r");
    assert (file_input != NULL);

    // находим размер файла
    fseek (file_input, 0L, SEEK_END);
    long size_file_input = ftell(file_input);
    fseek(file_input, 0L, SEEK_SET);

    // выделяем память для текста
    char* text = (char*) calloc (size_file_input, sizeof(char));
    assert (text != NULL);

    // переносим файл в массив
    int counter = fscanf (file_input, "%[^EOF]", text);

    // заканчиваем работу с файлом ввода
    fclose (file_input);

// МАССИВ УКАЗАТЕЛЕЙ НА СТРОКИ

    // считаем количество строк (с разделителем \n) в массиве
    char* symb_ptr = &text[0];
    int n_strings = 1; // сразу посчитали последнюю строку потому что в ней нет \n
    while (*symb_ptr != '\0')
        {
        if (*symb_ptr == '\n') // +1 строка если нашли \n
            n_strings += 1; 
        symb_ptr += 1;
        }

    // создаём массив указателей на начало каждой строки
    char** strings_ptr = (char**) calloc (n_strings, sizeof (char*));
    assert (strings_ptr != NULL);

    // заполняем массив указателей
    strings_ptr[0] = &text[0]; 
    symb_ptr = &text[0];
    for (int i = 1; i < n_strings; i++)
        {
        while (*symb_ptr != '\n')
            symb_ptr += 1;
        strings_ptr[i] = (symb_ptr + 1);
        symb_ptr += 1;
        }

// МАССИВ СТРУКТУР СО СТРОКАМИ ТЕКСТА

    PtrAndLenString* strings_data = (PtrAndLenString*) calloc (n_strings, SIZE_PtrAndLenString);

    for (int i = 0; i < n_strings; i++)
        {
        *(strings_data + i) = {strings_ptr[i], TextStrLen(strings_ptr[i])};
        }

    StructSwap (&strings_data[0], &strings_data[1]);
    PrintTextFromStruct (strings_data, n_strings, SIZE_PtrAndLenString);

// СОРТИРОВКА 1
// СОРТИРОВКА 2

// ОСВОБОЖДЕНИЕ ПАМЯТИ

    free (text); text = NULL;
    free (strings_ptr); strings_ptr = NULL;
    free (strings_data); strings_data = NULL; 
    }

//----------------------------------------------------------------

void StructSwap (PtrAndLenString* struct1, PtrAndLenString* struct2)
    {
    PtrAndLenString swap;
    swap = *struct1;
    *struct1 = *struct2;
    *struct2 = swap;
    }