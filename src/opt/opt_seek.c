/*
** opt_seek.c for tetris in /home/THOMAZ_C/PSU_2016_tetris/src/opt/
**
** Made by Corentin Thomazeau
** Login   <THOMAZ_C@epitech.net>
**
** Started on  Wed Mar  1 19:56:07 2017 Corentin Thomazeau
** Last update Mon Mar 13 16:53:31 2017 Corentin Thomazeau
*/

#include <stdlib.h>
#include "m_basics.h"
#include "m_opt.h"

char	*opt_seek_value(const char *const str, const int start)
{
  int	i;
  char	*ret;

  i = 0;
  while (str[start + i])
    i = i + 1;
  if (i == 0)
    return (err_ndsip("Null argument value"));
  if ((ret = malloc(sizeof(char) * (i + 1))) == 0)
    return (err_ndsip("Memory allocation failed"));
  i = 0;
  while (str[start + i])
    {
      ret[i] = str[start + i];
      i = i + 1;
    }
  ret[i] = 0;
  return (ret);
}

int	opt_cmp(const char *const first, const char *const second,
		const int type)
{
  int	i;

  i = 0;
  while (first[i + type] != '\0' && second[i] != '\0' &&
	 first[i + type] == second[i])
    i = i + 1;
  if (type == 2 && first[i + type - 1] != '=' && first[i + type] == second[i]
      && first[i + type] == 0)
    return (0);
  if (type == 2 && first[i + type] == '=' && second[i] == 0)
    return (i + 3);
  if (type == 1 && first[i + type] == second[i])
    return (i);
  return (-1);
}

int	opt_seek_double(const char *const tested, char **tester, char **opt)
{
  int	i;
  int	cmp;

  i = 0;
  while (i < 10 && (cmp = opt_cmp(tested, tester[i], 2)) == -1)
    i = i + 1;
  if (i == 10)
    return (-1);
  free(opt[i]);
  if (cmp == 0)
    {
      if (i == 8 || i == 9)
	opt[i] = my_dup("1");
      else
	return (-1);
    }
  else if (i == 9)
    opt_spe_size(opt, tested, cmp);
  else
    opt[i] = opt_seek_value(tested, cmp);
  if (opt[i] == 0)
    return (-1);
  return (0);
}

int	opt_seek_simple(const char *const tested, char **tester)
{
  int	i;

  i = 0;
  while (i < 9 && opt_cmp(tested, tester[i], 1) == -1)
    i++;
  if (i >= 9)
    return (-1);
  return (i);
}

int	opt_seek(int *it, char **av, char **opt, char ***test)
{
  int	check;

  if (my_strcmp(av[it[0]], "-h") == 0 || my_strcmp(av[it[0]], "--help") == 0)
    return (1);
  if (av[it[0]][1] != '-')
    {
      check = opt_seek_simple(av[it[0]], test[0]);
      if (check == -1)
	return (err_sdsip("Unknown argument"));
      free(opt[check]);
      if (check != 8 && check != 7)
	{
	  if (opt_spe_simple(it, av, opt, check) == 84)
	    return (84);
	}
      else
	opt[check] = my_dup("1");
      if (opt[check] == 0)
	return (err_sdsip("Memory allocation failed"));
    }
  else
    if ((check = opt_seek_double(av[it[0]], test[1], opt)) == -1)
	return (err_sdsip("Unknown argument"));
  return (0);
}
