/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 23:33:14 by nkojima           #+#    #+#             */
/*   Updated: 2025/05/30 18:56:42 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Finds the first occurrence of a character in a string.
 *
 * Params:
 * @s: The string to search.
 * @c: The character to find.
 *
 * Return:
 * A pointer to the first occurrence of the character `c` in the string `s`,
 * or NULL if the character is not found.
 */
char	*ft_strchr(const char *str, int c)
{
	char	char_c;

	char_c = (char)c;
	while (*str)
	{
		if (*str == char_c)
			return ((char *)str);
		str++;
	}
	if (char_c == '\0')
		return ((char *)str);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	str[42] = "Hello, world!";

// 	printf("ft: %s\n", ft_strchr(str, '\0'));
// 	printf("  : %s\n", strchr(str, '\0'));
// 	return (0);
// }
