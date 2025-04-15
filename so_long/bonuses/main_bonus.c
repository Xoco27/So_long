/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:17:44 by cfleuret          #+#    #+#             */
/*   Updated: 2025/01/31 12:34:44 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	char	*move;

	if (movement(keysym, data) == 1)
	{
		ft_printf("You are dead, you moved %d times.", data->move);
		on_destroy(data);
	}
	if (keysym == XK_Escape)
		on_destroy(data);
	move = ft_itoa(data->move);
	print_img(data->img.wall, 0, 0, data);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xFFFFFF, "Moves:");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 70, 10, 0xFFFFFF, move);
	free(move);
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
	if (check_filename(argv[1]) == 1)
		return (perror("Error\nWrong file extension"), 1);
	data.move = 0;
	data.map = make_tab(data.map, argv);
	if (data.map == NULL)
		return (perror("Error\nEmpty map"), 1);
	if (another_check(&data) == 1)
		return (1);
	if (!data.map)
		return (perror("Error\nMap making failed."), 1);
	set_win(&data);
	if (initiate(&data) == 1)
		return (perror("Error\nFailed to initiate data or window"), 1);
	create_images(&data);
	mlx_loop_hook(data.mlx_ptr, print_foe, &data);
	hook(&data);
	free_map(data.map);
	return (0);
}
