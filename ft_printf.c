/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:29:27 by gmelissi          #+#    #+#             */
/*   Updated: 2021/11/11 23:48:55 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

void	ft_seq_fmt(t_seq *seq, va_list ap)
{
	while (seq)
	{
		if (!(seq->data))
		{
			if (seq->tconv == 's')
				(void)ft_set_s(seq, va_arg(ap, char *));
			if (seq->tconv == 'c')
				(void)ft_set_c(seq, (char)va_arg(ap, int));
			if (seq->tconv == 'u') // #' '+ = UB with u
				(void)ft_set_u(seq, va_arg(ap, unsigned int));
//			if (ft_strchr("xX", seq->tconv)) // ' '+ = UB with xX
//				(void)ft_set_u(seq, va_arg(ap, unsigned int));
//			if (seq->tconv == 'p')
//				seq->data = va_arg(ap, void *);
//			if (ft_strchr("di", seq->tconv))
//				seq->data = va_arg(ap, int);
		}
		seq = seq->next;
	}
	return ;
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_seq	*queue;
	int		res;

	res = 0;
	queue = ft_q_set(fmt);
	va_start(ap, fmt);
	ft_seq_fmt(queue, ap);
	va_end(ap);
	res = ft_q_print(queue);
	ft_seq_clear(&queue);
	return (res);
}
