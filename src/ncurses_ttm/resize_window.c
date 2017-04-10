/*
** resize_window.c for resize_window in /home/sachs_a/delivery/system_unix/PSU_2016_tetris/src/ncurses_ttm
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Sat Mar 18 10:59:36 2017 Alexandre Sachs
** Last update Sun Mar 19 11:16:09 2017 Corentin Thomazeau
*/

#include "game.h"
#include "m_basics.h"
#include <ncurses.h>

int	window_checker()
{
  int	windowx;
  int	windowy;

  getmaxyx(stdscr, windowy, windowx);
  if (windowy < 50 || windowx < 190)
    return (84);
  return (0);
}

void	print_error()
{
  char	*error;
  char	*error2;

  error = "!!! GAME PAUSE !!!";
  error2 = "The Window is to small : Please put it in fullscreen!";
  clear();
  move(LINES / 2, (COLS / 2) - (my_strlen(error) / 2));
  printw(error);
  move(LINES / 2 + 1, (COLS / 2) - (my_strlen(error2) / 2));
  printw(error2);
  refresh();
}

int	resize_window(t_details_ttm *details, int level, int score)
{
  static int	lev = 1;
  static int	scr = 0;

  if (level != 0)
    lev = level;
  if (score != 0)
    scr = score;
  if (window_checker() == 84)
    {
      print_error();
      while (window_checker() == 84)
	{
	  getch();
	  print_error();
	}
      clear();
      game_page(details, lev, scr);
    }
  return (0);
}
