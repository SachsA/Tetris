/*
** suppr_line.c for suppr_line in /home/sachs_a/delivery/system_unix/PSU_2016_tetris/src/ncurses_ttm
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Sat Mar 18 18:08:52 2017 Alexandre Sachs
** Last update Sun Mar 19 10:39:48 2017 Corentin Thomazeau
*/

#include "game.h"

char	**go_down(char **map, int *size, int i, int *score)
{
  int	j;

  while (i > 0)
    {
      j = -1;
      while (++j < size[1])
	{
	  if (i - 1 < 0)
	    map[i][j] = ' ';
	  else
	    map[i][j] = map[i - 1][j];
	}
      i--;
    }
  return (suppr_line(map, size, score));
}

char	**suppr_line(char **map, int *size, int *score)
{
  int	i;
  int	j;

  i = -1;
  while (++i < size[0])
    {
      j = -1;
      while (++j < size[1] && i < size[0])
	{
	  if (map[i][j] == ' ')
	    {
	      i++;
	      j = -1;
	    }
	}
      if (j == size[1])
	{
	  go_down(map, size, i, score);
	  *score = *score + 1;
	}
    }
  return (map);
}
