#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Tabela de pontos para cada letra
int points[] = {
    1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1,
    3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Função para calcular a pontuação de uma palavra
int compute_score(char word[])
{
    int score = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (isalpha(word[i]))
        {                                      // Verifica se é uma letra
            char uppercase = toupper(word[i]); // Converte para maiúscula
            score += points[uppercase - 'A'];  // Subtrai 'A' para obter índice correto
        }
    }
    return score;
}

int main()
{
    char word1[100], word2[100];

    // Entrada dos jogadores
    printf("Player 1: ");
    scanf("%s", word1);

    printf("Player 2: ");
    scanf("%s", word2);

    // Calcula a pontuação de cada palavra
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Determina o vencedor
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}