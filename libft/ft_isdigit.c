/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:51:34 by nkojima           #+#    #+#             */
/*   Updated: 2025/05/25 18:00:53 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Checks if a character is a digit (0-9).
 *
 * Params:
 * @c: The character to check.
 *
 * Return:
 * - 1 if the character is a digit.
 * - 0 otherwise.
 */
int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

// int	main(void)
// {
// 	printf("ft_isdigit(): %d\n", ft_isdigit('9'));
// 	printf("isdigit(): %d\n", isdigit('9'));
// 	printf("ft_isdigit(): %d\n", ft_isdigit('a'));
// 	printf("isdigit(): %d\n", isdigit('a'));
// 	return (0);
// }
