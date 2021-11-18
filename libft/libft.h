/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:09:01 by gmelissi          #+#    #+#             */
/*   Updated: 2021/11/17 20:40:27 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif
# ifndef LONG_MAX
#  define LONG_MAX 9223372036854775807
# endif
# ifndef SIZE_MAX
#  define SIZE_MAX 18446744073709551615
# endif

int		ft_atoi(const char *src);
void	ft_bzero(void *s, size_t n);
char	*ft_htoa(size_t n);
int		ft_isdigit(int c);
char	*ft_itoa(long n);
size_t	ft_abs(long a);
long	ft_max(long a, long b);
long	ft_min(long a, long b);
size_t	ft_smin(size_t a, size_t b);
size_t	ft_smax(size_t a, size_t b);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_toupper(int c);

#endif
