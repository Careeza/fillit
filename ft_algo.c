
#include <stdio.h>
#include <stdlib.h>
#include "fillit.h"

char    *ft_tab(int c, char *tab)
{
    int i;

    if (!tab)
        free (tab);   
    if (!(tab = (char*)malloc(sizeof(char) * (c * (c + 1) + 1))))
        return (NULL);
    i = 0;
    while (i < (c * (c + 1)))
    {
        if ((i + 1) % (c + 1) == 0)
            tab[i] = '\n';
        else
            tab[i] = '.';
        i++;
    }
    tab[i] = '\0';
    printf("%s\n", tab);
    return (tab);
}

char    *ft_algo(char **tetri, int c, char *tab)
{
    tab = ft_tab(c, tab);
    if (ft_blabla(tetri, tab, c) == -1)
        ft_algo(**tetri, c + 1)
    return (tab);
}

int main(void)
{
    char **tetri;

    ft_algo(tetri, 0);
    return (0);
}