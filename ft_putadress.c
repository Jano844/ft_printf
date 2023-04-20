/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:38:58 by jsanger           #+#    #+#             */
/*   Updated: 2023/04/20 13:54:35 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadress(size_t adress)
{
	int	i;
	int	check;

	i = 2;
	if (ft_putchar_fd('0', 1) == -1)
		return (-1);
	if (ft_putchar_fd('x', 1) == -1)
		return (-1);
	check = ft_puthex_fd(adress, 1, 'x');
	if (check == -1)
		return (-1);
	i += check;
	return (i);
}
