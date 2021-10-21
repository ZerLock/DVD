##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

CC	=	gcc

SRC	=	$(wildcard src/*.c)

OBJ	=	$(SRC:.c=.o)

LDFLAGS	=	-L/usr/local/lib -lcsfml-window -lcsfml-graphics

CPFLAGS	=	-W -Werror

CFLAGS	=	-I./include

NAME	=	dvd

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f src/$(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
