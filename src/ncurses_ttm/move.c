/*
** move.c for tetris in /home/THOMAZ_C/PSU_2016_tetris/src/ncurses_ttm/
**
** Made by Corentin Thomazeau
** Login   <THOMAZ_C@epitech.net>
**
** Started on  Sat Mar 11 17:14:07 2017 Corentin Thomazeau
** Last update Sat Mar 18 18:26:41 2017 Corentin Thomazeau
*/

#include "m_basics.h"
#include "game.h"

void	move_print(t_details_ttm *ele, char **map, char c)
{
  int	it[2];

  it[0] = 0;
  while (it[0] < ele->height)
    {
      it[1] = 0;
      while (it[1] < ele->width)
	{
	  if (ele->forme[it[0]][it[1]] == '*')
	    map[ele->posy + it[0]][ele->posx + it[1]] = c;
	  it[1] += 1;
	}
      it[0] += 1;
    }
}

int	move_impact_scene(int *futur, char **map, t_details_ttm *ele, int hei)
{
  int	it[2];

  it[0] = -1;
  while (++it[0] < ele->height)
    {
      it[1] = -1;
      while (++it[1] < ele->width)
	{
	  if (ele->forme[it[0]][it[1]] == '*' && it[0] + futur[1] <= hei &&
	      map[it[0] + futur[1]][futur[0] + it[1]] != ' ')
	    return (1);
	}
    }
  return (0);
}

int	move_impact(int *futur, char **map, t_details_ttm *ele,
		    char **opt)
{
  int	hei;

  hei = my_getnbr(opt[9]);
  if (futur[0] < 0 || futur[0] + ele->width > my_getnbr(opt[10]))
    return (1);
  if (futur[1] < 0 || futur[1] + ele->height > hei)
    return (1);
  return (move_impact_scene(futur, map, ele, hei));
}

int	move_core(t_details_ttm *ele, char direc, char **map, char **opt)
{
  int	futur[2];
  int	get;

  move_print(ele, map, ' ');
  futur[0] = ele->posx + direc % 2;
  futur[1] = ele->posy + direc / 2;
  get = move_impact(futur, map, ele, opt);
  if (get == 0)
    {
      ele->posx = futur[0];
      ele->posy = futur[1];
    }
  move_print(ele, map, ele->color + 48);
  return (!get);
}
