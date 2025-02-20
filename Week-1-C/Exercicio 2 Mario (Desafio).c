#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 9

void dama(char tabuleiro[SIZE][SIZE], int rodada)
{
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (tabuleiro[0][j] == 'b')
            {
                tabuleiro[0][j] = 'B';
            }
        }
    }

    for (int i = 7; i < 8; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (tabuleiro[7][j] == 'p')
            {
                tabuleiro[7][j] = 'P';
            }
        }
    }
}

void ataque(char tabuleiro[SIZE][SIZE], int linha, int coluna, int linhaAdm, int linhaOrigem, int colunaOrigem,
            int rodada)
{
    if (rodada % 2 == 0)
    {
        tabuleiro[linhaAdm][coluna] = tabuleiro[linhaOrigem][colunaOrigem];
    }
    else if (rodada % 2 == 1)
    {
        tabuleiro[linhaAdm][coluna] = tabuleiro[linhaOrigem][colunaOrigem];
    }
}

int vericacaoPeca(char tabuleiro[SIZE][SIZE], int linhaAdm, int linha,
                  int coluna)
{
    if (tabuleiro[linhaAdm][coluna] == 'B' ||
        tabuleiro[linhaAdm][coluna] == 'P')
    {
        if (tabuleiro[linhaAdm + 1][coluna + 1] != '-' &&
            tabuleiro[linhaAdm + 1][coluna - 1] != '-' &&
            tabuleiro[linhaAdm - 1][coluna + 1] != '-' &&
            tabuleiro[linhaAdm - 1][coluna - 1] != '-')
        {
            return 1;
        }
    }
    else if (tabuleiro[linhaAdm][coluna] == 'b')
    {
        if (tabuleiro[linhaAdm - 1][coluna + 1] != '-' &&
            tabuleiro[linhaAdm - 1][coluna - 1] != '-')
        {
            return 1;
        }
    }
    else if (tabuleiro[linhaAdm][coluna] == 'p')
    {
        if (tabuleiro[linhaAdm + 1][coluna + 1] != '-' &&
            tabuleiro[linhaAdm + 1][coluna - 1] != '-')
        {
            return 1;
        }
    }
    return 0;
}

