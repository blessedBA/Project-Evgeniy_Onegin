#include <stdio.h>


void printArray (char** dynamicArray, int count_rows, FILE* outputSource,
                 int mode, int number_row)
{
    switch (mode)
    {
        case 0:
            for (size_t y = 0; y < count_rows; y++)
            {
                fprintf(outputSource, "[%zu] = %s\n", y, dynamicArray[y]);
            }
            break;
        case 1:
            printf("[%zu] = %s\n", number_row, dynamicArray[number_row]);
            break;
    }

}

int getNumberRows (FILE* inputsource)
{
    int count_rows = 0, ch = 0;
    while ((ch = fgetc(inputsource)) != EOF)
    {
        if (ch == '\n')
        {
            count_rows++;
        }
    }
    count_rows++;
    return count_rows;


}

int* getAddress (int array[][4], const size_t y, const size_t x)
{
    return &(array[y][x]);
}

int findMaxString (FILE* inputSource, int count_all_symbols)
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
