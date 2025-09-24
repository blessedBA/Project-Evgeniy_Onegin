#include <assert.h>
#include <stdio.h>


bool openingFileIsCorrect (FILE* opened_file)
{
    if (opened_file == nullptr)
    {
        perror("failed to open input file\n");
        return false;
    }
    return true;

}
