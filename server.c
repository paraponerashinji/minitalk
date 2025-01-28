/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:22:13 by aharder           #+#    #+#             */
/*   Updated: 2025/01/28 16:47:19 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <signal.h>

#define MAX_BITS 8

int	custom_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0 || str[i] != '\0')
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

char	*join_char(char *message, char c)
{
	int	i;
	int	j;
	int	k;

	if (message != NULL)
	{
		i = ft_strlen(message);
		k = custom_strlen(message);
	}
	else
	{
		i = 0;
		k = 0;
	}
	j = i;
	if (j == 0)
		j = 1;
	if (k >= i - 1)
		message = ft_realloc(message, i * sizeof(char), (j * 2) * sizeof(char));
	message[i] = c;
	message[i + 1] = '\0';
	return (message);
}

void	printmessage(int signal)
{
	static int	current_bit = 0;
	static int	bits_received[MAX_BITS];
	static char	*str = NULL;

	if (current_bit < MAX_BITS)
	{
		if (signal == SIGUSR1)
			bits_received[current_bit++] = 0;
		else if (signal == SIGUSR2)
			bits_received[current_bit++] = 1;
	}
	if (current_bit == MAX_BITS)
	{
		if (is_null(bits_received))
		{
			ft_printf("%s", str);
			free(str);
			str = NULL;
		}
		else
			str = join_char(str, compress_bits(bits_received));
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
