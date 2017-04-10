/*
** error.c for tetris in /home/THOMAZ_C/PSU_2016_tetris/src/basics/
**
** Made by Corentin Thomazeau
** Login   <THOMAZ_C@epitech.net>
**
** Started on  Tue Mar  7 16:58:35 2017 Corentin Thomazeau
** Last update Tue Mar  7 17:00:25 2017 Corentin Thomazeau
*/

#include <unistd.h>

int	err_sdsip(const char *str)
{
  int		i;

  i = -1;
  while (str[++i]);
  write(2, "Error - ", 8);
  write(2, str, i);
  write(2, "\n", 1);
  return (84);
}

void	*err_ndsip(const char *str)
{
  int		i;

  i = -1;
  while (str[++i]);
  write(2, "Error - ", 8);
  write(2, str, i);
  write(2, "\n", 1);
  return (NULL);
}
