#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(char text[])
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(char text[])
{
    int count = 1; // Começamos com 1 porque há sempre uma palavra a mais que os espaços
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }
    return count;
}

int count_sentences(char text[])
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}

int main()
{
    char text[1000];

    printf("Digite um texto:\n");
    fgets(text, sizeof(text), stdin);

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = ((float)letters / words) * 100;
    float S = ((float)sentences / words) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    printf("O índice de legibilidade é: %d\n", index);

    if (index < 1)
    {
        printf("Classificação: Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Classificação: Grade 16+\n");
    }
    else
    {
        printf("Classificação: Grade %d\n", index);
    }

    return 0;
}
