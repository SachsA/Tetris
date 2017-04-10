/*
** intro.c for intro in /home/sachs_a/delivery/system_unix/PSU_2016_tetris/src/ncurses_ttm
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Wed Mar  8 18:27:02 2017 Alexandre Sachs
** Last update Sat Mar 18 20:47:35 2017 Alexandre Sachs
*/

#include <unistd.h>
#include <ncurses.h>

void		print_date()
{
  attron(COLOR_PAIR(5));
  mvprintw(LINES / 2 - 25, COLS - 16, " __   __     __ ");
  mvprintw(LINES / 2 - 24, COLS - 16, " __) |  | /|   /");
  mvprintw(LINES / 2 - 23, COLS - 16, "(___ |__|  |  / ");
}

void		intro_next()
{
  mvprintw(LINES / 2 + 3, COLS / 2 - 28, "Created By SACHS Alexandre and THOM"
					 "AZEAU Corentin");
  mvprintw(LINES - 2, COLS - 188, "Producer : EPITECH");
  mvprintw(LINES - 2, COLS - 26, "#Ongle/Manucure Compagny#");
  attron(COLOR_PAIR(2));
  mvprintw(LINES / 2 + 5, COLS / 2 - 16, "Visa number : 21428469666");
}

void		intro()
{
  attron(COLOR_PAIR(1));
  mvprintw(LINES / 2 - 5, COLS / 2 - 26, " _____   _____   _____   _____    "
	   "¤   _____  ");
  mvprintw(LINES / 2 - 4, COLS / 2 - 26, "|_   _| | ____| |_   _| |  _  \\  "
	   "| | /  ___/");
  mvprintw(LINES / 2 - 3, COLS / 2 - 26, "  | |   | |__     | |   | |_| |  |"
	   " | | |___  ");
  mvprintw(LINES / 2 - 2, COLS / 2 - 26, "  | |   |  __|    | |   |  _  /  |"
	   " | \\___  \\");
  mvprintw(LINES / 2 - 1, COLS / 2 - 26, "  | |   | |___    | |   | | \\ \\ "
	   " | |  ___| |");
  mvprintw(LINES / 2, COLS / 2 - 26, "  |_|   |_____|   |_|   |_|  \\_\\"
	   " |_| /_____/");
  attron(COLOR_PAIR(3));
  intro_next();
  print_date();
  refresh();
  sleep(6);
  clear();
}
