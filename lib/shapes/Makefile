##
## EPITECH PROJECT, 2019
## My Screensaver
## File description:
## Shapes Makefile
##

CC 		= 	gcc

SRC		=	line.c \
			square.c \
			rectangle.c \
			circle.c \
			digit.c \

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror $(INC)

INC		=	-I../../include

HEADER	=	shapes.h

NAME	=	libshapes.a

all:		$(OBJ)
			ar rc $(NAME) $(OBJ)
			cp $(NAME) ../
			cp $(HEADER) ../../include

clean:
			@rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)
			rm -f ../$(NAME)
			rm -f ../../include/$(HEADER)

re:			fclean all

.phony:		re fclean clean
