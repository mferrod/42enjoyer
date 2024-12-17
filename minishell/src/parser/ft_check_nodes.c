/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_nodes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:21:21 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/16 14:00:18 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_set_token_id(t_token **tokens)
{
	t_token	*aux;
	int		i;

	i = 0;
	aux = *tokens;
	while (aux != NULL)
	{
		i++;
		aux->id = i;
		aux = aux->next;
	}
}

int	ft_check_nodes(t_minishell *minishell)
{
	ft_set_token_id(&minishell->tokens);
	if (ft_check_seman_token(&minishell->tokens, minishell) == 1
		|| minishell->err_par == 1)
		return (1);
	ft_token_expansions(&minishell->tokens, minishell);
	ft_expand_tokens(&minishell->tokens);
	return (0);
}

void	ft_expand_tokens(t_token **tokens)
{
	t_token	*aux;
	char	*copy;

	aux = *tokens;
	while (aux)
	{
		while (aux->next && aux->next->join == 1 && ((aux->type == T_WORD)
				|| (aux->type == T_QUOTE) || (aux->type == T_DQUOTE)))
		{
			copy = ft_strdup(aux->str);
			free(aux->str);
			aux->str = ft_strjoin(copy, aux->next->str);
			free(copy);
			ft_del_token(tokens, aux->next->id);
		}
		aux = aux->next;
	}
	ft_set_token_id(tokens);
}

int	ft_check_seman_token(t_token **tokens, t_minishell *mini)
{
	t_token	*aux;

	aux = *tokens;
	if (!aux)
		return (1);
	while (aux)
	{
		if (ft_check_token_pipes(tokens, mini) == 1)
			return (1);
		if (aux->type != T_DQUOTE && aux->type != T_QUOTE && aux->type != T_WORD
			&& aux->type != T_PIPE)
		{
			if (!aux->next)
				return (ft_error_minishell(UNEX_TOKEN, mini, 2), 1);
			if (aux->next->type != T_WORD && aux->next->type != T_QUOTE
				&& aux->next->type != T_DQUOTE)
				return (ft_error_minishell(UNEX_ENOFL, mini, 2), 1);
		}
		aux = aux->next;
	}
	return (0);
}

int	ft_check_token_pipes(t_token **tokens, t_minishell *mini)
{
	t_token	*token;

	token = *tokens;
	while (token)
	{
		if (token->type == T_PIPE)
		{
			if (token->id == 1)
				return (ft_error_minishell(UNEX_TOKEN, mini, 2), 1);
			if (!token->next)
				return (ft_error_minishell(UNEX_ENOFL, mini, 2), 1);
			if (token->next->type == T_PIPE)
				return (ft_error_minishell(UNEX_TOKEN, mini, 2), 1);
		}
		token = token->next;
	}
	return (0);
}
