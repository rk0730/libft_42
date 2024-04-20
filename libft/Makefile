# コンパイラ
CC = cc
AR = ar r
FLAGS = -Wall -Wextra -Werror
SANITIZE = -fsanitize=address -g

# srcなど

SRCDIR = srcs
INCDIR = include

# find ./srcs -type f -name "*.c"
# このコマンドで出したものをコピペする
SRCS = $(SRCDIR)/ft_isalpha.c \
	$(SRCDIR)/ft_isdigit.c \
	$(SRCDIR)/ft_isalnum.c \
	$(SRCDIR)/ft_isascii.c \
	$(SRCDIR)/ft_isprint.c \
	$(SRCDIR)/ft_strlen.c \
	$(SRCDIR)/ft_memset.c \
	$(SRCDIR)/ft_bzero.c \
	$(SRCDIR)/ft_memcpy.c \
	$(SRCDIR)/ft_memmove.c \
	$(SRCDIR)/ft_memchr.c \
	$(SRCDIR)/ft_memcmp.c \
	$(SRCDIR)/ft_strnstr.c \
	$(SRCDIR)/ft_strlcpy.c \
	$(SRCDIR)/ft_strlcat.c \
	$(SRCDIR)/ft_toupper.c \
	$(SRCDIR)/ft_tolower.c \
	$(SRCDIR)/ft_strchr.c \
	$(SRCDIR)/ft_strrchr.c \
	$(SRCDIR)/ft_strncmp.c \
	$(SRCDIR)/ft_atoi.c \
	$(SRCDIR)/ft_calloc.c \
	$(SRCDIR)/ft_strdup.c \
	$(SRCDIR)/ft_substr.c \
	$(SRCDIR)/ft_strjoin.c \
	$(SRCDIR)/ft_strtrim.c \
	$(SRCDIR)/ft_split.c \
	$(SRCDIR)/ft_itoa.c \
	$(SRCDIR)/ft_strmapi.c \
	$(SRCDIR)/ft_striteri.c \
	$(SRCDIR)/ft_putchar_fd.c \
	$(SRCDIR)/ft_putstr_fd.c \
	$(SRCDIR)/ft_putendl_fd.c \
	$(SRCDIR)/ft_putnbr_fd.c

SRCS += $(SRCDIR)/ft_stradd_first.c
SRCS += $(SRCDIR)/ft_array_add.c

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = $(SRCDIR)/ft_lstnew.c \
	$(SRCDIR)/ft_lstadd_front.c \
	$(SRCDIR)/ft_lstsize.c \
	$(SRCDIR)/ft_lstlast.c \
	$(SRCDIR)/ft_lstadd_back.c \
	$(SRCDIR)/ft_lstdelone.c \
	$(SRCDIR)/ft_lstclear.c \
	$(SRCDIR)/ft_lstiter.c \
	$(SRCDIR)/ft_lstmap.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

NAME = libft.a

# テスト関連
TESTSRCDIR = test
TESTSRC = $(TESTSRCDIR)/test_libft.c

ERRORSRC = $(TESTSRCDIR)/error_libft.c

# ターゲット

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)

%.o: %.c
	$(CC) $(FLAGS) -I$(INCDIR) -c $< -o $@

#メモリリークチェック
leak: libft
	leaks -q -atExit -- ./libft

#セグフォなどの場所を確認する
sanitize: $(TESTSRC)
	$(CC) $(NAME) -I$(INCDIR) $(FLAGS) $(SANITIZE) $^ -D FT -o $@
	./$@

#自分が作ったテスト関連
test: re lib.txt libft.txt
	diff lib.txt libft.txt

%.txt: %
	./$< > $@

lib:$(TESTSRC)
	$(CC) $(NAME) -I$(INCDIR) $(FLAGS) $^ -o $@

libft:$(TESTSRC)
	$(CC) $(NAME) -I$(INCDIR) $(FLAGS) $^ -D FT -o $@

error:$(ERRORSRC)
	$(CC) $(NAME) -I$(INCDIR) $(FLAGS) $^ -o $@
	./$@

#clean関連
clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	rm -rf sanitize.dSYM
	rm -f *.txt lib libft sanitize error

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
