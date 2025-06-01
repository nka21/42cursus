# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/01 14:16:20 by nkojima           #+#    #+#              #
#    Updated: 2025/06/01 16:26:02 by nkojima          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################################
#            Settings           #
#################################
NAME         = libftprintf.a
CFLAGS       = -Wall -Wextra -Werror
ARFLAGS      = rcs

#################################
#         Source Files          #
#################################
PRINTF_FILES = ft_printf \
               ft_utils

CONV_FILES   = ft_print_char \
               ft_print_decimal \
               ft_print_hex_lower \
               ft_print_hex_upper \
               ft_print_integer \
               ft_print_percent \
               ft_print_pointer \
               ft_print_string \
               ft_print_unsigned

LIBFT_FILES  = ft_strlen \
               ft_putchar_fd \
               ft_putstr_fd

#################################
#        Paths & Objects        #
#################################
SRCDIR       = src
CONVDIR      = $(SRCDIR)/conversions
LIBFTDIR     = $(SRCDIR)/libft

PRINTF_SRCS  = $(addprefix $(SRCDIR)/, $(addsuffix .c, $(PRINTF_FILES)))
CONV_SRCS    = $(addprefix $(CONVDIR)/, $(addsuffix .c, $(CONV_FILES)))
LIBFT_SRCS   = $(addprefix $(LIBFTDIR)/, $(addsuffix .c, $(LIBFT_FILES)))

SRCS         = $(PRINTF_SRCS) $(CONV_SRCS) $(LIBFT_SRCS)
OBJS         = $(SRCS:.c=.o)
INCLUDES     = -I./include -I./$(LIBFTDIR)/include

#################################
#            Rules              #
#################################
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

test: $(NAME)
	$(CC) $(CFLAGS) $(INCLUDES) main.c -L. -lftprintf -o test_printf
	./test_printf

clean:
	$(RM) $(OBJS)
	$(RM) test_printf

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test
