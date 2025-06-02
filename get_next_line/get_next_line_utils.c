/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:56:30 by nkojima           #+#    #+#             */
/*   Updated: 2025/06/02 15:20:12 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * Copies n bytes from memory area src to memory area dst.
 *
 * Params:
 * @dst: The destination memory area.
 * @src: The source memory area.
 * @cpy_size: The number of bytes to copy.
 *
 * Return:
 * A pointer to the destination memory area (dst).
 */
void	*ft_memcpy(void *dst, const void *src, size_t cpy_size)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;

	if (cpy_size == 0 || dst == src)
		return (dst);
	dst_ptr = (unsigned char *)dst;
	src_ptr = (const unsigned char *)src;
	while (cpy_size--)
		*dst_ptr++ = *src_ptr++;
	return (dst);
}

/**
 * Concatenates two strings into a newly allocated string.
 *
 * Params:
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return:
 * A newly allocated string containing `s1` followed by `s2`,
	or NULL on failure.
 */
char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	total_len;
	char	*joined;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	total_len = len1 + len2;
	joined = malloc(sizeof(*joined) * (total_len + 1));
	if (!joined)
		return (NULL);
	if (s1)
		ft_memcpy(joined, s1, len1);
	ft_memcpy(joined + len1, s2, len2);
	joined[total_len] = '\0';
	free(s1);
	return (joined);
}

/**
 * Finds the first occurrence of a character in a string.
 *
 * Params:
 * @s: The string to search.
 * @c: The character to find.
 *
 * Return:
 * A pointer to the first occurrence of the character `c` in the string `s`,
 * or NULL if the character is not found.
 */
char	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}

/**
 * Calculates the length of a string.
 *
 * Params:
 * @str: The string to measure.
 *
 * Return:
 * The number of characters in the string (excluding the null terminator).
 */
size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}
