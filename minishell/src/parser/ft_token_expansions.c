/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_expansions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:22:06 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:22:07 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_check_virgu(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '~')
		{
			if (i == 0)
				return (1);
			else if (i > 0 && str[i - 1] == ' ')
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

void	ft_token_expansions(t_token **tokens, t_minishell *shell)
{
	t_token	*token;
	int		tkn_analyzer;

	token = *tokens;
	while (token)
	{
		tkn_analyzer = ft_tkn_analyzer(token->str);
		if (tkn_analyzer == 1)
			ft_expand_prime(&token, shell);
		else if (tkn_analyzer == 2)
			ft_expand_dollars(&token, shell);
		else if (tkn_analyzer == 3)
		{
			ft_expand_prime(&token, shell);
			ft_expand_dollars(&token, shell);
		}
		token = token->next;
	}
}

int	ft_tkn_analyzer(char *str)
{
	int	virgu;
	int	dollar;

	virgu = ft_check_virgu(str);
	dollar = ft_check_dollar(str);
	if (virgu == 1 && dollar == 1)
		return (3);
	else if (dollar == 1)
		return (2);
	else if (virgu == 1)
		return (1);
	return (0);
}
