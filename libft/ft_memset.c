/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:02:33 by nkojima           #+#    #+#             */
/*   Updated: 2025/05/15 19:10:30 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)buf;
	while (n--)
		*ptr++ = (unsigned char)ch;
	return (buf);
}

// int	main(void)
// {
// 	char	buf1[10];
// 	char	buf2[10];

// 	ft_memset(buf1, 'A', sizeof(buf1));
// 	memset(buf2, 'A', sizeof(buf2));
// 	printf("ft: %.*s\n", (int)sizeof(buf1), buf1);
// 	printf("  : %.*s\n", (int)sizeof(buf2), buf2);
// 	return (0);
// }
