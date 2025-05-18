/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:31:38 by nkojima           #+#    #+#             */
/*   Updated: 2025/05/18 19:47:19 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
/**
 * strlcpy linux ugokanai
 */
int	main(void)
{
	char	ft_dst[10];
	size_t	ft_len;

	// char	dst[10];
	// size_t	len;
	ft_len = ft_strlcpy(ft_dst, "Hello, world!", sizeof(ft_dst));
	// len = strlcpy(dst, "Hello, world!", sizeof(dst));
	printf("ft: %s %zu\n", ft_dst, ft_len);
	// printf("  : %s %zu\n", dst, len);
	return (0);
}
