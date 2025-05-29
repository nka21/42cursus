/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 01:30:43 by nkojima           #+#    #+#             */
/*   Updated: 2025/05/30 01:32:33 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int ft_put_hex(unsigned int n, char *base)
{
    int count;
    
    count = 0;
    if (n >= 16)
        count += ft_put_hex(n / 16, base);
    ft_putchar_fd(base[n % 16], 1);
    return (count + 1);
}

int ft_print_hex_lower(unsigned int n)
{
    return (ft_put_hex(n, "0123456789abcdef"));
}

