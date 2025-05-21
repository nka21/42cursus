/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 01:15:27 by nkojima           #+#    #+#             */
/*   Updated: 2025/05/21 02:40:17 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Compares the first `n` bytes of two memory areas.
 *
 * This function compares the first `n` bytes of the memory areas `s1` and `s2`.
 *
 * Params:
 * @s1: Pointer to the first memory area.
 * @s2: Pointer to the second memory area.
 * @n: Number of bytes to compare.
 *
 * Return:
 * - 0, if the `s1` and `s2` are equal.
 * - A negative value if `s1` is less than `s2`.
 * - A positive value if `s1` is greater than `s2`.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				cnt;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	cnt = 0;
	while (cnt < n && (*p1 == *p2))
	{
		p1++;
		p2++;
		cnt++;
	}
	if (cnt == n)
		return (0);
	return ((const unsigned char)*p1 - (const unsigned char)*p2);
}

// int	main(void)
// {
// 	size_t		n;
// 	const char	s1[42] = "Hello, world!";
// 	const char	s2[42] = "Helwo, w0rld!";

// 	n = 42;
// 	printf("ft: %d\n", ft_memcmp(s1, s2, n));
// 	printf("  : %d\n", memcmp(s1, s2, n));
// 	return (0);
// }
