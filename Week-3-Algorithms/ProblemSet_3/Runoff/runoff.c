#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 9
#define MAX_VOTERS 100

// Struct para candidatos
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array de candidatos
candidate candidatos[MAX];

// Matriz de preferências dos eleitores
int preferencias[MAX_VOTERS][MAX];

// Número de candidatos e votantes
int num_candidatos;
int num_votantes;

// Protótipos
bool votar(int eleitor, int rank, string nome);
bool vencedor(void);
int encontrar_min(void);
bool empate(int min);
void eliminar(int min);
void zerar_votos(void);
void realizar_votacao(void);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Uso: runoff [candidato1] [candidato2] ...\n");
        return 1;
    }

    // Inicializa candidatos
    num_candidatos = argc - 1;
    if (num_candidatos > MAX)
    {
        printf("Máximo de candidatos é %i\n", MAX);
        return 2;
    }

    for (int i = 0; i < num_candidatos; i++)
    {
        candidatos[i].name = argv[i + 1];
        candidatos[i].votes = 0;
        candidatos[i].eliminated = false;
    }

    // Recebe número de eleitores
    num_votantes = get_int("Número de eleitores: ");
    if (num_votantes > MAX_VOTERS)
    {
        printf("Máximo de eleitores é %i\n", MAX_VOTERS);
        return 3;
    }

    // Recebe as preferências
    for (int i = 0; i < num_votantes; i++)
    {
        for (int j = 0; j < num_candidatos; j++)
        {
            string nome = get_string("Votante %i - preferência %i: ", i + 1, j + 1);
            if (!votar(i, j, nome))
            {
                printf("Voto inválido.\n");
                return 4;
            }
        }
    }

    // Executa a eleição
    while (true)
    {
        realizar_votacao();

        if (vencedor())
        {
            break;
        }

        int min = encontrar_min();
        if (empate(min))
        {
            for (int i = 0; i < num_candidatos; i++)
            {
                if (!candidatos[i].eliminated)
                {
                    printf("%s\n", candidatos[i].name);
                }
            }
            break;
        }

        eliminar(min);
    }

    return 0;
}

// Registra a preferência do eleitor
bool votar(int eleitor, int rank, string nome)
{
    for (int i = 0; i < num_candidatos; i++)
    {
        if (strcmp(nome, candidatos[i].name) == 0)
        {
            preferencias[eleitor][rank] = i;
            return true;
        }
    }
    return false;
}

// Soma votos com base nas preferências
void realizar_votacao(void)
{
    zerar_votos();

    for (int i = 0; i < num_votantes; i++)
    {
        for (int j = 0; j < num_candidatos; j++)
        {
            int index = preferencias[i][j];
            if (!candidatos[index].eliminated)
            {
                candidatos[index].votes++;
                break;
            }
        }
    }
}

// Verifica se há vencedor
bool vencedor(void)
{
    for (int i = 0; i < num_candidatos; i++)
    {
        if (!candidatos[i].eliminated && candidatos[i].votes > num_votantes / 2)
        {
            printf("Vencedor: %s\n", candidatos[i].name);
            return true;
        }
    }
    return false;
}

// Retorna o menor número de votos
int encontrar_min(void)
{
    int min = num_votantes + 1;
    for (int i = 0; i < num_candidatos; i++)
    {
        if (!candidatos[i].eliminated && candidatos[i].votes < min)
        {
            min = candidatos[i].votes;
        }
    }
    return min;
}

// Verifica empate
bool empate(int min)
{
    for (int i = 0; i < num_candidatos; i++)
    {
        if (!candidatos[i].eliminated && candidatos[i].votes != min)
        {
            return false;
        }
    }
    return true;
}

// Elimina candidatos com o menor número de votos
void eliminar(int min)
{
    for (int i = 0; i < num_candidatos; i++)
    {
        if (!candidatos[i].eliminated && candidatos[i].votes == min)
        {
            candidatos[i].eliminated = true;
            printf("Candidato eliminado: %s\n", candidatos[i].name);
        }
    }
}

// Zera votos
void zerar_votos(void)
{
    for (int i = 0; i < num_candidatos; i++)
    {
        candidatos[i].votes = 0;
    }
}
