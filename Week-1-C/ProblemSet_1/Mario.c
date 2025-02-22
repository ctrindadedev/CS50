int main(int argc, char const *argv[])
{
    int tam, i,j;
    char sharp = '#';
    printf("Height: ");
    scanf("%d", &tam);
    while (tam > 8 || tam < 1) 
    {
        printf("Type a height between 1 and 8\n");
        printf("Height: ");
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
