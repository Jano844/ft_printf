/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:38:58 by jsanger           #+#    #+#             */
/*   Updated: 2023/04/20 10:51:54 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadress(size_t adress)
{
	int	i;
	int	check;

	i = 2;
	check = ft_putchar_fd('0', 1);
	check = ft_putchar_fd('x', 1);
	if (check == -1)
		return (-1);
	check = ft_puthex_fd(adress, 1, 'x');
	if (check == -1)
		return (-1);
	i += check;
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
