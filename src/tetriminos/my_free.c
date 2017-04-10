/*
** my_free.c for my_free in /home/sachs_a/delivery/system_unix/PSU_2016_tetris/src/tetriminos
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Fri Mar  3 18:10:52 2017 Alexandre Sachs
** Last update Thu Mar 16 22:52:40 2017 Alexandre Sachs
*/

#include <stdlib.h>
#include <dirent.h>
#include "my.h"

void		free_dirent(struct dirent **entry, int lignes)
{
  int		i;

  i = 0;
  while (i < lignes)
    {
      free(entry[i]);
      i++;
    }
  free(entry);
}

void		free_tetra_list(t_details_ttm *list)
{
  int		i;

  if (list->next != 0)
    free_tetra_list(list->next);
  i = 0;
  while (i < list->height)
    {
      free(list->forme[i]);
      i++;
    }
  free(list->forme);
  free(list->name);
  free(list->path);
  free(list);
}
