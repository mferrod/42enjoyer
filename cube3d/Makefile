LIBFT_DIR   = libft
MLX_DIR     = MLX42
SRC_DIR     = src
OBJ_DIR     = obj
GNL_DIR     = get_next_line

SRCS = main.c errors.c checker.c find_char.c frees.c save_player_pos.c set_tex_color.c load_textures.c
GNL_SRCS = get_next_line.c get_next_line_utils.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))
GNL_SRCS := $(addprefix $(GNL_DIR)/, $(GNL_SRCS))
ALL_SRCS = $(SRCS) $(GNL_SRCS)
OBJS = $(ALL_SRCS:%.c=$(OBJ_DIR)/%.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g 
NAME = cub3D
INCLUDES = -I . -I ${LIBFT_DIR} -I ${GNL_DIR} -I ${MLX_DIR}/include

# Flags para Linux de MLX42
MLX_FLAGS = -L$(MLX_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm

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
	@cmake -S $(MLX_DIR) -B $(MLX_DIR)/build   # Ejecuta cmake en el directorio build
	@$(MAKE) -C $(MLX_DIR)/build
	@if [ ! -f $(MLX_DIR)/build/libmlx42.a ] && [ ! -f $(MLX_DIR)/build/libmlx42.so ]; then \
		echo "Error: No se encontró la librería MLX42 en $(MLX_DIR)/build"; \
		exit 1; \
	fi
	@$(CC) $(INCLUDES) $(OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR)/build clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(MLX_DIR)/build/libmlx42.a
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
