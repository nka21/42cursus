/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 02:45:57 by nkojima           #+#    #+#             */
/*   Updated: 2025/05/21 18:03:31 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

/**
 * Converts a string to an integer.
 *
 * Skips leading whitespace, handles optional `+` or `-` sign, and converts
 * numeric characters to an integer until a non-digit is encountered.
 *
 * Params:
 * @str: The string to convert.
 *
 * Return:
 * The integer value represented by the string.
 */
int	ft_atoi(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (ft_isspace((int)*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (ft_isdigit((int)*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return ((int)(sign * result));
}

// int	main(void)
// {
// 	char	str[42] = "  -42aaa";

// 	printf("ft: %d\n", ft_atoi(str));
// 	printf("  : %d\n", atoi(str));
// 	return (0);
// }
