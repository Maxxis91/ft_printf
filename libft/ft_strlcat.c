/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:02:00 by gmelissi          #+#    #+#             */
/*   Updated: 2021/10/21 20:44:32 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	const char	*s;
	char		*d;
	size_t		len;

	s = src;
	d = dst;
	while (*d && dstsize > 0)
	{
		d++;
		dstsize--;
	}
	len = d - dst;
	if (dstsize > 0)
	{
		while (*s && dstsize-- > 1)
		{
			*d = *s;
			s++;
			d++;
		}
		*d = '\0';
	}
	return (len + ft_strlen(src));
}
