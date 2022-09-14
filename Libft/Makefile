NAME = libft.a
RM = rm -f
FLAGS = -Wall -Wextra -Werror
CC = gcc

SRC = \
	./ft_Additional_func2.c\
	./ft_isthat.c\
	./ft_remain2.c\
	./ft_Additional_func3.c\
	./ft_memory.c\
	./ft_split.c\
	./ft_Additional_func1.c\
	./ft_alloc.c\
	./ft_remain.c\
	./ft_string.c


OBJS = $(SRC:.c=.o)

all: $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rs $(NAME) $(OBJS)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
