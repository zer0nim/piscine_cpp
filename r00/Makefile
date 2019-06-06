NAME = ft_retro

SRCDIR = srcs

SRC_NAME =	main.cpp \
			AEntity.cpp \
			AMovable.cpp \
			ClockTime.cpp \
			Enemy.cpp \
			EventManager.cpp \
			GameManager.cpp \
			Player.cpp \
			View.cpp \
			Pos.cpp \
			Shape.cpp \
			Bullet.cpp

OBJ_PATH = obj

OBJ_NAME = $(SRC_NAME:.cpp=.o)

SRC = $(SRC_NAME)

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	clang++ -o $(NAME) $(OBJ) -lncurses

$(OBJ_PATH)/%.o: $(SRCDIR)/%.cpp
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	clang++ -c $< $(FLAGS) -I includes/ -o $@

clean:
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
