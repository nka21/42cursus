#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t cpy_size);

#endif
