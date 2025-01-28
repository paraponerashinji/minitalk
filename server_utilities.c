/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:17:19 by aharder           #+#    #+#             */
/*   Updated: 2025/01/28 18:17:57 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	custom_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0 && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	is_null(int *bits_received)
{
	int	i;

	i = 0;
	while (i < MAX_BITS)
	{
		if (bits_received[i] == 1)
			return (0);
		i++;
	}
	return (1);
}

char	compress_bits(int *bits_received)
{
	int		i;
	char	c;

	i = 0;
	while (i < MAX_BITS)
	{
		c = (c << 1) | bits_received[i];
		i++;
	}
	return (c);
}
