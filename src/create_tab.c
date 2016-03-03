/*
** create_tab.c for  in /home/maison_f/Epitech/rendu/PSU_2015_minishell1
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Tue Jan 19 18:53:34 2016 Maisonnave Florian
** Last update Sun Jan 24 04:50:07 2016 Maisonnave Florian
*/

#include "my_sh.h"

int	compt_lines(char *str)
{
  int	lines;
  int	i;

  i = 0;
  lines = 1;
  while (str[i])
    {
      if (str[i] == 32 || str[i] == 9)
	{
	  lines++;
	  while (str[i] == 32 || str[i] == 9)
	    i++;
	}
      i++;
    }
  lines++;
  return (lines);
}

int	compt_colons(char *str)
{
  int	max_colons;
  int	colons;
  int	i;

  i = 0;
  colons = 0;
  max_colons = 0;
  while (str[i])
    {
      if (str[i] == 32 || str[i] == 9)
	{
	  if (max_colons < colons)
	    max_colons = colons;
	  colons = 0;
	  while (str[i] == 32 || str[i] == 9)
	    i++;
	}
      i++;
      colons++;
    }
  return (max_colons);
}

void	malloc_tab(t_my_sh *sh)
{
  int	i;

  if ((sh->tab = malloc(sizeof(char*) * (sh->lines + 1))) == NULL)
    return;
  i = 0;
  while (i < sh->lines)
    {
      if ((sh->tab[i] = malloc(sizeof(char) * (sh->colons + 1))) == NULL)
	return;
      i++;
    }
}

void	suppr_end_space(char *str)
{
  int	i;

  i = my_strlen(str) - 1;
  while ( i >= 0 && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
    --i;
  str[++i] = '\0';
}

void	copy_tab(t_my_sh *sh, char *str)
{
  int	i;
  int	x;
  int	y;

  i = 0;
  x = 0;
  y = 0;
  while (str[i] == 32 || str[i] == 9)
    i++;
  while (str[i])
    {
      if (str[i] == 32 || str[i] == 9)
	{
	  x = 0;
	  y++;
	  i++;
	  while (str[i] == 32 || str[i] == 9)
	    i++;
	}
      sh->tab[y][x++] = str[i++];
    }
  sh->tab[y][x] = '\0';
  sh->tab[y + 1] = NULL;
}
