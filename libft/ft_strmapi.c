/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:22:28 by gmelissi          #+#    #+#             */
/*   Updated: 2021/10/21 21:19:29 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	res = (char *)malloc(++len);
	if (!res)
		return (NULL);
	*(res + --len) = '\0';
	if (len)
		len--;
	while (len)
	{
		*(res + len) = f(len, *(s + len));
		len--;
	}
	*(res + len) = f(len, *(s + len));
	return (res);
}
