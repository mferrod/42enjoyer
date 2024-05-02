/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianonof@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:00:37 by marianof          #+#    #+#             */
/*   Updated: 2024/04/29 13:52:21 by marianof         ###   ########.fr       */
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
	int				pos;
	struct s_node	*next;
}					t_node;

//PARSEO
long		check_string(char *c);
int			check_char(char c, int i);
long		*check_if_duplicated(long *numbers);
void		error_and_free(void *c);
void		error(void);
t_node		*new_node(long n);
t_node		*stack_gen(long *numbers, int numbers_count);
long		ft_atol(const char *str);
long		*parser(int total_numb, char **data);

//MOVEMENTS
void		sa(t_node **node);
void		ra(t_node **node);
void		rra(t_node **node);
void		push_a(t_node **node_a, t_node **node_b);
void		sb(t_node **node);
void		rb(t_node **node);
void		rrb(t_node **node);
void		push_b(t_node **node_a, t_node **node_b);

//STRUCTS CHECKERS
int			check_if_sorted(t_node **node);
int			stack_len(t_node **node);
long		stack_avg(t_node **node);
void	act_with_avg(t_node **node_a, t_node **node_b, long avg);
void	sort_3_stack(t_node **sortme);

#endif
