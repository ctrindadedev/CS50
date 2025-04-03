#include <stdio.h>
#include <string.h>

#define MAX 9

// Struct para armazenar candidatos - candidates have name and votess
typedef struct
{
    char name[50];
    int votes;
} candidate;

// Array para armazenar candidatos

candidate candidates[MAX];
int candidate_count = 0;

// Protótipos das funções à serem desenvolvidas
void candidatoCreator(int count, char *names[]);
int votar(char *name);
void print_winner(void);

int main(int argc, char *argv[])
{
    // Verifica se há candidatos suficientes
    if (argc < 2)
    {
        printf("Uso: plurality [candidato ...]\n");
        return 1;
    }

    candidatoCreator(argc - 1, argv + 1);

    int voter_count;
    printf("Número de eleitores: ");
    scanf("%d", &voter_count);

    // Registrar os votos
    for (int i = 0; i < voter_count; i++)
    {
        char name[50];
        printf("Voto: ");
        scanf("%s", name);

        if (!votar(name))
        {
            printf("Voto inválido!\n");
        }
    }
    print_winner();

    return 0;
}

// Função para criar candidatos
void candidatoCreator(int count, char *names[])
{
    if (count > MAX)
    {
        printf("Número máximo de candidatos excedido!\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        strcpy(candidates[i].name, names[i]);
        candidates[i].votes = 0;
    }
    candidate_count = count;
}

// Função para registrar votos
int votar(char *name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            // Voto válido/true
            return 1;
        }
    }
    // Voto inválido/false
    return 0;
}

// Função para exibir o vencedor
void print_winner(void)
{
    int maior = 0;
    char vencedores[MAX][50];
    int count = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > maior)
        {
            maior = candidates[i].votes;
            count = 0;
            strcpy(vencedores[count++], candidates[i].name);
        }
        else if (candidates[i].votes == maior)
        {
            strcpy(vencedores[count++], candidates[i].name);
        }
    }

    printf("Vencedor(es): ");
    for (int i = 0; i < count; i++)
    {
        printf("%s ", vencedores[i]);
    }
    printf("\n");
}
