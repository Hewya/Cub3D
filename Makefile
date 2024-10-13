# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoutill <amoutill@student.42lehavre.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 03:52:33 by amoutill          #+#    #+#              #
#    Updated: 2024/07/25 23:08:19 by amoutill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

LIBFT_DIR = lib/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDE = $(LIBFT_DIR)

MINILIBX_DIR = lib/minilibx
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx.a
MINILIBX_INCLUDE = $(MINILIBX_DIR)

CFLAGS = -Wall -Wextra -Werror # -g -O0 -fsanitize=address,leak

NAME = cub3d

SRC_FILES = main.c parse_cub_map.c parse_cub_map_utils.c parse_cub_map_utils_1.c parsing_utils.c sanitize_map.c is_valid_map.c is_enclosed.c init_player.c init_game_data.c ft_perror.c init_mlx.c init_textures.c texture.c moves.c minimap.c finding_wall.c ray_stuff.c rendering.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(BUILD_DIR)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB) $(MINILIBX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -L$(MINILIBX_DIR) -o $(NAME) -lmlx -lm -lX11 -lXext

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX_LIB):
	$(MAKE) -C $(MINILIBX_DIR)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MINILIBX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
