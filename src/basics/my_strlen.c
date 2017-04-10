/*
** my_strlen.c for my_strlen in /home/sachs_a/delivery/fonctions_utiles
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Mon Jan  9 15:12:43 2017 Alexandre Sachs
** Last update Wed Mar  1 00:03:52 2017 Alexandre Sachs
*/

#include <stdlib.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}
