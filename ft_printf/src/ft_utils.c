/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:00:58 by nkojima           #+#    #+#             */
/*   Updated: 2025/05/30 23:10:58 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_put_hex(unsigned int n, char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_put_hex(n / 16, base);
	ft_putchar_fd(base[n % 16], 1);
	return (count + 1);
}

int	ft_putptr_hex(unsigned long num)
{
	int	count;

	count = 0;
	if (num >= 16)
		count += ft_putptr_hex(num / 16);
	if ((num % 16) < 10)
		count += ft_print_char('0' + (num % 16));
	else
		count += ft_print_char('a' + (num % 16 - 10));
	return (count);
}

int	ft_put_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_put_unsigned(n / 10);
	ft_putchar_fd((n % 10) + '0', 1);
	return (count + 1);
}
