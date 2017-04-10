/*
** my_str_isnum.c for my_str_isnum in /home/sachs_a/delivery/functions
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Sat Nov 26 23:50:44 2016 Alexandre Sachs
** Last update Wed Feb 22 22:54:14 2017 Alexandre Sachs
*/

int	my_str_isnum(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
    {
      if ((str[i] < 48 || str[i] > 57) && (str[i] != '+') && (str[i] != '-'))
	return (0);
    }
  return (1);
}
