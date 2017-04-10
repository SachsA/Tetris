/*
** print_titles_game.c for print_titles_game in /home/sachs_a/delivery/system_unix/PSU_2016_tetris/src/ncurses_ttm
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Fri Mar 10 22:53:02 2017 Alexandre Sachs
** Last update Sat Mar 18 16:03:46 2017 Alexandre Sachs
*/

#include <ncurses.h>

void	print_title()
{
  attron(COLOR_PAIR(3));
  mvprintw(LINES / 2 - 23, COLS / 2 - 26, " _____   _____   _____   _____    "
	   "¤   _____  ");
  mvprintw(LINES / 2 - 22, COLS / 2 - 26, "|_   _| | ____| |_   _| |  _  \\  "
	   "| | /  ___/");
  mvprintw(LINES / 2 - 21, COLS / 2 - 26, "  | |   | |__     | |   | |_| |  |"
	   " | | |___  ");
  mvprintw(LINES / 2 - 20, COLS / 2 - 26, "  | |   |  __|    | |   |  _  /  |"
	   " | \\___  \\");
  mvprintw(LINES / 2 - 19, COLS / 2 - 26, "  | |   | |___    | |   | | \\ \\ "
	   " | |  ___| |");
  mvprintw(LINES / 2 - 18, COLS / 2 - 26, "  |_|   |_____|   |_|   |_|  \\_\\"
	   " |_| /_____/");
  attroff(COLOR_PAIR(3));
}

void	print_gl_hf()
{
  attron(COLOR_PAIR(1));
  mvprintw(LINES / 2 - 16, COLS / 2 - 70, " _____   _____   _____   _____    "
	   "    _       _   _   _____   _   _         _   _       ___   _  "
	   "   _   _____        _____   _   _   __   _  ");
  mvprintw(LINES / 2 - 15, COLS / 2 - 70, "/  ___| /  _  \\ /  _  \\ |  _  \\"
	   "      | |     | | | | /  ___| | | "
	   "/ /       | | | |     /   | | |   / / | "
	   "____|      |  ___| | | | | |  \\ | | ");
  mvprintw(LINES / 2 - 14, COLS / 2 - 70, "| |     | | | | | | | | | | | |   "
	   "   | |     | | | | | |     | |/ / "
	   "       | |_| |    / /| | | |  / /  | |__"
	   "        | |__   | | | | |   \\| | ");
  mvprintw(LINES / 2 - 13, COLS / 2 - 70, "| |  _  | | | | | | | | | | | |  "
	   "    | |     | | | | | |     | |\\ \\"
	   "        |  _  |   / / | | | | / /   |  "
	   "__|       |  __|  | | | | | |\\   | ");
  mvprintw(LINES / 2 - 12, COLS / 2 - 70, "| |_| | | |_| | | |_| | | |_| |  "
	   "    | |___  | |_| | | |___  | | \\ "
	   "\\       | | | |  / /  | | | |/ /    | |_"
	   "__       | |     | |_| | | | \\  | ");
  mvprintw(LINES / 2 - 11, COLS / 2 - 70, "\\_____/ \\_____/ \\_____/ |_____"
	   "/      |_____| \\_____/ \\_____| |_"
	   "|  \\_\\      |_| |_| /_/   |_| |___/    "
	   " |_____|      |_|     \\_____/ |_|  \\_| ");
  attroff(COLOR_PAIR(1));
}
