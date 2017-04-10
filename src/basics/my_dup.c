/*
** my_dup.c for tetris in /home/THOMAZ_C/PSU_2016_tetris/src/basics/
**
** Made by Corentin Thomazeau
** Login   <THOMAZ_C@epitech.net>
**
** Started on  Tue Feb 28 22:41:59 2017 Corentin Thomazeau
** Last update Thu Mar  2 16:05:23 2017 Corentin Thomazeau
*/

#include <stdlib.h>

char	*my_dup(const char *const str)
{
  char	*ret;
  int	i;

  i = 0;
  while (str[i] != 0)
    i = i + 1;
  if ((ret = malloc(sizeof(char) * (i + 1))) == 0)
    return (0);
  i = 0;
  while (str[i] != 0)
    {
      ret[i] = str[i];
      i = i + 1;
    }
  ret[i] = 0;
  return (ret);
}
