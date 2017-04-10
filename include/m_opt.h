/*
** m_opt.h for tetris in /home/THOMAZ_C/PSU_2016_tetris/include/
**
** Made by Corentin Thomazeau
** Login   <THOMAZ_C@epitech.net>
**
** Started on  Thu Mar  2 16:08:40 2017 Corentin Thomazeau
** Last update Mon Mar 13 18:07:06 2017 Corentin Thomazeau
*/

#ifndef M_OPT_H_
# define M_OPT_H_

int	opt_init(char	**);
char	**opt_core(int, char **);
void	free_opt_test(char ***test);
int	opt_apply(int, char **, char **, char ***);

char	***opt_test_get();
char	**opt_test_first();
char	**opt_test_second();

int	opt_seek_simple(const char *const, char **);
int	opt_seek(int *, char **, char **, char ***);
char	*opt_seek_value(const char *const, const int);
int	opt_seek_double(const char *const, char **, char **);
int	opt_cmp(const char *const, const char *const, const int);

void	opt_display_keys(char *);
void	opt_display_core(char **);
void	opt_display_all_keys(char **);

void	opt_free_opt(char **);
int	opt_check_number(char *);
char	**opt_check_core(char **);

int	opt_spe_simple(int *, char **, char **, int);
char	*opt_spe_divide(const char *const, int, int);
void	opt_spe_size(char **, const char *const, int);

int	opt_recheck_keys(char **);
void	opt_recheck_uncaps(char *);
int	opt_recheck_seek(char *, char ***);
int	opt_recheck_core(int, char **, char ***);
int	opt_recheck_cmp(const char *, const char *);

#endif /* !M_OPT_H_ */
