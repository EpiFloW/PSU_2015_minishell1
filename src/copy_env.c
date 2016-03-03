/*
** copy_env.c for  in /home/maison_f/Epitech/rendu/PSU_2015_minishell1
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Sun Jan 24 00:59:46 2016 Maisonnave Florian
** Last update Sun Jan 24 15:33:27 2016 Maisonnave Florian
*/

#include "my_sh.h"

void	create_env(t_my_sh *sh, char **env)
{
  sh->lines = 0;
  sh->colons = 0;
  sh->lines = lines_env(env);
  sh->colons = colons_env(env);
  malloc_env(sh);
  copy_env(sh, env);
}

int	lines_env(char **env)
{
  int	i;

  i = 0;
  while (env[i] != NULL)
    i++;
  i++;
  return (i);
}

int	colons_env(char **env)
{
  int	max_colons;
  int	i;
  int	k;

  i = 0;
  k = 0;
  max_colons = 0;
  while (env[i] != NULL)
    {
      while (env[i][k])
	{
	  k++;
	}
      if (k > max_colons)
	max_colons = k;
      k = 0;
      i++;
    }
  max_colons++;
  return (max_colons);
}

void	malloc_env(t_my_sh *sh)
{
  int	i;

  if ((sh->env_tab = malloc(sizeof(char*) * (sh->lines + 1))) == NULL)
    return;
  i = 0;
  while (i < sh->lines)
    {
      if ((sh->env_tab[i] = malloc(sizeof(char) * (sh->colons + 1))) == NULL)
	return;
      i++;
    }
}

void	copy_env(t_my_sh *sh, char **env)
{
  int	y;
  int	x;

  y = 0;
  x = 0;
  while (env[y] != NULL)
    {
      while (env[y][x])
	{
	  sh->env_tab[y][x] = env[y][x];
	  x++;
	}
      sh->env_tab[y][x] = '\0';
      x = 0;
      y++;
    }
  sh->env_tab[y] = NULL;
}
