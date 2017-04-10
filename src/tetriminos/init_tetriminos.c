/*
** init_tetriminos.c for init_tetriminos in /home/sachs_a/delivery/system_unix/PSU_2016_tetris
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Fri Mar  3 10:58:08 2017 Alexandre Sachs
** Last update Thu Mar 16 23:41:02 2017 Alexandre Sachs
*/

#include <stdlib.h>
#include "m_basics.h"
#include "my.h"

char		*alloc_name(char *name)
{
  int		i;
  int		size;
  char		*new;

  i = 0;
  size = my_strlen(name);
  if ((new = malloc(sizeof(char) * (size - 9))) == NULL)
    return (NULL);
  while ((size - 11 - i) >= 0)
    {
      new[i] = name[i];
      i++;
    }
  new[size - 10] = 0;
  return (new);
}

t_details_ttm	*alloc_new(char *name)
{
  t_details_ttm	*details;

  if ((details = malloc(sizeof(t_details_ttm))) == NULL)
    return (NULL);
  if ((details->name = alloc_name(name)) == NULL)
    return (NULL);
  details->forme = NULL;
  details->path = NULL;
  details->width = 0;
  details->height = 0;
  details->color = 0;
  return (details);
}
