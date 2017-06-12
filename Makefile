##
## Makefile for tetris in /home/ibanez_j/PSU_2016_tetris
##
## Made by Jean-Alexandre IBANEZ
## Login   <ibanez_j@epitech.net>
##
## Started on  Mon Mar  6 11:44:54 2017 Jean-Alexandre IBANEZ
## Last update Sun Mar 19 23:33:37 2017 Jean-Alexandre IBANEZ
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wextra -Wall -I./include
CLFAGS	+= -ansi -pedantic

NAME	= tetris

SRCS	= ./srcs/check_tetri.c		\
	  ./srcs/error_hdl.c		\
	  ./srcs/main.c			\
	  ./srcs/set_funcs2.c		\
	  ./srcs/word_tab.c		\
	  ./srcs/debug_display.c	\
	  ./srcs/getnbr.c		\
	  ./srcs/no_display.c		\
	  ./srcs/set_funcs.c		\
	  ./srcs/utils2.c		\
	  ./srcs/display_tetri.c	\
	  ./srcs/get_next_line.c	\
	  ./srcs/puts.c			\
	  ./srcs/struct.c		\
	  ./srcs/utils.c		\
	  ./srcs/set_term.c		\
	  ./srcs/check_tetri2.c		\
	  ./srcs/init_c.c		\
	  ./srcs/title_win.c		\
	  ./srcs/win_init.c		\
	  ./srcs/process.c		\
	  ./srcs/checks.c		\
	  ./srcs/str_rm.c		\
	  ./srcs/hdl_input.c		\
	  ./srcs/colors.c		\
	  ./srcs/draw.c			\
	  ./srcs/tab.c

OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) -L./lib -lmy -lncurses

all:  $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
