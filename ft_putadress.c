/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:38:58 by jsanger           #+#    #+#             */
/*   Updated: 2023/04/19 09:05:31 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadress(size_t adress)
{
	int	i;

	i = 2;
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	i += ft_puthex_fd(adress, 1, 'x');
	return (i);
}

// int	main(void)
// {
// 	void	*p;
// 	size_t	i;

// 	i = (size_t) & p;
// 	printf("%p\n", p);
// 	printf("0x");
// 	printf("%zx\n", i);
// 	ft_putadress(i);
// 	printf("\n");
// 	printf("%zu\n", i);
// 	return (0);
// }
