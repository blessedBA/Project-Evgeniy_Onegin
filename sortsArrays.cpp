#include "funcsForArrays.h"

#include <assert.h>
#include <string.h>


void bubbleSortArray (char** dynamic_pointer_array, const int number_rows)
{
    assert(dynamic_pointer_array != nullptr);
    int delta_strings = 0;
    char* temp = nullptr;
    for (int i = 0; i < number_rows; i++)
    {
        for (int j = 0; j < number_rows - 1; j++)
        {
            delta_strings = customStrcmp(dynamic_pointer_array[j], dynamic_pointer_array[j + 1]);
            if (delta_strings > 0)
            {
                swapLinesWithPointers(dynamic_pointer_array, j, j + 1);
            }
        }
    }
}

void reverseBubbleSortArray (char** dynamic_pointer_array, const int number_rows)
{
    assert(dynamic_pointer_array != nullptr);
    char* temp = nullptr;
    for (int i = 0; i < number_rows; ++i)
    {
        for (int j = 0; j < number_rows - 1; ++j)
        {
            const char* ch1 = lastChar(dynamic_pointer_array[j]);
            const char* ch2 = lastChar(dynamic_pointer_array[j + 1]);
            if (reverseCustomStrcmp(ch1, ch2) < 0)
            {
                swapLinesWithPointers(dynamic_pointer_array, j, j + 1);
            }
        }
    }
}

int compareStr (const void* str1, const void* str2)
{
    const char* s1 = *(char**)str1;
    const char* s2 = *(char**)str2;

    return customStrcmp(s1, s2);
}
