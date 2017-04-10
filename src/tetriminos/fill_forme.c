/*
** fill_forme.c for fill_forme in /home/sachs_a/delivery/system_unix/PSU_2016_tetris/src/tetriminos
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Fri Mar  3 16:59:52 2017 Alexandre Sachs
** Last update Sun Mar 19 10:19:20 2017 Corentin Thomazeau
*/

#include <stdlib.h>
#include "get_next_line.h"
#include "m_basics.h"
#include "my.h"

t_details_ttm	*is_there_stars(t_details_ttm *details, int j)
{
  int		i;

  i = -1;
  if (details->forme[j] == NULL)
    {
      details->width = 0;
      return (NULL);
    }
  while (details->forme[j][++i] != '\0' && details->forme[j][i] != '\n')
    if ((details->forme[j][i] != '*') && (details->forme[j][i] != ' '))
      return (details->width = 0, details);
  i = -1;
  while (details->forme[j][++i] != '\0' && details->forme[j][i] != '\n')
    if (details->forme[j][i] == '*')
      return (details);
  details->width = 0;
  return (NULL);
}

char		*epur_end_str(char *str, int *lengh)
{
  int		i;
  int		size;
  char		*ret;

  i = 0;
  size = my_strlen(str);
  while (i < size - 1 && str[size - 1 - i] != '*')
    i++;
  *lengh = size - i;
  if (i == 0)
    return (str);
  if ((ret = malloc(sizeof(char) * (size - i + 2))) == NULL)
    return (NULL);
  my_memset(ret, 0, size - i + 2);
  size = -1;
  while (++size < *lengh)
    ret[size] = str[size];
  ret[size] = '\0';
  free(str);
  return (ret);
}

t_details_ttm	*fill_forme(t_details_ttm *details, int fd)
{
  int		i;
  int		size;
  int		check;
  char		*str;

  check = 0;
  if (details->width <= 0)
    return (details);
  i = 0;
  while ((str = get_next_line(fd)) != NULL && i < details->height)
    {
      if ((details->forme[i] = epur_end_str(str, &size)) == NULL)
	return (NULL);
      if (my_strlen(details->forme[i]) > details->width)
	return (details->width = 0, details);
      if (is_there_stars(details, i) == NULL)
	return (details);
      if (check == 0 && size == details->width)
	check = 1;
      i++;
    }
  if (check == 0 || i != details->height)
    details->width = 0;
  return (details);
}
