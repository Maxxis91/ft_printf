/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:31:56 by gmelissi          #+#    #+#             */
/*   Updated: 2021/11/11 21:42:38 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_flags
{
	char	x;
	char	zpad;
	char	ladj;
	char	bpos;
	char	sign;
}	t_flags;

typedef struct s_seq
{
	t_flags			*flags;
	size_t			width;
	size_t			prcsn;
	char			tconv;
	char			*data;
	struct s_seq	*next;
}	t_seq;

t_seq	*ft_seq_new(void);
void	ft_seq_set(t_seq *seq, char *flg, size_t w, size_t p);
void	ft_seq_push(t_seq **seq, t_seq *new);
void	ft_seq_del(t_seq *seq);
void	ft_seq_clear(t_seq **seq);
char	**ft_parse(const char *s);
t_seq	*ft_q_set(const char *fmt);
size_t	ft_q_print(t_seq *seq);
void	ft_seq_fmt(t_seq *seq, va_list ap);
int		ft_printf(const char *fmt, ...);
void	*ft_set_s(t_seq *seq, char *s);
void	*ft_set_c(t_seq *seq, char c);
void	*ft_set_u(t_seq *seq, unsigned int n);

#endif
