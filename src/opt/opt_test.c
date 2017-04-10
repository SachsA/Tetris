/*
** opt_test.c for tetris in /home/THOMAZ_C/PSU_2016_tetris/src/opt/
**
** Made by Corentin Thomazeau
** Login   <THOMAZ_C@epitech.net>
**
** Started on  Wed Mar  1 18:51:00 2017 Corentin Thomazeau
** Last update Fri Mar 10 22:58:41 2017 Corentin Thomazeau
*/

#include <stdlib.h>
#include "m_basics.h"

void	free_opt_test(char ***test)
{
  int	i;

  i = 0;
  while (i < 9)
    {
      free(test[0][i]);
      free(test[1][i]);
      i++;
    }
  free(test[1][i]);
  free(test[0]);
  free(test[1]);
  free(test);
}

char	**opt_test_first()
{
  char	**ret;

  if ((ret = malloc(sizeof(char*) * (9))) == 0)
    return (0);
  ret[0] = my_dup("l");
  ret[1] = my_dup("kl");
  ret[2] = my_dup("kr");
  ret[3] = my_dup("kt");
  ret[4] = my_dup("kd");
  ret[5] = my_dup("kq");
  ret[6] = my_dup("kp");
  ret[7] = my_dup("w");
  ret[8] = my_dup("d");
  return (ret);
}

char	**opt_test_second()
{
  char	**ret;

  if ((ret = malloc(sizeof(char*) * (10))) == 0)
    return (0);
  ret[0] = my_dup("level");
  ret[1] = my_dup("key-left");
  ret[2] = my_dup("key-right");
  ret[3] = my_dup("key-turn");
  ret[4] = my_dup("key-drop");
  ret[5] = my_dup("key-quit");
  ret[6] = my_dup("key-pause");
  ret[7] = my_dup("without-next");
  ret[8] = my_dup("debug");
  ret[9] = my_dup("map-size");
  return (ret);
}

int	opt_test_alloc(char ***ret)
{
  int	i;

  if (ret[0] == 0 || ret[1] == 0)
    return (1);
  i = -1;
  while (++i < 9)
    {
      if (ret[0][i] == 0 || ret[1][i] == 0)
	return (1);
    }
  if (ret[1][i] == 0)
    return (1);
  return (0);
}

char	***opt_test_get()
{
  char	***ret;

  if ((ret = malloc(sizeof(char**) * (2))) == 0)
    return (0);
  ret[0] = opt_test_first();
  ret[1] = opt_test_second();
  if (opt_test_alloc(ret))
    return (0);
  return (ret);
}
