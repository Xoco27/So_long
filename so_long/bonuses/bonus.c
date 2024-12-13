/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:09:40 by cfleuret          #+#    #+#             */
/*   Updated: 2024/12/12 16:20:50 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
void	print_foe(t_data *data)
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
				print_img(data->img.foe, x, y, data);
			x++;
		}
		y++;
	}
}

void	timer(void)
{
	int	i;

	i = 60;
	while (i > 0)
		i--;
}

void	bigger_timer(void)
{
	int	i;

	i = 3000000;
	while (i > 0)
		i--;
}

void	contact(t_data *data)
{
	int	x;
	int	y;

	x = data->player.pos_x;
	y = data->player.pos_y;
	print_img(data->img.wall, x, y, data);
	print_img(data->player.right, x, y, data);
	timer();
	print_img(data->img.wall, x, y, data);
	print_img(data->player.up, x, y, data);
	timer();
	print_img(data->img.wall, x, y, data);
	print_img(data->player.left, x, y, data);
	timer();
	print_img(data->img.wall, x, y, data);
	print_img(data->player.down, x, y, data);
	timer();
	print_img(data->img.wall, x, y, data);
	print_img(data->player.dead, x, y, data);
	bigger_timer();
	ft_printf("You are dead, you moved %d times.", data->move);
}
