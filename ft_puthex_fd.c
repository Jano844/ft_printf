/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:51:45 by jsanger           #+#    #+#             */
/*   Updated: 2023/04/20 11:45:42 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_fd(size_t n, int fd, char c)
{
	int	i;
	int	check;

	i = 0;
	if (n <= 9)
	{
		check = ft_putchar_fd(n + '0', fd);
		if (check == -1)
			return (-1);
		i = 1;
	}
	else if (n >= 10 && n <= 15)
	{
		if (c == 'x')
			check = ft_putchar_fd(n - 10 + 'a', fd);
		else
			check = ft_putchar_fd(n - 10 + 'A', fd);
		if (check == -1)
			return (-1);
		i = 1;
	}
	else
		i = ft_puthex_fd(n / 16, fd, c) + ft_puthex_fd(n % 16, fd, c);
	return (i);
}
