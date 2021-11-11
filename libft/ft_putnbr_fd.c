/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:36:35 by gmelissi          #+#    #+#             */
/*   Updated: 2021/10/21 21:35:17 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (fd < 0)
		return ;
	if (n == INT_MIN)
		write(fd, "-2147483648", 11);
	else
	{
		if (n >= 0 && n <= 9)
		{
			c = n + 48;
			write(fd, &c, 1);
		}	
		if (n < 0)
		{
			write (fd, "-", 1);
			ft_putnbr_fd(-n, fd);
		}
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
	}
}
