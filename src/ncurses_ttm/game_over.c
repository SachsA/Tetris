/*
** game_over.c for game_over in /home/sachs_a/delivery/system_unix/PSU_2016_tetris/src/ncurses_ttm
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Sat Mar 18 20:20:11 2017 Alexandre Sachs
** Last update Sat Mar 18 20:40:58 2017 Alexandre Sachs
*/

#include <unistd.h>
#include <ncurses.h>

void	game_over()
{
  clear();
  attron(COLOR_PAIR(1));
  mvprintw(LINES / 2 - 3, COLS / 2 - 40, " _____       ___       ___  ___   _"
					 "____        _____   _     _   _____   _____   ");
  mvprintw(LINES / 2 - 2, COLS / 2 - 40, "/  ___|     /   |     /   |/   | | "
					 "____|      /  _  \\ | |   / / | ____| |  _  \\  ");
  mvprintw(LINES / 2 - 1, COLS / 2 - 40, "| |        / /| |    / /|   /| | | "
					 "|__        | | | | | |  / /  | |__   | |_| |  ");
  mvprintw(LINES / 2, COLS / 2 - 40, "| |  _    / / | |   / / |__/ | | |  __|"
				     "       | | | | | | / /   |  __|  |  _  /  ");
  mvprintw(LINES / 2 + 1, COLS / 2 - 40, "| |_| |  / /  | |  / /       | | | "
					 "|___       | |_| | | |/ /    | |___  | | \\ \\  ");
  mvprintw(LINES / 2 + 2, COLS / 2 - 40, "\\_____/ /_/   |_| /_/        |_| |"
					 "_____|      \\_____/ |___/     |_____| |_|  \\_\\ ");
  refresh();
  attroff(COLOR_PAIR(1));
  sleep(4);
}
