/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:51:45 by jsanger           #+#    #+#             */
/*   Updated: 2023/04/18 10:51:22 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_puthex_fd(int n, int fd, char c)
{
	int	i;

	i = 0;
	if (n <= 9)
	{
		ft_putchar_fd(n + '0', fd);
		i = 1;
	}
	else if (n >= 10 && n <= 15)
	{
		if (c == 'x')
			ft_putchar_fd(n - 10 + 'a', fd);
		else
			ft_putchar_fd(n - 10 + 'A', fd);
		i = 1;
	}
	else
	{
		i = ft_puthex_fd(n / 16, fd, c) + ft_puthex_fd(n % 16, fd, c);
	}
	return (i);
}
