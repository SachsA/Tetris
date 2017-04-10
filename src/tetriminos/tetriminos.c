/*
** tetriminos.c for tetriminos in /home/sachs_a/delivery/system_unix/PSU_2016_tetris/src/tetriminos
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Fri Mar  3 11:06:11 2017 Alexandre Sachs
** Last update Fri Mar 17 22:38:22 2017 Alexandre Sachs
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include "m_basics.h"
#include "my.h"

int			revalphasort(const struct dirent **a, const struct dirent **b)
{
  int			get;

  get = alphasort(a, b);
  get = get * -1;
  return (get);
}

int			find_tetriminos_list(t_details_ttm **details, int *nb,
					     t_details_ttm **last, struct dirent *entry)
{
  if (entry->d_type == DT_REG && check_name(entry->d_name) == 0)
    {
      if (((*details) = alloc_new(entry->d_name)) == NULL)
	return (1);
      (*details)->path = my_dup(entry->d_name);
      if (((*details) = check_tetriminos(*details)) == NULL)
	return (1);
      (*details)->next = *last;
      *last = *details;
      *nb = *nb + 1;
    }
  return (0);
}

t_details_ttm		*check_size(t_details_ttm *last, char **opt)
{
  int			size1;
  int			size2;
  t_details_ttm		*tmp;

  tmp = last;
  size1 = my_getnbr(opt[9]);
  size2 = my_getnbr(opt[10]);
  while (tmp != NULL)
    {
      if ((tmp->width > size2) || (tmp->height > size1) ||
	  (tmp->width > size1) || (tmp->height > size2))
	tmp->width = 0;
      tmp = tmp->next;
    }
  return (last);
}

t_details_ttm		*find_tetriminos(char **opt)
{
  int			i;
  int			max;
  int			nb;
  struct dirent		**entry;
  t_details_ttm		*details;
  t_details_ttm		*last;

  i = -1;
  last = NULL;
  details = NULL;
  nb = 0;
  if (chdir("./tetriminos") == -1)
    return (NULL);
  max = scandir(".", &entry, NULL, revalphasort);
  while (++i < max)
    {
      if (find_tetriminos_list(&details, &nb, &last, entry[i]) == 1)
	return (NULL);
    }
  free_dirent(entry, max);
  if (details == NULL)
    return (err_ndsip("No Valid File"));
  last->nb_ttm = nb;
  return (check_size(last, opt));
}
