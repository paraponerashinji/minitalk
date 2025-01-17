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
//#include "libft.h"
#include <signal.h>
#include <stdlib.h>
#define MAX_BITS 8

size_t ft_strlen2(const char *str) {
    size_t length = 0;
    // Parcours de la chaîne de caractères jusqu'à atteindre le caractère nul '\0'
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dst);
}

void	*ft_realloc(void *ptr, int old_size, int new_size)
{
    void	*new_ptr;

    if (new_size == 0)
    {
        free(ptr);
        return (NULL);
    }
    if (ptr == NULL)
        return (malloc(new_size));
    new_ptr = malloc(new_size);
    if (new_ptr && ptr)
    {
        ft_memcpy(new_ptr, ptr, old_size);
        free(ptr);
    }
    return (new_ptr);
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
	int	i;
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
   
    if (message != NULL)
    	i = ft_strlen2(message);
    else
	    i = 0;
    message = ft_realloc(message, i * sizeof(char), (i + 2) * sizeof(char)); // +2 for new char and '\0'
    message[i] = c;
    message[i + 1] = '\0';
    return (message);
}

void	printmessage(int signal)
{
	static int	current_bit = 0;
	static int	bits_received[MAX_BITS];
	static char	*str = NULL;
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
			free(str);
			str = NULL;
		}
		else
		{
			c = compress_bits(bits_received);
			str = join_char(str, c);
		}
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
