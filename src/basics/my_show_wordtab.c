/*
** my_show_wordtab.c for my_show_wordtab in /home/sachs_a/delivery/CPool_Day08/task03
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Wed Oct 12 09:23:05 2016 Alexandre Sachs
** Last update Tue Mar  7 12:14:17 2017 Corentin Thomazeau
*/

#include "m_basics.h"
#include <stdio.h>

int	my_show_wordtab(char **tab, int height)
{
  int	i;

  i = 0;
  while (i < height)
    {
      my_printf("%s\n", tab[i]);
      i = i + 1;
    }
  return (0);
}
