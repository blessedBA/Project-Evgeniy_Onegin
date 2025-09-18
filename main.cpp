#include "BREDOGENERATOR.H"
#include "sortsArrays.h"
#include "funcsForArrays.h"

#include <assert.h>
#include <fcntl.h>
#include <math.h>
// #include <inttypes.h>       /*Для использования типов данных с точной шириной
//                             (например, int32_t - для 32-битного целого числа)*/
// #include <limits.h>       /*Для использования макросов, определяющих пределы типов данных
//                             (например, INT32_MAX - максимальное значение для 32-битного целого числа)*/
#include <string.h>       /*Для использования функций работы со строками (например, strlen)*/
#include <ctype.h>          // для функций проверки символов
#include <stdbool.h>        // вместо _Bool - bool, вместо 1 и 0 - true и false
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

enum MODES
{
    ALL_ROWS,
    ONE_ROW
};

char** getDynPointerArray (char* buffer, const ssize_t size_file, const int number_rows);
void swapLinesSymbBySymb (char** dynamicArray, const size_t string1, const size_t string2);
void addEndOfStringToEOF (char* buffer, const ssize_t size_file);


int main()
{
    const char* filepath = "Onegin.txt";
    int fileInput = open("Onegin.txt", O_RDONLY);
    FILE* fileOutput = fopen("onegin_OUT.txt", "w");
    if (fileInput == -1)
    {
        perror("failed to open input file\n");
        return 1;
    }
    if (fileOutput == nullptr)
    {
        perror("failed to open/create output file\n");
        return 1;
    }
    struct stat st {};
    const int get_info = (int)stat(filepath, &st);
    if (get_info != 0)
    {
        perror("failed to get info about file!!!\n");
        return 1;
    }
    char*  buffer = (char*)calloc(st.st_size + 1, sizeof(char));
    int delta_pointer_buffer = int(&buffer[1] - &buffer[0]);

    printf("delta_pointer_buffer = %d\n", delta_pointer_buffer);
    printf("buffer[0] = %c\n", buffer[0]);
    printf("pointer to buffer[0] = %p\n", buffer);

    if (buffer == nullptr)
    {
        assert(0 && "failed to allocate memory\n");
    }

    const ssize_t size_file = read(fileInput, buffer, st.st_size) + 1;
    if (size_file == -1)
    {
        assert(0 && "failed to read file!!!\n");
    }
    addEndOfStringToEOF(buffer, size_file);

    printf("size_file = %zd\n", size_file);
    printf("st.st_size = %lld\n", st.st_size);

    close(fileInput);

    const int number_rows = getNumberRows(buffer, size_file);
    printf("number_rows = %d\n", number_rows);
    char** dynamic_pointer_array = getDynPointerArray(buffer, size_file, number_rows);
    int delta_pointers = (int)(&dynamic_pointer_array[2] - &dynamic_pointer_array[1]);

    printf("delta_pointers = %d\n", delta_pointers);
    printf("dynamic_pointer_array[0] = %p\n", dynamic_pointer_array[0]);
    printf("pointer to buffer[0] = %p\n", buffer);
    //bubbleSortArray (dynamic_pointer_array, number_rows);
    reverseBubbleSortArray(dynamic_pointer_array, number_rows);
    //qsort(dynamic_pointer_array, (size_t)number_rows, sizeof(char*), compareStr);
    printArray(dynamic_pointer_array, number_rows, fileOutput, ALL_ROWS, NULL);
    //START_BREDOGENERATOR(dynamic_pointer_array, "ЗАПУСКАЙ!!!!  ");

    free(dynamic_pointer_array);
    fclose(fileOutput);

    return 0;
}

char** getDynPointerArray(char* buffer, const ssize_t size_file, const int number_rows)
{
    char** dynamic_pointer_array = (char**)calloc(number_rows, sizeof(char*));
    dynamic_pointer_array[0] = buffer;
    int num_row = 1;
    for (int i = 0; i < size_file; i++)
    {
        if (buffer[i] == '\n')
        {
            dynamic_pointer_array[num_row] = buffer + i + 1;
            num_row++;
            buffer[i] = '\0';
        }
    }
    return dynamic_pointer_array;
}



void addEndOfStringToEOF (char* buffer, const ssize_t size_file)
{
    buffer[size_file - 1] = EOF;
    buffer[size_file - 2] = '\0';
}


