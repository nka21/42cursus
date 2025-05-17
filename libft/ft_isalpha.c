/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:51:31 by nkojima           #+#    #+#             */
/*   Updated: 2025/05/15 19:09:54 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 文字が英字であることを判定します。
// 「英字である」とは、「文字がAからZ もしくはaからzである」ことです。
// 真：英字　　　→0以外を返す
// 偽：英字以外　→0を返す

static int	ft_islower(unsigned char c)
{
	return ('a' <= c && c <= 'z');
}

static int	ft_isupper(unsigned char c)
{
	return ('A' <= c && c <= 'Z');
}

int	ft_isalpha(int c)
{
	unsigned char	uc;

	if (c == EOF)
	{
		return (0);
	}
	uc = (unsigned char)c;
	return (ft_islower(uc) || ft_isupper(uc));
}

// int	main(void)
// {
// 	printf("ft_isalpha('a'): %d\n", ft_isalpha('a'));
// 	printf("isalpha('a'): %d\n", isalpha('a'));
// 	printf("ft_isalpha(0x0f): %d\n", ft_isalpha(0x0f));
// 	printf("isalpha(0x0f): %d\n", isalpha(0x0f));
// 	return (0);
// }
