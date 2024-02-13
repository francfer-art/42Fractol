# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 16:36:22 by francfer          #+#    #+#              #
#    Updated: 2024/01/31 11:52:39 by francfer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
NAME_BONUS = fractol_bonus
CC = gcc -Wall -Wextra -Werror
CFLAGS = -I/usr/X11/include
LDFLAGS = -L minilib -L/usr/X11/lib -lmlx -framework OpenGL -framework AppKit -lX11
SRC_DIR = src
SRC_BONUS = src_bonus
OBJ_DIR = obj
OBJ_BONUS_DIR = obj_bonus
FILES = events.c initialization.c main.c math_utils.c rendering.c rendering1.c \
utils.c
FILES_BONUS = events.c initialization.c main_bonus.c math_utils.c rendering.c rendering1.c \
utils.c
SOURCES = $(FILES:%=$(SRC_DIR)/%)
SOURCES_BONUS = $(FILES:%=$(SRC_BONUS)/%)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))
SOURCES_BONUS = $(FILES_BONUS:%=$(SRC_BONUS)/%)
OBJECTS_BONUS = $(patsubst $(SRC_BONUS)/%.c, $(OBJ_BONUS_DIR)/%.o, $(SOURCES_BONUS))

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJECTS_BONUS)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS)/%.c
	@mkdir -p $(OBJ_BONUS_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

norm: 
	@cd src && norminette

norm_bonus: 
	@cd src_bonus && norminette
	
clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(OBJ_BONUS_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re norm norm_bonus