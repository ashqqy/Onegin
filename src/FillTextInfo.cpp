/// @file

#include <assert.h>

#include "FillTextInfo.h"
#include "Onegin.h"
#include "Structs.h"

//----------------------------------------------------------------

/** @brief Функция создает массив с текстом из файла, считает количество строк 
и создает массив структур с указателем на каждую строку и длиной каждой строки
     @param[out] text_info Структура, в которой хранится вся информация о тексте (функция заполняет её)
     @param[in] name_of_file Имя входного файла
*/
void FillTextInfo (TextInfo* text_info, const char* name_of_file)
    {
    /// Открываем файл с входными данными
    FILE* file_input = fopen(name_of_file, "rb"); //"EugeneOnegin.txt"
    assert (file_input != NULL);

    /// Читаем файл в массив text
    char* text = NULL;
    size_t size_file_input = TextCreator (file_input, &text);
    assert (text != NULL);
    /// Закрываем файл с входными данными
    fclose (file_input);
    /// Добавляем указатель на text в общую структуру
    (*text_info).text = text; 

    /** Считаем количество строк (с разделителем \ n) в массиве
    и заменяем \ n на \ 0 */
    int n_strings = SymbolSwap (text, size_file_input, '\n', '\0');
    /// Добавляем количество строк в общую структуру
    (*text_info).n_strings = n_strings; 

    /// Создаём массив структур с данными каждой строки текста
    PtrAndLenString* strings_data = (PtrAndLenString*) calloc (n_strings + 1, SIZE_PtrAndLenString);
    assert (strings_data != 0);
    /// Заполняем массив структур
    FillStringsData (text_info, strings_data);
    }

//----------------------------------------------------------------