#include "BREDOGENERATOR.H"
#include "sortsArrays.h"
#include "funcsForArrays.h"
#include "funcsForFiles.h"
#include "Files.h"
#include "bufferAndDynArray.h"
//#include "../DEDs_small_tasks/customStringFuncs.h" // -I DEDs_small_tasks
#include <assert.h>
#include <fcntl.h>
#include <math.h>
#include <inttypes.h>        // Для использования типов данных с точной шириной
                             // (например, int32_t - для 32-битного целого числа)
#include <limits.h>          // Для использования макросов, определяющих пределы типов данных
                             // (например, INT32_MAX - максимальное значение для 32-битного целого числа)
#include <string.h>          // Для использования функций работы со строками (например, strlen)
#include <ctype.h>           // для функций проверки символов
#include <stdbool.h>         // вместо _Bool - bool, вместо 1 и 0 - true и false
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

//int delta_pointer_buffer = int(&buffer[1] - &buffer[0]);
// printf("delta_pointer_buffer = %d\n", delta_pointer_buffer);
// printf("buffer[0] = %c\n", buffer[0]);
// printf("pointer to buffer[0] = %p\n", buffer);
// printf("number_rows = %d\n", number_rows);
// printf("size_file = %zd\n", size_file);
// printf("st.st_size = %lld\n", st.st_size);
//int delta_pointers = (int)(&dynamic_pointer_array[2] - &dynamic_pointer_array[1]);
// printf("delta_pointers = %d\n", delta_pointers);
// printf("dynamic_pointer_array[0] = %p\n", dynamic_pointer_array[0]);
// printf("pointer to buffer[0] = %p\n", buffer);

enum MODES
{
    ALL_ROWS,
    ONE_ROW
};

int main()
{
    const char* filepath = ONEGIN_IN;
    FILE* file_input = fopen(ONEGIN_IN, "r");
    FILE* file_output = fopen(ONEGIN_OUT, "w");
    if (openingFileIsCorrect(file_input) ==  false &&
        openingFileIsCorrect(file_output) == false)
    {
        assert(0);
    }


    ssize_t size_file = 0;
    char* buffer = creatBuffer(&size_file, filepath);
    if (buffer == nullptr)
    {
        assert(0 && "failed to allocate memory\n");
    }
    writeBuffer(buffer, file_input, &size_file);

    fclose(file_input);

    const int number_rows = getNumberRows(buffer, size_file);
    char** dynamic_pointer_array = getDynPointerArray(buffer, size_file, number_rows);

    //bubbleSortArray (dynamic_pointer_array, number_rows);
    //reverseBubbleSortArray(dynamic_pointer_array, number_rows);
    qsort(dynamic_pointer_array, (size_t)number_rows, sizeof(char*), compareStr);
    printArray(dynamic_pointer_array, number_rows, file_output, ALL_ROWS, 0);

    fprintf(file_output, "\n\n\n\n\n");

    qsort(dynamic_pointer_array, (size_t)number_rows, sizeof(char*), reverseCompareStr);
    printArray(dynamic_pointer_array, number_rows, file_output, ALL_ROWS, 0);

    fprintf(file_output, "\n\n\n\n\n");

    printBuffer(buffer, file_output);
    //START_BREDOGENERATOR(dynamic_pointer_array, "ЗАПУСКАЙ!!!!  ");

    free(dynamic_pointer_array);
    fclose(file_output);

    return 0;
}
