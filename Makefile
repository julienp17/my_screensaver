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
				framebuffer.c \
				get_animation.c \
				random.c \
				utils.c \
				color_convertion.c \
				animations/rainbow_rain/rainbow_rain.c \
				animations/blizzard/blizzard.c \
				animations/bouncing_ball/bouncing_ball.c \
				animations/circus_circles/circus_circles.c \
				animations/building_windows/building_windows.c \
				animations/rgb_tan/rgb_tan.c \
				animations/random_numbers/random_numbers.c \
				animations/digital_clock/digital_clock.c \
				animations/digital_clock/my_time.c \
				animations/zebra_horizon/zebra_horizon.c \
				animations/ten_print/ten_print.c \
				animations/laser/laser.c \
				animations/laser/photons.c \
				animations/hamon/hamon.c \
				animations/lorenz_attractor/lorenz_attractor.c \
				animations/solar_system/solar_system.c \
				animations/bubble_sort_visualizer/bubble_sort_visualizer.c \
				animations/flowers/flowers.c \
				animations/flowers/flower_create.c \

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

CFLAGS		= 	-W -Wall -Wextra -Werror $(INC) $(LDFLAGS)

LDFLAGS		=	-lcsfml-graphics -lcsfml-system -lm $(MY_LDFLAGS)

LDFLAGS_UT	= 	-lcriterion -lgcov --coverage

MY_LDFLAGS 	=	-L./lib -lmy -lshapes

DBFLAGS 	=	-g -g3 -ggdb

NAME 		= 	my_screensaver

NAME_UT 	= 	unit_tests

all: $(NAME)

$(NAME): makelibs $(OBJ) $(OBJ_M)
	@echo -e "\e[1;32mCompiling $(NAME) binary... \e[0m"
	$(CC) -o $(NAME) $(OBJ_M) $(OBJ) $(CFLAGS)

makelibs:
	make -C ./lib/my/ all
	make -C ./lib/shapes/ all

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
	@echo -e "\e[1;32mCleaning libmy library... \e[0m"
	@make -C ./lib/my/ clean
	@echo -e "\e[1;32mCleaning shapes library... \e[0m"
	@make -C ./lib/my/ clean

fclean: clean
	@echo -e "\e[1;32mRemoving $(NAME) binary...\e[0m"
	rm -f $(NAME)
	@echo -e "\e[1;32mRemoving $(NAME_UT) binary... \e[0m"
	rm -f $(NAME_UT)

re: fclean all
