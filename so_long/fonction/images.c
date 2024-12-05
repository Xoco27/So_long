/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:43:30 by cfleuret          #+#    #+#             */
/*   Updated: 2024/12/04 13:52:42 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include "mlx/mlx.h"
void	wh(t_data *data)
{
	data->img.width = 128;
	data->img.height = 128;
	data->player.width = 96;
	data->player.height = 96;
}

void	create_images(t_data *data)
{
	data->img.wall = mlx_xpm_file_to_image(data->mlx_ptr, "assets/wall.xpm",
			&data->img.width, &data->img.height);
	data->img.floor = mlx_xpm_file_to_image(data->mlx_ptr, "assets/floor.xpm",
			&data->img.width, &data->img.height);
	data->img.background = mlx_xpm_file_to_image(data->mlx_ptr, "assets/background.xpm",
			&data->img.width, &data->img.height);
	data->img.exit_closed = mlx_xpm_file_to_image(data->mlx_ptr, "assets/door_closed.xpm",
			&data->img.width, &data->img.height);
	data->img.exit_opened = mlx_xpm_file_to_image(data->mlx_ptr, "assets/door_opened.xpm",
			&data->img.width, &data->img.height);
	data->img.item = mlx_xpm_file_to_image(data->mlx_ptr, "assets/item.xpm",
			&data->img.width, &data->img.height);
	data->img.spawn = mlx_xpm_file_to_image(data->mlx_ptr, "assets/spawn.xpm",
			&data->img.width, &data->img.height);
	data->player.up = mlx_xpm_file_to_image(data->mlx_ptr, "assets/link_up.xpm",
			&data->player.width, &data->player.height);
	data->player.down = mlx_xpm_file_to_image(data->mlx_ptr, "assets/link_down.xpm",
			&data->player.width, &data->player.height);
	data->player.right = mlx_xpm_file_to_image(data->mlx_ptr, "assets/link_right.xpm",
			&data->player.width, &data->player.height);
	data->player.left = mlx_xpm_file_to_image(data->mlx_ptr, "assets/link_left.xpm",
			&data->player.width, &data->player.height);
}