void movimentoPeca(char tabuleiro[SIZE][SIZE], int linha, int coluna,
                   int linhaAdm, int rodada)
{
    int opcao;
    if (rodada % 2 == 0)
    {
        if (tabuleiro[linhaAdm][coluna] == 'B')
        {
            if (linhaAdm - 1 >= 0)
            {
                if (coluna + 1 < SIZE && tabuleiro[linhaAdm - 1][coluna + 1] == '-')
                {
                    printf("opção 1: %d %d\n", linha + 1, coluna + 1);
                }
                if (coluna - 1 >= 0 && tabuleiro[linhaAdm - 1][coluna - 1] == '-')
                {
                    printf("opção 2: %d %d\n", linha + 1, coluna - 1);
                }
            }
            if (linhaAdm + 1 < SIZE)
            {
                if (coluna + 1 < SIZE && tabuleiro[linhaAdm + 1][coluna + 1] == '-')
                {
                    printf("opção 3: %d %d\n", linha - 1, coluna + 1);
                }
                if (coluna - 1 >= 0 && tabuleiro[linhaAdm + 1][coluna - 1] == '-')
                {
                    printf("opção 4: %d %d\n", linha - 1, coluna - 1);
                }
            }
            printf("escolha uma opção (usando apenas o numeral): ");
            scanf(" %d", &opcao);
            printf("\n");
            if (opcao == 1 && tabuleiro[linhaAdm - 1][coluna + 1] == '-')
            {
                tabuleiro[linhaAdm][coluna] = '-';
                tabuleiro[linhaAdm - 1][coluna + 1] = 'B';
            }
            else if (opcao == 2 && tabuleiro[linhaAdm - 1][coluna - 1] == '-')
            {
                tabuleiro[linhaAdm][coluna] = '-';
                tabuleiro[linhaAdm - 1][coluna - 1] = 'B';
            }
            else if (opcao == 3 && tabuleiro[linhaAdm + 1][coluna + 1] == '-')
            {
                tabuleiro[linhaAdm][coluna] = '-';
                tabuleiro[linhaAdm + 1][coluna + 1] = 'B';
            }
            else if (opcao == 4 && tabuleiro[linhaAdm + 1][coluna - 1] == '-')
            {
                tabuleiro[linhaAdm][coluna] = '-';
                tabuleiro[linhaAdm + 1][coluna - 1] = 'B';
            }
            else
            {
                printf("Opção inválida!\n");
                movimentoPeca(tabuleiro, linha, coluna, linhaAdm, rodada);
            }
        }
        else if (tabuleiro[linhaAdm][coluna] == 'b')
        {
            if (linhaAdm - 1 >= 0)
            {
                if (coluna + 1 < SIZE && tabuleiro[linhaAdm - 1][coluna + 1] == '-')
                {
                    printf("opção 1: %d %d\n", linha + 1, coluna + 1);
                }
                if (coluna - 1 >= 0 && tabuleiro[linhaAdm - 1][coluna - 1] == '-')
                {
                    printf("opção 2: %d %d\n", linha + 1, coluna - 1);
                }
            }
            printf("escolha uma opção (usando apenas o numeral): ");
            scanf(" %d", &opcao);
            printf("\n");
            if (opcao == 1 && tabuleiro[linhaAdm - 1][coluna + 1] == '-')
            {
                tabuleiro[linhaAdm][coluna] = '-';
                tabuleiro[linhaAdm - 1][coluna + 1] = 'b';
            }
            else if (opcao == 2 && tabuleiro[linhaAdm - 1][coluna - 1] == '-')
            {
                tabuleiro[linhaAdm][coluna] = '-';
                tabuleiro[linhaAdm - 1][coluna - 1] = 'b';
            }
            else
            {
                printf("Opção inválida!\n");
                movimentoPeca(tabuleiro, linha, coluna, linhaAdm, rodada);
            }
        }
    }
    else
    {
        if (tabuleiro[linhaAdm][coluna] == 'P')
        {
            if (linhaAdm + 1 < SIZE)
            {
                if (coluna + 1 < SIZE && tabuleiro[linhaAdm + 1][coluna + 1] == '-')
                {
                    printf("opção 1: %d %d\n", linha - 1, coluna + 1);
                }
                if (coluna - 1 >= 0 && tabuleiro[linhaAdm + 1][coluna - 1] == '-')
                {
                    printf("opção 2: %d %d\n", linha - 1, coluna - 1);
                }
            }
            if (linhaAdm - 1 >= 0)
            {
                if (coluna + 1 < SIZE && tabuleiro[linhaAdm - 1][coluna + 1] == '-')
                {
                    printf("opção 3: %d %d\n", linha + 1, coluna + 1);
                }
                if (coluna - 1 >= 0 && tabuleiro[linhaAdm - 1][coluna - 1] == '-')
                {
                    printf("opção 4: %d %d\n", linha + 1, coluna - 1);
                }
            }
            printf("escolha uma opção (usando apenas o numeral): ");
            scanf(" %d", &opcao);
            printf("\n");
            if (opcao == 1 && tabuleiro[linhaAdm + 1][coluna + 1] == '-')
            {
                tabuleiro[linhaAdm][coluna] = '-';
                tabuleiro[linhaAdm + 1][coluna + 1] = 'P';
            }
            else if (opcao == 2 && tabuleiro[linhaAdm + 1][coluna - 1] == '-')
            {
                tabuleiro[linhaAdm][coluna] = '-';
                tabuleiro[linhaAdm + 1][coluna - 1] = 'P';
            }
            else if (opcao == 3 && tabuleiro[linhaAdm - 1][coluna + 1] == '-')
            {
                tabuleiro[linhaAdm][coluna] = '-';
                tabuleiro[linhaAdm - 1][coluna + 1] = 'P';
            }
            else if (opcao == 4 && tabuleiro[linhaAdm - 1][coluna - 1] == '-')
            {
                tabuleiro[linhaAdm][coluna] = '-';
                tabuleiro[linhaAdm - 1][coluna - 1] = 'P';
            }
            else
            {
                printf("Opção inválida!\n");
                movimentoPeca(tabuleiro, linha, coluna, linhaAdm, rodada);
            }
        }
        else if (tabuleiro[linhaAdm][coluna] == 'p')
        {
            if (linhaAdm + 1 < SIZE)
            {
                if (coluna + 1 < SIZE && tabuleiro[linhaAdm + 1][coluna + 1] == '-')
                {
                    printf("opção 1: %d %d\n", linha - 1, coluna + 1);
                }
                if (coluna - 1 >= 0 && tabuleiro[linhaAdm + 1][coluna - 1] == '-')
                {
                    printf("opção 2: %d %d\n", linha - 1, coluna - 1);
                }
            }
            printf("escolha uma opção (usando apenas o numeral): ");
            scanf(" %d", &opcao);
            printf("\n");
            if (opcao == 1 && tabuleiro[linhaAdm + 1][coluna + 1] == '-')
            {
                tabuleiro[linhaAdm][coluna] = '-';
                tabuleiro[linhaAdm + 1][coluna + 1] = 'p';
            }
            else if (opcao == 2 && tabuleiro[linhaAdm + 1][coluna - 1] == '-')
            {
                tabuleiro[linhaAdm][coluna] = '-';
                tabuleiro[linhaAdm + 1][coluna - 1] = 'p';
            }
            else
            {
                printf("Opção inválida!\n");
                movimentoPeca(tabuleiro, linha, coluna, linhaAdm, rodada);
            }
        }
    }
}

