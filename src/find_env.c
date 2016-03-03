/*
** find_env.c for  in /home/maison_f/Epitech/rendu/PSU_2015_minishell1
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Wed Jan 20 21:58:11 2016 Maisonnave Florian
** Last update Sun Jan 24 18:05:20 2016 Maisonnave Florian
*/

#include "my_sh.h"

char	*save_path(char **env, int tmp)
{
  char *path;
  int	i;
  int	k;

  i = 0;
  k = 5;
  path = malloc(sizeof(char) * 1000);
  while (env[tmp][k])
    path[i++] = env[tmp][k++];
  path[i] = '\0';
  return (path);
}

char	*find_path(char **env)
{
  char	*res;
  char	*str;
  int	tmp;
  int	i;
  int	k;

  i = 0;
  k = 0;
  tmp = 0;
  str = "PATH=";
  while (env[i] != NULL)
    {
      while (env[i][k] == str[k] && k < 5)
	{
	  tmp = i;
	  k++;
	}
      if (k < 5)
	k = 0;
      i++;
    }
  if (k >= 5)
    res = save_path(env, tmp);
  return (res);
}
