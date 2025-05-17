/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:10:05 by nkojima           #+#    #+#             */
/*   Updated: 2025/05/15 19:10:46 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower(int c)
{
	return ('a' <= c && c <= 'z');
}

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 32);
	return (c);
}

int	main(void)
{
	printf("ft_('a'): %d\n", ft_toupper('a'));
	printf("toupper('a'): %d\n", toupper('a'));
	printf("ft_('A'): %d\n", ft_toupper('A'));
	printf("toupper('A'): %d\n", toupper('A'));
	return (0);
}
