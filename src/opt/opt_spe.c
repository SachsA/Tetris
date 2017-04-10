/*
** opt_spe.c for tetris in /home/THOMAZ_C/PSU_2016_tetris/src/opt/
**
** Made by Corentin Thomazeau
** Login   <THOMAZ_C@epitech.net>
**
** Started on  Fri Mar 10 21:58:42 2017 Corentin Thomazeau
** Last update Thu Mar 16 18:26:31 2017 Corentin Thomazeau
*/

#include <stdlib.h>
#include "m_basics.h"

int	opt_spe_simple(int *it, char **av, char **opt, int check)
{
  if (it[0] + 1 >= it[1] || av[it[0] + 1][0] == '-')
    return (err_sdsip("Invalid argument uses"));
  opt[check] = my_dup(av[it[0] + 1]);
  if (opt[check] == 0)
    return (1);
  it[0] = it[0] + 1;
  return (0);
}

char	*opt_spe_divide(const char *const tested, int start, int end)
{
  int	len;
  char	*ret;

  len = -1;
  if (end == -1)
    {
      while (tested[start + ++len]);
    }
  else
    len = start - end;
  if ((ret = malloc(sizeof(char) * (len + 1))) == 0)
    return (0);
  len = 0;
  while ((end == -1 || len < end) && tested[start + len] != 0)
    {
      ret[len] = tested[start + len];
      len++;
    }
  ret[len] = 0;
  return (ret);
}

void	opt_spe_size(char **opt, const char *const tested, int cmp)
{
  int	more;

  more = 0;
  while (tested[cmp + more] != ',')
    more++;
  free(opt[10]);
  opt[9] = opt_spe_divide(tested, cmp, more);
  opt[10] = opt_spe_divide(tested, cmp + more + 1, -1);
  if (opt[10] == 0)
    free(opt[9]);
}
