/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:09:40 by cfleuret          #+#    #+#             */
/*   Updated: 2024/12/13 17:42:19 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	timer(void)
{
	unsigned long	i;

	i = 300000000;
	while (i > 0)
		i--;
}

int	print_foe(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'F')
				anime(data, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

void	contact(t_data *data)
{
	int	x;
	int	y;

	x = data->player.pos_x;
	y = data->player.pos_y;
	print_img(data->img.wall, x, y, data);
	print_img(data->player.down, x, y, data);
	mlx_do_sync(data->mlx_ptr);
	timer();
	print_img(data->img.wall, x, y, data);
	print_img(data->player.right, x, y, data);
	mlx_do_sync(data->mlx_ptr);
	timer();
	print_img(data->img.wall, x, y, data);
	print_img(data->player.up, x, y, data);
	mlx_do_sync(data->mlx_ptr);
	timer();
	print_img(data->img.wall, x, y, data);
	print_img(data->player.left, x, y, data);
	mlx_do_sync(data->mlx_ptr);
	timer();
	print_img(data->img.wall, x, y, data);
	print_img(data->player.dead, x, y, data);
	mlx_do_sync(data->mlx_ptr);
	timer();
}

int	movement(int keysym, t_data *data)
{
	if (keysym == XK_s)
	{
		down_char(data->map, data);
		if (data->map[data->player.pos_y][data->player.pos_x] == 'F')
			return (1);
	}
	if (keysym == XK_w)
	{
		up_char(data->map, data);
		if (data->map[data->player.pos_y][data->player.pos_x] == 'F')
			return (1);
	}
	if (keysym == XK_d)
	{
		right_char(data->map, data);
		if (data->map[data->player.pos_y][data->player.pos_x] == 'F')
			return (1);
	}
	if (keysym == XK_a)
	{
		left_char(data->map, data);
		if (data->map[data->player.pos_y][data->player.pos_x] == 'F')
			return (1);
	}
	return (0);
}
