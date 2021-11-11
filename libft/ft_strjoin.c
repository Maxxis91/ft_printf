/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:53:27 by gmelissi          #+#    #+#             */
/*   Updated: 2021/10/14 19:46:18 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;
	int		n;

	if (!s1 && !s2)
		return (NULL);
	len = 1;
	if (s1)
		len += ft_strlen(s1);
	if (s2)
		len += ft_strlen(s2);
	res = (char *)malloc(len);
	if (!res)
		return (NULL);
	n = 0;
	if (s1)
		n = ft_strlcpy(res, s1, len);
	if (s2)
		(void)ft_strlcpy(res + n, s2, len - n);
	return (res);
}
