/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_expan_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:22:03 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/16 15:48:31 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_prime_util(int *i, char *str, t_minishell *shell)
{
	char	*first;
	char	*second;

	first = ft_substr(str, 0, *i);
	second = ft_substr(str, *i + 1, ft_strlen(str));
	free(str);
	str = ft_strjoin(first, shell->home);
	free(first);
	first = ft_strdup(str);
	free(str);
	str = ft_strjoin(first, second);
	free(second);
	free(first);
	return (str);
}

static void	ft_side_ex_prime(t_token *aux, t_minishell *shell, int *i)
{
	char	*first;

	if (*i > 0 && aux->str[*i - 1] == ' ')
		aux->str = ft_prime_util(i, aux->str, shell);
	else if (*i == 0)
	{
		first = ft_substr(aux->str, *i + 1, ft_strlen(aux->str));
		free(aux->str);
		aux->str = ft_strjoin(shell->home, first);
		free(first);
	}
}

void	ft_expand_prime(t_token **token, t_minishell *shell)
{
	int		i;
	t_token	*aux;

	i = 0;
	aux = *token;
	while (aux->str[i])
	{
		if (aux->type == T_WORD)
		{
			if (aux->str[i] == '~')
				ft_side_ex_prime(aux, shell, &i);
		}
		i++;
	}
}

void	ft_expand_dollars(t_token **token, t_minishell *shell)
{
	t_token	*aux;
	int		i;

	aux = *token;
	i = 0;
	while (aux->str[i])
	{
		if (aux->type == T_WORD || aux->type == T_DQUOTE)
		{
			if (aux->str[i] == '$' && aux->str[i + 1] != '\0'
				&& aux->str[i + 1] != ' ')
			{
				aux->str = ft_dollar_util(&i, aux->str, shell);
				continue ;
			}
		}
		i++;
	}
}
