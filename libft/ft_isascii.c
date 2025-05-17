/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:51:28 by nkojima           #+#    #+#             */
/*   Updated: 2025/05/15 19:10:17 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 文字がASCII文字であることを判定します。
// 「ASCII文字である」とは、文字のASCIIコードが0から127であることです。
// 真：ASCII文字　　　→0以外を返す
// 偽：ASCII文字以外　→0を返す

int	ft_isascii(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	return (0 <= uc && uc <= 127);
}

// int	main(void)
// {
// 	printf("ft_isascii('!'): %d\n", ft_isascii('!'));
// 	printf("isascii('!'): %d\n", isascii('!'));
// 	printf("ft_isascii(EOF): %d\n", ft_isascii(EOF));
// 	printf("isascii(EOF): %d\n", isascii(EOF));
// 	return (0);
// }
