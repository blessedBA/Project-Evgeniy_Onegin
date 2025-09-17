#include "funcsForArrays.h"

#include <assert.h>
#include <math.h>
// #include <inttypes.h>       /*Для использования типов данных с точной шириной
//                             (например, int32_t - для 32-битного целого числа)*/
// #include <limits.h>       /*Для использования макросов, определяющих пределы типов данных
//                             (например, INT32_MAX - максимальное значение для 32-битного целого числа)*/
#include <string.h>       /*Для использования функций работы со строками (например, strlen)*/
#include <ctype.h>          // для функций проверки символов
#include <stdbool.h>        // вместо _Bool - bool, вместо 1 и 0 - true и false
#include <stdlib.h>

enum MODES
{
    ALL_ROWS,
    ONE_ROW
};
void freeDynamicArray (char** dynamicArray, const int count_rows);
char** getDynArray (int count_rows, FILE* inputstream);
void swapLinesWithStrcpy (char** dynamicArray, const int string1, const int string2);
void swapLinesSymbBySymb (char** dynamicArray, const int string1, const int string2);

int main()
{
    FILE* fileInput = fopen("Onegin.txt", "r");
    FILE* fileOutput = fopen("onegin_OUT.txt", "w");

    int count_rows = getNumberRows(fileInput);
    char** dynamicArray = getDynArray(count_rows, fileInput);
    swapLinesWithStrcpy (dynamicArray, 3, 4);
    printArray(dynamicArray, count_rows, fileOutput, ONE_ROW, 3);
    printArray(dynamicArray, count_rows, fileOutput, ONE_ROW, 5);
    printArray(dynamicArray, count_rows, fileOutput, ALL_ROWS, NULL);
    fclose(fileInput);
    fclose(fileOutput);
    return 0;
}

char** getDynArray(int count_rows, FILE* inputsource)
{
    char** dynamicArray = nullptr;
    size_t startLenString = 0;
    int count_all_symbols = 0;
    dynamicArray = (char**)calloc(count_rows, sizeof(char*)); //NOTE - тк размер любого указателя - 8 байт а не 4(64разр)
    assert(dynamicArray != nullptr && "failed to allocate memory\n");

    int max_symbols_in_one_row = findMaxString(inputsource, count_all_symbols);
    for (int y = 0; y < count_rows; y++)
    {
        dynamicArray[y] = (char*)calloc(max_symbols_in_one_row + 1, sizeof(char)); // +1 для нул символа
        assert(dynamicArray[y] != nullptr && "failed to allocate memory for y string\n");
    }
    for (int y = 0; y < count_rows; y++)
    {
        getline(&dynamicArray[y], &startLenString, inputsource);
        if (startLenString == 1)
        {
            dynamicArray[y][startLenString - 1] = '\0';
            startLenString = 0;
            continue;
        }
        startLenString = 0;
    }
    return dynamicArray;
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

void swapLinesSymbBySymb (char** dynamicArray, const int string1, const int string2)
{

}
