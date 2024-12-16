/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:39:20 by cfleuret          #+#    #+#             */
/*   Updated: 2024/12/12 15:52:50 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# ifndef TILE
#  define TILE 128
# endif

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
# include "../mlx/mlx.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_map
{
	void	*floor;
	void	*wall;
	void	*exit_closed;
	void	*exit_opened;
	void	*item;
	void	*spawn;
	void	*img_foe;
	void	*foe;
	void	*foe_right;
	void	*foe_left;
	int		foe_frame;
	int		width;
	int		height;
}		t_map;

typedef struct s_player
{
	void	*up;
	void	*down;
	void	*right;
	void	*left;
	void	*dead;
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
	char		**copy;
	int			win_width;
	int			win_height;
	int			score;
	int			total;
	int			move;
	int			r;
	t_map		img;
	t_player	player;
}			t_data;

void	create_images(t_data *data);
char	*get_next_line(int fd);
void	free_map(char **map);
char	**make_tab(char **map, char **argv);
char	**fill_rows(char **map, char **argv);
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
int		is_map_valid(t_data *data);
int		another_check(t_data *data);
int		print_foe(t_data *data);
void	timer(void);
void	contact(t_data *data);
int		movement(int keysym, t_data *data);
void	make_copy(char **map, char ***copy);
void	anime(t_data *data, int x, int y);
void	actions(t_data *data, int x, int y);
int		non_valid(char **map);
#endif