// valida a posição para saber se tem a peça do jogador ou nao
// comecei a fazer, mas deu errado e tou refazendo o codigo geral
void escolhendoPeca(char tabuleiro[SIZE][SIZE], int rodada)
{
    int linha, coluna;
    int linhaAdm;

    printf("Linha:\n");
    scanf("%d", &linha);
    linhaAdm = 8 - linha;
    printf("Coluna:\n");
    scanf("%d", &coluna);

    if (linhaAdm < 0 || linhaAdm >= SIZE || coluna < 0 || coluna >= SIZE)
    {
        printf("Invalido! Tente novamente\n");
        escolhendoPeca(tabuleiro, rodada);
        return;
    }

    if (rodada % 2 == 0)
    {
        if (tabuleiro[linhaAdm][coluna] != 'b' &&
            tabuleiro[linhaAdm][coluna] != 'B')
        {
            printf("Invalido! Tente novamente\n");
            escolhendoPeca(tabuleiro, rodada);
        }
        else if (vericacaoPeca(tabuleiro, linhaAdm, linha, coluna))
        {
            printf("Invalido! Tente novamente\n");
            escolhendoPeca(tabuleiro, rodada);
        }
        else
        {
            printf("Posição valida, qual seu movimento?\n");
            movimentoPeca(tabuleiro, linha, coluna, linhaAdm, rodada);
        }
    }
    else
    {
        if (tabuleiro[linhaAdm][coluna] != 'p' &&
            tabuleiro[linhaAdm][coluna] != 'P')
        {
            printf("Invalido! Tente novamente\n");
            escolhendoPeca(tabuleiro, rodada);
        }
        else if (vericacaoPeca(tabuleiro, linhaAdm, linha, coluna))
        {
            printf("Invalido! Tente novamente\n");
            escolhendoPeca(tabuleiro, rodada);
        }
        else
        {
            printf("Posição valida, qual seu movimento?\n");
            movimentoPeca(tabuleiro, linha, coluna, linhaAdm, rodada);
        }
    }
}

// verifica quem vai jogar toda rodada
int jogadorRodada(int rodada)
{
    if (rodada % 2 == 0)
    {
        printf("Escolha uma peça:\n");
    }
    else if (rodada % 2 == 1)
    {
        printf("Escolha uma peça:\n");
    }
    return (rodada % 2);
}

// incia o tabuleiro incial
void inicializarTabuleiro(char tabuleiro[SIZE][SIZE])
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (i % 2 == 1 && j % 2 == 1 || i % 2 == 0 && j % 2 == 0)
            {
                tabuleiro[i][j] = 'p';
            }
            else
            {
                tabuleiro[i][j] = '-';
            }
        }
    }
    for (int i = 3; i < 5; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            tabuleiro[i][j] = '-';
        }
    }
    for (int i = 5; i < 8; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (i % 2 == 1 && j % 2 == 1 || i % 2 == 0 && j % 2 == 0)
            {
                tabuleiro[i][j] = 'b';
            }
            else
            {
                tabuleiro[i][j] = '-';
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (i == 8 && j == 0)
            {
                tabuleiro[i][j] = '0';
            }
            else if (j == 0)
            {
                tabuleiro[i][j] = '8' - i;
            }
            else if (i == 8)
            {
                tabuleiro[i][j] = '0' + j;
            }
        }
    }
}

