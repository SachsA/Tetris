/*
** tetris.c for tetris in /home/sachs_a/delivery/system_unix/PSU_2016_tetris/src/ncurses_ttm
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Sat Mar 11 14:31:33 2017 Alexandre Sachs
** Last update Sun Mar 19 11:26:31 2017 Corentin Thomazeau
*/

#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include "m_basics.h"
#include "game.h"

char		**malloc_map(int height, int width)
{
  int		i;
  char		**map;

  i = 0;
  if ((map = malloc(sizeof(char *) * height)) == NULL)
    return (NULL);
  while (i < height)
    {
      if ((map[i] = malloc(sizeof(char) * (width + 1))) == NULL)
	return (NULL);
      my_memset(map[i], ' ', width);
      map[i][width] = 0;
      i++;
    }
  return (map);
}

void		print_map(char **map, int height, int width)
{
  int		i;
  int		j;
  char		get;

  i = 0;
  while (i < height)
    {
      j = 0;
      while (j < width)
	{
	  get = map[i][j];
	  if (get != ' ')
	    attron(COLOR_PAIR(get - 40));
	  mvprintw(LINES / 2 - 7 + i, COLS / 2 - 9 + j, " ");
	  if (get != ' ')
	    attroff(COLOR_PAIR(get - 40));
	  j++;
	}
      i++;
    }
  refresh();
}

int		tetris_boucle(char **opt, t_details_ttm *ele, char **map,
			      float tim)
{
  int		a;
  int		game;
  int		size[2];
  int		pause;

  a = 0;
  game = 1;
  size[0] = my_getnbr(opt[9]);
  size[1] = my_getnbr(opt[10]);
  pause = -1;
  while (game == 1)
    {
      resize_window(ele, 0, 0);
      game = tetris_test_in(opt, ele, map, &pause);
      if (pause == -1)
	{
	  if (a++ >= tim)
	    {
	      game = move_core(ele, 2, map, opt);
	      a = 0;
	    }
	  print_map(map, size[0], size[1]);
	}
    }
  return (game);
}

int		tetris_game(float tim, char **opt, char **map,
			    t_details_ttm *ele)
{
  static int	score = 0;
  static int	lev = 0;
  int		game;
  int		size[2];

  size[0] = ele->posx;
  size[1] = ele->posy;
  score_box(score);
  resize_window(ele, lev, score);
  if (move_impact(size, map, ele, opt))
    {
      game_over();
      return (2);
    }
  size[0] = my_getnbr(opt[9]);
  size[1] = my_getnbr(opt[10]);
  game = tetris_boucle(opt, ele, map, tim);
  map = suppr_line(map, size, &score);
  if (score >= lev * 2 + 1)
    {
      lev += 1;
      game += 1;
    }
  print_map(map, size[0], size[1]);
  return (game);
}

int		tetris(t_details_ttm *details, char **opt)
{
  char			**map;
  int			level;
  int			get;
  float		tim;
  t_details_ttm	*next[2];

  srand(12742);
  level = my_getnbr(opt[0]);
  if ((map = malloc_map(my_getnbr(opt[9]), my_getnbr(opt[10]))) == NULL)
    return (84);
  get = 0;
  next[0] = new_rd_ttm(details);
  while (get == 0 || get == 1)
    {
      level += get;
      tim = 10 - 0.5 * level;
      next[1] = next[0];
      next[0] = new_rd_ttm(details);
      game_page(next[0], level, 0);
      get = tetris_game(tim, opt, map, new_element_spawn(next[1],
							 my_getnbr(opt[10])));
    }
  return (get);
}
