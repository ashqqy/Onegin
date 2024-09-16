#ifndef DATA_SORT
#define DATA_SORT

#include "Structs.h"

typedef int (*compare_func_t) (PtrAndLenString str1, PtrAndLenString str2);

void DataSort (TextInfo text_info, compare_func_t CompareFunc);

#endif //DATA_SORT