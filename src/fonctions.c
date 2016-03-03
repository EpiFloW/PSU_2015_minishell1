/*
** fonctions.c for  in /home/maison_f/Epitech/rendu/PSU_2015_minishell1
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Tue Jan 19 18:21:30 2016 Maisonnave Florian
** Last update Tue Jan 19 19:43:33 2016 Maisonnave Florian
*/

#include "my_sh.h"

void	my_putchar(char c)
{
  write (1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}

void	my_putnbr(int nb)
{
  int	i;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  i = nb % 10;
  if (nb >= 10)
    my_putnbr(nb / 10);
  my_putchar(i + 48);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
