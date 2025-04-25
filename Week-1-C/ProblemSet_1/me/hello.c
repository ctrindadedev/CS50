#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char *name[40];
    printf("What's your name? ");
    scanf("%s", &name);
    printf("Hello %s \n", name);
    return 0;
}
