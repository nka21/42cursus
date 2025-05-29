/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 22:44:46 by nkojima           #+#    #+#             */
/*   Updated: 2025/05/29 22:52:41 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_putptr_hex(unsigned long num)
{
    int count;

    count = 0;
    if (num >= 16)
        count += ft_putptr_hex(num / 16);
    if ((num % 16) < 10)
        count += ft_print_char('0' + (num % 16));
    else
        count += ft_print_char('a' + (num % 16 - 10));
    return (count);
}

int ft_print_pointer(void *ptr)
{
    int count;

    count = 0;
    if (!ptr)
        return (write(1, "(nil)", 5));

    count += write(1, "0x", 2);
    count += ft_putptr_hex((unsigned long)ptr);
    return (count);
}