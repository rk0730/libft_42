# コンパイラ
CC = cc
AR = ar rc
CFLAGS = -Wall -Wextra -Werror

#消去--
SANITIZE = -fsanitize=address -g

# srcなど

SRCDIR = srcs
INCDIR = .

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

ifdef WITH_BONUS
	SRCS += $(BONUS_SRCS)
	OBJS += $(BONUS_OBJS)
endif

NAME = libft.a

# テスト関連--消去
TESTSRCDIR = test
TESTSRC = $(TESTSRCDIR)/test_libft.c

ERRORSRC = $(TESTSRCDIR)/error_libft.c

#テスター関連
TEST1_NAME = libft-tester-tokyo
TEST2_NAME = libft-unit-test
TEST3_NAME = libftTester

# ターゲット

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus:
	make WITH_BONUS=1

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

norm:
	norminette libft.h srcs/
	@echo
	norminette -R CheckDefine libft.h

test1:
	@echo "\n$(TEST1_NAME)\n"
	@if [ ! -d "../$(TEST1_NAME)" ]; then \
		git clone https://github.com/usatie/libft-tester-tokyo.git ../$(TEST1_NAME); \
	fi
	make -C ../$(TEST1_NAME) LIBFT_DIR=../libft/ all
#	make -C ../$(TEST1_NAME) LIBFT_DIR=../libft/ bonus

test2:
	@echo "\n$(TEST2_NAME)\n"
	@if [ ! -d "../$(TEST2_NAME)" ]; then \
		git clone https://github.com/alelievr/libft-unit-test.git ../$(TEST2_NAME); \
	fi
	make -C ../$(TEST2_NAME) f
	make -C ../$(TEST2_NAME) fclean

test3:
	@echo "\n$(TEST3_NAME)\n"
	@if [ ! -d "$(TEST3_NAME)" ]; then \
		git clone https://github.com/Tripouille/libftTester.git $(TEST3_NAME); \
	fi
	make -C $(TEST3_NAME) m
#	make -C $(TEST3_NAME) b
#	make -C $(TEST3_NAME) fclean

review: norm test1 test2 test3 clean

cleantester:
	rm -rf ../$(TEST1_NAME)
	rm -rf ../$(TEST2_NAME)
	rm -rf $(TEST3_NAME)

#---消す

#メモリリークチェック
leak: libft
	leaks -q -atExit -- ./libft

#セグフォなどの場所を確認する
sanitize: $(TESTSRC)
	$(CC) $(NAME) -I$(INCDIR) $(CFLAGS) $(SANITIZE) $^ -D FT -o $@
	./$@

#自分が作ったテスト関連
test: re lib.txt libft.txt
	diff lib.txt libft.txt

%.txt: %
	./$< > $@

lib:$(TESTSRC)
	$(CC) $(NAME) -I$(INCDIR) $(CFLAGS) $^ -o $@

libft:$(TESTSRC)
	$(CC) $(NAME) -I$(INCDIR) $(CFLAGS) $^ -D FT -o $@

error:$(ERRORSRC)
	$(CC) $(NAME) -I$(INCDIR) $(CFLAGS) $^ -o $@
	./$@

#---消す

#clean関連
clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	rm -rf sanitize.dSYM
	rm -f *.txt lib libft sanitize error

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus norm test1 test2 test3 review cleantester clean fclean re
