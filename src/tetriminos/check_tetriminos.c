/*
** check_tetriminos.c for check_tetriminos in /home/sachs_a/delivery/system_unix/PSU_2016_tetris/src/tetriminos
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Fri Mar  3 15:51:36 2017 Alexandre Sachs
** Last update Fri Mar 17 23:52:45 2017 Alexandre Sachs
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "m_basics.h"
#include "my.h"

int		fill_params_tetris(t_details_ttm *details, char *str)
{
  char		**tab;

  if ((tab = my_str_to_wordtab(str, ' ')) == 0)
    return (84);
  if (tablen(tab) != 3)
    return (details->width = 0, 0);
  if (my_str_isnum(tab[0]) == 0 ||
      my_str_isnum(tab[1]) == 0 || my_str_isnum(tab[2]) == 0)
    return (details->width = 0, 0);
  if (((details->width = my_getnbr(tab[0])) < 0)
      || ((details->height = my_getnbr(tab[1])) < 0))
    return (details->width = 0, 0);
  if ((details->color = my_getnbr(tab[2])) < 0
      || (details->color = my_getnbr(tab[2])) > 7)
    return (details->width = 0, 0);
  if ((details->forme = malloc(sizeof(char *) * details->height)) == NULL)
    return (84);
  return (0);
}

t_details_ttm	*check_tetriminos(t_details_ttm *details)
{
  int		fd;
  char		*str;

  if ((fd = open(details->path, O_RDONLY)) < 0)
    return (details);
  if ((str = get_next_line(fd)) == NULL)
    return (details);
  if (fill_params_tetris(details, str) != 0)
    return (NULL);
  if (fill_forme(details, fd) == NULL)
    return (NULL);
  close(fd);
  return (details);
}
