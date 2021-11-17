/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:33:40 by gmelissi          #+#    #+#             */
/*   Updated: 2021/11/14 22:17:16 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static int	ft_is_zero(t_seq *seq, char *s)
{
	if (seq->flags->bpos)
		seq->flags->sign = 0;
	if (!seq->prcsn && *s == 48)
	{
		seq->width = ft_smax(seq->flags->bpos, seq->flags->sign);
		if (!seq->width)
		{
			free(s);
			s = NULL;
		}
		if (seq->flags->bpos)
			*s = 32;
		if (seq->flags->sign)
			*s = 43;
		seq->data = s;
		return (1);
	}
	return (0);
}

static char	*ft_get_zprec(t_seq *seq, char *s)
{
	char	*res;
	long	len;

	len = ft_smax(seq->prcsn + (*s == 45), ft_strlen(s));
	if (*s != 45 && (seq->flags->bpos || seq->flags->sign))
		++len;
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	ft_bzero(res, len + 1);
	(void)ft_memset(res, 48, len);
	(void)ft_strlcpy(res + len - ft_strlen(s), s, ft_strlen(s) + 1);
	if (*s == 45)
	{
		*(ft_strchr(res, *s)) = 48;
		*res = *s;
	}
	if (*res == 48 && seq->flags->bpos)
		*res = 32;
	if (*res == 48 && seq->flags->sign)
		*res = 43;
	free(s);
	return (res);
}

static char	*ft_get_pad(t_seq *seq, char *s)
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
		(void)ft_strncpy(res, s, ft_strlen(s));
	else
		(void)ft_strncpy(res + seq->width - ft_strlen(s), s, ft_strlen(s) + 1);
	if (!ft_isdigit(*s) && seq->flags->zpad)
	{
		*(ft_strchr(res, *s)) = 48;
		*res = *s;
	}
	free(s);
	return (res);
}

void	*ft_set_d(t_seq *seq, int d)
{
	char	*tmp;
	char	*zprec;
	char	*res;

	tmp = ft_itoa(d);
	if (ft_is_zero(seq, tmp))
		return (NULL);
	if (seq->prcsn >= 0 || seq->flags->ladj)
		seq->flags->zpad = 0;
	seq->prcsn = ft_abs(seq->prcsn);
	zprec = ft_get_zprec(seq, tmp);
	seq->width = ft_smax(seq->width, ft_strlen(zprec));
	res = ft_get_pad(seq, zprec);
	seq->data = res;
	return (res);
}
