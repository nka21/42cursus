/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:54:29 by nkojima           #+#    #+#             */
/*   Updated: 2025/05/21 18:16:17 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Calculates the length of a string.
 *
 * Params:
 * @str: The string to measure.
 *
 * Return:
 * The number of characters in the string (excluding the null terminator).
 */
size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

// int	main(void)
// {
// 	printf("ft_strlen(): %zu\n", ft_strlen("42tokyo"));
// 	printf("strlen(): %lu\n", strlen("42tokyo"));
// 	printf("ft_strlen(): %zu\n", ft_strlen("あいうえお"));
// 	printf("strlen(): %lu\n", strlen("あいうえお"));
// 	printf("ft_strlen(): %zu\n", ft_strlen(NULL));
// 	printf("strlen(): %lu\n", strlen(NULL));
// 	return (0);
// }
