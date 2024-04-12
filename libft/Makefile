FLAGS = -Wall -Wextra -Werror

SRCDIR = srcs
INCDIR = include

# find ./srcs -type f -name "*.c"
# このコマンドで出したものをコピペする
SRCS = $(SRCDIR)/ft_strlen.c

OBJS = $(SRCS:.c=.o)

NAME = libft.a

# テスト関連
TESTSRCDIR = test
TESTSRC = $(TESTSRCDIR)/test_libft.c

all: $(NAME)

$(NAME): $(OBJS)
	ar r $(NAME) $(OBJS)

%.o: %.c
	gcc $(FLAGS) -I$(INCDIR) -c $< -o $@

test: re lib.txt libft.txt
	diff lib.txt libft.txt

%.txt: %
	./$< > $@

lib:$(TESTSRC)
	gcc $(NAME) -I$(INCDIR) $(FLAGS) $^ -o $@

libft:$(TESTSRC)
	gcc $(NAME) -I$(INCDIR) $(FLAGS) $^ -D FT -o $@

clean:
	rm -f $(OBJS)

cleantest:
	rm -f *.txt
	rm -f lib libft

fclean: clean cleantest
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
