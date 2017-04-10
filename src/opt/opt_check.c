/*
** opt_check.c for tetris in /home/THOMAZ_C/PSU_2016_tetris/src/opt/
**
** Made by Corentin Thomazeau
** Login   <THOMAZ_C@epitech.net>
**
** Started on  Tue Mar  7 17:14:26 2017 Corentin Thomazeau
** Last update Mon Mar 13 18:07:10 2017 Corentin Thomazeau
*/

#include <stdlib.h>
#include "m_basics.h"
#include "m_opt.h"

#include <stdio.h>

void	opt_free_opt(char **opt)
{
  int	i;

  i = 0;
  while (i < 11)
    {
      free(opt[i]);
      i++;
    }
  free(opt);
}

int	opt_check_number(char *opt)
{
  int	i;

  i = 0;
  while (opt[i])
    {
      if (opt[i] < 48 || opt[i] > 57)
	return (1);
      i++;
    }
  return (0);
}

char	**opt_check_core(char **opt)
{
  int	get;

  get = 0;
  get += opt_check_number(opt[0]);
  get += opt_check_number(opt[8]);
  get += opt_check_number(opt[9]);
  get += opt_check_number(opt[10]);
  if (get > 0)
    {
      opt_free_opt(opt);
      return (err_ndsip("Invalid argument type"));
    }
  return (opt);
}
