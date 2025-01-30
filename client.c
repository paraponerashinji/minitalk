/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:30:02 by aharder           #+#    #+#             */
/*   Updated: 2025/01/28 16:46:41 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>

int	char_to_bin(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << (7 - i)))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i++;
		usleep(100);
	}
	return (i);
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;

	if (argc < 2)
	{
		ft_printf("Mauvaise utilisation");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
	{
		char_to_bin(pid, argv[2][i]);
		i++;
	}
	char_to_bin(pid, '\0');
	i = 0;
	return (0);
}
