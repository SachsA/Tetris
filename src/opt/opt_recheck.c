/*
** opt_recheck.c for tetris in /home/THOMAZ_C/PSU_2016_tetris/src/opt/
**
** Made by Corentin Thomazeau
** Login   <THOMAZ_C@epitech.net>
**
** Started on  Mon Mar 13 16:08:02 2017 Corentin Thomazeau
** Last update Sun Mar 19 15:41:32 2017 Corentin Thomazeau
*/

#include "m_basics.h"

int	opt_recheck_cmp(const char *first, const char *second)
{
  int	i;
  int	a;

  i = 0;
  a = -1;
  while (first[++a] == '-');
  while (first[i + a] == second[i] && second[i] != 0)
    i++;
  if (a == 1 && first[i + a] == second[i] && first[i + a] == 0)
    return (0);
  if (a == 2 && first[i + a] == '=' && second[i] == 0)
    return (0);
  return (1);
}

int	opt_recheck_seek(char *tested, char ***tester)
{
  int	i;

  i = -1;
  if (tested[1] == '-')
    {
      while (++i < 10)
	{
	  if (opt_recheck_cmp(tested, tester[1][i]) == 0)
	    return (i);
	}
    }
  else
    {
      while (++i < 9)
	{
	  if (opt_recheck_cmp(tested, tester[0][i]) == 0)
	    return (i);
	}
    }
  return (0);
}

int	opt_recheck_core(int ac, char **av, char ***test)
{
  int	i;
  char	opt[11];
  int	get;

  i = 1;
  my_memset(opt, 0, 11);
  while (i < ac)
    {
      if (av[i][0] == '-')
	{
	  get = opt_recheck_seek(av[i], test);
	  if (get != 8 && opt[get] == 1)
	    return (1);
	  opt[get] = 1;
	}
      i++;
    }
  return (0);
}

void	opt_recheck_uncaps(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0 && str[i] != '\033')
    {
      if (str[i] >= 65 && str[i] <= 90)
	str[i] = str[i] + 32;
      i++;
    }
}

int	opt_recheck_keys(char **opt)
{
  int	i;
  int	j;

  i = 1;
  while (i < 6)
    {
      j = i + 1;
      while (j < 7)
	{
	  if (my_strcmp(opt[i], opt[j]) == 0)
	    return (1);
	  j++;
	}
      i++;
    }
  if (my_getnbr(opt[0]) <= 0 || my_getnbr(opt[9]) <= 0
      || my_getnbr(opt[10]) <= 0)
    return (2);
  return (0);
}
