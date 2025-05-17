/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:51:34 by nkojima           #+#    #+#             */
/*   Updated: 2025/05/15 19:10:20 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 文字が数字であることを判定します。
// 「数字である」とは、「文字が0から9(ASCIIコードでいえば48から57)である」ことです。
// 真：数字　　　→0以外を返す
// 偽：数字以外　→0を返す

int	ft_isdigit(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	return ('0' <= uc && uc <= '9');
}

// int	main(void)
// {
// 	printf("ft_isdigit(): %d\n", ft_isdigit('9'));
// 	printf("isdigit(): %d\n", isdigit('9'));
// 	printf("ft_isdigit(): %d\n", ft_isdigit('a'));
// 	printf("isdigit(): %d\n", isdigit('a'));
// 	return (0);
// }
