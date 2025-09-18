#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>


void printArray (char** dynamicArray, const int count_rows, FILE* outputSource,
                 int mode, int number_row)
{
    printf("count_rows(printArray) = %d\n", count_rows);
    switch (mode)
    {
        case 0:
            for (size_t y = 0; y < count_rows; y++)
            {
                fprintf(outputSource, "[%4zu] = %s\n", y, dynamicArray[y]);
            }
            break;
        case 1:
            printf("[%4zu] = %s\n", number_row, dynamicArray[number_row]);
            break;
    }

}

int getNumberRows (const char* buffer, const ssize_t size_file)
{
    int count_rows = 0;
    for (int i = 0; i < size_file; i++)
    {
        if (buffer[i] == '\n')
        {
            count_rows++;
        }
        if (buffer[i] == EOF && buffer[i - 1] != '\n')
        {
            count_rows++;
            return count_rows;
        }
    }
    return count_rows;
}

int* getAddress (int array[][4], const size_t y, const size_t x)
{
    return &(array[y][x]);
}

int findMaxString (FILE* inputSource, int* count_all_symbols)
{
    int max = 0, count_symbols_in_one_row = 0;
    int ch = 0;
    while(ch = fgetc(inputSource) != '\n')
    {
        if (ch == EOF)
        {
            *count_all_symbols++;
            count_symbols_in_one_row++;
            if (count_symbols_in_one_row > max)
            {
                max = count_symbols_in_one_row;
            }
        }
        *count_all_symbols++;
        count_symbols_in_one_row++;
        if (count_symbols_in_one_row > max)
        {
            max = count_symbols_in_one_row;
        }

    }
    rewind(inputSource);
    return max;
}

void freeDynamicArray (char** dynamicArray, const int count_rows)
{
    assert(dynamicArray != nullptr);
    for (int y = 0; y < count_rows; y++)
    {
        free(dynamicArray[y]);
    }
    free(dynamicArray);
}

void swapLinesWithStrcpy (char** dynamicArray, const int string1, const int string2)
{
    char temp[100] = {};
    strcpy(temp, dynamicArray[string1]);
    strcpy(dynamicArray[string1], dynamicArray[string2]);
    strcpy(dynamicArray[string2], temp);
}

// ОРИГИНАЛ ФУНКЦИИ customStrcmp - В ФАЙЛЕ /Users/pashamalyshev/Documents/GitHub/DEDs_small_tasks/customStringFuncs.cpp
int customStrcmp (const char* str1, const char* str2) // ломается при полном совпадении подстрок
                                                      // и одновременно при разном размере строк
{
    int delta_symbols = 0;
    int i = 0;
    if (isalpha(str1[0] == 0) || isalpha(str2[0] == 0))
    {
        printf("%s\n", str1);
        printf("%s\n", str2);
        i = 1;
    }
    for (; (str1[i] != '\0') && (str2[i] != '\0'); i++)
    {
        if (islower(str1[i]) == 0)
        {
            tolower(str1[i]);
        }
        if (islower(str2[i]) == 0)
        {
            tolower(str2[i]);
        }
        delta_symbols = str1[i] - str2[i];
        if (delta_symbols != 0)
        {
            break;
        }
    }

    return delta_symbols;
}

// ОРИГИНАЛ ФУНКЦИИ customStrcmp - В ФАЙЛЕ /Users/pashamalyshev/Documents/GitHub/DEDs_small_tasks/customStringFuncs.cpp
int reverseCustomStrcmp (const char* str1, const char* str2) // ломается при полном совпадении подстрок
                                                      // и одновременно при разном размере строк
{
    int delta_symbols = 0;
    int i = 0;
    if (isalpha(str1[0] == 0) || isalpha(str2[0] == 0))
    {
        printf("%s\n", str1);
        printf("%s\n", str2);
        i = 1;
    }
    for (; (*(str1 - i) != '\0') && (*(str2 - i) != '\0'); i++)
    {
        if (islower(*(str1 - i)) == 0)
        {
            tolower(*(str1 - i));
        }
        if (islower(*(str2 - i)) == 0)
        {
            tolower(*(str2 - i));
        }
        delta_symbols = *(str1 - i) - *(str2 - i);
        if (delta_symbols != 0)
        {
            break;
        }
    }

    return delta_symbols;
}

int KOSTYL_reverseCustomStrcmp (char* str1, char* str2)
{
    char* rptr_to_second_str = str1 + strlen(str1) - 1;
    char* rptr_to_first_str  = str2 + strlen(str2) - 1;
    int delta_symbols = 0;
    int i = 0;
    if (isalpha(rptr_to_second_str[0] == 0) || rptr_to_first_str[0] == 0)
    {
        printf("%s\n", str1);
        printf("%s\n", str2);
        i = 1;
    }
    for (; i != (strlen(str1) - 1) && i != (strlen(str2) - 1); i++)
    {
        if (islower(*(rptr_to_second_str - i)) == 0)
        {
            tolower(*(rptr_to_second_str - i));
        }
        if (islower(*(rptr_to_first_str - i)) == 0)
        {
            tolower(*(rptr_to_first_str - i));
        }
        delta_symbols = *(rptr_to_second_str - i) - *(rptr_to_first_str - i);
        if (delta_symbols != 0)
        {
            break;
        }
    }

    return delta_symbols;
}

char* lastChar(char* s)
{
    size_t len = strlen(s);
    return (len == 0) ? s : (s + len - 1);
}

void swapLinesWithPointers (char** dyn_array_pointers, const int str1, const int str2)
{
    char* temp = dyn_array_pointers[str1];
    dyn_array_pointers[str1] = dyn_array_pointers[str2];
    dyn_array_pointers[str2] = temp;
}
