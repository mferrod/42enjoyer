NAME	:= philosophers
CFLAGS	:= -g -Wall -Werror -Wextra

SRCS	:= main.c parsing.c inits.c utils.c
	
OBJS	:= ${SRCS:.c=.o}

all: $(NAME)


%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LINK) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re