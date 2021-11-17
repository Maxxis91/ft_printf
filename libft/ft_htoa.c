/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:02:10 by gmelissi          #+#    #+#             */
/*   Updated: 2021/11/14 18:22:15 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(size_t n)
{
	size_t	res;

	res = 1;
	if (!(n / 16))
		return (res);
	else
		res += ft_numlen(n / 16);
	return (res);
}

char	*ft_htoa(size_t n)
{
	char	*b;
	char	*res;
	size_t	len;

	b = "0123456789abcdef";
	len = ft_numlen(n);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	*(res + len--) = '\0';
	while (n / 16)
	{
		*(res + len--) = b[n % 16];
		n /= 16;
	}
	*(res + len) = b[n % 16];
	return (res);
}
