/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:49:28 by jsanger           #+#    #+#             */
/*   Updated: 2023/04/18 11:17:56 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strchr(const char *str, int let)
{
	while ((*str != '\0'))
	{
		if ((unsigned char)*str == (unsigned char)let)
			return ((char *)str);
		str++;
	}
	if ((unsigned char)*str == (unsigned char)let)
		return ((char *)str);
	return (NULL);
}

// int main()
// {
//     char str1[] = "HelloWorld";
//     char str2[] = "HelloWorld";
//     int letter = 'W';

//     printf("%s\n", ft_strchr(str1, letter));
//     //ft_strchr(str1, letter);
//     printf("%s\n", strchr(str2, letter));
//     return(0);
// }

// size_t	i;

// 	i = 0;
// 	while ((str[i] != '\0') && (str[i] != let))
// 	{
// 		i++;
// 	}
// 	if (str[i] == let)
// 	{
// 		return ((char *)str + i);
// 	}
// 	return (NULL);
