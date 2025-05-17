/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:10:08 by nkojima           #+#    #+#             */
/*   Updated: 2025/05/15 19:10:42 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c)
{
	return ('A' <= c && c <= 'Z');
}

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c + 32);
	return (c);
}

int	main(void)
{
	printf("ft_('a'): %d\n", ft_tolower('a'));
	printf("tolower('a'): %d\n", tolower('a'));
	printf("ft_('A'): %d\n", ft_tolower('A'));
	printf("tolower('A'): %d\n", tolower('A'));
	return (0);
}
