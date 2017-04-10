/*
** my.h for myh in /home/sachs_a/delivery/system_unix/PSU_2016_tetris/src/ncurses_ttm
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Tue Mar  7 19:51:10 2017 Alexandre Sachs
** Last update Sun Mar 19 11:24:18 2017 Corentin Thomazeau
*/

#ifndef GAME_H_
# define GAME_H_

# include "my.h"
# include <ncurses.h>

/*
** canon
*/
void	cano_nik(int);

/*
** INIT_GAME
*/
void	game_page(t_details_ttm *, int, int);
void	init_screen();
int	paserel(t_details_ttm *, char **);

/*
** GAME
*/
int	tetris(t_details_ttm *, char **);
int	tetris_game(float, char **, char **,
		    t_details_ttm *);
int     window_checker();
int     resize_window(t_details_ttm *, int, int);
void	game_over();

/*
** PRINT_TITLES_GAME
*/
void	print_title();
void	print_gl_hf();
void	print_map(char **, int, int);

/*
** BOXES
*/
void	boxes(t_details_ttm *, int, int);
void	lvl_box(char **);
void	next_box(t_details_ttm *);
void	score_box(int);

/*
** INTRO
*/
void	intro();
void	intro_next();
void	print_date();

/*
**
*/
t_details_ttm	*new_rd_ttm(t_details_ttm *);
t_details_ttm	*new_element_spawn(t_details_ttm *, int);
int		rotation(t_details_ttm *, char **, char **);
int		tetris_test_in(char **const, t_details_ttm *, char **, int *);

/*
** MOVE
*/
char	**suppr_line(char **, int *, int *);
void	move_print(t_details_ttm *, char **, char);
int	move_core(t_details_ttm *, char, char **, char **);
int	move_impact(int *, char **, t_details_ttm *, char **);
int	move_impact_scene(int *, char **, t_details_ttm *, int);

#endif /* !GAME_H_ */
