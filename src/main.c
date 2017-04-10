/*
** main.c for main in /home/sachs_a/delivery/system_unix/tetris
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Mon Feb 27 19:38:15 2017 Alexandre Sachs
** Last update Fri Mar 17 21:36:28 2017 Corentin Thomazeau
*/

#include <term.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "game.h"
#include "m_opt.h"
#include "m_basics.h"
#include "get_next_line.h"

int				display_h(char *name)
{
  my_printf("Usage:\t%s [options]\nOptions:\n"
	    "\t--help\t\t\tDisplay this help\n"
	    "\t-l --level={num}\tStart Tetris at level num (def: 1)\n"
	    "\t-kl --key-left={K}\tMove the tetrimino LEFT using the K key "
	    "(def: left arrow)\n\t-kr --key-right={K}\tMove the tetrimino "
	    "RIGHT using the K key (def: right arrow)\n\t-kt --key-turn={K"
	    "}\tTURN the tetrimino clockwise 90d using the K key "
	    "(def: top arrow)\n\t-kd --key-drop={K}\tDROP the tetrimino us"
	    "ing the K key (def: down arrow)\n\t-kq --key-quit={K}\tQUIT t"
	    "he game using the K key (def: 'q' key)\n\t-kp --key-pause={K}"
	    "\tPAUSE/RESTART the game using the K key (def: space bar)\n\t"
	    "--map-size={row,col}\tSet the numbers of rows and columns of t"
	    "he map (def: 20,10)\n\t-w --without-next\tHide next tetrimino"
	    " (def: false)\n\t-d --debug\t\tDebug mode (def: false)\n",
	    name);
  return (0);
}

void				cano_nik(int status)
{
  static struct termios	old;
  static struct termios	new;

  if (status == 1)
    {
      ioctl(0, TCGETS, &old);
      ioctl(0, TCGETS, &new);
      new.c_lflag &= ~ICANON;
      new.c_lflag &= ~ECHO;
      new.c_cc[VMIN] = 0;
      new.c_cc[VTIME] = 1;
      ioctl(0, TCSETS, &new);
    }
  else if (status == 0)
    {
      ioctl(0, TCSETS, &old);
    }
}

void				debug_disp(char **opt, t_details_ttm *details,
				   char *buff)
{
  opt_display_core(opt);
  print_tetriminos(details);
  my_printf("Press any key to start Tetris");
  buff[0] = 0;
}

int				intermediate(char **opt, t_details_ttm *details)
{
  int				get;
  char				buff[16];

  my_memset(buff, 1, 16);
  if (opt[8][0] == '1')
    debug_disp(opt, details, buff);
  if (supp_error(&details) == 1)
    return (write(1, "\n", 1), err_sdsip("No valid tetrimino"));
  cano_nik(1);
  while (buff[0] == 0)
    read(0, buff, 16);
  cano_nik(0);
  get = paserel(details, opt);
  if (opt[8][0] == '1')
    my_printf("\n");
  free_tetra_list(details);
  return (get);
}

int				main(int argc, char **argv)
{
  int				get;
  char				**opt;
  t_details_ttm			*details;

  opt = opt_core(argc, argv);
  if (opt == 0)
    return (84);
  if (opt[8][0] == '2')
    return (display_h(argv[0]));
  if ((details = find_tetriminos(opt)) == NULL)
    return (84);
  get = intermediate(opt, details);
  opt_free_opt(opt);
  return (get);
}
