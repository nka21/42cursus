/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:33:34 by nkojima           #+#    #+#             */
/*   Updated: 2025/05/30 23:05:45 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);

int	ft_put_hex(unsigned int n, char *base);
int	ft_putptr_hex(unsigned long num);
int	ft_put_unsigned(unsigned int n);

int	ft_print_char(int c);
int	ft_print_string(char *str);
int	ft_print_pointer(void *ptr);
int	ft_print_decimal(int n);
int	ft_print_integer(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hex_lower(unsigned int n);
int	ft_print_hex_upper(unsigned int n);
int	ft_print_percent(void);

#endif
