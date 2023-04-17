/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:07:10 by jsanger           #+#    #+#             */
/*   Updated: 2023/04/17 14:56:43 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_check_arg(va_list args, char format)
{
	if (format == 'c')
		ft_putchar_fd((char)va_arg(args, int), 1);
	if (format == 'i' || format == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	if (format == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	if (format == 'u')
		ft_put_unsigned_nbr_fd(va_arg(args, unsigned int), 1);
}

int	ft_printf(const char *format, ...)
{
	int		num_args;
	int		i;
	va_list	args;

	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				ft_putchar_fd(format[i], 1);
			else
				ft_check_arg(args, format[i]);
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	ft_printf("%%Hello %c World %i%s %u\n", 'a', 10, "Hallo", 1234567890);
	printf("%%Hello %c World %i%s %u\n", 'a', 10, "Hallo", 1234567890);
	return (0);
}
