LIBFT_DIR   = libft
SRC_DIR     = src
OBJ_DIR     = obj

SRCS = main.c errors.c parser.c childs.c frees.c utils.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))
ALL_SRCS = $(SRCS)
OBJS = $(ALL_SRCS:%.c=$(OBJ_DIR)/%.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g 
NAME = pipex
INCLUDES = -I . -I ${LIBFT_DIR}

all: $(NAME)

# Regla general para compilar archivos .c a archivos .o
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)/$(SRC_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Regla para crear los directorios necesarios en obj/
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/$(SRC_DIR):
	@mkdir -p $(OBJ_DIR)/$(SRC_DIR)

$(NAME): $(OBJS)
	@$(MAKE) -s -C $(LIBFT_DIR)
	@$(CC) $(INCLUDES) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
