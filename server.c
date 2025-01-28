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

#include "server.h"

static int	g_k = 0;

char	*join_char(char *message, char c)
{
	int	i;
	int	j;

	if (message != NULL)
		i = ft_strlen(message);
	else
		i = 0;
	j = i;
	if (j == 0)
		j = 1;
	if (i + 1 >= g_k)
	{
		if (g_k == 0)
			g_k = 1;
		g_k *= 2;
		message = ft_realloc(message, i * sizeof(char), g_k);
	}
	message[i] = c;
	message[i + 1] = '\0';
	return (message);
}

void	sigintfree(char *str)
{
	free(str);
	exit(0);
}

void	printandfree(char *str)
{
	ft_printf("%s", str);
	free(str);
	g_k = 0;
}

void	printmessage(int signal)
{
	static int	current_bit = 0;
	static int	bits_received[MAX_BITS];
	static char	*str = NULL;

	if (signal == SIGINT)
		sigintfree(str);
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
			printandfree(str);
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
		signal(SIGINT, printmessage);
		pause();
	}
}
