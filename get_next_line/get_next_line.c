/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:56:12 by nkojima           #+#    #+#             */
/*   Updated: 2025/06/02 15:27:32 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stored_data = NULL;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*newline_pos;

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		stored_data = ft_strjoin(stored_data, buffer);
		if (ft_strchr(stored_data, '\n'))
			break ;
	}
	if (bytes_read < 0 || (bytes_read == 0 && !stored_data))
	{
		free(stored_data);
		stored_data = NULL;
		return (NULL);
	}
	newline_pos = ft_strchr(stored_data, '\n');
	if (newline_pos)
		*(newline_pos + 1) = '\0';
	return (strdup(stored_data));
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
	{
		printf("Usage: ./a.out FileName");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
