/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:52:07 by aharder           #+#    #+#             */
/*   Updated: 2024/10/24 13:05:44 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFT_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_var_bordel
{
	char	*output;
	int		i;
	int		len;
	int		split;
	int		y;
}	t_var_bordel;

int			ft_atoi(const char *str);
int			ft_isalnum(char c);
int			ft_isalpha(char c);
int			ft_isprint(char c);
int			ft_isascii(int c);
int			ft_isdigit(char c);
void		*ft_bzero(void *ptr, int size);
void		*ft_calloc(unsigned long elementCount, unsigned long elementSize);
char		*ft_itoa(int nb, int base);
void		*ft_memchr(void *source, int searchedChar, int size);
int			ft_memcmp(void *ptr1, void *ptr2, int size);
void		*ft_memcpy(void *dest, const void *source, int size);
void		*ft_memmove(void *dest, const void *source, int size);
void		*ft_memset(void *ptr, int value, int size);
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *str, int fd);
void		ft_putendl_fd(char *s, int fd);
char		**ft_split(const char *str, char c);
char		*ft_strdup(char *src);
char		*ft_strjoin(const char *dest, const char *src);
int			ft_strlcat(char *dest, const char *src, size_t size);
int			ft_strlcpy(char *dest, const char *src, size_t size);
int			ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, unsigned int n);
const char	*ft_strnstr(const char *str, const char *searchedStr, size_t n);
char		*ft_strchr(char *str, int searchedChar);
char		*ft_strrchr(char *str, int searchedChar);
char		*ft_strtrim(const char *str, const char *set);
char		*ft_substr(const char *s, unsigned int start, size_t length);
char		ft_tolower(char str);
char		ft_toupper(char str);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
