# NAME = cub3D
# CC = cc
# CFLAGS = -Wall -Wextra -Werror

# LIBFT_DIR = ./Libft/
# LIBFT = $(LIBFT_DIR)libft
# LDFLAGS = -L$(LIBFT_DIR)

# MLX_DIR = ./minilibx-linux/
# MLX_LIB = $(MLX_DIR)libmlx.a
# MLX = -L$(MLX_DIR) -lmlx -lXext -lX11

# INC_DIR = includes
# SRC_DIR = 
# SRC_FILES = main.c \


# SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
# OBJS = $(SRCS:.c=.o)

# all: $(NAME)

# $(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
# 	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS) $(MLX) $(LIBFT)

# $(LIBFT): 
# 	make -C $(LIBFT_DIR) 

# $(MLXLIB):
# 	make -C $(MLX_DIR)

# %.o: %.c
# 	$(CC) $(CFLAGS) -Iincludes -c $< -o $@

# clean:
# 	rm -f $(OBJS)

# fclean: clean
# 	rm -f $(NAME)
# 	make -C $(LIBFT_DIR)  fclean
# 	make -C $(MLX_DIR) fclean

# re: fclean all

# .PHONY: all clean fclean re


chihiro:
	cc main.c parse/*.c parse/get_next_line/*.c ./lib/Libft/libft
#make chihiro で実行すればOK！
