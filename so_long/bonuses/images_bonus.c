/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:43:30 by cfleuret          #+#    #+#             */
/*   Updated: 2024/12/13 20:29:34 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	wh(t_data *data)
{
	data->img.width = TILE;
	data->img.height = TILE;
	data->player.width = TILE;
	data->player.height = TILE;
}

void	create_more(t_data *data)
{
	data->img.foe_left = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/foe_left.xpm", &data->img.width, &data->img.height);
	data->img.foe_right = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/foe_right.xpm", &data->img.width, &data->img.height);
	data->player.dead = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/link_dead.xpm", &data->img.width, &data->img.height);
}

void	create_images(t_data *data)
{
	wh(data);
	data->img.wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/wall.xpm", &data->img.width, &data->img.height);
	data->img.floor = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/floor.xpm", &data->img.width, &data->img.height);
	data->img.exit_closed = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/door_closed.xpm", &data->img.width, &data->img.height);
	data->img.exit_opened = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/door_opened.xpm", &data->img.width, &data->img.height);
	data->img.item = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/item.xpm", &data->img.width, &data->img.height);
	data->player.up = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/link_up.xpm", &data->player.width, &data->player.height);
	data->player.down = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/link_down.xpm", &data->player.width, &data->player.height);
	data->player.right = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/link_right.xpm", &data->player.width, &data->player.height);
	data->player.left = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/link_left.xpm", &data->player.width, &data->player.height);
	data->img.foe = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/foe.xpm", &data->img.width, &data->img.height);
	create_more(data);
}

void	destroy(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.wall);
	mlx_destroy_image(data->mlx_ptr, data->img.floor);
	mlx_destroy_image(data->mlx_ptr, data->img.exit_closed);
	mlx_destroy_image(data->mlx_ptr, data->img.exit_opened);
	mlx_destroy_image(data->mlx_ptr, data->img.item);
	mlx_destroy_image(data->mlx_ptr, data->player.up);
	mlx_destroy_image(data->mlx_ptr, data->player.down);
	mlx_destroy_image(data->mlx_ptr, data->player.right);
	mlx_destroy_image(data->mlx_ptr, data->player.left);
	mlx_destroy_image(data->mlx_ptr, data->img.foe);
	mlx_destroy_image(data->mlx_ptr, data->img.foe_left);
	mlx_destroy_image(data->mlx_ptr, data->img.foe_right);
	mlx_destroy_image(data->mlx_ptr, data->player.dead);
}

void	anime(t_data *data, int x, int y)
{
	if (data->img.foe_frame < 20000)
		data->img.img_foe = data->img.foe_left;
	else if (data->img.foe_frame < 40000)
		data->img.img_foe = data->img.foe;
	else if (data->img.foe_frame < 60000)
		data->img.img_foe = data->img.foe_right;
	else
		data->img.foe_frame = 0;
	print_img(data->img.img_foe, x, y, data);
	data->img.foe_frame++;
}
