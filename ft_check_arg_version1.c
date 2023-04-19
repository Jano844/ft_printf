/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg_version1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:32:31 by jsanger           #+#    #+#             */
/*   Updated: 2023/04/19 09:32:35 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int	ft_check_arg(va_list args, char format)
// {
// 	int		returnval;
// 	void	*string;

// 	returnval = 0;
// 	if (format == 'c')
// 		returnval += ft_putchar_fd((char)va_arg(args, int), 1);
// 	if (format == 'i' || format == 'd')
// 		returnval += ft_putnbr_fd(va_arg(args, int), 1);
// 	if (format == 's')
// 	{
// 		string = va_arg(args, char *);
// 		if (string != (void *) NULL)
// 			returnval += ft_putstr_fd((char *) string, 1);
// 		else
// 			returnval += ft_putstr_fd("(null)", 1);
// 	}
// 	if (format == 'u')
// 		returnval += ft_put_unsigned_nbr_fd(va_arg(args, unsigned int), 1);
// 	if (format == '%')
// 		returnval += ft_putchar_fd(format, 1);
// 	if (format == 'x' || format == 'X')
// 		returnval += ft_puthex_fd(va_arg(args, unsigned int), 1, format);
// 	if (format == 'p')
// 	{
// 		string = va_arg(args, char *);
// 		returnval += ft_putadress((size_t) & *string);
// 	}
// 	return (returnval);
// }