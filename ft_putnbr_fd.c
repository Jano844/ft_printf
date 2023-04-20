/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:36:57 by jsanger           #+#    #+#             */
/*   Updated: 2023/04/20 11:40:51 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	if (n == -2147483648)
	{
		if (ft_putstr_fd("-2147483648", fd) == -1)
			return (-1);
		return (11);
	}
	if (n < 0)
	{
		if (ft_putchar_fd('-', fd) == -1)
			return (-1);
		n = -n;
		i++;
	}
	check = ft_put_unsigned_nbr_fd((unsigned int)n, fd);
	i += check;
	if (check == -1)
		return (-1);
	return (i);
}

int	ft_put_unsigned_nbr_fd(unsigned int n, int fd)
{
	unsigned int	i;
	int				check;

	i = 1;
	if (n >= 10)
	{
		check = ft_put_unsigned_nbr_fd(n / 10, fd);
		if (check == -1)
			return (-1);
		i += check;
	}
	if (ft_putchar_fd(n % 10 + '0', fd) == -1)
		return (-1);
	return (i);
}
