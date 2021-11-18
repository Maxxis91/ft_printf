/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:02:10 by gmelissi          #+#    #+#             */
/*   Updated: 2021/11/17 20:39:05 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(long n)
{
	size_t	res;

	res = 1;
	if (!(n / 10))
	{	
		if (n < 0)
			res++;
	}
	else
		res += ft_numlen(n / 10);
	return (res);
}

char	*ft_itoa(long n)
{
	char	*res;
	size_t	len;
	int		sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	len = ft_numlen(n);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	*(res + len--) = '\0';
	while (n / 10)
	{
		*(res + len--) = (char)((sign * (n % 10)) + 48);
		n /= 10;
	}
	*(res + len) = (char)((sign * (n % 10)) + 48);
	if (len)
		*res = '-';
	return (res);
}
