# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 16:47:58 by nkojima           #+#    #+#              #
#    Updated: 2025/05/21 17:16:30 by nkojima          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################################
#            Settings           #
#################################
NAME      = libft.a
CC        = cc
CFLAGS    = -Wall -Wextra -Werror
AR        = ar
ARFLAGS   = rcs
RM        = rm -f

#################################
#         Source & Objects      #
#################################
SRC_FILES = isalpha \
			isdigit \
			isalnum \
			isascii \
			isprint \
			strlen \
			memset \
			bzero \
			memcpy \
			memmove \
			strlcpy \
			strlcat \
			toupper \
			tolower \
			strchr \
			strrchr \
			strncmp \
			memchr \
			memcmp \
			strnstr \
			atoi \
			calloc \
			strdup \
			substr \
			strjoin \
			strtrim \
			split \
			itoa \
			strmapi \
			striteri \
			putchar_fd \
			putstr_fd \
			putendl_fd \
			putnbr_fd 
SRCS 	   = $(addprefix ft_, $(addsuffix .c, $(SRC_FILES)))
OBJS       = $(SRCS:.c=.o)

#################################
#            Rules              #
#################################
.PHONY: all clean fclean re

all: $(NAME)

# ライブラリ作成：既存のオブジェクトが変わらなければ再生成しない
$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

# オブジェクト生成：ヘッダが変更されたら再コンパイル
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
