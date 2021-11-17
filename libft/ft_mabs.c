/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mabs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 21:39:51 by gmelissi          #+#    #+#             */
/*   Updated: 2021/11/13 21:51:51 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_min(long a, long b)
{
	if (a < b)
		return (a);
	return (b);
}

long	ft_max(long a, long b)
{
	if (a > b)
		return (a);
	return (b);
}

size_t	ft_smin(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t	ft_smax(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

size_t	ft_abs(long a)
{
	if (a < 0)
		return ((size_t)(-a));
	return ((size_t)(a));
}
