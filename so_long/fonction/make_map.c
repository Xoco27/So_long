/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:48:22 by cfleuret          #+#    #+#             */
/*   Updated: 2024/12/05 15:46:44 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	*ft_delete(char **map, int i)
{
	while (--i >= 0)
		free(map[i]);
	free(map);
	perror("Error creating map.");
	return (NULL);
}

char	**make_tab(char **map)
{
	char	*txt;
	int	fd;
	int	i;

	i = 0;
	fd = open("maps/map.ber", O_RDONLY);
	if (fd < 0)
		return (perror("Error opening file 1."), NULL);
	while ((txt = get_next_line(fd)))
	{
		i++;
		free(txt);
	}
	if (i == 0)
		return (perror("Error: Empty map file"), NULL);
	close(fd);
	map = malloc(sizeof(char *) * (i + 1));
	if (!map)
		return (perror("Error: Empty tab"), NULL);
	map = fill_rows(map);
	return (map);
}

char	**fill_rows(char **map)
{
	char	*txt;
	int	fd;
	int	i;

	i = 0;
	fd = open("maps/map.ber", O_RDONLY);
	if (fd < 0)
	{
		free(map);
		return (perror("Error opening file 2."), NULL);
	}
	while ((txt = get_next_line(fd)))
	{
		map[i] = strdup(txt);
		free(txt);
		if (!map[i])
		{
			close(fd);
			return (ft_delete(map, i));
		}
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	print_img(void *img, int x, int y, t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, x * TILE, y * TILE);
}

void	print_map(char **map, t_data *data)
{
	int	x;
	int	y;

	y = 0;
	if (!map || !map[y])
		return;
	while (map[++y])
	{
		x = 0;
		if (!map[y][x])
			break;
		while (map[y][++x])
		{
			if (map[y][x] == '1')
				print_img(data->player.up, x, y, data);
			else if (map[y][x] == '0')
				print_img(data->img.floor, x, y, data);
			else if (map[y][x] == 'C')
				print_img(data->img.item, x, y, data);
			else if (map[y][x] == 'E')
				print_img(data->img.exit_closed, x, y, data);
			else if (map[y][x] == 'P')
				print_img(data->img.spawn, x, y, data);
		}
	}
}