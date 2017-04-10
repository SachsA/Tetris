/*
** m_basics.h for tetris in /home/THOMAZ_C/PSU_2016_tetris/include/
**
** Made by Corentin Thomazeau
** Login   <THOMAZ_C@epitech.net>
**
** Started on  Thu Mar  2 16:28:43 2017 Corentin Thomazeau
** Last update Tue Mar  7 17:01:05 2017 Corentin Thomazeau
*/

#ifndef M_BASICS_H_
# define M_BASICS_H_

int			tablen(char **);
int			my_strlen(char *);
int			my_getnbr(char *);
int			my_str_isnum(char *);
int			my_printf(char *, ...);
int			err_sdsip(const char *);
void			*err_ndsip(const char *);
int			my_strcmp(char *, char *);
char			*my_dup(const char *const);
char			*my_strcat(char *, char *);
char			*my_strcat_n(char *, char *);
char			*my_memset(char *, int, int);
int			my_show_wordtab(char **, int);
char			**my_str_to_wordtab(char *, char);

#endif /* !M_BASICS_H_ */
