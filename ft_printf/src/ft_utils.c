/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:00:58 by nkojima           #+#    #+#             */
/*   Updated: 2025/06/01 19:17:27 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_put_hex(unsigned int n, char *base)
{
	int		count;
	size_t	base_len;

	base_len = ft_strlen(base);
	count = 0;
	if (n >= base_len)
		count += ft_put_hex(n / base_len, base);
	ft_putchar_fd(base[n % base_len], 1);
	return (count + 1);
}

int	ft_putptr_hex(unsigned long num)
{
	char	*hex_base;
	int		count;
	size_t	base_len;

	hex_base = "0123456789abcdef";
	base_len = ft_strlen(hex_base);
	count = 0;
	if (num >= base_len)
		count += ft_putptr_hex(num / base_len);
	count += ft_print_char(hex_base[num % base_len]);
	return (count);
}

int	ft_put_unsigned(unsigned int n)
{
	char	*decimal_base;
	int		count;
	size_t	base_len;

	decimal_base = "0123456789";
	base_len = ft_strlen(decimal_base);
	count = 0;
	if (n >= base_len)
		count += ft_put_unsigned(n / base_len);
	ft_putchar_fd(decimal_base[n % base_len], 1);
	return (count + 1);
}
