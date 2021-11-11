/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:33:40 by gmelissi          #+#    #+#             */
/*   Updated: 2021/11/11 23:49:53 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char	*ft_get_zprec(t_seq *seq, char *s)
{
	char	*res;

	res = (char *)malloc(seq->prcsn + 1);
	if (!res)
		return (NULL);
	ft_bzero(res, seq->prcsn + 1);
	(void)ft_memset(res, 48, seq->prcsn);
	(void)ft_strlcpy(res + seq->prcsn - ft_strlen(s), s, ft_strlen(s) + 1);
	free(s);
	return (res);
}

static char	*ft_get_pad(t_seq *seq, const char *s)
{
	char	*res;

	res = (char *)malloc(seq->width - ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	ft_bzero(res, seq->width - ft_strlen(s) + 1);
	if (seq->flags->zpad && !seq->flags->ladj)
		(void)ft_memset(res, 48, seq->width - ft_strlen(s));
	else
		(void)ft_memset(res, 32, seq->width - ft_strlen(s));
	return (res);
}

static void	ft_set_res(t_seq *seq, char **r, char *a, char *b)
{
	if (seq->flags->ladj)
	{
		(void)ft_strlcpy(*r, a, sizeof(r));
		(void)ft_strlcat(*r, b, sizeof(r));
	}
	else
	{
		(void)ft_strlcpy(*r, b, sizeof(r));
		(void)ft_strlcat(*r, a, sizeof(r));
	}
	free(a);
	free(b);
	return ;
}

void	*ft_set_u(t_seq *seq, unsigned int u)
{
	char	*tmp;
	char	*pad;
	char	*zprec;
	char	*res;

	tmp = ft_itoa(u);
	seq->prcsn = ft_smax(seq->prcsn, ft_strlen(tmp));
	seq->width = ft_smax(seq->width, seq->prcsn);
	res = (char *)malloc(seq->width + 1);
	if (!res)
		return (NULL);
	zprec = ft_get_zprec(seq, tmp);
	if (!zprec)
		return (NULL);
	pad = ft_get_pad(seq, zprec);
	if (!pad)
		return (NULL);
	ft_set_res(seq, &res, zprec, pad);
	seq->data = res;
	return (res);
}
