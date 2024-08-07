LIBFT_DIR   = libft
MLX_DIR     = MLX42
SRC_DIR     = src
OBJ_DIR     = obj
GNL_DIR     = get_next_line
PRINTF_DIR  = ft_printf  # Añade el directorio de ft_printf

SRCS = main.c errors.c checker.c so_long_utils_a.c so_long_utils_b.c so_long_utils_c.c so_long_utils_d.c flood_fill.c
GNL_SRCS = get_next_line.c get_next_line_utils.c  # Archivos .c en la carpeta get_next_line
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))
GNL_SRCS := $(addprefix $(GNL_DIR)/, $(GNL_SRCS))
ALL_SRCS = $(SRCS) $(GNL_SRCS)
OBJS = $(ALL_SRCS:%.c=$(OBJ_DIR)/%.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
NAME = so_long
INCLUDES = -I . -I ${LIBFT_DIR} -I ${GNL_DIR} -I ${PRINTF_DIR} -I ${MLX_DIR}/include  # Añade el directorio de includes de MLX42 y ft_printf

# Flags para Linux de MLX42
MLX_FLAGS = -L$(MLX_DIR) -lmlx42 -ldl -lglfw -pthread -lm

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
	@$(MAKE) -s -C $(PRINTF_DIR)  # Añade la compilación de ft_printf
	@if [ ! -f $(MLX_DIR)/libmlx42.a ] && [ ! -f $(MLX_DIR)/libmlx42.so ]; then \
		echo "Error: No se encontró la librería MLX42 en $(MLX_DIR)"; \
		exit 1; \
	fi
	@$(CC) $(INCLUDES) $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf $(MLX_FLAGS) -o $(NAME)  # Incluye ft_printf en el enlace

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean  # Añade la limpieza de ft_printf
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean  # Añade la limpieza completa de ft_printf
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
