/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:07:10 by jsanger           #+#    #+#             */
/*   Updated: 2023/04/19 09:09:39 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_arg(va_list args, char format)
{
	int		returnval;
	void	*string;

	returnval = 0;
	if (format == 'c')
		returnval += ft_putchar_fd((char)va_arg(args, int), 1);
	if (format == 'i' || format == 'd')
		returnval += ft_putnbr_fd(va_arg(args, int), 1);
	if (format == 's')
	{
		string = va_arg(args, char *);
		if (string != (void *) NULL)
			returnval += ft_putstr_fd((char *) string, 1);
		else
			returnval += ft_putstr_fd("(null)", 1);
	}
	if (format == 'u')
		returnval += ft_put_unsigned_nbr_fd(va_arg(args, unsigned int), 1);
	if (format == '%')
		returnval += ft_putchar_fd(format, 1);
	if (format == 'x' || format == 'X')
		returnval += ft_puthex_fd(va_arg(args, unsigned int), 1, format);
	if (format == 'p')
	{
		string = va_arg(args, char *);
		returnval += ft_putadress((size_t) & *string);
	}
	return (returnval);
}

int	ft_printf(const char *format, ...)
{
	int		returnval;
	int		i;
	va_list	args;

	i = 0;
	returnval = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			returnval += ft_check_arg(args, format[i]);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			returnval++;
		}
		i++;
	}
	va_end(args);
	return (returnval);
}

// int	main(void)
// {
// 	printf("{{%d}}\n", printf("abcdefg%% %u %s %x", 1234567, "abc", -123));
// 	printf("{{%d}}\n", ft_printf("abcdefg%% %u %s %x", 1234567, "abc", -123));
// 	return (0);
// }
