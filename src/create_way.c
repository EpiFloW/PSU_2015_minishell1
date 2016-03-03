/*
** create_way.c for  in /home/maison_f/Epitech/rendu/PSU_2015_minishell1
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Thu Jan 21 00:19:47 2016 Maisonnave Florian
** Last update Sun Jan 24 14:01:33 2016 Maisonnave Florian
*/

#include "my_sh.h"

void	create_way(t_my_sh *sh, char *buffer)
{
  int	i;
  int	x;

  i = 0;
  x = 0;
  sh->lines = 0;
  sh->colons = 0;
  sh->lines = lines_way(buffer);
  sh->colons = colons_way(buffer);
  malloc_way(sh);
  copy_way(sh, buffer, i, x);
}

int	lines_way(char *str)
{
  int	lines;
  int	i;

  i = 0;
  lines = 1;
  while (str[i])
    {
      if (str[i] == 58)
	lines++;
      i++;
    }
  lines++;
  return (lines);
}

int	colons_way(char *str)
{
  int	max_colons;
  int	colons;
  int	i;

  i = 0;
  colons = 0;
  max_colons = 0;
  while (str[i])
    {
      if (str[i] == 58)
	{
	  if (max_colons < colons)
	    max_colons = colons;
	  colons = 0;
	}
      i++;
      colons++;
    }
  max_colons++;
  return (max_colons);
}

void	malloc_way(t_my_sh *sh)
{
  int	i;

  if ((sh->way = malloc(sizeof(char*) * (sh->lines + 1))) == NULL)
    return;
  i = 0;
  while (i < sh->lines)
    {
      if ((sh->way[i] = malloc(sizeof(char) * (sh->colons + 1))) == NULL)
	return;
      i++;
    }
}

void	copy_way(t_my_sh *sh, char *str, int i, int x)
{
  int	y;
  int	z;

  y = 0;
  z = 0;
  while (str[i])
    {
      if (str[i] == 58)
	{
	  x = 0;
	  y++;
	  i++;
	}
      sh->way[y][x++] = str[i++];
      if (str[i] == 58 || str[i + 1] == '\0')
	{
	  sh->way[y][x] = '/';
	  x++;
	  while (sh->tab[0][z])
	    sh->way[y][x++] = sh->tab[0][z++];
	  z = 0;
	}
    }
  sh->way[y++] = NULL;
}
