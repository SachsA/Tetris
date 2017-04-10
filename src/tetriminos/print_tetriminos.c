/*
** print_tetriminos.c for print_tetriminos in /home/sachs_a/delivery/system_unix/PSU_2016_tetris/src/tetriminos
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Fri Mar  3 18:29:59 2017 Alexandre Sachs
** Last update Tue Mar 14 19:03:09 2017 Alexandre Sachs
*/

#include <stdlib.h>
#include "m_basics.h"
#include "my.h"

void		print_tetriminos(t_details_ttm *details)
{
  t_details_ttm	*tmp;

  tmp = details;
  my_printf("Tetriminos : %i\n", tmp->nb_ttm);
  while (tmp != NULL)
    {
      my_printf("Tetriminos : Name %s : ", tmp->name);
      if (tmp->width == 0)
	my_printf("Error\n");
      else
	{
	  my_printf("Size %d*%d : Color %d :\n", tmp->width,
		    tmp->height, tmp->color);
	  my_show_wordtab(tmp->forme, tmp->height);
	}
      tmp = tmp->next;
    }
}
