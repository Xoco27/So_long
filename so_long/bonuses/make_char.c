/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:00:15 by cfleuret          #+#    #+#             */
/*   Updated: 2024/12/10 17:34:12 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	pos(char **map, t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				data->player.pos_x = x;
				data->player.pos_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	down_char(char **map, t_data *data)
{
	if (map[data->player.pos_y + 1][data->player.pos_x] != '1')
	{
		if (map[data->player.pos_y + 1][data->player.pos_x] == 'F')
		{
			contact(data);
			return ;
		}
		print_img(data->img.floor, data->player.pos_x,
			data->player.pos_y, data);
		data->player.pos_y += 1;
		print_img(data->player.down, data->player.pos_x,
			data->player.pos_y, data);
		data->move++;
		score(data);
		ft_exit(data);
	}
	else
		return ;
}

void	up_char(char **map, t_data *data)
{
	if (map[data->player.pos_y - 1][data->player.pos_x] != '1')
	{
		if (map[data->player.pos_y - 1][data->player.pos_x] == 'F')
		{
			contact(data);
			return ;
		}
		print_img(data->img.floor, data->player.pos_x,
			data->player.pos_y, data);
		data->player.pos_y -= 1;
		print_img(data->player.up, data->player.pos_x,
			data->player.pos_y, data);
		data->move++;
		score(data);
		ft_exit(data);
	}
	else
		return ;
}

void	right_char(char **map, t_data *data)
{
	if (map[data->player.pos_y][data->player.pos_x + 1] != '1')
	{
		if (map[data->player.pos_y][data->player.pos_x + 1] == 'F')
		{
			contact(data);
			bigger_timer();
			data->player.pos_x += 1;
			return ;
		}
		print_img(data->img.floor, data->player.pos_x,
			data->player.pos_y, data);
		data->player.pos_x += 1;
		print_img(data->player.right, data->player.pos_x,
			data->player.pos_y, data);
		data->move++;
		score(data);
		ft_exit(data);
	}
	else
		return ;
}

void	left_char(char **map, t_data *data)
{
	if (map[data->player.pos_y][data->player.pos_x - 1] != '1')
	{
		if (map[data->player.pos_y][data->player.pos_x - 1] == 'F')
		{
			contact(data);
			return ;
		}
		print_img(data->img.floor, data->player.pos_x,
			data->player.pos_y, data);
		data->player.pos_x -= 1;
		print_img(data->player.left, data->player.pos_x,
			data->player.pos_y, data);
		data->move++;
		score(data);
		ft_exit(data);
	}
	else
		return ;
}
