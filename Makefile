# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 03:52:33 by amoutill          #+#    #+#              #
#    Updated: 2024/07/24 01:02:00 by amoutill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

LIBFT_DIR = lib/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDE = $(LIBFT_DIR)

MINILIBX_DIR = lib/minilibx-linux
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx.a
MINILIBX_INCLUDE = $(MINILIBX_DIR)

CFLAGS = -Wall -Wextra -Wpedantic -Werror -g -O0 -I include -I minilibx-linux #-fsanitize=address

NAME = cub3d

SRC_FILES = main.c \
			ft_perror.c \
			map_parser/parse_cub_map.c \
			map_parser/parse_cub_map_utils.c \
			map_parser/parse_cub_map_utils_1.c \
			map_parser/parsing_utils.c \
			map_parser/sanitize_map.c \
			map_parser/is_valid_map.c \
			map_parser/is_enclosed.c \
			init/init_player.c \
			init/init_game_data.c \
			init/init_mlx.c \
			init/init_textures.c \
			build_game/drawing_wall.c \
			build_game/finding_wall.c \
			build_game/minimap.c \
			build_game/moves.c \
			build_game/ray_stuff.c \
			build_game/texture.c \


SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(BUILD_DIR)/, $(SRC_FILES:.c=.o))

all: $(BUILD_DIR) $(NAME)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)/build_game
	mkdir -p $(BUILD_DIR)/map_parser
	mkdir -p $(BUILD_DIR)/init

$(NAME): $(OBJS) $(LIBFT_LIB) $(MINILIBX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MINILIBX_LIB) -o $(NAME) -lXext -lX11 -lm

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX_LIB):
	$(MAKE) -C $(MINILIBX_DIR)

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

a: clean all
	codesign -s "Axel Moutillon" --entitlements=get-task-allow.plist ./$(NAME)

.PHONY: all clean fclean re a
