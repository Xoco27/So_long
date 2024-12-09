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
	int		y;
	size_t	len;

	len = 0;
	y = 0;
	len = ft_strlen(map[0]) - 1;
	while (map[y])
	{
		printf("%s\n1\n", map[y]);
		if (ft_strlen(map[y]) - 1!= len)
			return (1);
		y++;
	}
	return (0);
}

int	check_height(char **map)
{
	size_t	len;
	int		y;

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
	int	c;

	c = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				c++;
			x++;
		}
		y++;
	}
	if (c == 0)
		return (0);
	return (c);
}

int	check(char **map)
{
	int	c;
	
	if (check_rect(map) == 0)
		return (perror("Error:\n map is not a rectangle"), 0);
	if (check_height(map) == 0)
		return (perror("Error:\n map's height is not full of 1"), 0);
	if (check_width(map) == 0)
		return (perror("Error:\n map's width is not full of 1"), 0);
	c = check_items(map);
	if (c == 0)
		return (perror("Error:\n map does not have any collectibles"), 0);
	if (check_es(map) == 0)
		return (perror("Error:\n map does not have an exit or a spawn"), 0);
	else
		return (c);
}