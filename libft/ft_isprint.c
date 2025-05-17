/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:43:00 by nkojima           #+#    #+#             */
/*   Updated: 2025/05/15 19:10:22 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 引数の値が、印刷可能文字かどうか
// 印刷可能文字とは、ASCIIコードが32~126である文字のこと
// 真：印刷可能文字　　　→0以外を返す
// 偽：印刷可能文字以外　→0を返す

int	ft_isprint(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	return (32 <= uc && uc <= 126);
}

// int	main(void)
// {
// 	printf("ft_isprint('!'): %d\n", ft_isprint('!'));
// 	printf("isprint('!'): %d\n", isprint('!'));
// 	printf("ft_isprint(EOF): %d\n", ft_isprint(EOF));
// 	printf("isprint(EOF): %d\n", isprint(EOF));
// 	return (0);
// }
