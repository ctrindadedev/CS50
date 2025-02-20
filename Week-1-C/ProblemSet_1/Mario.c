int main(int argc, char const *argv[])
{
    int tam, i,j;
    char sharp = '#';
    printf("Insira um tamanho entre 1 e 8:\n");
    scanf("%d", &tam);
    while (tam > 8 || tam < 1) 
    {
        printf("Tamanho incorreto, insira um tamanho novamente:\n");
        scanf("%d", &tam);
    }
    for ( i = 1; i <= tam; i++)
    {
        for (j = 0; j < i; j++)
        {
            printf("%c", sharp);
        }
        printf("\n");
    }   
    return 0;
}
