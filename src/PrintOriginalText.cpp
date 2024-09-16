#include <cstring>
#include <assert.h>

#include "PrintOriginalText.h"

//----------------------------------------------------------------

/// @brief Функция, печатающая массив строк text построчно
/// @param[in] text_info Структура с информацией о тексте
/// @param[in] file_output Файл для вывода
void PrintOriginalText (TextInfo text_info, FILE* file_output)
    {
    assert (file_output != NULL);

    char* ptr_printing_line = text_info.text;
    for (int i = 0; i < text_info.n_strings; ++i)
        {
        fputs (ptr_printing_line, file_output);
        ptr_printing_line = strchr (ptr_printing_line, '\0') + 1;
        }
    }

//----------------------------------------------------------------