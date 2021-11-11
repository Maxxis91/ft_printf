/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:57:41 by gmelissi          #+#    #+#             */
/*   Updated: 2021/10/21 21:04:05 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcnt(char const *s, char c)
{
	size_t	res;

	res = 0;
	if (!s || !*s)
		return (res);
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || !*(s + 1)))
			res++;
		s++;
	}
	return (res);
}

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s == c)
		s++;
	while (*s && *s++ != c)
		len++;
	return (len);
}

static char	**ft_free_2d(char **ar)
{
	size_t	i;

	i = 0;
	while (ar[i])
	{
		free(ar[i]);
		ar[i++] = NULL;
	}
	free(ar);
	ar = NULL;
	return (ar);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	cnt;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	cnt = ft_wordcnt(s, c);
	res = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < cnt)
	{
		len = ft_wordlen(s, c) + 1;
		while (*s == c)
			s++;
		res[i] = (char *)malloc(len);
		if (!res[i])
			return (ft_free_2d(res));
		ft_strlcpy(res[i++], s, len);
		s += len;
	}
	res[i] = NULL;
	return (res);
}
