/*
** find_home.c for  in /home/maison_f/Epitech/rendu/PSU_2015_minishell1/src
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Mon Jan 25 09:07:44 2016 Maisonnave Florian
** Last update Mon Jan 25 09:11:33 2016 Maisonnave Florian
*/

#include "my_sh.h"

char	*save_home(t_my_sh *sh, int tmp)
{
  char	*home;
  int	i;
  int	k;

  i = 0;
  k = 5;
  home = malloc(sizeof(char) * 1000);
  while (sh->env_tab[tmp][k])
    home[i++] = sh->env_tab[tmp][k++];
  home[i] = '\0';
  return (home);
}

void	find_home(t_my_sh *sh)
{
  char	*str;
  int	tmp;
  int	i;
  int	k;

  i = 0;
  k = 0;
  str = "HOME=";
  while (sh->env_tab[i] != NULL)
    {
      while (sh->env_tab[i][k] == str[k] && k < 5)
	{
	  tmp = i;
	  k++;
	}
      if (k < 5)
	k = 0;
      i++;
    }
  if (k >= 5)
    sh->home = save_home(sh, tmp);
}
