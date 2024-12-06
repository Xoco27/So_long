/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:19:58 by cfleuret          #+#    #+#             */
/*   Updated: 2024/12/06 16:39:02 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	background(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.background,
		data->win_width, data->win_height);
}

void	ft_exit(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	if (data->score == 0)
	{
		while (data->map[y])
		{
			x = 0;
			while (data->map[y][x])
			{
				if (data->map[y][x] == 'E')
					print_img(data->img.exit_opened, x, y, data);
				x++;
			}
			y++;
		}
	}
}
