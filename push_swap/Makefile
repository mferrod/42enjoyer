LIBFT_DIR   = libft
LIBFT_PATH = libft/libft.a

SRCS =  main.c errorfuncs.c stacks.c my_funcs_one.c my_funcs_two.c my_funcs_three.c my_funcs_four.c my_funcs_five.c my_funcs_six.c sort_stacks.c rotate.c swap.c reverse_rotate.c push.c
CC = gcc
CFLAGS= -Wall -Werror -Wextra -g #-fsanitize=address -g
OBJ = $(SRCS:.c=.o)
NAME = push_swap
INCLUDES = -I . -I ${LIBFT_DIR}

all: $(NAME)
%.o: %.c
	@${CC} ${FLAGS} $(INCLUDES) -c $^ -o $@

$(NAME): $(OBJ)
	@$(MAKE) -s all bonus -C $(LIBFT_DIR)
	@$(CC) $(INCLUDES) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean reLIBFT_DIR   = libft