/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:33:40 by gmelissi          #+#    #+#             */
/*   Updated: 2021/11/18 20:46:36 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_get_zprec(t_seq *seq, char *s)
{
	char	*res;
	long	len;

	if (seq->prcsn < 0 || \
			(seq->prcsn >= 0 && (size_t)seq->prcsn > ft_strlen(s)))
		len = ft_strlen(s) + 1;
	else
		len = seq->prcsn + 1;
	res = (char *)malloc(len);
	if (!res)
		return (NULL);
	ft_bzero(res, len);
	(void)ft_strlcpy(res, s, len);
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
	(void)ft_memset(res, 32, seq->width);
	if (seq->flags->ladj)
		(void)ft_strncpy(res, s, ft_strlen(s));
	else
		(void)ft_strncpy(res + seq->width - ft_strlen(s), s, ft_strlen(s) + 1);
	free(s);
	return (res);
}

void	*ft_set_s(t_seq *seq, char *s)
{
	char	*tmp;
	char	*zprec;
	char	*res;

	if (!s)
		tmp = ft_strdup("(null)");
	else
		tmp = ft_strdup(s);
	zprec = ft_get_zprec(seq, tmp);
	seq->width = ft_smax(seq->width, ft_strlen(zprec));
	res = ft_get_pad(seq, zprec);
	seq->data = res;
	return (res);
}
