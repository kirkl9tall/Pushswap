NAME = push_swap
SRC = ft_split.c main.c parssing.c rules.c sort.c utils.c utils2.c
OBJS = $(SRC:.c=.o)

CC = cc
FLAGS = -Wall -Werror -Wextra
RM = rm -rf


all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
clean :
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re