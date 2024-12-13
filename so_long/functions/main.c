/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:17:44 by cfleuret          #+#    #+#             */
/*   Updated: 2024/12/12 14:46:44 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	set_win(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
		y++;
	x = ft_strlen(data->map[0]);
	data->win_height = y * TILE;
	data->win_width = x * TILE;
}

int	on_destroy(t_data *data)
{
	destroy(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_map(data->map);
	exit(0);
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == XK_s)
		down_char(data->map, data);
	if (keysym == XK_w)
		up_char(data->map, data);
	if (keysym == XK_d)
		right_char(data->map, data);
	if (keysym == XK_a)
		left_char(data->map, data);
	if (keysym == XK_Escape)
		on_destroy(data);
	ft_printf("move: %d\n", data->move);
	if (data->score == 0
		&& data->map[data->player.pos_y][data->player.pos_x] == 'E')
	{
		ft_printf("You won in %d moves !\n", data->move);
		on_destroy(data);
	}
	return (0);
}

void	hook(t_data *data)
{
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, on_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask,
		on_destroy, data);
	mlx_loop(data->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (perror("Error\nNot enough or too much arguments."), 1);
	data.move = 0;
	data.map = make_tab(data.map, argv);
	if (another_check(&data) == 1)
		return (1);
	if (!data.map)
		return (perror("Error\nMap making failed."), 1);
	set_win(&data);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (perror("Error\nFailure initiating mlx."), 1);
	data.win_ptr = mlx_new_window(data.mlx_ptr,
			data.win_width, data.win_height, "So_long");
	if (!data.win_ptr)
		return (perror("Error\nFailure initiating window"), 1);
	create_images(&data);
	print_map(data.map, &data);
	pos(data.map, &data);
	hook(&data);
	free_map(data.map);
	return (0);
}
