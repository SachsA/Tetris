/*
** supp_error.c for supp_error in /home/sachs_a/delivery/system_unix/PSU_2016_tetris/src/tetriminos
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Mon Mar 13 11:02:12 2017 Alexandre Sachs
** Last update Fri Mar 17 23:56:55 2017 Alexandre Sachs
*/

#include <unistd.h>
#include <stdlib.h>
#include "m_basics.h"
#include "my.h"

t_details_ttm	*free_retur_next(t_details_ttm *details)
{
  int		i;
  t_details_ttm	*save;

  i = -1;
  save = details->next;
  while (++i < details->height)
    free(details->forme[i]);
  free(details->forme);
  free(details->name);
  free(details->path);
  return (save);
}

void		parcour(t_details_ttm *tmp, int *nb)
{
  t_details_ttm *tmp2;

  tmp2 = tmp->next->next;
  free(tmp->next);
  tmp->next = tmp2;
  *nb -= 1;
}

int		supp_error(t_details_ttm **details)
{
  int		nb;
  t_details_ttm *tmp;

  nb = (*details)->nb_ttm;
  while (*details != NULL && ((*details)->width <= 0))
    {
      nb -= 1;
      (*details) = (*details)->next;
    }
  if ((*details) == NULL)
    return (1);
  tmp = *details;
  while (tmp != NULL && tmp->next != NULL)
    {
      if (tmp->next->width <= 0)
	parcour(tmp, &nb);
      else
	tmp = tmp->next;
    }
  (*details)->nb_ttm = nb;
  return (0);
}
