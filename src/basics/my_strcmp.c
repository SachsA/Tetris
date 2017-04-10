/*
** my_strcmp.c for my_strcmp in /home/romain_g/delivery/CPool_Day06
**
** Made by romain gadrat
** Login   <romain_g@epitech.net>
**
** Started on  Mon Oct 10 13:58:17 2016 romain gadrat
** Last update Wed Mar  1 20:07:29 2017 Corentin Thomazeau
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' || s2[i] != '\0')
    {
      if (s1[i] < s2[i] || s1[i] > s2[i])
	return (s1[i] - s2[i]);
      i = i + 1;
    }
  return (s1[i] - s2[i]);
}
