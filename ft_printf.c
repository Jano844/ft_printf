/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:07:10 by jsanger           #+#    #+#             */
/*   Updated: 2023/09/25 19:22:02 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_arg(va_list args, char format)
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
	int		check;
	va_list	args;

	i = -1;
	returnval = 0;
	va_start(args, format);
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			check = ft_check_arg(args, format[++i]);
			returnval += check;
		}
		else
		{
			check = ft_putchar_fd(format[i], 1);
			returnval++;
		}
		if (check == -1)
			return (-1);
	}
	va_end(args);
	return (returnval);
}

// int	main(void)
// {
// 	printf("%d\n", ft_printf("%d\n", -100));
// 	printf("%d\n", printf("%d\n", -100));
// 	return (0);
// }
