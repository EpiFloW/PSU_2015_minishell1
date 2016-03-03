/*
** my_getnbr.c for  in /home/maison_f/Epitech/rendu/CPE_2015_BSQ
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Sun Dec 20 22:35:49 2015 Maisonnave Florian
** Last update Sun Jan 24 05:22:53 2016 Maisonnave Florian
*/

#include "my_sh.h"

int	my_neg(char *str)
{
  int	i;
  int	c;

  i = 0;
  c = 0;
  while (str[i] > '9' || str[i] < '0')
    {
      if (str[i] == '-')
	c++;
      i++;
    }
  if (c % 2 != 0)
    return (1);
  else
    return (0);
}

int	my_num(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  else
    return (0);
}

int	my_getnbr(char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (my_num(str[i]) == 0)
    i++;
  while (my_num(str[i]) == 1)
    {
      nb = ((nb * 10) + (str[i] - 48));
      i++;
    }
  if (my_neg(str) == 1)
    nb = -nb;
  return (nb);
}
