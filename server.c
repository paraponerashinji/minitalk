/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:22:13 by aharder           #+#    #+#             */
/*   Updated: 2024/12/22 15:38:19 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <signal.h>

#define MAX_BITS 8

void	printmessage(int signal)
{
	static int	current_bit = 0;
	int	bits_received[MAX_BITS];
	char	c;
	int	i;

	if (current_bit < MAX_BITS)
	{
		if (signal == SIGUSR1)
			bits_received[current_bit] = 0;
		else if (signal == SIGUSR2)
			bits_received[current_bit] = 1;
		current_bit++;
	}
	if (current_bit == MAX_BITS)
	{
		i = 0;
		while (i < MAX_BITS)
		{
			c = (c << 1) | bits_received[i];
			i++;
		}
		ft_printf("%c", c);
		current_bit = 0;
	}
}

int	main(void)
{
	ft_printf("Server up !\nServer PID : %i\n", getpid());
	while (1)
	{
		signal(SIGUSR1, printmessage);
		signal(SIGUSR2, printmessage);
		pause();
	}	
}
