/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_char_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:00:15 by cfleuret          #+#    #+#             */
/*   Updated: 2024/12/16 14:28:02 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	pos(char **map, t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				data->player.pos_x = x;
				data->player.pos_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	down_char(char **map, t_data *data)
{
	if (map[data->player.pos_y + 1][data->player.pos_x] != '1'
			&& map[data->player.pos_y + 1][data->player.pos_x] != 'E'
			&& data->score != 0)
	{
		actions(data, 0, 1);
		score(data);
		ft_exit(data);
	}
	else if (map[data->player.pos_y + 1][data->player.pos_x] != '1'
			&& data->score == 0)
	{
		actions(data, 0, 1);
		score(data);
		ft_exit(data);
	}
}

void	up_char(char **map, t_data *data)
{
	if (map[data->player.pos_y - 1][data->player.pos_x] != '1'
			&& map[data->player.pos_y - 1][data->player.pos_x] != 'E'
			&& data->score != 0)
	{
		actions(data, 0, -1);
		score(data);
		ft_exit(data);
	}
	else if (map[data->player.pos_y - 1][data->player.pos_x] != '1'
			&& data->score == 0)
	{
		actions(data, 0, -1);
		score(data);
		ft_exit(data);
	}
}

void	right_char(char **map, t_data *data)
{
	if (map[data->player.pos_y][data->player.pos_x + 1] != '1'
			&& map[data->player.pos_y][data->player.pos_x + 1] != 'E'
			&& data->score != 0)
	{
		actions(data, 1, 0);
		score(data);
		ft_exit(data);
	}
	else if (map[data->player.pos_y][data->player.pos_x + 1] != '1'
			&& data->score == 0)
	{
		actions(data, 1, 0);
		score(data);
		ft_exit(data);
	}
}

void	left_char(char **map, t_data *data)
{
	if (map[data->player.pos_y][data->player.pos_x - 1] != '1'
			&& map[data->player.pos_y][data->player.pos_x - 1] != 'E'
			&& data->score != 0)
	{
		actions(data, -1, 0);
		score(data);
		ft_exit(data);
	}
	else if (map[data->player.pos_y][data->player.pos_x - 1] != '1'
			&& data->score == 0)
	{
		actions(data, -1, 0);
		score(data);
		ft_exit(data);
	}
}
