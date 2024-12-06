/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:08:57 by cfleuret          #+#    #+#             */
/*   Updated: 2024/12/06 13:13:17 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	check_rect(char	**map)
{
	int	y;
	size_t	len;

	len = 0;
	y = 1;
	len = ft_strlen(map[0]) - 1;
	while(map[y])
	{
		if (ft_strlen(map[y]) - 1 != len)
			return (1);
		y++;
	}
	return (0);
}

int	check_height(char **map)
{
	size_t	len;
	int	y;

	y = 1;
	len = ft_strlen(map[0]) - 1;
	while (map[y])
	{
		if (map[y][0] != '1' || map[y][len] != '1')
			return (1);
		y++;
	}
	return (0);
}

int	check_width(char **map)
{
	int	x;
	int	last_row;

	x = 0;
	last_row = 0;
	while (map[last_row])
		last_row++;
	last_row--;
	while (map[0][x])
	{
		if (map[0][x] != '1' || map[last_row][x] != '1')
			return (1);
		x++;
	}
	return (0);
}

int	check_items(char **map)
{
	int	x;
	int	y;

	y = 0;
	while(map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check(char **map)
{
	if (check_rect(map) == 1)
		return (perror("Error\n: map is not a rectangle"), 1);
	if (check_height(map) == 1)
		return (perror("Error\n: map's height is not full of 1"), 1);
	if (check_width(map) == 1)
		return (perror("Error\n: map's width is not full of 1"), 1);
	if (check_items(map) == 1)
		return (perror("Error\n: map does not have any collectibles"), 1);
	if (check_ES(map) == 1)
		return (perror("Error\n: map does not have an exit or a spawn"), 1);
	else
		return (0);
}
