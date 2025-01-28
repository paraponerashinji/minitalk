/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:18:04 by aharder           #+#    #+#             */
/*   Updated: 2025/01/28 18:22:00 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "libft.h"
# include <signal.h>
# include <stdlib.h>

# define MAX_BITS 8

char	*join_char(char *message, char c);
void	sigintfree(char *str);
void	printmessage(int signal);
int		main(void);
int		custom_strlen(const char *str);
int		is_null(int *bits_received);
char	compress_bits(int *bits_received);
#endif
