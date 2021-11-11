/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:07:13 by gmelissi          #+#    #+#             */
/*   Updated: 2021/10/21 19:54:23 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*r;

	if (len > 0)
	{
		r = b;
		while (len > 0)
		{
			*r++ = (unsigned char)c;
			len--;
		}
	}
	return (b);
}
