/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 00:07:39 by nkojima           #+#    #+#             */
/*   Updated: 2025/05/30 01:07:13 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int ft_put_unsigned(unsigned int n)
{
    int count;
    
    count = 0;
    if (n >= 10)
        count += ft_put_unsigned(n / 10);
    ft_putchar_fd((n % 10) + '0', 1);
    return (count + 1);
}

int	ft_print_unsigned(unsigned int n)
{
    return (ft_put_unsigned(n));
}