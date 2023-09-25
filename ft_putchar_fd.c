/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:32:54 by jsanger           #+#    #+#             */
/*   Updated: 2023/09/25 19:16:58 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	ft_putchar_fd(char c, int fd)
{
	int	i;

	i = write(fd, &c, 1);
	if (i == -1)
		return (-1);
	return (1);
}

// int main()
// {
//     char c;
//     int fd;

//     fd = 1;
//     c = 'c';
//     ft_putchar_fd(c, fd);
// 	return 0;
// }
