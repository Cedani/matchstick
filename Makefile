##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC		=		main.c 	\

UNIT 	=		./tests/test.c 	\

OBJ 	= $(SRC:.c=.o)

CC 		= gcc

NAME	=		matchstick

all:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
		rm -rf *.o

fclean: clean
		rm -f $(NAME)

re: 	fclean all
