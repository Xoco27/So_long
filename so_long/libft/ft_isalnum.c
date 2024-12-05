/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:55:36 by cfleuret          #+#    #+#             */
/*   Updated: 2024/10/15 09:40:18 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)
{
	if (c < 48 || c > 57)
	{
		if (c < 65 || c > 90)
		{
			if (c < 97 || c > 122)
				return (0);
		}
	}
	return (8);
}

/*int	main(void)
{
	printf("%d", isalnum(100));
	printf("%d", ft_isalnum(48));
	return (0);
}*/
