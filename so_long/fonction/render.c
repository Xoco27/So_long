/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:19:58 by cfleuret          #+#    #+#             */
/*   Updated: 2024/12/05 16:26:29 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	background(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.background,
			data->win_width, data->win_height);
}
