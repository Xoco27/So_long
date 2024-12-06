/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:17:51 by cfleuret          #+#    #+#             */
/*   Updated: 2024/12/06 13:12:23 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
void	clean_line(char *line)
{
	size_t len;
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

int	check_ES(char **map)
{
	int	x;
	int	y;
	int	e;
	int	s;

	y = 0;
	e = 0;
	s = 0;
	while(map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				e++;
			if (map[y][x] == 'P')
				s++;
			x++;
		}
		y++;
	}
	if (e != 1 || s != 1)
		return (1);
	return (0);
}
