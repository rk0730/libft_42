FLAGS = -Wall -Wextra -Werror

SRCDIR = srcs
INCDIR = .

SRCS = $(SRCDIR)/ft_isdigit.c \
	$(SRCDIR)/ft_strlen.c \
	$(SRCDIR)/ft_bzero.c \
	$(SRCDIR)/ft_memcpy.c \
	$(SRCDIR)/ft_memset.c \
	$(SRCDIR)/ft_memmove.c \
	$(SRCDIR)/ft_calloc.c

OBJS = $(SRCS:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar r $(NAME) $(OBJS)

%.o: %.c
	gcc $(FLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
