/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:31:47 by gmelissi          #+#    #+#             */
/*   Updated: 2021/11/13 21:53:02 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	const char	*s;
	char		*d;

	if (len)
	{
		s = src;
		d = dst;
		while (len--)
		{
			*d++ = *s++;
			if (!*s)
			{
				while (len--)
					*d++ = 0;
				break ;
			}
		}
	}
	return (dst);
}
