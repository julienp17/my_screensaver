##
## EPITECH PROJECT, 2019
## My Screensaver
## File description:
## Makefile
##

CC 			= 	gcc

MAIN		=	$(addprefix $(SRC_D), $(MAIN_F))
OBJ_M		=	$(MAIN:.c=.o)
MAIN_F		=	main.c

SRC			= 	$(addprefix $(SRC_D), $(SRC_F))
OBJ 		= 	$(SRC:.c=.o)
SRC_D 		= 	src/
SRC_F 		= 	usage.c \
				screensaver.c \
				framebuffer.c \
				animations.c \
				animations/purple_rain.c \
				animations/starfield.c \

SRC_UT   	=	$(addprefix $(SRC_UT_D), $(SRC_UT_F))
OBJ_UT 	 	=	$(SRC_UT:.c=.o)
SRC_UT_D 	= 	tests/
SRC_UT_F 	= 	

INC			= 	-I./include/

CFLAGS		= 	-W -Wall -Wextra -Werror $(INC) $(LDFLAGS)

LDFLAGS		=	-L./lib -lmy -lcsfml-graphics -lm

LDFLAGS_UT	= 	-lcriterion -lgcov --coverage

DBFLAGS 	=	-g -g3 -ggdb

NAME 		= 	my_screensaver

NAME_UT 	= 	unit_tests

all: $(NAME)

$(NAME): makelib $(OBJ) $(OBJ_M)
	@echo -e "\e[1;32mCompiling $(NAME) binary... \e[0m"
	$(CC) -o $(NAME) $(OBJ_M) $(OBJ) $(CFLAGS) $(DBFLAGS)

makelib:
	make -C ./lib/my/ all

tests_run: clean $(OBJ) $(OBJ_UT)
	@echo -e "\e[1;32mCompiling $(NAME_UT) binary... \e[0m"
	$(CC) -o $(NAME_UT) $(SRC) $(SRC_UT) $(CFLAGS) $(LDFLAGS_UT)
	@./$(NAME_UT)
	@rm -f $(SRC_UT_F:.c=.gcda)
	@rm -f $(SRC_UT_F:.c=.gcno)

clean:
	@echo -e "\e[1;32mRemoving source object files...\e[0m"
	rm -f $(OBJ)
	@echo -e "\e[1;32mRemoving source coverage files...\e[0m"
	rm -f $(SRC_F:.c=.gcda)
	rm -f $(SRC_F:.c=.gcno)
	@echo -e "\e[1;32mRemoving unit_tests object files... \e[0m"
	rm -f $(OBJ_UT)
	@echo -e "\e[1;32mRemoving unit_tests coverage files...\e[0m"
	rm -f $(SRC_UT_F:.c=.gcda)
	rm -f $(SRC_UT_F:.c=.gcno)

fclean: clean
	@echo -e "\e[1;32mRemoving $(NAME) binary...\e[0m"
	rm -f $(NAME)
	@echo -e "\e[1;32mRemoving $(NAME_UT) binary... \e[0m"
	rm -f $(NAME_UT)

re: fclean all
