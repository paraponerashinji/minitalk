/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:28:46 by aharder           #+#    #+#             */
/*   Updated: 2025/01/28 16:28:49 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

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
char		*ft_itoa(int nb);
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
void		*ft_realloc(void *ptr, int old_size, int new_size);

/*
	printf
*/

int			ft_printf(const char *str, ...);
int			gettype(char c, va_list args);
int			getargcount(const char *str);
int			findlengthhex(unsigned long int n);
int			findlength(unsigned int n);
int			ft_putchar(char c);
int			ft_putnbr(int n);
int			ft_putstr(char *str);
int			ft_puthexupper(unsigned int n);
int			ft_puthexlower(unsigned int n);
int			ft_putunsignednbr(unsigned int n);
int			ft_putptr(unsigned long int n);
#endif
