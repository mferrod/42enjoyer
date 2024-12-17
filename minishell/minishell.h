/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:36:22 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/16 15:52:05 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define _GNU_SOURCE
# include "includes/libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

# define SHLL_NAME "AweboteShell"
# define UNEX_TOKEN "syntax error near unexcepted token"
# define UNEX_ENOFL "syntax error unexpected end of file"
# define ERROR_Q "unexpected EOF while looking for matching `''"
# define ERROR_DQ "unexpected EOF while looking for matching `\"'"
# define HEDC_CD \
	"warning: here-document \
delimited by end-of-file (wanted `"
# define MALLOC_ERR "Error on malloc assignment"

typedef enum e_token_type
{
	T_PIPE,
	T_QUOTE,
	T_WORD,
	T_DOLLAR,
	T_DQUOTE,
	T_IN,
	T_OUT,
	T_DIN,
	T_DOUT,
}						t_ttype;

typedef struct s_env
{
	char				*key;
	char				*value;
	struct s_env		*next;
}						t_env;

typedef struct s_token
{
	int					id;
	char				*str;
	enum e_token_type	type;
	int					join;
	struct s_token		*next;
}						t_token;

typedef struct s_cmd
{
	int					id;
	char				**argv;
	int					fd_in;
	int					fd_out;
	int					err;
	char				*route;
	int					tube[2];
	struct s_cmd		*next;
}						t_cmd;

typedef struct s_minishell
{
	t_env				*env_list;
	t_token				*tokens;
	t_cmd				*cmds;
	int					shelevel;
	char				**envp;
	char				*location;
	char				*home;
	int					err_state;
	int					err_par;
	int					stdin;
	int					stdout;
}						t_minishell;

extern int				g_mini_signal;

// PARSER
t_token					*ft_new_token_node(char *str, t_ttype type, int join);
t_token					*ft_data_entry(char *str, t_minishell *shell);
void					ft_token_word(char *str, int *i, t_token **tokens);
void					ft_token_dq(char *str, int *i, t_token **tokens,
							t_minishell *shell);
void					ft_token_q(char *str, int *i, t_token **tokens,
							t_minishell *shell);
void					ft_token_out(char *str, int *i, t_token **tokens);
void					ft_token_in(char *str, int *i, t_token **tokens);
void					ft_token_pipe(char *str, int *i, t_token **tokens);
void					ft_lstadd_back_msh(t_token **lst, t_token *new);
int						ft_check_nodes(t_minishell *minishell);
void					ft_expand_tokens(t_token **tokens);
void					ft_set_token_id(t_token **tokens);
void					ft_del_token(t_token **tokens, int id_del);
int						ft_check_seman_token(t_token **tokens,
							t_minishell *mini);
int						ft_check_token_pipes(t_token **tokens,
							t_minishell *mini);
void					ft_token_expansions(t_token **tokens,
							t_minishell *shell);
int						ft_tkn_analyzer(char *str);
void					ft_expand_prime(t_token **token, t_minishell *shell);
void					ft_expand_dollars(t_token **token, t_minishell *shell);
char					*ft_dollar_util(int *i, char *str, t_minishell *mini);
t_cmd					*ft_new_cmd_node(void);
void					ft_lstadd_back_cmd(t_cmd **lst, t_cmd *new);
void					ft_create_cmds(t_minishell *msh, t_token **tkns);
char					**ft_make_cmd_str(t_token **tkn);
void					ft_setfd(t_minishell *msh, t_token **tkns, t_cmd *cmd);
void					ft_set_cmd_id(t_cmd **cmds);
int						ft_count_args(t_token *tkn);
void					ft_cmd_creator(t_minishell *msh);
void					ft_infile(t_minishell *msh, t_cmd *cmd, t_token **tkn);
void					ft_outfile(t_minishell *msh, t_cmd *cmd, t_token **tkn);
void					ft_apdfile(t_minishell *msh, t_cmd *cmd, t_token **tkn);
void					ft_heredoc_init(t_minishell *msh, t_cmd *cmd,
							t_token **tkn);
void					ft_hd_scnd(char *str, t_cmd *cmd, t_minishell *shl,
							int fd);
