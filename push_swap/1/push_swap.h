/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariano <mariano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:00:37 by marianof          #+#    #+#             */
/*   Updated: 2024/07/26 20:22:51 by mariano          ###   ########.fr       */
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
	int					n;
	int					index;
	int					pos;
	int					cost_a;
	int					cost_b;
	int					total_cost;
	int					cheapest_node;
	struct s_node		*cheapest_r_node;
	struct s_node		*target_node;
	struct s_node		*next;
}						t_node;

//PARSEO
long		check_string(char *c);
int			check_char(char c, int i);
long		*check_if_duplicated(long *numbers);
t_node		*new_node(long n);
t_node		*stack_gen(long *numbers, int numbers_count);
long		*parser(int total_numb, char **data);

//UTILS
void		error_and_free(void *c);
void		error(void);
long		ft_atol(const char *str);
void		print_stack(t_node *list);
void		free_stack(t_node **stack);
void		free_stacks(t_node **stack_a, t_node **stack_b);
void		save_and_push_3(t_node **stack_a, t_node **stack_b);
int			stack_average(t_node **stack);
void		cal_costs(t_node **stack_a, t_node **stack_b);
void		set_positions(t_node **stack);
void		get_target(t_node **stack_a, t_node **stack_b);
int			top_calc(t_node **stack);
void		assing_index(t_node **stack);
t_node		*find_smallest(t_node **stack);
void		get_cost(t_node **stack_a, t_node **stack_b);
void		get_the_lowest_cost(t_node **stack_a, t_node **stack_b);
int			absolute_cost(int a, int b);
int			ft_lowest_to_top(t_node **stack_a);

//MOVEMENTS
void		swap(t_node **node);
void		rotate(t_node **node);
void		reverse_rotate(t_node **node);
void		push(t_node **src, t_node **dest);
void		sa(t_node **node);
void		sb(t_node **node);
void		ss(t_node **node_a, t_node **node_b);
void		ra(t_node **node);
void		rb(t_node **node);
void		rr(t_node **node_a, t_node **node_b);
void		rra(t_node **node);
void		rrb(t_node **node);
void		rrr(t_node **node_a, t_node **node_b);
void		push_a(t_node **node_a, t_node **node_b);
void		push_b(t_node **node_a, t_node **node_b);
void		make_moves(t_node **stack_a, t_node **stack_b, t_node *low_node);
void		rrr_mov(t_node **a, t_node **b, int *cost_a, int *cost_b);
void		rr_mov(t_node **a, t_node **b, int *cost_a, int *cost_b);
void		ra_mov(t_node **stack_a, int *cost_of_a);
void		rb_mov(t_node **stack_b, int *cost_of_b);
void		rra_mov(t_node **stack_a, int *cost_of_a);
void		rrb_mov(t_node **stack_b, int *cost_of_b);

//SORTERS
void		sort_big_stack(t_node **stack_a, t_node **stack_b);
void		sort_3_stack(t_node **sortme);

//STRUCTS CHECKERS
int			check_if_sorted(t_node **node);
int			stack_len(t_node **node);
long		stack_avg(t_node **node);
void		act_with_avg(t_node **node_a, t_node **node_b, long avg);
int			find_top_index(t_node *stack);

#endif
