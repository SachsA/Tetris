/*
** get_next_line.h for get_next_line.h in /home/sachs_a/delivery/get_next_line/CPE_2016_getnextline
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Mon Jan  2 09:24:46 2017 Alexandre Sachs
** Last update Sat Mar 18 17:18:31 2017 Alexandre Sachs
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# ifndef READ_SIZE
#  define READ_SIZE 30
# endif /* !READ_SIZE */

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_var_gnl
{
  int	fin;
  int	pos;
  char	buffer[READ_SIZE + 1];
}		t_var_gnl;

char	*get_next_line(const int);

#endif /* !GET_NEXT_LINE_H_ */
