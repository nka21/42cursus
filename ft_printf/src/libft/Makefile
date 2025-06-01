# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 16:47:58 by nkojima           #+#    #+#              #
#    Updated: 2025/06/01 15:08:14 by nkojima          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################################
#            Settings           #
#################################
NAME      = libft.a
CFLAGS    = -Wall -Wextra -Werror
ARFLAGS   = rcs

#################################
#         Source & Objects      #
#################################
SRC_FILES = strlen \
			putchar_fd \
			putstr_fd
SRCS 	   = $(addprefix ft_, $(addsuffix .c, $(SRC_FILES)))
OBJS       = $(SRCS:.c=.o)

#################################
#            Rules              #
#################################
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
