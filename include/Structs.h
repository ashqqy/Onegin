#ifndef STRUCTS
#define STRUCTS

#include <stdio.h>

struct PtrAndLenString
    {
    char* ptr_str; // указатель на строку
    size_t len_str; // длина строки
    };

const size_t SIZE_PtrAndLenString = sizeof (PtrAndLenString);

#endif //STRUCTS