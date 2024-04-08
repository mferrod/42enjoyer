/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:00:37 by marianof          #+#    #+#             */
/*   Updated: 2024/04/08 18:40:09 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <libft.h>
# include <limits.h>

typedef struct s_node
{
	int				n;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

long		check_string(char *c);
int			check_char(char c, int i);
long		*check_if_duplicated(long *numbers);
void		error_and_free(void *c);
void		error(void);
t_node		*new_node(long n);
t_node		*stack_gen(long *numbers);
long		ft_atol(const char *str);

#endif