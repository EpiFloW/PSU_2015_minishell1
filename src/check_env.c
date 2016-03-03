/*
** check_env.c for  in /home/maison_f/Epitech/rendu/PSU_2015_minishell1
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Sat Jan 23 01:30:42 2016 Maisonnave Florian
** Last update Sun Jan 24 17:07:14 2016 Maisonnave Florian
*/

#include "my_sh.h"

int	check_setenv(t_my_sh *sh)
{
  char	*str;
  int	check;
  int	i;

  i = 0;
  check = 0;
  str = "setenv\0";
  while (sh->tab[0][i] == str[i] && sh->tab[1] == NULL)
    i++;
  if (i == 8)
    {
      i = 0;
      check = 1;
      while (sh->env_tab[i] != NULL)
	{
	  my_putstr(sh->env_tab[i]);
	  my_putstr("\n");
	  i++;
	}
    }
  return (check);
}
