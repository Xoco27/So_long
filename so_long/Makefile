INCLUDES = -I/usr/include -Imlx

SO_LONG =	main.c

OBJS = $(SO_LONG:.c=.o)

MLX_DIR = ./mlx

MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

LIBFT = libft/libft.a

NAME = so_long.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

.c.o:
			$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)
			
$(NAME): 	$(OBJS) $(LIBFT) $(MLX_LIB)
			cp $(OBJS) $(LIBFT)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

$(LIBFT):
		$(MAKE) -C libft

$(MLX_LIB):
		@make -C $(MLX_DIR)

all:		$(NAME) $(MLX_FLAGS)

clean:
			$(MAKE) clean -C libft
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME) $(LIBFT)

re:			fclean all

.PHONY:		all clean fclean re
