#include <stdio.h>
#include <cstdlib>
#include <assert.h>
#include <cstring>

#include "./../include/StringsCompare.h"
#include "./../include/DataSwap.h"
#include "./../include/Constants.h"
#include "./../include/Structs.h"
#include "./../include/PrintText.h"
#include "./../include/MassiveCreator.h"
#include "./../include/StringsCounter.h"

//----------------------------------------------------------------

int main ()
    {
    // создаем указатель на файл
    FILE* file_input = fopen("./../SmallOnegin.txt", "rb");
    assert (file_input != NULL);

    // читаем файл в массив текст
    char* text = MassiveCreator (file_input);

    /* считаем количество строк (с разделителем \n) в массиве
    и заменяем \n на \0 */
    int n_strings = 0;
    StringsCounter (text, &n_strings);

    /* создаём массив указателей на начало каждой строки
    +1 для указателя на конец последней строки */
    char** strings_ptr = (char**) calloc (n_strings + 1, sizeof (char*)); 
    assert (strings_ptr != NULL);

    // заполняем массив указателей
    strings_ptr[0] = &text[0]; 
    char* symb_ptr = &text[0];
    for (int i = 1; i < n_strings + 1; i++)
        {
        while (*symb_ptr != '\0')
            symb_ptr += 1;
        strings_ptr[i] = (symb_ptr + 1);
        symb_ptr += 1;
        }

// МАССИВ СТРУКТУР СО СТРОКАМИ ТЕКСТА

    PtrAndLenString* strings_data = (PtrAndLenString*) calloc (n_strings, SIZE_PtrAndLenString);

    for (int i = 0; i < n_strings; i++)
        {
         // считаем длину как разность соседних указателей
         *(strings_data + i) = {strings_ptr[i], (size_t) (strings_ptr[i + 1] - strings_ptr[i])}; 
        }

// СОРТИРОВКА 1

    for (int i = 0; i < n_strings - 1; i++)
        {
        for (int j = i + 1; j < n_strings; j++)
            {
            if (StringsCompare (strings_data[i].ptr_str, strings_data[j].ptr_str) > 0)
                DataSwap (&strings_data[i], &strings_data[j], sizeof (PtrAndLenString*));
            }
        }
    PrintText (strings_data, n_strings, SIZE_PtrAndLenString);

// СОРТИРОВКА 2

// ОСВОБОЖДЕНИЕ ПАМЯТИ

    free (text); text = NULL;
    free (strings_ptr); strings_ptr = NULL;
    free (strings_data); strings_data = NULL; 
    }

//----------------------------------------------------------------


//----------------------------------------------------------------

// fstat
// сделать пропуск символов
// make файлы
// swap функция для любых типов данных (передаем сколько байт менять) - сделано
// поменять \n на \0 и printf на puts (потому что быстрее) - сделано