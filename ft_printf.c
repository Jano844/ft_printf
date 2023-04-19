/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:07:10 by jsanger           #+#    #+#             */
/*   Updated: 2023/04/19 12:06:58 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_arg(va_list args, char format)
{
	int		ret;
	void	*str;

	ret = 0;
	if (format == 'c')
		ret += ft_putchar_fd((char)va_arg(args, int), 1);
	else if (format == 'i' || format == 'd')
		ret += ft_putnbr_fd(va_arg(args, int), 1);
	else if (format == 's')
	{
		str = va_arg(args, char *);
		if (str != NULL)
			ret += ft_putstr_fd((char *)str, 1);
		else
			ret += ft_putstr_fd("(null)", 1);
	}
	else if (format == 'u')
		ret += ft_put_unsigned_nbr_fd(va_arg(args, unsigned int), 1);
	else if (format == '%')
		ret += ft_putchar_fd(format, 1);
	else if (format == 'x' || format == 'X')
		ret += ft_puthex_fd(va_arg(args, unsigned int), 1, format);
	else if (format == 'p')
		ret += ft_putadress((size_t)&*va_arg(args, char *));
	return (ret);
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
