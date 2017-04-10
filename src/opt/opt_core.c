/*
** opt_core.c for tetris in /home/THOMAZ_C/PSU_2016_tetris/src/opt/
**
** Made by Corentin Thomazeau
** Login   <THOMAZ_C@epitech.net>
**
** Started on  Tue Feb 28 21:15:41 2017 Corentin Thomazeau
** Last update Thu Mar 16 23:22:22 2017 Corentin Thomazeau
*/

#include <ncurses.h>
#include <dirent.h>
#include <stdlib.h>
#include <term.h>
#include "m_basics.h"
#include "m_opt.h"
#include "keys.h"
#include "my.h"

void	opt_init_key(char **opt)
{
  setupterm(0, 1, 0);
  opt[1] = my_dup(tigetstr("kcub1"));
  opt[2] = my_dup(tigetstr("kcuf1"));
  opt[3] = my_dup(tigetstr("kcuu1"));
  opt[4] = my_dup(tigetstr("kcud1"));
}

int	opt_init(char	**opt)
{
  int	i;

  i = 0;
  opt_init_key(opt);
  opt[0] = my_dup("1");
  opt[5] = my_dup("q");
  opt[6] = my_dup(" ");
  opt[7] = my_dup("0");
  opt[8] = my_dup("0");
  opt[9] = my_dup("20");
  opt[10] = my_dup("10");
  while (i < 11)
    {
      if (opt[i] == 0)
	return (1);
      i++;
    }
  return (0);
}

int	opt_apply(int ac, char **av, char **opt, char ***test)
{
  int	couple[2];
  int	ex;

  couple[0] = 1;
  couple[1] = ac;
  ex = 0;
  while (couple[0] < couple[1] && ex == 0)
    {
      if (av[couple[0]][0] != '-')
	return (err_sdsip("Unknown argument"));
      ex = opt_seek(couple, av, opt, test);
      couple[0] = couple[0] + 1;
    }
  return (ex);
}

char	**opt_core(int ac, char **av)
{
  int	get;
  char	**opt;
  char	***test;

  if ((opt = malloc(sizeof(char*) * (11))) == 0 || opt_init(opt) == 1)
    return (err_ndsip("Memory Allocation failed"));
  test = opt_test_get();
  if ((get = opt_apply(ac, av, opt, test)) == 84)
    return (0);
  if (opt_recheck_core(ac, av, test) || opt_recheck_keys(opt))
    return (err_ndsip("Redefined argument / Invalid number"));
  if (get == 1)
    opt[8][0] = '2';
  free_opt_test(test);
  opt = opt_check_core(opt);
  return (opt);
}
