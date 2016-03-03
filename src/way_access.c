/*
** way_access.c for  in /home/maison_f/Epitech/rendu/PSU_2015_minishell1/src
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Mon Jan 25 09:03:50 2016 Maisonnave Florian
** Last update Mon Jan 25 09:27:22 2016 Maisonnave Florian
*/

#include "my_sh.h"

int	check_cd(t_my_sh *sh)
{
  char	*str;
  int	check;
  int	i;

  i = 0;
  check = 0;
  str = "cd\0";
  while (sh->tab[0][i] == str[i])
    i++;
  if (i == 4)
    {
      check = 1;
      if (sh->tab[1] == NULL)
	chdir(sh->home);
    }
  return (check);
}
