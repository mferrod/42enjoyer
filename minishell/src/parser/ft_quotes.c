/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:21:54 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:21:55 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_token_q(char *str, int *i, t_token **tokens, t_minishell *shell)
{
	int	join;
	int	start;

	start = *i + 1;
	join = 0;
	if (str[*i])
	{
		if (*i > 0 && str[*i - 1] != ' ')
			join = 1;
		*i += 1;
		while (str[*i] && str[*i] != '\'')
			*i += 1;
		if (str[*i] && str[*i] == '\'')
		{
			ft_lstadd_back_msh(tokens, ft_new_token_node(ft_substr(str, start,
						*i - start), T_QUOTE, join));
			*i += 1;
		}
		else
		{
			shell->err_par = 1;
			ft_error_minishell(ERROR_Q, shell, 2);
		}
	}
}

void	ft_token_in(char *str, int *i, t_token **tokens)
{
	char	*to_dup;

	to_dup = NULL;
	if (str[*i])
	{
		if (str[*i] == '<' && str[*i + 1] == '<')
		{
			to_dup = ft_strdup("<<");
			ft_lstadd_back_msh(tokens, ft_new_token_node(to_dup, T_DIN,
					0));
			*i += 2;
		}
		else if (str[*i] == '<')
		{
			to_dup = ft_strdup("<");
			ft_lstadd_back_msh(tokens, ft_new_token_node(to_dup, T_IN,
					0));
			*i += 1;
		}
	}
	free(to_dup);
}

void	ft_token_out(char *str, int *i, t_token **tokens)
{
	char	*to_dup;

	to_dup = NULL;
	if (str[*i])
	{
		if (str[*i] == '>' && str[*i + 1] == '>')
		{
			to_dup = ft_strdup(">>");
			ft_lstadd_back_msh(tokens, ft_new_token_node(to_dup,
					T_DOUT, 0));
			*i += 2;
		}
		else if (str[*i] == '>')
		{
			to_dup = ft_strdup(">");
			ft_lstadd_back_msh(tokens, ft_new_token_node(to_dup, T_OUT,
					0));
			*i += 1;
		}
	}
	free(to_dup);
}

void	ft_token_pipe(char *str, int *i, t_token **tokens)
{
	if (str[*i])
	{
		ft_lstadd_back_msh(tokens, ft_new_token_node(ft_strdup("|"), T_PIPE,
				0));
		*i += 1;
	}
}

void	ft_del_token(t_token **tokens, int id_del)
{
	t_token	*prev;
	t_token	*current;

	if (!tokens || !((*tokens)))
		return ;
	prev = NULL;
	current = *tokens;
	while (current)
	{
		if (current->id == id_del)
		{
			if (prev)
				prev->next = current->next;
			else
				*tokens = current->next;
			free(current->str);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}
