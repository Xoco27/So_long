/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:17:44 by cfleuret          #+#    #+#             */
/*   Updated: 2024/12/06 15:06:18 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include "mlx/mlx.h"

int on_destroy(t_data *data)
{
	destroy(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int on_keypress(int keysym, t_data *data)
{
	if (keysym == XK_s)
		down_char(data->map, data);
	if (keysym == XK_w)
		up_char(data->map, data);
	if (keysym == XK_d)
		right_char(data->map, data);
	if (keysym == XK_a)
		left_char(data->map, data);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.win_height = 1080;
	data.win_width = 1920;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.win_width, data.win_height, "Test");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	create_images(&data);
	data.map = make_tab(data.map);
	if (!data.map)
		return (1);
	if (check(data.map) == 1)
		return (1);
	print_map(data.map, &data);
	pos(data.map, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
