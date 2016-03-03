/*
** exec.c for  in /home/maison_f/Epitech/rendu/PSU_2015_minishell1
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Fri Jan 22 23:56:35 2016 Maisonnave Florian
** Last update Fri Jan 29 12:58:33 2016 Maisonnave Florian
*/

#include "my_sh.h"

void	infinite_loop_end(t_my_sh *sh)
{
  if (sh->tab[0][0] == '/')
    cmd_way(sh);
  else
    {
      create_way(sh, find_path(sh->env_tab));
      find_home(sh);
      if (check_cd(sh) == 0)
	{
	  if (check_setenv(sh) == 0)
	    {
	      if (sh->check == 0)
		exec_prog(sh);
	    }
	}
    }
}

void	exec_prog(t_my_sh *sh)
{
  pid_t	pid;
  int	statut;

  pid = 0;
  if ((check_access(sh) > -1))
    {
      pid = fork();
      if (pid == 0)
	{
	  if ((execve(sh->way[check_access(sh)], sh->tab, sh->env_tab)) == 0)
	    kill(pid, SIGINT);
	}
      else
	{
	  wait(&statut);
	  if (WIFSIGNALED(statut))
	    write(2, "Segmentation fault (core dumped)\n", 33);
	}
    }
  else
    {
      my_putstr(sh->tab[0]);
      my_putstr(" : Command not found\n");
    }
}
