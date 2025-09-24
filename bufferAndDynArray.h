#ifndef BUFFER_AND_DYN_ARRAY_H
#define BUFFER_AND_DYN_ARRAY_H
#include <stdio.h>


char** getDynPointerArray (char* buffer, const ssize_t size_file, const int number_rows);
void swapLinesSymbBySymb (char** dynamicArray, const size_t string1, const size_t string2);
void addEndOfStringToEOF (char* buffer, const ssize_t size_file);

char* creatBuffer (ssize_t* size_file, const char* filepath);
void writeBuffer (char* buffer, FILE* file_input, ssize_t* size_file);

void printBuffer (char* buffer, FILE* file_output);


#endif // BUFFER_AND_DYN_ARRAY_H
