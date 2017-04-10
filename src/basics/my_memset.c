/*
** my_memset.c for my_memset in /home/sachs_a/delivery/system_unix/PSU_2016_tetris/src/basics
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Wed Mar  1 10:42:33 2017 Alexandre Sachs
** Last update Wed Mar  1 10:47:00 2017 Alexandre Sachs
*/

char	*my_memset(char *str, int val, int size)
{
  int	i;

  i = 0;
  while (str && i < size)
    {
      str[i] = val;
      i++;
    }
  return (str);
}
