/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:06:10 by gmelissi          #+#    #+#             */
/*   Updated: 2021/10/21 19:54:03 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*r;

	r = s;
	while (n > 0)
	{
		if (*r == (unsigned char)c)
			return ((void *)r);
		r++;
		n--;
	}
	return (NULL);
}
