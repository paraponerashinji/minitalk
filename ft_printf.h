/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:03:49 by aharder           #+#    #+#             */
/*   Updated: 2024/11/04 16:08:15 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_PRINTF_HEADER_H

#include <stdarg.h>
#include <unistd.h>

//int	main();
// Main corpse
int	ft_printf(const char *str, ...);
int	gettype(char c, va_list args);

// Utilities
int	getargcount(const char *str);
int	ft_strlen(const char *str);
int	findlengthhex(unsigned long int n);
int	findlength(unsigned int n);
// Printers
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putstr(char *str);
int	ft_puthexupper(unsigned int n);
int	ft_puthexlower(unsigned int n);

// More Printers
int	ft_putunsignednbr(unsigned int n);
int	ft_putptr(unsigned long int n);
