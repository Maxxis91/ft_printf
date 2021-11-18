/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:29:27 by gmelissi          #+#    #+#             */
/*   Updated: 2021/11/18 21:35:58 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_q_fmt(t_seq *seq, va_list ap)
{
	while (seq)
	{
		if (!(seq->data))
		{
			if (seq->tconv == 'c')
				(void)ft_set_c(seq, (char)va_arg(ap, int));
			if (seq->tconv == 's')
				(void)ft_set_s(seq, va_arg(ap, char *));
			if (seq->tconv == 'p')
				(void)ft_set_p(seq, va_arg(ap, void *));
			if (ft_strchr("di", seq->tconv))
				(void)ft_set_d(seq, va_arg(ap, int));
			if (seq->tconv == 'u')
				(void)ft_set_u(seq, va_arg(ap, unsigned int));
			if (ft_strchr("xX", seq->tconv))
				(void)ft_set_x(seq, va_arg(ap, unsigned int));
			if (seq->tconv == '%')
				(void)ft_set_c(seq, '%');
		}
		seq = seq->next;
	}
	return ;
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

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_seq	*queue;
	int		res;

	res = 0;
	queue = ft_q_set(fmt);
	va_start(ap, fmt);
	ft_q_fmt(queue, ap);
	va_end(ap);
	res = ft_q_print(queue);
	ft_seq_clear(&queue);
	return (res);
}
