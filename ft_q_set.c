/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_q_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 01:36:26 by gmelissi          #+#    #+#             */
/*   Updated: 2021/11/19 01:08:03 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_set_str(t_seq *seq, char *tok)
{
	size_t	len;

	len = ft_strlen(tok);
	ft_seq_set(seq, "", len, len);
	seq->data = tok;
	seq->tconv = 115;
	return ;
}

static void	ft_set_conv(t_seq *seq, char *tok)
{
	char	*tmp;
	char	*flg;
	size_t	prec;
	size_t	width;

	tmp = tok + 1;
	while (ft_strchr("#0- +", *tmp))
		++tmp;
	width = ft_atoi(tmp);
	flg = ft_substr(tok + 1, 0, tmp - tok - 1);
	ft_seq_set(seq, flg, 0, -1);
	while (ft_isdigit(*tmp))
		++tmp;
	prec = -1;
	if (*tmp == '.')
		prec = ft_atoi(++tmp);
	while (ft_isdigit(*tmp))
		++tmp;
	ft_seq_set(seq, "", width, prec);
	seq->tconv = *tmp;
	if (*tmp == 37)
		ft_seq_set(seq, "", ft_smax(seq->width, 1), 1);
	free(flg);
	free(tok);
	return ;
}

static void	ft_seq_set_tok(t_seq *seq, char *tok)
{
	if (*tok != 37)
		ft_set_str(seq, tok);
	else
		ft_set_conv(seq, tok);
	return ;
}

t_seq	*ft_q_set(const char *fmt)
{
	t_seq	*seq;
	t_seq	*tmp;
	char	**res;
	char	**d;
	size_t	len;

	res = ft_parse(fmt);
	seq = NULL;
	d = res;
	while (*res)
	{
		len = ft_strlen(*res) - 1;
		if (**res != 37 || \
			(**res == 37 && len && ft_strchr("cspdiuxX%", *(*res + len))))
		{
			tmp = ft_seq_new();
			ft_seq_set_tok(tmp, *res);
			ft_seq_push(&seq, tmp);
		}
		res++;
	}
	free(d);
	return (seq);
}
