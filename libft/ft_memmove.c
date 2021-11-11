/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:07:00 by gmelissi          #+#    #+#             */
/*   Updated: 2021/11/04 21:53:31 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_setdir(int dir, int *m, int *n)
{
	if (!dir)
	{
		*m = 1;
		*n = 0;
	}
	else
	{
		*m = -1;
		*n = 1;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*s;
	char		*d;
	int			m;
	int			n;

	s = src;
	d = dst;
	if (s != d)
	{
		ft_setdir((d > s && (size_t)s + len > (size_t)d), &m, &n);
		s += ((len - 1) * n);
		d += ((len - 1) * n);
		while (len-- > 0)
		{
			*d = *s;
			s += m;
			d += m;
		}
	}
	return (dst);
}
