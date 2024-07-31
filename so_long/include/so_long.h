/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:55:27 by marianof          #+#    #+#             */
/*   Updated: 2024/07/31 19:50:02 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

void		check_param(char *param);
void		error(void);
void		error_and_free(void *c);
void		error_and_free_matrix(void **c);
char		**make_matrix(char *path_to_file);
int			count_lines_from_file(char *path);
#endif