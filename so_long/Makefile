NAME = so_long
BONUS_NAME = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = functions
BONUS_DIR = bonuses
OBJ_DIR = obj
LIBFT_DIR = libft
PRINTF_DIR = ft_printf
MLX_DIR = mlx
ASSETS_DIR = assets
MAPS_DIR = maps

SO_LONG = $(wildcard $(SRC_DIR)/*.c)
SO_LONG_BONUS = $(wildcard $(BONUS_DIR)/*.c)

OBJS = $(SO_LONG:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJB = $(SO_LONG_BONUS:$(BONUS_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = $(LIBFT_DIR)/libft.a
MLX_LIB = $(MLX_DIR)/libmlx.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11

INCLUDES = -I/usr/include -Imlx -I$(LIBFT_DIR) -I$(PRINTF_DIR)

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_FLAGS) $(PRINTF)
	
$(BONUS_NAME): $(OBJB) $(LIBFT) $(MLX_LIB) $(PRINTF)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJB) $(LIBFT) $(MLX_FLAGS) $(PRINTF)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)
	
$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)
	
$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)
	rm -f $(NAME) $(BONUS_NAME)
re: fclean all

.PHONY: all clean fclean re bonus
