/*
** my_sh.h for  in /home/maison_f/Epitech/rendu/PSU_2015_minishell1
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Tue Jan 19 18:47:37 2016 Maisonnave Florian
** Last update Mon Jan 25 10:12:46 2016 Maisonnave Florian
*/

#ifndef MY_SH_H
# define MY_SH_H_
# define _POSIX_SOURCE

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct	s_my_sh
{
  char		**final_tab;
  char		**env_tab;
  char		**tab;
  char		**way;
  char		*home;
  char		*host;
  int		check;
  int		lines;
  int		colons;
  int		tmp_acc;
}		t_my_sh;

void	my_putchar(char);
void	my_putstr(char *);
int	compt_lines(char *);
int	compt_colons(char *);
void	my_putnbr(int);
int	my_strlen(char *);
void	malloc_tab(t_my_sh *);
void	copy_tab(t_my_sh *, char *);
void	create_tab(t_my_sh *, char *);
char	*save_path(char **, int);
char	*find_path(char **);
void	create_way(t_my_sh *, char *);
void	malloc_way(t_my_sh *);
void	copy_way(t_my_sh *, char *, int, int);
int	lines_way(char *);
int	colons_way(char *);
int	check_access(t_my_sh *);
void	way_and_exec(t_my_sh *);
int	check_setenv(t_my_sh *);
void	exec_prog(t_my_sh *);
int	check_access_way(t_my_sh *);
void	cmd_way(t_my_sh *);
void	infinite_loop_null(t_my_sh *, char *, int);
void	create_env(t_my_sh *, char **);
int	lines_env(char **);
int	colons_env(char **);
void	malloc_env(t_my_sh *);
void	copy_env(t_my_sh *, char **);
int	space_and_tab(char *);
void	infinite_loop_end(t_my_sh *);
void	suppr_end_space(char *);
int	char_or_int(t_my_sh *);
int	my_getnbr(char *);
int	my_num(char);
int	my_neg(char *);
int	exit_cmd_return(t_my_sh *);
int	check_setenv_options(t_my_sh *);
char	*save_home(t_my_sh *, int);
void	find_home(t_my_sh *);
int	check_cd(t_my_sh *);

#endif /* !MY_SH_H_ */
