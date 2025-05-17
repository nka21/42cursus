/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:51:36 by nkojima           #+#    #+#             */
/*   Updated: 2025/05/15 19:09:51 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 文字が英数字であることを判定します。
// 「英数字である」とは、「英字である」または「数字である」ことです。
// 真：英数字　　　→0以外を返す
// 偽：英数字以外　→0を返す

int	ft_isalnum(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	return (ft_isalpha(uc) || ft_isdigit(uc));
}

// int	main(void)
// {
// 	printf("ft_isalnum('2'): %d\n", ft_isalnum('2'));
// 	printf("isalnum('2'): %d\n", isalnum('2'));
// 	printf("ft_isalnum('a'): %d\n", ft_isalnum('a'));
// 	printf("isalnum('a'): %d\n", isalnum('a'));
// 	printf("ft_isalnum('?'): %d\n", ft_isalnum('?'));
// 	printf("isalnum('?'): %d\n", isalnum('?'));
// 	return (0);
// }
