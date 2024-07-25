LIBFT_DIR   = libft
LIBFT_PATH = libft/libft.a

SRCS =  main.c errorfuncs.c stacks.c my_funcs.c my_funcs2.c my_funcs3.c my_funcs4.c my_funcs5.c my_funcs6.c sort_stacks.c rotate.c swap.c reverse_rotate.c push.c
CC = gcc
CFLAGS= -Wall -Werror -Wextra -g
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