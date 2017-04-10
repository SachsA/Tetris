/*
** new_element.c for tetris in /home/THOMAZ_C/PSU_2016_tetris/src/ncurses_ttm/
**
** Made by Corentin Thomazeau
** Login   <THOMAZ_C@epitech.net>
**
** Started on  Sat Mar 11 16:59:36 2017 Corentin Thomazeau
** Last update Sun Mar 19 11:25:55 2017 Corentin Thomazeau
*/

#include <stdlib.h>
#include <unistd.h>
#include "m_basics.h"
#include "game.h"

t_details_ttm	*new_element_spawn(t_details_ttm *details, int width)
{
  details->posx = (width - details->width) / 2;
  details->posy = 0;
  details->rota = 0;
  return (details);
}

int		tetris_test_in(char **const opt, t_details_ttm *ele,
			       char **map, int *pause)
{
  char		buff[16];

  my_memset(buff, 0, 16);
  read(0, buff, 16);
  if (buff[0] == '\033' && buff[1] == 91)
    buff[1] = 79;
  if (my_strcmp(opt[5], buff) == 0)
    return (4);
  if (my_strcmp(opt[6], buff) == 0)
    *pause = *pause * -1;
  if (*pause == -1)
    {
      if (my_strcmp(opt[1], buff) == 0)
	move_core(ele, -1, map, opt);
      if (my_strcmp(opt[2], buff) == 0)
	move_core(ele, 1, map, opt);
      if (my_strcmp(opt[3], buff) == 0)
	rotation(ele, map, opt);
    }
  return (1);
}

t_details_ttm		*new_rd_ttm(t_details_ttm *ele)
{
  int			i;
  int			slctd;
  t_details_ttm	*this;

  i = 0;
  this = ele;
  slctd = rand() % ele->nb_ttm;
  while (i < slctd && ele->next != 0)
    {
      this = this->next;
      i++;
    }
  return (this);
}
