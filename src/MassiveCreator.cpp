#include <cstdlib>
#include <assert.h>

#include "./../include/MassiveCreator.h"

//----------------------------------------------------------------

/// @brief Функция создаёт массив с текстом на основе данных из файла
/// @param[in] file_input указатель на файл
/// @return указатель на начало массива с текстом
char* MassiveCreator (FILE* file_input)
    {
    // находим размер файла
    fseek (file_input, 0L, SEEK_END); //лучше fstat
    long size_file_input = ftell(file_input);
    fseek(file_input, 0L, SEEK_SET);

    // выделяем память для текста
    char* text = (char*) calloc (size_file_input + 2, sizeof(char)); // +2 чтобы потом добавить \r\n последней строки
    assert (text != NULL);

    // переносим файл в массив
    size_t counter = fread (text, sizeof(char), size_file_input, file_input);
    assert (size_file_input == counter);

    // заканчиваем работу с файлом ввода
    fclose (file_input);

    // добавляем в последнюю строку файла \r\n
    *(text + size_file_input) = '\r';
    *(text + size_file_input + 1) = '\n';

    return text;
    }

//----------------------------------------------------------------