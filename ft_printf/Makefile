# コンパイラとフラグ
CFLAGS = -Wall -Wextra -Werror

# ソースファイルとオブジェクトファイル
SRCS = src/ft_printf.c \
		src/utils.c \
       $(wildcard src/conversions/*.c) \
       $(wildcard src/libft/*.c)
OBJS = $(SRCS:.c=.o)

# ヘッダーファイルのディレクトリ
INCLUDES = -I./include -I./src/libft/include

# ライブラリ名
NAME = libftprintf.a

# デフォルトターゲット
all: $(NAME)

# ライブラリの作成
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# オブジェクトファイルの作成
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# テスト用ターゲット（提出する必要はない）
test: $(NAME)
	$(CC) $(CFLAGS) $(INCLUDES) main.c -L. -lftprintf -o test_printf
	./test_printf

# クリーンアップ
clean:
	rm -f $(OBJS)
	rm -f test_printf

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test
