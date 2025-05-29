/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 02:45:17 by nkojima           #+#    #+#             */
/*   Updated: 2025/05/30 03:19:18 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Searches for the substring `find` in the string `str`.
 *
 * Params:
 * @str: The string to search in.
 * @find: The substring to search for.
 * @len: The maximum number of characters to search.
 *
 * Return:
 * - A pointer to the first occurrence of `find` in `str`.
 * - `NULL` if `find` is not found within the first `len` characters.
 */
char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	find_len;

	find_len = ft_strlen(find);
	if (!find_len)
		return ((char *)str);
	// TODO: len = 0 で strがNULLの挙動を確認する
	// 本家はセグフォしないけど、これだとしそう?
	while (*str && len >= find_len)
	{
		if (!ft_strncmp(str, find, find_len))
			return ((char *)str);
		str++;
		len--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	str[42] = "Hello, world!";
// 	char	find[42] = "o, w";
// 	size_t	len;

// 	len = 42;
// 	printf("ft: %s\n", ft_strnstr(str, find, len));
// 	printf("  : %s\n", strnstr(str, find, len));
// 	return (0);
// }
