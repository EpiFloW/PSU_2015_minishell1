/*
** access.c for  in /home/maison_f/Epitech/rendu/PSU_2015_minishell1
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Thu Jan 21 11:33:46 2016 Maisonnave Florian
** Last update Sat Jan 23 06:46:15 2016 Maisonnave Florian
*/

#include "my_sh.h"

int	check_access(t_my_sh *sh)
{
  int	i;

  i = 0;
  sh->tmp_acc = -1;
  while (i <= sh->lines)
    {
      if ((access(sh->way[i], F_OK) == 0) && (access(sh->way[i], X_OK) == 0))
	sh->tmp_acc = i;
      i++;
    }
  return (sh->tmp_acc);
}
