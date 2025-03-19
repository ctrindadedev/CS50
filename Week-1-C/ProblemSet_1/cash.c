#include <stdio.h>

int main()
{
    int coins = 0;
    // Prompt the user for change owed, in cents
    int change_owed = 113;

    if (change_owed <= 0)
    {
        printf("Não terá troco!\n");
        return 0;
    }

    // Calculate how many quarters you should give customer
    while (change_owed >= 25)
    {
        coins++;
        // Subtract the value of those quarters from cents
        change_owed = change_owed - 25;
    }

    // Calculate how many dimes you should give customer
    while (change_owed >= 10)
    {
        coins++;
        // Subtract the value of those dimes from cents
        change_owed = change_owed - 10;
    }

    // Calculate how many nickels you should give customer
    while (change_owed >= 5)
    {
        coins++;
        // Subtract the value of those nickels from cents
        change_owed = change_owed - 5;
    }

    // Calculate how many pennies you should give customer
    while (change_owed >= 1)
    {
        coins++;
        // Subtract the value of those pennies from cents
        change_owed = change_owed - 1;
    }

    // Print total coins
    printf("%d\n", coins);

    return 0;
}
