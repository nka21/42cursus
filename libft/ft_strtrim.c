/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:12:01 by nkojima           #+#    #+#             */
/*   Updated: 2025/05/30 03:35:40 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Allocates and returns a copy of `s1` with any leading or
 * trailing characters found in `set` removed.
 *
 * Params:
 * @s1: The string to be trimmed.
 * @set: The string containing the set of characters to be removed.
 *
 * Return
 * A newly allocated trimmed string, or NULL on allocation failure.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	// TODO: s1 と set が とっても大きい数が入っている場合を考慮して、計算量の工夫をしたい
	// 現状 (N)^2 になってるからそれを O(N) にしたい
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, start, end - start));
}

// int	main(void)
// {
// 	char	*s1;
// 	char	*set;

// 	s1 = "1234AAA22331122";I
// 	set = "1234";
// 	printf("%s\n", ft_strtrim(s1, set));
// 	return (0);
// }
