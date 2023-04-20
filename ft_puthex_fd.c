/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:51:45 by jsanger           #+#    #+#             */
/*   Updated: 2023/04/20 13:58:10 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_fd(size_t n, int fd, char c)
{
	int	i;

	i = 0;
	return (num_to_hex(n, fd, c, i));
}

int	num_to_hex(size_t n, int fd, char c, int i)
{
	if (n <= 9)
	{
		if (ft_putchar_fd(n + '0', fd) == -1)
			return (-1);
		i = 1;
	}
	else if (n >= 10 && n <= 15)
	{
		if (c == 'x')
			i = ft_putchar_fd(n - 10 + 'a', fd);
		else
			i = ft_putchar_fd(n - 10 + 'A', fd);
		if (i == -1)
			return (-1);
		i = 1;
	}
	else
	{
		i = ft_puthex_fd(n / 16, fd, c);
		if (i == -1)
			return (-1);
		i += ft_puthex_fd(n % 16, fd, c);
	}
	return (i);
}
