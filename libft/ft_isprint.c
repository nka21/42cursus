/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:43:00 by nkojima           #+#    #+#             */
/*   Updated: 2025/05/21 18:20:00 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

/**
 * Checks if a character is printable, including space.
 *
 * Params:
 * @c: The character to check.
 *
 * Return:
 * - 1 if the character is printable.
 * - 0 otherwise.
 */
int	ft_isprint(int c)
{
	return (32 <= c && c <= 126);
}

// int	main(void)
// {
// 	printf("ft_isprint('!'): %d\n", ft_isprint('!'));
// 	printf("isprint('!'): %d\n", isprint('!'));
// 	printf("ft_isprint(EOF): %d\n", ft_isprint(EOF));
// 	printf("isprint(EOF): %d\n", isprint(EOF));
// 	return (0);
// }
