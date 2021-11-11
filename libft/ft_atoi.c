/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:01:17 by gmelissi          #+#    #+#             */
/*   Updated: 2021/10/21 20:48:28 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if ((c > 8 && c < 14) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *src)
{
	unsigned long	res;
	int				neg;
	const char		*s;

	s = src;
	res = 0;
	neg = 0;
	while (*s && ft_isspace(*s))
		s++;
	if (*s && (*s == '+' || *s == '-'))
		if (*s++ == '-')
			neg = 1;
	while (*s && ft_isdigit(*s) && res < (unsigned long)LONG_MAX + 1)
		res = res * 10 + *s++ - 48;
	if ((neg && res > (unsigned long)LONG_MAX + 1) \
			|| (!neg && res > (unsigned long)LONG_MAX))
		return (neg - 1);
	if (neg)
		res *= -1;
	return ((int)res);
}
