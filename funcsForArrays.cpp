#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>


void printArray (char** dynamicArray, const int count_rows, FILE* outputSource,
                 int mode, int number_row)
{
    assert(dynamicArray != nullptr && "invalid dynamicArray\n");
    assert(outputSource != nullptr && "invalid outputSource\n");
    //printf("count_rows(printArray) = %d\n", count_rows);
    switch (mode)
    {
        case 0:
            for (int y = 0; y < count_rows; y++)
            {
                fprintf(outputSource, "[%4d] = %s\n", y, dynamicArray[y]);
            }
            break;
        case 1:
            printf("[%4d] = %s\n", number_row, dynamicArray[number_row]);
            break;
        default:
            printf("invalid mode\n");
    }

}

int getNumberRows (const char* buffer, const ssize_t size_file)
{
    assert(buffer != nullptr && "invalid buffer\n");

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
    assert(inputSource != nullptr && "invalid inputSource\n");
    assert(count_all_symbols != nullptr && "invalid pointer of count_all_symbols\n");
    int max = 0, count_symbols_in_one_row = 0;
    int ch = 0;
    while((ch = fgetc(inputSource)) != '\n')
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

/*void freeDynamicArray (char** dynamicArray, const int count_rows)
{
    assert(dynamicArray != nullptr);
    for (int y = 0; y < count_rows; y++)
    {
        free(dynamicArray[y]);
    }
    free(dynamicArray);
}*/

void swapLinesWithStrcpy (char** dynamicArray, const int string1, const int string2)
{
    assert(dynamicArray != nullptr && "invalid pointer to dynamicArray!!!\n");

    char temp[100] = {};
    strcpy(temp, dynamicArray[string1]);
    strcpy(dynamicArray[string1], dynamicArray[string2]);
    strcpy(dynamicArray[string2], temp);
}

// ОРИГИНАЛ ФУНКЦИИ customStrcmp - В ФАЙЛЕ /Users/pashamalyshev/Documents/GitHub/DEDs_small_tasks/customStringFuncs.cpp
int customStrcmp (const char* str1, const char* str2) // ломается при полном совпадении подстрок
                                                      // и одновременно при разном размере строк
{
    assert(str1 != nullptr && "invalid pointer of str1!!!\n");
    assert(str1 != nullptr && "invalid pointer of str2!!!\n");

    int delta_symbols = 0;
    int i = 0;
    if (isalpha(str1[0] == 0) || isalpha(str2[0] == 0))
    {
        i = 1;
    }
    for (; (str1[i] != '\0') && (str2[i] != '\0'); i++)
    {
        tolower(str1[i]);
        tolower(str2[i]);

        delta_symbols = str1[i] - str2[i];
        if (delta_symbols != 0)
        {
            return delta_symbols;
        }
    }

    return 0;
}

// ОРИГИНАЛ ФУНКЦИИ customStrcmp - В ФАЙЛЕ /Users/pashamalyshev/Documents/GitHub/DEDs_small_tasks/customStringFuncs.cpp
int reverseCustomStrcmp (const char* str1, const char* str2) // ломается при полном совпадении подстрок
                                                             // и одновременно при разном размере строк
{
    assert(str1 != nullptr && "invalid pointer of str1!!!\n");
    assert(str1 != nullptr && "invalid pointer of str2!!!\n");

    int delta_symbols = 0;
    int i = 0;
    for (int ind = 0; ind < 3; ind++)
    {
        if ((isalpha(str1[ind]) == 0) || (isalpha(str2[ind]) == 0))
        {
            i = ind + 1;
        }
    }
    for (; (*(str1 - i) != '\0') && (*(str2 - i) != '\0'); i++)
    {
        tolower(*(str1 - i));
        tolower(*(str2 - i));

        delta_symbols = *(str1 - i) - *(str2 - i);
        if (delta_symbols != 0)
        {
            return delta_symbols;
        }
    }

    return 0;
}


char* lastChar(const char* s)
{
    assert(s != nullptr && "invalid adress of char!!!\n");
    size_t len = strlen(s);

    return (len == 0) ? (char*)s : ((char*)s + len - 1);
}

void swapLinesWithPointers (char** dynArraychar, const int str1, const int str2)
{
    assert(dynArraychar && "invalid pointer to dynArraychar!!!\n");

    char* temp = dynArraychar[str1];
    dynArraychar[str1] = dynArraychar[str2];
    dynArraychar[str2] = temp;

}
