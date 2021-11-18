/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:33:40 by gmelissi          #+#    #+#             */
/*   Updated: 2021/11/18 21:37:21 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_get_pad(t_seq *seq, char c)
{
	char	*res;

	res = (char *)malloc(seq->width + 1);
	if (!res)
		return (NULL);
	ft_bzero(res, seq->width + 1);
	if (seq->flags->zpad)
		(void)ft_memset(res, 48, seq->width);
	else
		(void)ft_memset(res, 32, seq->width);
	if (seq->flags->ladj)
		*res = c;
	else
		*(res + seq->width - 1) = c;
	return (res);
}

void	*ft_set_c(t_seq *seq, char c)
{
	char	*res;

	if (seq->flags->ladj)
		seq->flags->zpad = 0;
	seq->width = ft_smax(seq->width, 1);
	res = ft_get_pad(seq, c);
	seq->data = res;
	return (res);
}
