##
## Makefile for tetris in /home/sachs_a/delivery/system_unix/tetris
##
## Made by Alexandre Sachs
## Login   <sachs_a@epitech.net>
##
## Started on  Mon Feb 27 20:02:10 2017 Alexandre Sachs
## Last update Sat Mar 18 20:20:34 2017 Alexandre Sachs
##

CC		= gcc

RM		= rm -rf

ARRC		= ar crs

MK		= make

SRC_BIN		= src/main.c					\
		  src/opt/opt_core.c				\
		  src/opt/opt_display.c				\
		  src/opt/opt_seek.c				\
		  src/opt/opt_test.c				\
		  src/opt/opt_check.c				\
		  src/opt/opt_spe.c				\
		  src/opt/opt_recheck.c				\
		  src/tetriminos/tetriminos.c			\
		  src/tetriminos/check.c			\
		  src/tetriminos/check_tetriminos.c		\
		  src/tetriminos/fill_forme.c			\
		  src/tetriminos/init_tetriminos.c		\
		  src/tetriminos/my_free.c			\
		  src/tetriminos/print_tetriminos.c		\
		  src/tetriminos/supp_error.c			\
		  src/ncurses_ttm/boxes.c			\
		  src/ncurses_ttm/game_page.c			\
		  src/ncurses_ttm/init_screen.c			\
		  src/ncurses_ttm/intro.c			\
		  src/ncurses_ttm/paserel.c			\
		  src/ncurses_ttm/print_titles_game.c		\
		  src/ncurses_ttm/tetris.c			\
		  src/ncurses_ttm/resize_window.c		\
		  src/ncurses_ttm/move.c			\
		  src/ncurses_ttm/new_element.c			\
		  src/ncurses_ttm/rotation.c			\
		  src/ncurses_ttm/suppr_line.c			\
		  src/ncurses_ttm/game_over.c

SRC_LIB		= src/basics/my_strcmp.c			\
		  src/basics/my_dup.c				\
		  src/basics/my_getnbr.c			\
		  src/basics/get_next_line.c			\
		  src/basics/my_strcat.c			\
		  src/basics/my_show_wordtab.c			\
		  src/basics/my_str_to_wordtab.c		\
		  src/basics/my_str_isnum.c			\
		  src/basics/my_memset.c			\
		  src/basics/tablen.c				\
		  src/basics/error.c

OBJ_BIN		= $(SRC_BIN:.c=.o)

OBJ_LIB		= $(SRC_LIB:.c=.o)

CFLAGS		+= -I ./include/
CFLAGS		+= -I ./lib/my_printf/include/
CFLAGS		+= -W -Werror -Wall -Wextra -g

LDFLAGS		+= -L./lib/my -lmy
LDFLAGS		+= -L./lib/my_printf -lmy_printf
LDFLAGS		+= -lncurses

NAME_BIN	= ./tetris

NAME_LIB	= ./lib/my/libmy.a

NAME_PRINT	= lib/my_printf/

$(NAME_BIN):	$(OBJ_LIB) $(OBJ_BIN)
		$(ARRC) $(NAME_LIB) $(OBJ_LIB)
		$(MK) -C $(NAME_PRINT)
		$(CC) -o $(NAME_BIN) $(OBJ_BIN) $(LDFLAGS)

all:		$(NAME_BIN)

clean:
		$(RM) $(OBJ_BIN)
		$(RM) $(OBJ_LIB)
		$(MK) clean -C $(NAME_PRINT)

fclean:		clean
		$(RM) $(NAME_BIN)
		$(RM) $(NAME_LIB)
		$(MK) fclean -C $(NAME_PRINT)

re:		fclean all

.PHONY:		all clean fclean re
