#include "BREDOGENERATOR.H"

#include <assert.h>
#include <cstdlib>
#include <stdio.h>

const int TYPOE_SOZDANIE = 47;
void START_BREDOGENERATOR(char** dynarr, char* key_word)
{
    int HROMOSOMES = 44, transformer = 1;
    int ch = 0;
    printf("ИТАК, сколько говна вы хочите???\n");
    while (transformer % 4 != 0 && scanf("%d", &transformer))
    {
        HROMOSOMES++;
        if (HROMOSOMES == TYPOE_SOZDANIE)
        {
            printf("ой да иди ты нахуй\n\n");
            printf("*тут снести программу в ноль*");
            crashProgramm();
        }
        printf("я только по четверостиишиям, давай нормально запиши эбля\n");

        while((ch = getchar()) != '\n')
        ;
    }

    GLAVNOE_RAZEBALOVO(dynarr, transformer);
}

void GLAVNOE_RAZEBALOVO (char** spisok_kuchek_govna, int count_govna)
{
    if (spisok_kuchek_govna == nullptr)
    {
        printf("да пошел ты нахуй\n\n");
        crashProgramm();
    }
    if (count_govna == 0)
    {
        printf("говно есть всегда, даже в тебе!!!\n\n");
        crashProgramm();
    }
    if (count_govna < 0)
    {
        printf("ты говно в себя решил запихнуть?\n\n");
        crashProgramm();
    }
    int randomNumber = 0;
    printf("ваше говно:\n");
    for (int i = 0; i < count_govna; i++)
    {
        randomNumber = 2 + rand() % 5311;
        printf("%s\n", spisok_kuchek_govna[randomNumber - 2]);
        printf("%s\n", spisok_kuchek_govna[randomNumber - 1]);
        printf("%s\n", spisok_kuchek_govna[randomNumber]);
        printf("%s\n\n", spisok_kuchek_govna[randomNumber + 1]);
    }
    printf("МЯУ");
}

void crashProgramm()
{
    char* ch = nullptr;
    *ch = 54;
}
