/*
** my.h for myh in /home/sachs_a/delivery/system_unix/PSU_2016_tetris
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Wed Mar  1 01:25:48 2017 Alexandre Sachs
** Last update Sat Mar 18 21:39:09 2017 Alexandre Sachs
*/

#ifndef MY_H_
# define MY_H_

#include <dirent.h>
# define UNUSED __attribute__((unused))

typedef struct		s_details_ttm
{
  int			nb_ttm;
  int			width;
  int			height;
  int			color;
  int			posx;
  int			posy;
  int			rota;
  char			**forme;
  char			*name;
  char			*path;
  struct s_details_ttm	*next;
}			t_details_ttm;

/*
** TETRIMINOS
*/
int             check_name(char *);
void		print_tetriminos(t_details_ttm *);
t_details_ttm   *find_tetriminos();
int             fill_params_tetris(t_details_ttm *, char *);
t_details_ttm   *check_tetriminos(t_details_ttm *);
char            *epur_end_str(char *, int *);
t_details_ttm   *fill_forme(t_details_ttm *, int);
char            *alloc_name(char *);
t_details_ttm   *alloc_new(char *);
void		free_dirent(struct dirent **, int);
void		free_tetra_list(t_details_ttm *);
int		find_tetriminos_list(t_details_ttm **, int *,
				      t_details_ttm **, struct dirent *);
int             supp_error(t_details_ttm **);
t_details_ttm	*is_there_stars(t_details_ttm *, int);

#endif /* !MY_H_ */
