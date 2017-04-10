/*
** boxes.c for boxes in /home/sachs_a/delivery/system_unix/PSU_2016_tetris/src/ncurses_ttm
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Fri Mar 10 22:27:36 2017 Alexandre Sachs
** Last update Sun Mar 19 11:11:59 2017 Corentin Thomazeau
*/

#include "my.h"
#include "m_opt.h"
#include "m_basics.h"
#include <ncurses.h>

void		next_box(t_details_ttm *details)
{
  WINDOW	*next;

  mvprintw(LINES / 2 - 8, COLS / 2 - 26, "NEXT");
  refresh();
  next = newwin(6, 12, LINES / 2 - 7, COLS / 2 - 30);
  wbkgd(next, COLOR_PAIR(2));
  box(next, 0, 0);
  attron(COLOR_PAIR(2));
  mvwprintw(next, 2, 5 - (my_strlen(details->name) / 2),
	    details->name);
  refresh();
  attroff(COLOR_PAIR(2));
  wrefresh(next);
}

void		lvl_box(int level)
{
  WINDOW	*lvl;

  mvprintw(LINES / 2 - 1, COLS / 2 - 26, "LVL");
  refresh();
  lvl = newwin(6, 12, LINES / 2, COLS / 2 - 30);
  wbkgd(lvl, COLOR_PAIR(5));
  box(lvl, 0, 0);
  attron(COLOR_PAIR(5));
  mvwprintw(lvl, 2, 1, "%i", level);
  refresh();
  attroff(COLOR_PAIR(5));
  wrefresh(lvl);
}

void		score_box(int score_i)
{
  WINDOW	*score;

  mvprintw(LINES / 2 + 6, COLS / 2 - 27, "SCORE");
  refresh();
  score = newwin(6, 12, LINES / 2 + 7, COLS / 2 - 30);
  wbkgd(score, COLOR_PAIR(4));
  box(score, 0, 0);
  attron(COLOR_PAIR(4));
  mvwprintw(score, 2, 1, "%i", score_i);
  refresh();
  attroff(COLOR_PAIR(4));
  wrefresh(score);
}

void		boxes(t_details_ttm *details, int level, int score)
{
  next_box(details);
  lvl_box(level);
  score_box(score);
}
