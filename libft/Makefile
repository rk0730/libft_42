FLAGS = -Wall -Wextra -Werror

SRCS = ft_strlen.c ft_isdigit.c
OBJS = $(SRCS:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar r $(NAME) $(OBJS)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
