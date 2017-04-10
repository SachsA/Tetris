/*
** tablen.c for tablen in /home/sachs_a/delivery/system_unix/PSU_2016_tetris
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Wed Mar  1 19:08:24 2017 Alexandre Sachs
** Last update Wed Mar  1 19:08:26 2017 Alexandre Sachs
*/

int	tablen(char **tab)
{
  int	i;

  if (!tab)
    return (-1);
  i = 1;
  while (tab[i])
    i++;
  return (i);
}