// verifica quantas peças cada lado tem, e caso algum lado tenha 0 printa uma
// mensagem e acaba com o jogo
int quantidadePecas(char tabuleiro[SIZE][SIZE])
{
    int cont1 = 0, cont2 = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (tabuleiro[i][j] == 'p' || tabuleiro[i][j] == 'P')
            {
                cont1++;
            }
            else if (tabuleiro[i][j] == 'b' || tabuleiro[i][j] == 'B')
            {
                cont2++;
            }
        }
    }
    if (cont1 == 0)
    {
        printf("As brancas venceram!\n");
        return 1;
    }
    else if (cont2 == 0)
    {
        printf("As pretas venceram!\n");
        return 1;
    }
    return 0;
}

// imprime o tabuleiro
void imprimirTabuleiro(char tabuleiro[SIZE][SIZE])
{
    printf("\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf(" %c", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// ultima função que eu criei, varre o mapa e verifica se tem uma peça que tem
// que atacar a outra caso seja true essa função tem que ir direto para uma
// função de ataque
int ataqueObrigatorio(char tabuleiro[SIZE][SIZE], int rodada)
{
    int linha, coluna;
    int linhaAdm;

    if (rodada % 2 == 0)
    {
        printf("Vez das brancas\n");
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if ((tabuleiro[i][j] == 'b' || tabuleiro[i][j] == 'B') &&
                    (tabuleiro[i - 1][j + 1] == 'p' ||
                     tabuleiro[i - 1][j + 1] == 'P') &&
                    tabuleiro[i - 2][j + 2] == '-')
                {
                    printf("Você tem que jogar com a peça da posição %d %d\n\n", (8 - i),
                           j);
                    imprimirTabuleiro(tabuleiro);
                    ataque(tabuleiro, (8 - i), j + 2, i - 2, i, j, rodada);
                    tabuleiro[i][j] = '-';
                    tabuleiro[i - 1][j + 1] = '-';
                    return 1;
                }
                else if ((tabuleiro[i][j] == 'b' || tabuleiro[i][j] == 'B') &&
                         (tabuleiro[i - 1][j - 1] == 'p' ||
                          tabuleiro[i - 1][j - 1] == 'P') &&
                         tabuleiro[i - 2][j - 2] == '-')
                {
                    printf("Você tem que jogar com a peça da posição %d %d\n\n", (8 - i),
                           j);
                    imprimirTabuleiro(tabuleiro);
                    ataque(tabuleiro, (8 - i), j - 2, i - 2, i, j, rodada);
                    tabuleiro[i][j] = '-';
                    tabuleiro[i - 1][j - 1] = '-';
                    return 1;
                }
                else if (tabuleiro[i][j] == 'B' &&
                         (tabuleiro[i + 1][j + 1] == 'p' ||
                          tabuleiro[i + 1][j + 1] == 'P') &&
                         tabuleiro[i + 2][j + 2] == '-')
                {
                    printf("Você tem que jogar com a peça da posição %d %d\n\n", (8 - i),
                           j);
                    imprimirTabuleiro(tabuleiro);
                    ataque(tabuleiro, (8 - i), j + 2, i + 2, i, j, rodada);
                    tabuleiro[i][j] = '-';
                    tabuleiro[i + 1][j + 1] = '-';
                    return 1;
                }
                else if (tabuleiro[i][j] == 'B' &&
                         (tabuleiro[i + 1][j - 1] == 'p' ||
                          tabuleiro[i + 1][j - 1] == 'P') &&
                         tabuleiro[i + 2][j - 2] == '-')
                {
                    printf("Você tem que jogar com a peça da posição %d %d\n\n", (8 - i),
                           j);
                    imprimirTabuleiro(tabuleiro);
                    ataque(tabuleiro, (8 - i), j - 2, i + 2, i, j, rodada);
                    tabuleiro[i][j] = '-';
                    tabuleiro[i + 1][j - 1] = '-';
                    return 1;
                }
            }
        }
    }
    else if (rodada % 2 == 1)
    {
        printf("Vez das pretas\n");
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if ((tabuleiro[i][j] == 'p' || tabuleiro[i][j] == 'P') &&
                    (tabuleiro[i + 1][j + 1] == 'b' ||
                     tabuleiro[i + 1][j + 1] == 'B') &&
                    tabuleiro[i + 2][j + 2] == '-')
                {
                    printf("Você tem que jogar com a peça da posição %d %d\n\n", (8 - i),
                           j);
                    imprimirTabuleiro(tabuleiro);
                    ataque(tabuleiro, (8 - i), j + 2, i + 2, i, j, rodada);
                    tabuleiro[i][j] = '-';
                    tabuleiro[i + 1][j + 1] = '-';
                    return 1;
                }
                else if ((tabuleiro[i][j] == 'p' || tabuleiro[i][j] == 'P') &&
                         (tabuleiro[i + 1][j - 1] == 'b' ||
                          tabuleiro[i + 1][j - 1] == 'B') &&
                         tabuleiro[i + 2][j - 2] == '-')
                {
                    printf("Você tem que jogar com a peça da posição %d %d\n\n", (8 - i),
                           j);
                    imprimirTabuleiro(tabuleiro);
                    ataque(tabuleiro, (8 - i), j - 2, i + 2, i, j, rodada);
                    tabuleiro[i][j] = '-';
                    tabuleiro[i + 1][j - 1] = '-';
                    return 1;
                }
                else if (tabuleiro[i][j] == 'P' &&
                         (tabuleiro[i - 1][j + 1] == 'b' ||
                          tabuleiro[i - 1][j + 1] == 'B') &&
                         tabuleiro[i - 2][j + 2] == '-')
                {
                    printf("Você tem que jogar com a peça da posição %d %d\n\n", (8 - i),
                           j);
                    imprimirTabuleiro(tabuleiro);
                    ataque(tabuleiro, (8 - i), j + 2, i - 2, i, j, rodada);
                    tabuleiro[i][j] = '-';
                    tabuleiro[i - 1][j + 1] = '-';
                    return 1;
                }
                else if (tabuleiro[i][j] == 'P' &&
                         (tabuleiro[i - 1][j - 1] == 'b' ||
                          tabuleiro[i - 1][j - 1] == 'B') &&
                         tabuleiro[i - 2][j - 2] == '-')
                {
                    printf("Você tem que jogar com a peça da posição %d %d\n\n", (8 - i),
                           j);
                    imprimirTabuleiro(tabuleiro);
                    ataque(tabuleiro, (8 - i), j - 2, i + 2, i, j, rodada);
                    tabuleiro[i][j] = '-';
                    tabuleiro[i - 1][j - 1] = '-';
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(void)
{
    srand(time(NULL));

    int linha, coluna;
    int auxiliar;

    char tabuleiro[SIZE][SIZE];
    char nome1[50], nome2[50];
    char player1[] = "brancas", player2[] = "pretas";
    int acabou = 0;
    int rodada = 0;

    printf("Bem Vindo, insira os nomes dos jogadores:\n");
    scanf("%s", nome1);
    scanf("%s", nome2);
    printf("\n");
    if (rand() % 2 == 0)
    {
        printf("%s suas peças são as %s!\n", nome1, player1);
        printf("%s suas peças são as %s!\n\n", nome2, player2);
    }
    else
    {
        printf("%s suas peças são as %s!\n", nome1, player2);
        printf("%s suas peças são as %s!\n\n", nome2, player1);
    }

    inicializarTabuleiro(tabuleiro);

    while (!acabou)
    {
        if (quantidadePecas(tabuleiro))
        {
            printf("Deseja jogar novamente? (0 para sim, 1 para não)\n");
            scanf("%d", &auxiliar);
            if (auxiliar == 0)
            {
                inicializarTabuleiro(tabuleiro);
                imprimirTabuleiro(tabuleiro);
                rodada = 0;
            }
            else if (auxiliar == 1)
            {
                acabou = 1;
                break;
            }
        }
        if (ataqueObrigatorio(tabuleiro, rodada))
        {
            imprimirTabuleiro(tabuleiro);
            rodada++;
            continue;
        }

        dama(tabuleiro, rodada);
        imprimirTabuleiro(tabuleiro);
        rodada = jogadorRodada(rodada);
        escolhendoPeca(tabuleiro, rodada);
        rodada++;
    }

    return 0;
}