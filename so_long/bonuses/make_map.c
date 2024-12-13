/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:48:22 by cfleuret          #+#    #+#             */
/*   Updated: 2024/12/10 17:46:26 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

char	**make_tab(char **map, char **argv)
{
	char	*txt;
	int		fd;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (perror("Error\nError opening file 1."), NULL);
	txt = get_next_line(fd);
	while (txt)
	{
		i++;
		free(txt);
		txt = get_next_line(fd);
	}
	if (i == 0)
		return (perror("Error\nEmpty map file"), NULL);
	close(fd);
	map = malloc(sizeof(char *) * (i + 1));
	if (!map)
		return (perror("Error\nEmpty tab"), NULL);
	map = fill_rows(map, argv);
	return (map);
}

char	**fill_rows(char **map, char **argv)
{
	char	*txt;
	int		fd;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error(map);
	txt = get_next_line(fd);
	while (txt)
	{
		clean_line(txt);
		map[i] = ft_strdup(txt);
		free(txt);
		if (!map[i])
		{
			close(fd);
			return (free_map(map), NULL);
		}
		txt = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	print_img(void *img, int x, int y, t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, img, x * TILE, y * TILE);
}

void	print_map(char **map, t_data *data)
{
	int	x;
	int	y;

	y = 0;
	if (!map || !map[y])
		return ;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0')
				print_img(data->img.floor, x, y, data);
			else if (map[y][x] == '1')
				print_img(data->img.wall, x, y, data);
			else if (map[y][x] == 'C')
				print_img(data->img.item, x, y, data);
			else if (map[y][x] == 'E')
				print_img(data->img.exit_closed, x, y, data);
			else if (map[y][x] == 'P')
				print_img(data->player.down, x, y, data);
			x++;
		}
		y++;
	}
}
