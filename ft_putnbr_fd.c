/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:36:57 by jsanger           #+#    #+#             */
/*   Updated: 2023/04/18 11:17:48 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libftprintf.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	i;

	i = 1;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return (11);
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		i++;
	}
	if (n >= 10)
	{
		i += ft_putnbr_fd(n / 10, fd);
	}
	ft_putchar_fd(n % 10 + '0', fd);
	return (i);
}

int	ft_put_unsigned_nbr_fd(unsigned int n, int fd)
{
	int	i;

	i = 1;
	if (n >= 10)
	{
		i += ft_put_unsigned_nbr_fd(n / 10, fd);
	}
	ft_putchar_fd(n % 10 + '0', fd);
	return (i);
}
