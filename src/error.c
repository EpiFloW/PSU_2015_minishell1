/*
** error.c for  in /home/maison_f/Epitech/rendu/PSU_2015_minishell1
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Sun Jan 24 01:53:56 2016 Maisonnave Florian
** Last update Sun Jan 24 13:37:43 2016 Maisonnave Florian
*/

#include "my_sh.h"

int	space_and_tab(char *buffer)
{
  int	i;
  int	space;

  i = 0;
  space = 0;
  while (buffer[i])
    {
      while (buffer[i] == 9 || buffer[i] == 32)
	{
	  i++;
	  space++;
	}
      i++;
    }
  i--;
  if (i == space)
    return (1);
  else
    return (0);
}

int	char_or_int(t_my_sh *sh)
{
  int	res;
  int	i;

  i = 0;
  res = 0;
  while (sh->tab[1][i] > 47 && sh->tab[1][i] < 58)
    i++;
  if (sh->tab[1][i] == '\0')
    res = my_getnbr(sh->tab[1]);
  else
    {
      sh->check++;
      res = 0;
      write(2, "exit : Error Syntax\n", 20);
    }
  return (res);
}

int		exit_cmd_return(t_my_sh *sh)
{
  static int	mess = 0;
  char		*str;
  int		check;
  int		i;

  i = 0;
  check = 0;
  str = "exit\0";
  while (sh->tab[0][i] == str[i] && sh->tab[1] != NULL)
    i++;
  if (i == 6)
    {
      check = char_or_int(sh);
      if (mess == 0 && check > 0)
	my_putstr("exit\n");
      mess++;
    }
  return (check);
}
