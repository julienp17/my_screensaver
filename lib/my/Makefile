##
## EPITECH PROJECT, 2019
## My Screensaver
## File description:
## Libmy Makefile
##

CC 		= 	gcc

SRC		=	my_intlen.c \
			my_int_to_strnum.c \
			my_puterr.c \
			my_putstr.c \
			my_putchar.c \
			my_str_isnum_pos.c \
			my_strcmp.c \
			my_strlen.c \
			my_strnum_to_uint.c \
			my_revstr.c \

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror

HEADER	=	my.h

NAME	=	libmy.a

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
