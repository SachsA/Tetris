/*
** main.c for main in /home/sachs_a/delivery/system_unix/PSU_2016_tetris/src/ncurses_ttm
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Thu Mar  9 10:40:33 2017 Alexandre Sachs
** Last update Sun Mar 19 11:12:24 2017 Corentin Thomazeau
*/

#include <unistd.h>
#include <ncurses.h>
#include "m_basics.h"
#include "game.h"

int	paserel(t_details_ttm *details, char **opt)
{
  init_screen();
  intro();
  game_page(details, my_getnbr(opt[0]), 0);
  cano_nik(1);
  tetris(details, opt);
  cano_nik(0);
  endwin();
  return (0);
}
