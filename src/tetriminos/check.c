/*
** check.c for check in /home/sachs_a/delivery/system_unix/PSU_2016_tetris/src/tetriminos
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Fri Mar  3 11:27:39 2017 Alexandre Sachs
** Last update Thu Mar 16 17:49:26 2017 Corentin Thomazeau
*/

#include "m_basics.h"
#include "my.h"

int		check_name(char *path)
{
  int		i;
  int		size;
  const char	cmp[11] = ".tetrimino";

  i = 0;
  size = my_strlen(path);
  while (i <= size && i < 11)
    {
      if (cmp[10 - i] != path[size - i])
	return (84);
      i++;
    }
  if (i == 11)
    return (0);
  return (84);
}
