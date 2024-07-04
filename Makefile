CC			= cc
CFLAGS		= -Wall -Werror -Wextra -Ofast
NAME		= cub3d

SRCS_PATH	= ./sources/
OBJ_PATH	= ./objects/
INC_PATH	= ./includes/
LIBFT_PATH	= ./libft/
LIBFT		= $(LIBFT_PATH)libft.a

LINKS			= -L minilibx-linux/ -lmlx -lXext -lX11
MLX_ARCHIVES	= minilibx-linux/libmlx_Linux.a

SRC		=	error	\
			init	\
			main	\
			parsing	\

INCS		=	-I libft \
				-I minilibx-linux \

SRCS		= $(addsuffix .c, $(addprefix $(SRCS_PATH), $(SRC)))
OBJS		= $(SRCS:$(SRCS_PATH)%.c=$(OBJ_PATH)%.o)
INCS		= -I $(INC_PATH) -I $(LIBFT_PATH)

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	$(MAKE) -C minilibx-linux/
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT) $(MLX_ARCHIVES) $(LINKS)

clean:
	$(MAKE) -C libft/ clean
	$(MAKE) -C minilibx-linux/ clean
	rm -rf $(OBJ_PATH)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re