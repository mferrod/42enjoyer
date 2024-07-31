LIBFT_DIR   = libft
SRC_DIR     = src
OBJ_DIR     = obj
GNL_DIR     = get_next_line

SRCS = main.c errors.c checker.c so_long_utils_a.c
GNL_SRCS = get_next_line.c get_next_line_utils.c  # Archivos .c en la carpeta get_next_line
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))
GNL_SRCS := $(addprefix $(GNL_DIR)/, $(GNL_SRCS))
ALL_SRCS = $(SRCS) $(GNL_SRCS)
OBJS = $(ALL_SRCS:%.c=$(OBJ_DIR)/%.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
NAME = so_long
INCLUDES = -I . -I ${LIBFT_DIR} -I ${GNL_DIR}  # Añade el directorio de includes de get_next_line

all: $(NAME)

# Regla general para compilar archivos .c a archivos .o
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)/$(SRC_DIR) $(OBJ_DIR)/$(GNL_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Regla para crear los directorios necesarios en obj/
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/$(SRC_DIR):
	@mkdir -p $(OBJ_DIR)/$(SRC_DIR)

$(OBJ_DIR)/$(GNL_DIR):
	@mkdir -p $(OBJ_DIR)/$(GNL_DIR)

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
