/*
** init_screen.c for init_screen in /home/sachs_a/delivery/system_unix/PSU_2016_tetris/src/ncurses_ttm
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Thu Mar  9 10:34:09 2017 Alexandre Sachs
** Last update Sat Mar 18 18:00:54 2017 Alexandre Sachs
*/

#include <ncurses.h>

void	init_screen()
{
  initscr();
  refresh();
  start_color();
  init_pair(0, COLOR_BLACK, COLOR_BLACK);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  init_pair(7, COLOR_WHITE, COLOR_BLACK);
  init_pair(8, COLOR_BLACK, COLOR_BLACK);
  init_pair(9, COLOR_RED, COLOR_RED);
  init_pair(10, COLOR_GREEN, COLOR_GREEN);
  init_pair(11, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(12, COLOR_BLUE, COLOR_BLUE);
  init_pair(13, COLOR_MAGENTA, COLOR_MAGENTA);
  init_pair(14, COLOR_CYAN, COLOR_CYAN);
  init_pair(15, COLOR_WHITE, COLOR_WHITE);
  curs_set(0);
  attron(A_BOLD);
}
