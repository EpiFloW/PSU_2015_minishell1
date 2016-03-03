/*
** check_cmd.c for  in /home/maison_f/Epitech/rendu/PSU_2015_minishell1
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Sat Jan 23 06:19:53 2016 Maisonnave Florian
** Last update Sun Jan 24 10:14:39 2016 Maisonnave Florian
*/

#include "my_sh.h"

int	check_access_way(t_my_sh *sh)
{
  int	i;

  i = 0;
  sh->tmp_acc = -1;
  while (i <= sh->lines)
    {
      if ((access(sh->tab[0], F_OK) == 0) && (access(sh->tab[0], X_OK) ==0))
	sh->tmp_acc = i;
      i++;
    }
  return (sh->tmp_acc);
}

void	cmd_way(t_my_sh *sh)
{
  int	pid;

  pid = 0;
  if ((check_access_way(sh) > -1))
    {
      pid = fork();
      if (pid == 0)
	execve(sh->tab[0], sh->tab, sh->env_tab);
    }
  else
    {
      my_putstr(sh->tab[0]);
      my_putstr(" : Command not found\n");
    }
}
