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
				window.c \
				get_animation.c \
				random.c \
				animations/rainbow_rain.c \
				animations/bouncing_ball.c \
				animations/game_of_life.c \
				animations/radar.c \
				data_structures/framebuffer.c \
				shapes/line.c \
				shapes/circle.c \
				shapes/square.c \

SRC_UT   	=	$(addprefix $(SRC_UT_D), $(SRC_UT_F))
OBJ_UT 	 	=	$(SRC_UT:.c=.o)
SRC_UT_D 	= 	tests/
SRC_UT_F 	= 	test_usage.c \
				test_get_random_float.c \
				libmy/test_my_int_to_strnum.c \
				libmy/test_my_puterr.c \
				libmy/test_my_str_isnum_pos.c \
				libmy/test_my_strcmp.c \
				libmy/test_my_strlen.c \
				libmy/test_my_strnum_to_uint.c \

INC			= 	-I./include/ \
				-I./include/animations \
				-I./include/data_structures \
				-I./include/shapes \

CFLAGS		= 	-W -Wall -Wextra -Werror $(INC) $(LDFLAGS) $(DBFLAGS)

LDFLAGS		=	-L./lib -lmy -lcsfml-graphics -lcsfml-system -lm

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
	@echo -e "\e[1;32mRemoving unit_tests object files... \e[0m"
	rm -f $(OBJ_UT)
	@echo -e "\e[1;32mRemoving coverage files...\e[0m"
	rm -f *.gc*

fclean: clean
	@echo -e "\e[1;32mRemoving $(NAME) binary...\e[0m"
	rm -f $(NAME)
	@echo -e "\e[1;32mRemoving $(NAME_UT) binary... \e[0m"
	rm -f $(NAME_UT)

re: fclean all
