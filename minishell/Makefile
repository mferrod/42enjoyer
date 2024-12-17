### // MAKEFILE // ###

NAME	:= minishell
CFLAGS	:=  -Wall -Werror -Wextra \
	-g #-fsanitize=address,undefined \
	#-Wunreachable-code -Ofast 

LIBFT_DIR = ./includes/libft
LIBFT = $(LIBFT_DIR)/libft.a
READLINE = -lreadline -L /Users/$(USER)/.brew/opt/readline/lib -I /Users/$(USER)/.brew/opt/readline/include

HEADERS	:= -I$(LIBFT_DIR)

SRCS	:= src/main.c \
		src/built/ft_cd.c \
		src/built/ft_echo.c \
		src/built/ft_env.c \
		src/built/ft_exit.c \
		src/built/ft_export.c \
		src/built/ft_pwd.c \
		src/built/ft_unset.c \
		src/data/ft_env_index.c \
		src/data/ft_save_env.c \
		src/data/ft_shellevel.c \
		src/data/ft_startup.c \
		src/data/ft_env_ptr.c \
		src/data/ft_start_msg.c \
		src/debug/ft_print_fun.c \
		src/debug/ft_prints.c \
		src/error/errors.c \
		src/exec/ft_eggsecutor.c \
		src/exec/ft_exec_b.c \
		src/exec/ft_execve.c \
		src/exec/ft_multi_cmd.c \
		src/exec/ft_one_cmd.c \
		src/exec/ft_set_io.c \
		src/free/ft_error.c \
		src/free/ft_free_env.c \
		src/free/ft_finish.c \
		src/free/ft_free_cmds.c \
		src/utils/ft_find_node.c \
		src/utils/ft_list_len.c \
		src/utils/ft_permission.c \
		src/utils/ft_search_path.c \
		src/utils/ft_location.c \
		src/parser/ft_tokenizer.c \
		src/parser/ft_quotes.c \
		src/parser/ft_check_nodes.c \
		src/parser/ft_token_expansions.c \
		src/parser/ft_token_expan_utils.c \
		src/parser/ft_dollar_util.c \
		src/parser/ft_commands.c \
		src/parser/ft_setfd.c \
		src/parser/ft_cmd_creator.c \
		src/parser/ft_fds.c \
		src/parser/ft_heredoc.c \
		src/parser/ft_signal.c \
		src/parser/ft_heredoc_utils.c \
		src/parser/ft_is_cmd_token.c \
		src/parser/ft_dollar_st.c \

OBJS	:= ${SRCS:.c=.o}

all: libft $(NAME)

libft:
	@make -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

# Regla general para compilar archivos .c a archivos .o
#$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)/$(SRC_DIR)
#	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(HEADERS) $(LINK) -o $(NAME) $(READLINE)
	@echo "$(NAME) created !"

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBFT_DIR)/*.o

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)

re: fclean all

.PHONY: all clean fclean re libft
