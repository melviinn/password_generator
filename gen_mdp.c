#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

void    putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int main(void)
{
    int             len_mdp;
    int             choice;
    int             i;
    int             random;
    char            *mdp;
    char            *all_possibilities;
    FILE            *file;

    len_mdp = 0;
    choice = 0;
    i = 0;
    random = 0;
    all_possibilities = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+\0";
    file = fopen("password.txt", "w");
    srand(time(NULL));

    putstr("\nPassword Generator...\n\n\n");
    putstr("Choose the length of your password: ");
    scanf("%i", &len_mdp);
    if (len_mdp > 50)
    {
        putstr("\nERROR: Password too long...\n");
        return (0);
    }
    mdp = malloc(sizeof(char) * (len_mdp + 1));
    if (!mdp)
        free(mdp);
    while (i < len_mdp)
    {
        random = rand() % (strlen(all_possibilities));
        mdp[i] = all_possibilities[random];
        i++;
    }
    mdp[len_mdp] = '\0';

    putstr("\n\n1. Display the password\n2. Write the password in a file\n\n");
    scanf("%i", &choice);
    if (choice == 1)
    {
        putstr("Your password is: ");
        putstr(mdp);
        putstr("\n");
    }
    else if (choice == 2)
    {
        putstr("Your password is available in the file: password.txt\n");
        fputs(mdp, file);
        fclose(file);
    }
    else
        putstr("Wrong choice...");

    free(mdp);
    return (0);
}