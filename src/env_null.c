/*
** env_null.c for  in /home/maison_f/Epitech/rendu/PSU_2015_minishell1
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Sat Jan 23 11:38:35 2016 Maisonnave Florian
** Last update Sun Jan 24 03:55:50 2016 Maisonnave Florian
*/

#include "my_sh.h"

void	infinite_loop_null(t_my_sh *sh, char *buffer, int arg)
{
  while (42)
    {
      write(1, "$> ", 3);
      arg = read(0, buffer, 4096);
      buffer[arg] = '\0';
      if (buffer != NULL)
	{
	  create_tab(sh, buffer);
	  my_putstr(sh->tab[0]);
	  my_putstr(" : Command not found\n");
	}
    }
}
