/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:55:45 by marianof          #+#    #+#             */
/*   Updated: 2024/08/11 20:50:56 by marianof         ###   ########.fr       */
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

void	pipex(char **args, char **env, int fd[2]);
void	create_first_child(int fd[2], char **args);
char	*search_command(char *cmd, char **cmd_paths);

//PARSER
char	**parser(char **env);
char	*search_command(char *cmd, char **cmd_paths);

#endif