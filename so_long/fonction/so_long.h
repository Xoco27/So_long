/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:39:20 by cfleuret          #+#    #+#             */
/*   Updated: 2024/12/06 16:39:35 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# ifndef TILE
#  define TILE 128
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>
# include <limits.h>
# include <fcntl.h>
# include <stdint.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libft/libft.h"
# include "mlx/mlx.h"

typedef struct s_map
{
	void	*floor;
	void	*wall;
	void	*background;
	void	*exit_closed;
	void	*exit_opened;
	void	*item;
	void	*spawn;
	int		width;
	int		height;
}		t_map;

typedef struct s_player
{
	void	*up;
	void	*down;
	void	*right;
	void	*left;
	int		width;
	int		height;
	int		pos_x;
	int		pos_y;
}		t_player;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	int			win_width;
	int			win_height;
	int			score;
	t_map		img;
	t_player	player;
}			t_data;

int		main(void);
void	create_images(t_data *data);
char	*get_next_line(int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
void	*ft_delete(char **map, int i);
char	**make_tab(char **map);
char	**fill_rows(char **map);
void	print_img(void *img, int x, int y, t_data *data);
void	print_map(char **map, t_data *data);
int		check(char **map);
void	clean_line(char *line);
void	destroy(t_data *data);
int		check_es(char **map);
void	pos(char **map, t_data *data);
void	down_char(char **map, t_data *data);
void	up_char(char **map, t_data *data);
void	right_char(char **map, t_data *data);
void	left_char(char **map, t_data *data);
void	error(char **map);
void	score(t_data *data);
void	ft_exit(t_data *data);
void	down_char(char **map, t_data *data);
void	up_char(char **map, t_data *data);
void	right_char(char **map, t_data *data);
void	left_char(char **map, t_data *data);
#endif
