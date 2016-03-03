##
## Makefile for  in /home/maison_f/Epitech/rendu/PSU_2015_minishell1
## 
## Made by Maisonnave Florian
## Login   <maison_f@epitech.net>
## 
## Started on  Mon Jan 11 22:06:37 2016 Maisonnave Florian
## Last update Mon Jan 25 09:08:01 2016 Maisonnave Florian
##

SRCS	=	src/main.c \
		src/fonctions.c \
		src/create_tab.c \
		src/create_way.c \
		src/find_env.c \
		src/access.c \
		src/exec.c \
		src/check_env.c \
		src/check_cmd.c \
		src/env_null.c \
		src/copy_env.c \
		src/error.c \
		src/my_getnbr.c \
		src/way_access.c \
		src/find_home.c \

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-W -Wall -Wextra -ansi -pedantic

HEAD	=	-Iinclude

CC	=	gcc -g $(CFLAGS) $(HEAD)

RM	=	rm -f

NAME	=	mysh

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
