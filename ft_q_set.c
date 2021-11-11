/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_q_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 01:36:26 by gmelissi          #+#    #+#             */
/*   Updated: 2021/11/11 22:24:15 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

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
	size_t	prec;
	size_t	width;

	tmp = tok + 1;
	while (ft_strchr("#0- +", *tmp))
		++tmp;
	width = ft_atoi(tmp);
	while (ft_isdigit(*tmp))
		++tmp;
	prec = 1;
	if (*tmp == '.')
		prec = ft_atoi(++tmp);
	while (ft_isdigit(*tmp))
		++tmp;
	ft_seq_set(seq, tok + 1, width, prec);
	seq->tconv = *tmp;
	if (*tmp == 37)
	{
		ft_seq_set(seq, tok + 1, 1, 1);
		seq->data = ft_substr(tmp, 0, 1);
	}
	free(tok);
	return ;
}

static void	ft_seq_set_tok(t_seq *seq, char *tok)
{
	if (*tok != 37)
		ft_set_str(seq, tok);
	else
	{
		ft_set_conv(seq, tok);
		if (seq->tconv == 115)
			seq->prcsn = SIZE_MAX;
	}
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

size_t	ft_q_print(t_seq *seq)
{
	size_t	res;
	size_t	i;
	char	*tmp;

	res = 0;
	while (seq)
	{
		i = seq->width;
		res += i;
		tmp = seq->data;
		while (i--)
			write(1, tmp++, 1);
		seq = seq->next;
	}
	return (res);
}
