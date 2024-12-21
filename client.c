/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:30:02 by aharder           #+#    #+#             */
/*   Updated: 2024/12/21 17:57:59 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	char_to_bin(char c)
{
	char	*bin;
	int	i;
	int	size;
	int	output;

	bin = ft_itoa(c, 2);
	size = ft_strlen(bin);
	i = 0;
	while (i < size)
	{
		output = bin[i] - 48;
		if (output == 1)
			printf("1");
		else if (output == 0)
			printf("0");
		i++;
	}
	output = ft_atoi(bin);
	free(bin);
	printf("\n");
	return (output);
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	*binstr;
	int	i;

	if (argc < 2)
	{
		printf("Mauvaise utilisation");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	binstr = malloc(ft_strlen(argv[2]) * sizeof(int));
	i = 0;
	while (argv[2][i] != '\0')
	{
		binstr[i] = char_to_bin(argv[2][i]);
		i++;
	}
	i = 0;/*
	while (argv[2][i] != '\0')
	{
		printf("%i\n", binstr[i]);
		i++;
	}*/
	return (0);
}
