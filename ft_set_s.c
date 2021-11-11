/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:33:40 by gmelissi          #+#    #+#             */
/*   Updated: 2021/11/11 18:49:39 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char	*ft_get_blnk(t_seq *seq, const char *s)
{
	char	*res;

	res = (char *)malloc(seq->width - ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	ft_bzero(res, seq->width - ft_strlen(s) + 1);
	(void)ft_memset(res, 32, seq->width - ft_strlen(s));
	return (res);
}

static void	ft_set_res(t_seq *seq, char **r, const char *a, const char *b)
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
	return ;
}

void	*ft_set_s(t_seq *seq, char *s)
{
	char	*tmp;
	char	*blnk;
	char	*res;

	if (!s)
		tmp = ft_substr("(null)", 0, ft_smin(seq->prcsn, 6));
	else
		tmp = ft_substr(s, 0, ft_smin(seq->prcsn, ft_strlen(s)));
	seq->width = ft_smax(seq->width, ft_strlen(tmp));
	res = (char *)malloc(seq->width + 1);
	if (!res)
		return (NULL);
	blnk = ft_get_blnk(seq, tmp);
	if (!blnk)
		return (NULL);
	ft_set_res(seq, &res, tmp, blnk);
	free(tmp);
	free(blnk);
	seq->data = res;
	return (res);
}
