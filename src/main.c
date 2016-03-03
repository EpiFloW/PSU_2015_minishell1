/*
** main.c for  in /home/maison_f/Epitech/rendu/PSU_2015_minishell1
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Tue Jan 19 18:19:12 2016 Maisonnave Florian
** Last update Mon Jan 25 09:17:06 2016 Maisonnave Florian
*/

#include "my_sh.h"

int	error(int ac, char **env)
{
  (void)env;
  if (ac > 1)
    {
      write(2, "Error : Too many arguments\n", 27);
      return (1);
    }
  return (0);
}

int	exit_cmd(t_my_sh *sh)
{
  char	*str;
  int	check;
  int	i;

  i = 0;
  check = 0;
  str = "exit\0";
  while (sh->tab[0][i] == str[i] && sh->tab[1] == NULL)
    i++;
  if (i == 6)
    {
      check = 1;
      my_putstr("exit\n");
    }
  return (check);
}

void	create_tab(t_my_sh *sh, char *buffer)
{
  sh->lines = 0;
  sh->colons = 0;
  sh->lines = compt_lines(buffer);
  sh->colons = compt_colons(buffer);
  malloc_tab(sh);
  suppr_end_space(buffer);
  copy_tab(sh, buffer);
}

int	infinite_loop(t_my_sh *sh, char *buffer, int arg)
{
  while (42)
    {
      sh->check = 0;
      write(1, "$> ", 3);
      arg = read(0, buffer, 4096);
      buffer[arg] =  '\0';
      if (buffer != NULL)
	{
	  create_tab(sh, buffer);
	  find_home(sh);
	  if ((space_and_tab(buffer)) == 0)
	    {
	      if (exit_cmd(sh) == 1)
		return (0);
	      if (exit_cmd_return(sh) > 0)
		return (exit_cmd_return(sh));
	      infinite_loop_end(sh);
	    }
	}
    }
  return (0);
}

int		main(int ac, char **av, char **env)
{
  t_my_sh	*sh;
  char		buffer[4096];
  int		arg;
  int		res;

  (void)av;
  (void)env;
  arg = 0;
  res = 0;
  if ((sh = malloc(sizeof(t_my_sh))) == NULL)
    return (1);
  if (error(ac, env) == 0)
    {
      if (*env != NULL)
	{
	  create_env(sh, env);
	  res = infinite_loop(sh, buffer, arg);
	}
      else
	infinite_loop_null(sh, buffer, arg);
    }
  return (res);
}
