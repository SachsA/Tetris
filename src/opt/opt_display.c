/*
** opt_display.c for tetris in /home/THOMAZ_C/PSU_2016_tetris/src/opt/
**
** Made by Corentin Thomazeau
** Login   <THOMAZ_C@epitech.net>
**
** Started on  Thu Mar  2 17:33:33 2017 Corentin Thomazeau
** Last update Sun Mar 19 15:39:47 2017 Corentin Thomazeau
*/

#include <unistd.h>
#include "m_basics.h"
#include "m_opt.h"

void	opt_display_keys(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\033')
	  write(1, "^E", 2);
      else if (str[i] == ' ')
	write(1, "(space)", 7);
      else
	write(1, &(str[i]), 1);
      i++;
    }
  write(1, "\n", 1);
}

void	opt_display_all_keys(char **opt)
{
  write(1, "Key Left : ", 11);
  opt_display_keys(opt[1]);
  write(1, "Key Right : ", 12);
  opt_display_keys(opt[2]);
  write(1, "Key Turn : ", 11);
  opt_display_keys(opt[3]);
  write(1, "Key Drop : ", 11);
  opt_display_keys(opt[4]);
  write(1, "Key Quit : ", 11);
  opt_display_keys(opt[5]);
  write(1, "Key Pause : ", 12);
  opt_display_keys(opt[6]);
}

void	opt_display_core(char **opt)
{
  write(1, "*** DEBUG MODE ***\n", 19);
  opt_display_all_keys(opt);
  if (opt[7][0] == '0')
    write(1, "Next : Yes\n", 11);
  else
    write(1, "Next : False\n", 13);
  my_printf("Level : %i\n", my_getnbr(opt[0]));
  my_printf("Size : %i*%i\n", my_getnbr(opt[9]), my_getnbr(opt[10]));
}
