/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:54:42 by gmelissi          #+#    #+#             */
/*   Updated: 2021/11/18 20:45:42 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_seq	*ft_seq_new(void)
{
	t_seq	*res;

	res = (t_seq *)malloc(sizeof(t_seq));
	res->flags = (t_flags *)malloc(sizeof(t_flags *));
	if (!res->flags || !res)
		return (NULL);
	res->flags->x = 0;
	res->flags->zpad = 0;
	res->flags->ladj = 0;
	res->flags->bpos = 0;
	res->flags->sign = 0;
	res->width = 0;
	res->prcsn = -1;
	res->tconv = 0;
	res->data = NULL;
	res->next = NULL;
	return (res);
}

void	ft_seq_set(t_seq *seq, char *flg, size_t w, long p)
{
	if (ft_strchr(flg, 35))
		seq->flags->x = 49;
	if (ft_strchr(flg, 48))
		seq->flags->zpad = 49;
	if (ft_strchr(flg, 45))
		seq->flags->ladj = 49;
	if (ft_strchr(flg, 32))
		seq->flags->bpos = 49;
	if (ft_strchr(flg, 43))
		seq->flags->sign = 49;
	seq->width = w;
	seq->prcsn = p;
	return ;
}

void	ft_seq_push(t_seq **seq, t_seq *new)
{
	t_seq	*last;

	if (!*seq)
	{
		*seq = new;
		return ;
	}
	last = *seq;
	while (last->next)
		last = last->next;
	last->next = new;
	return ;
}

void	ft_seq_del(t_seq *seq)
{
	free(seq->flags);
	seq->flags = NULL;
	free(seq->data);
	seq->data = NULL;
	free(seq);
	seq = NULL;
	return ;
}

void	ft_seq_clear(t_seq **seq)
{
	t_seq	*tmp;

	while (*seq)
	{
		tmp = *seq;
		*seq = tmp->next;
		ft_seq_del(tmp);
	}
	*seq = NULL;
	return ;
}
