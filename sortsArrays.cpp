#include "funcsForArrays.h"

#include <assert.h>
#include <string.h>


void bubbleSortArray (char** dynamic_pointer_array, const int number_rows)
{
    assert(dynamic_pointer_array != nullptr && "invalid dynamic_pointer_array\n");
    assert(number_rows > 0 && "invalid number of rows!!!\n");

    int delta_strings = 0;
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

// void reverseBubbleSortArray (char** dynamic_pointer_array, const int number_rows)
// {
//     assert(dynamic_pointer_array != nullptr && "invalid dynamic_pointer_array\n");
//     assert(number_rows > 0 && "invalid number of rows!!!\n");
//     char* temp = nullptr;
//     for (int i = 0; i < number_rows; ++i)
//     {
//         for (int j = 0; j < number_rows - 1; ++j)
//         {
//             const char* ch1 = lastChar(dynamic_pointer_array[j]);
//             const char* ch2 = lastChar(dynamic_pointer_array[j + 1]);
//             if (reverseCustomStrcmp(ch1, ch2) < 0)
//             {
//                 swapLinesWithPointers(dynamic_pointer_array, j, j + 1);
//             }
//         }
//     }
// }

int compareStr (const void* str1, const void* str2)
{
    assert(str1 != nullptr);
    assert(str2 != nullptr);

    const char* s1 = *(const char**)str1;
    const char* s2 = *(const char**)str2;

    return customStrcmp(s1, s2);
}

int reverseCompareStr (const void* str1, const void* str2)
{
    assert(str1 != nullptr);
    assert(str2 != nullptr);

    const char* s1 = *(const char* const*)str1;
    const char* s2 = *(const char* const*)str2;

    char* last_char1 = lastChar(s1);
    char* last_char2 = lastChar(s2);

    return -reverseCustomStrcmp(last_char1, last_char2);
}
