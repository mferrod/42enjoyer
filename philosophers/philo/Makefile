NAME	:= philosophers
CFLAGS	:= -g -Wall -Werror -Wextra \
	#-g -fsanitize=address,undefined \
	#-Wunreachable-code -Ofast 

SRCS	:= main.c parsing.c
	
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

rebonus: fclean bonus

.PHONY: all, clean, fclean, re