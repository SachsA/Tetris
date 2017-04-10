/*
** rotation.c for tetris in /home/THOMAZ_C/PSU_2016_tetris/src/ncurses_ttm/
**
** Made by Corentin Thomazeau
** Login   <THOMAZ_C@epitech.net>
**
** Started on  Fri Mar 17 20:49:38 2017 Corentin Thomazeau
** Last update Sat Mar 18 18:48:31 2017 Corentin Thomazeau
*/

#include <stdlib.h>
#include "m_basics.h"
#include "game.h"

char	*rotation_copy_forme_line(t_details_ttm *ele, int line)
{
  char	*ret;
  int	i;

  if ((ret = malloc(sizeof(char) * (ele->height))) == 0)
    return (0);
  i = 0;
  while (i < ele->height)
    {
      ret[i] = ele->forme[ele->height - i - 1][line];
      i++;
    }
  return (ret);
}

char	**rotation_copy_forme(t_details_ttm *ele)
{
  char	**ret;
  int	i;

  if ((ret = malloc(sizeof(char *) * (ele->width))) == 0)
    return (0);
  i = 0;
  while (i < ele->width)
    {
      if ((ret[i] = rotation_copy_forme_line(ele, i)) == 0)
	return (0);
      i++;
    }
  return (ret);
}

void	rotation_free_forme(char **forme, int height)
{
  int	i;

  i = 0;
  while (i < height)
    {
      free(forme[i]);
      i++;
    }
  free(forme);
}

void	rotation_swap(char ***save_f, t_details_ttm *ele,
		      int *save, char **new)
{
  *save = ele->height;
  ele->height = ele->width;
  ele->width = *save;
  *save_f = ele->forme;
  ele->forme = new;
}

int	rotation(t_details_ttm *ele, char **map, char **opt)
{
  char	**new;
  int	save;
  int	futur[2];
  char	**save_f;

  futur[0] = ele->posx;
  futur[1] = ele->posy;
  move_print(ele, map, ' ');
  if ((new = rotation_copy_forme(ele)) == 0)
    return (1);
  rotation_swap(&save_f, ele, &save, new);
  if (move_impact(futur, map, ele, opt))
    {
      ele->width = ele->height;
      ele->height = save;
      rotation_free_forme(ele->forme, ele->height);
      ele->forme = save_f;
    }
  else
    {
      rotation_free_forme(save_f, ele->width);
      ele->rota++;
    }
  move_print(ele, map, ele->color + 48);
  return (0);
}
