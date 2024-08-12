/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:55:45 by marianof          #+#    #+#             */
/*   Updated: 2024/08/12 18:15:08 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <unistd.h>
# include <sys/types.h>

// MY LIBRARIES
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

//ERRORS
void	error_and_free(void *c, char *error);
void	error(char *error);
void	error_and_free_matrix(char **matrix, char *error);

//FREE
void	free_matrix(char **matrix);

//PIPEX
void	pipex(char **args, char **env, int *fd);
void	create_first_child(int *fd, char **pars, char **args, char **envp);
void	create_second_child(int *fd, char **pars, char **args, char **envp);
char	*search_command(char *cmd, char **cmd_paths);

//PARSER
char	**parser(char **env);
char	*search_command(char *cmd, char **cmd_paths);
char	**cmd_split(char *args);

#endif