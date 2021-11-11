/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:56:04 by gmelissi          #+#    #+#             */
/*   Updated: 2021/10/21 20:21:56 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char	*s;
	char		*d;

	s = src;
	d = dst;
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
	return (ft_strlen(src));
}
