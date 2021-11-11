/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:08:09 by gmelissi          #+#    #+#             */
/*   Updated: 2021/10/21 20:19:30 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*n;
	const char	*h;
	size_t		i;

	n = needle;
	h = haystack;
	if (!(*n))
		return ((char *)h);
	if (len)
	{
		while (*h && h < haystack + len)
		{
			i = 0;
			while (h + i < haystack + len && *(h + i) && *(h + i) == *(n + i))
				if (!(*(n + i++ + 1)))
					return ((char *)h);
			h++;
		}
	}
	return (NULL);
}
