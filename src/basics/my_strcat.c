/*
** my_strcat.c for my_strcat in /home/sachs_a/delivery/system_unix/PSU_2016_tetris/src/basics
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Wed Mar  1 20:25:26 2017 Alexandre Sachs
** Last update Tue Mar 14 19:27:03 2017 Alexandre Sachs
*/

#include <stdlib.h>

int	my_strlen(char *);

char    *my_strcat(char *dest, char *src)
{
  int   len;
  int   i;

  if (!dest)
    return (NULL);
  len = my_strlen(dest);
  i = 0;
  while (src && src[i])
    {
      dest[len + i] = src[i];
      i = i + 1;
    }
  dest[len + i] = '\0';
  return (dest);
}
