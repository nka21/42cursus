/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:20:55 by nkojima           #+#    #+#             */
/*   Updated: 2025/05/30 03:03:12 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_unbr_fd(unsigned int uint_num, int fd)
{
	if (uint_num >= 10)
		put_unbr_fd(uint_num / 10, fd);
	ft_putchar_fd((uint_num % 10) + '0', fd);
}

/**
 * Outputs the integer `n` to the specified file descriptor.
 *
 * Params:
 * @n: The integer to output.
 * @fd: The file descriptor on which to write.
 */
void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	uint_num;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		// TODO: nb の符号反転 校舎環境
		uint_num = nb * -1;
	}
	else
		uint_num = (unsigned int)nb;
	put_unbr_fd(uint_num, fd);
}
