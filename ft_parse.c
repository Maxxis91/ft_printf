/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:23:58 by gmelissi          #+#    #+#             */
/*   Updated: 2021/11/19 01:12:36 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_get_str(const char *s)
{
	char	*res;
	size_t	len;
	char	*tmp;

	tmp = (char *)s;
	len = 0;
	while (*tmp && *tmp++ != 37)
		++len;
	res = (char *)malloc(++len);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s, len);
	return (res);
}

static char	*ft_get_conv(const char *s, const char *flg, const char *conv)
{
	char	*res;
	size_t	len;
	char	*tmp;

	tmp = (char *)s;
	len = 1;
	if (*(tmp + 1))
	{
		while (ft_strchr(flg, *++tmp))
			++len;
		while (ft_isdigit(*tmp))
			len += ft_isdigit(*tmp++);
		if (*tmp == '.')
			len += (*tmp++ == '.');
		while (ft_isdigit(*tmp))
			len += ft_isdigit(*tmp++);
		len += (ft_strchr(conv, *tmp) != NULL);
	}
	res = (char *)malloc(++len);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s, len);
	return (res);
}

static char	*ft_get_seq(const char *s)
{
	char		*res;
	const char	*flg;
	const char	*conv;

	if (!s)
		return (NULL);
	flg = "#0- +";
	conv = "cspdiuxX%";
	if (*s != 37)
		res = ft_get_str(s);
	else
		res = ft_get_conv(s, flg, conv);
	return (res);
}

static size_t	ft_cnt_seq(const char *s)
{
	size_t	res;
	char	*tmp;

	res = 1;
	while (*s)
	{
		tmp = ft_get_seq(s);
		s += ft_strlen(tmp);
		res++;
		free(tmp);
	}	
	return (res);
}

char	**ft_parse(const char *s)
{
	char	**tmp;
	size_t	len;
	size_t	cnt;
	char	**res;

	if (!s)
		return (NULL);
	len = 0;
	cnt = ft_cnt_seq(s);
	res = (char **)malloc(sizeof(char *) * ++cnt);
	if (!res)
		return (NULL);
	tmp = res;
	while (*s)
	{
		*tmp = ft_get_seq(s);
		len = ft_strlen(*tmp);
		s += len;
		tmp++;
	}
	*tmp = NULL;
	return (res);
}
