##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

MAIN	=		main.c	\

SRC		=		$(MATCH)	\
				$(MY)

CFLAGS	=	-g3

MATCH	=		./lib/match_function/loading_map.c	\
				./lib/match_function/error.c		\
				./lib/match_function/move.c			\
				./lib/match_function/art_int.c

MY		=		./lib/my/my_getnbr.c		\
				./lib/my/my_put_nbr.c	\
				./lib/my/my_putchar.c	\
				./lib/my/my_strlen.c	\
				./lib/my/my_str_isnum.c


UNIT 	=		./tests/test.c 	\

LIBMY	=		./lib/my/libmy.a

OBJ 	= $(SRC:.c=.o)

CC 		= gcc

NAME	=		matchstick

all:	$(OBJ)
	ar rc $(LIBMY) $(OBJ)
	$(CC) -o $(NAME) $(MAIN) $(LIBMY) $(CFLAGS)

clean:
		rm -rf *.o
		rm -rf lib/my/*.o
		rm -rf lib/match_function/*.o

fclean: clean
		rm -f $(NAME)
		rm -f $(LIBMY)

re: 	fclean all