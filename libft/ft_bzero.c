/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:04:48 by nkojima           #+#    #+#             */
/*   Updated: 2025/05/15 21:31:20 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		*ptr++ = 0;
	}
}

int	main(void)
{
	char	buf1[10];
	char	buf2[10];

	ft_bzero(buf1, sizeof(buf1));
	bzero(buf2, sizeof(buf2));
	printf("ft: %.*s\n", (int)sizeof(buf1), buf1);
	printf("  : %.*s\n", (int)sizeof(buf2), buf2);
	return (0);
}
