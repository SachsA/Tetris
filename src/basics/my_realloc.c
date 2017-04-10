/*
** my_realloc.c for my_realloc in /home/sachs_a/delivery/system_unix/PSU_2016_tetris
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Wed Mar  1 19:45:56 2017 Alexandre Sachs
** Last update Wed Mar  1 19:51:57 2017 Alexandre Sachs
*/

#include "my.h"
#include <stdlib.h>

char	*my_realloc(char *str, int size)
{
  int	i;
  char	*new_str;

  i = 0;
  if ((new_str = malloc(sizeof(*new_str) * (my_strlen(str) + size))) == NULL)
    return (NULL);
  while (str[i])
    {
      new_str[i] = str[i];
      i++;
    }
  free(str);
  return (new_str);
}