void					ctrl_c_hd(int signal);
char					*expand_heredoc(char *str, t_minishell *shl);
char					**ft_allocate_cmd_str(t_token *tkn);
void					ft_reboot(t_minishell *minishell);
char					*ft_dup_token_str(t_token *tkn);
int						ft_is_cmd_token(int type);
void					free_exit_hd(t_minishell *shl, t_cmd *cmd, int state);
void					ft_handle_sigint(int sig);
void					ft_suppress_output(void);
void					ft_handle_sigquit(int sig);
void					ft_free_and_exit(char *msg, t_minishell *msh, int state,
							int txt);
char					*ft_operation(t_minishell *m, int *i, char *str, int s);
char					*ft_dollar_st_pluz(char *str, int *i,
							t_minishell *mini);
char					*ft_dollar_st_zero(char *str, int *i,
							t_minishell *mini);
char					*ft_dollar_dol_pluz(char *str, int *i);
char					*ft_dollar_dol_zero(char *str, int *i);

// PARSE UTILS
int						ft_find_char(char *str, char c);
void					ft_set_env(t_minishell *minishell, char **envp);
t_env					*ft_new_node(char *key, char *value);
char					*ft_get_env(t_env **env, char *search);
char					*ft_prime_util(int *i, char *str, t_minishell *shell);
int						ft_check_virgu(char *str);
int						ft_check_dollar(char *str);

// ERRORS
void					ft_error_minishell(char *msg, t_minishell *shell,
							int err_state);
void					ft_open_errors(char *err_msg, char *err_name);

// FREES
void					ft_free_token(t_token *tok);
void					ft_free_env(t_minishell *minishell);
void					ft_free_tokens(t_token **tokens);
void					ft_free_cmds(t_cmd *cmds);
void					ft_free_cmd(t_cmd *cmd);
void					ft_free_sarr(char **str);
void					ft_free_double(char **ptr);
char					**ft_free_cmd_str(char **str, int size);
void					ft_finish(t_minishell *minishell);

// INIT
void					ft_start(char **envp, t_minishell *mini);
void					ft_start_msg(void);
void					ft_set_shellevel(t_minishell *mini);
void					ft_set_home(t_minishell *mini);

// ENV + UTILS
void					ft_save_env(t_minishell *minishell, char **envp);
t_env					*ft_new_node(char *key, char *value);
int						ft_free_env_node(t_env *node);
t_env					*ft_find_node(char *key, t_minishell *mini);
void					ft_create_env_ptr(t_minishell *mini);
void					ft_update_env_ptr(t_minishell *mini);
char					*ft_location(t_minishell *mini);

// BUILT-INS
void					ft_echo(char **args, t_minishell *mini);
void					ft_cd(char **argv, t_minishell *mini);
void					ft_pwd(t_minishell *mini);
void					ft_export(char **args, t_minishell *mini);
void					ft_env(t_minishell *mini);
void					ft_unset(char **args, t_minishell *mini);
void					ft_exit(char **argv, t_minishell *mini);

// BUILT-IN UTILS
void					ft_print_export(t_minishell *mini);
int						ft_find_char(char *str, char c);
int						ft_env_values(t_minishell *mini);
char					*ft_env_str(char *s1, char *s2);
void					ft_create_var(t_minishell *mini, char *key,
							char *value);
int						ft_free_env_node(t_env *node);

// EXEC
int						ft_is_build(char *cmd);
void					ft_exec_b(t_cmd *cmd, t_minishell *mini);
void					ft_execve(t_cmd *cmd, t_minishell *mini);
void					ft_eggsecutor(t_minishell *mini);
void					ft_one_cmd(t_cmd *cmd, t_minishell *mini);
void					ft_multi_cmd(t_minishell *mini);

// EXECUTION UTILS
char					**ft_get_path_ptr(t_minishell *mini);
char					*ft_search_path(char *name, char **directories);
int						ft_permission(char *cmd);
void					ft_create_pipes(t_cmd *cmd, t_minishell *mini);
void					ft_basic_io(t_cmd *cmd);
void					ft_set_io(t_cmd *cmd);
int						ft_cmd_len(t_minishell *mini);
int						ft_env_len(t_minishell *mini);
int						ft_wait(void);

// FINAL
void					ft_error(t_minishell *mini, char *msg);
void					ft_free_env(t_minishell *mini);

// debug
void					ft_print_env(t_env *list);
void					ft_print_tokens(t_token *list);
void					ft_print_cmds(t_cmd *list);
void					ft_print_ptr(char **ptr);

#endif
