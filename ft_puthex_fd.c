/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:51:45 by jsanger           #+#    #+#             */
/*   Updated: 2023/04/17 18:53:54 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_puthex_fd(int n, int fd)
{
	if (n <= 9)
	{
		ft_putchar_fd(n + '0', fd);
	}
	else if (n >= 10 && n <= 15)
	{
		ft_putchar_fd(n - 10 + 'a', fd);
	}
	else
	{
		ft_puthex_fd(n / 16, fd);
		ft_puthex_fd(n % 16, fd);
	}
}

int	main(void)
{
	int	num;

	num = 50;
	printf("%x\n", num);
	ft_puthex_fd(num, 1);
	return (0);
}
