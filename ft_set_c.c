/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:33:40 by gmelissi          #+#    #+#             */
/*   Updated: 2021/11/11 23:49:30 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char	*ft_get_blnk(t_seq *seq)
{
	char	*res;

	res = (char *)malloc(seq->width + 1);
	if (!res)
		return (NULL);
	ft_bzero(res, seq->width + 1);
	(void)ft_memset(res, 32, seq->width);
	return (res);
}

static void	ft_set_res(t_seq *seq, char **r, char c, const char *b)
{
	(void)ft_strlcpy(*r, b, sizeof(r));
	if (seq->flags->ladj)
		**r = c;
	else
		*(*r + seq->width - 1) = c;
	return ;
}

void	*ft_set_c(t_seq *seq, char c)
{
	char	*blnk;
	char	*res;

	seq->width = ft_smax(seq->width, 1);
	res = (char *)malloc(seq->width + 1);
	if (!res)
		return (NULL);
	blnk = ft_get_blnk(seq);
	if (!blnk)
		return (NULL);
	ft_set_res(seq, &res, c, blnk);
	free(blnk);
	seq->data = res;
	return (res);
}
