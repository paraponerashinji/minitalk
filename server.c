/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:22:13 by aharder           #+#    #+#             */
/*   Updated: 2024/12/22 17:20:25 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <signal.h>

#define MAX_BITS 8

int	is_null(int *bits_received)
{
	int	i;
	
	i = 0;
	while (i < MAX_BITS)
	{
		if (bits_received[i] == 1);
			return (0);
		i++;
	}
	return (1);
}

char	compress_bits(int *bits_received)
{
	int	i;
	
	i = 0;
	while (i < MAX_BITS)
	{
		c = (c << 1) | bits_received[i];
		i++;
	}
	return (c);
}

char	*join_char(char *message, c)
{	
	int	i;
	
	i = ft_strlen(message);
	message = ft_realloc(message, i * sizeof(char));
	message[i] = c;
	return (message);
}

void	printmessage(int signal)
{
	static int	current_bit = 0;
	static int	bits_received[MAX_BITS];
	static char	*str;
	char		c;

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
		if (is_null(bits_received))
		{
			ft_printf("%s", str);
			
		}
		else
		{
			c = compress_bits(bits_received);
			str = join_char(str, c);
		]
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
