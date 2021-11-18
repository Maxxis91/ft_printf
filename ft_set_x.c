/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:33:40 by gmelissi          #+#    #+#             */
/*   Updated: 2021/11/18 20:47:05 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_get_zprec(t_seq *seq, char *s)
{
	char	*res;
	long	len;

	len = ft_smax(seq->prcsn, ft_strlen(s));
	if (seq->flags->x)
		len += 2;
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	ft_bzero(res, len + 1);
	(void)ft_memset(res, 48, len);
	(void)ft_strlcpy(res + len - ft_strlen(s), s, ft_strlen(s) + 1);
	if (seq->flags->x)
		*(res + 1) = 120;
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
	if (seq->flags->x && seq->flags->zpad)
	{
		*(ft_strchr(res, 120)) = 48;
		*(res + 1) = 120;
	}
	free(s);
	return (res);
}

static void	ft_set_88(t_seq *seq, char *s)
{
	char	*tmp;

	tmp = s;
	if (seq->tconv == 88)
	{
		while (*tmp)
		{
			*tmp = ft_toupper(*tmp);
			tmp++;
		}
	}
	return ;
}

void	*ft_set_x(t_seq *seq, unsigned int x)
{
	char	*tmp;
	char	*zprec;
	char	*res;

	seq->flags->x *= (x > 0);
	if (!seq->prcsn && !x)
		tmp = ft_strdup("");
	else
		tmp = ft_htoa(x);
	if (seq->prcsn >= 0 || seq->flags->ladj)
		seq->flags->zpad = 0;
	seq->prcsn = ft_abs(seq->prcsn);
	zprec = ft_get_zprec(seq, tmp);
	seq->width = ft_smax(seq->width, ft_strlen(zprec));
	res = ft_get_pad(seq, zprec);
	ft_set_88(seq, res);
	seq->data = res;
	return (res);
}
