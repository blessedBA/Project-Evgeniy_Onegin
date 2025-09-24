#include "bufferAndDynArray.h"

#include <assert.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>


void writeBuffer (char* buffer, FILE* file_input, ssize_t* size_file)
{
    assert(buffer != nullptr && file_input != nullptr);
    assert(file_input != nullptr && "invalid pointer to file_input!!!\n");
    assert(size_file != nullptr && "invalid pointer to size_file!!!\n");

    *size_file = fread(buffer, sizeof(char), *size_file, file_input) + 1;
    if (*size_file == 0)
    {
        assert(0 && "failed to read file!!!\n");
    }
    addEndOfStringToEOF(buffer, *size_file);
}
char* creatBuffer(ssize_t* size_file, const char* filepath)
{
    assert(size_file != nullptr && "invalid pointer to size_file!!!\n");
    assert(filepath != nullptr && "invalid pointer to filepath!!!\n");

    struct stat st = {};
    const int get_info = (int)stat(filepath, &st);
    *size_file = st.st_size;
    if (get_info != 0)
    {
        perror("failed to get info about file!!!\n");
        return nullptr;
    }
    char*  buffer = (char*)calloc(*size_file + 2, sizeof(char));
    return buffer;
}

char** getDynPointerArray(char* buffer, const ssize_t size_file, const int number_rows)
{
assert(buffer != nullptr && "invalid pointer to buffer!!!\n");

    char** dynamic_pointer_array = (char**)calloc((size_t)number_rows, sizeof(char*));
    assert(dynamic_pointer_array != nullptr);

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
    assert(buffer != nullptr && "invalid pointer to buffer!!!\n");

    buffer[size_file - 1] = EOF;
    buffer[size_file - 2] = '\0';
}

void printBuffer (char* buffer, FILE* file_output)
{
    assert(buffer != nullptr && "invalid pointer to buffer!!!\n");
    assert(file_output != nullptr && "invalid pointer to file_output!!!\n");

    for (int i = 0; buffer[i] != EOF; i++)
    {
        if (buffer[i] == '\0')
        {
            fprintf(file_output, "\n");
            continue;
        }
        fputc(buffer[i], file_output);
    }
    return;
}

