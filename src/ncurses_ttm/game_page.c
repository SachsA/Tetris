/*
** game_page.c for game_page in /home/sachs_a/delivery/system_unix/PSU_2016_tetris/src/ncurses_ttm
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Thu Mar  9 10:38:02 2017 Alexandre Sachs
** Last update Sun Mar 19 11:10:41 2017 Corentin Thomazeau
*/

#include <ncurses.h>
#include "game.h"

void		game_page(t_details_ttm *details, int level, int scr)
{
  WINDOW	*win_game;

  clear();
  print_title();
  print_gl_hf();
  mvprintw(LINES / 2 - 9, COLS / 2 - 8, "THE GAME");
  refresh();
  win_game = newwin(22, 12, LINES / 2 - 8, COLS / 2 - 10);
  wbkgd(win_game, COLOR_PAIR(3));
  box(win_game, 0, 0);
  wrefresh(win_game);
  boxes(details, level, scr);
}
