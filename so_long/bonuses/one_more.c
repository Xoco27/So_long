/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_more.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:37:41 by cfleuret          #+#    #+#             */
/*   Updated: 2025/01/31 12:38:03 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_filename(char *filename)
{
	int	len;

	len = strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".ber", len) != 0)
		return (1);
	return (0);
}
