/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:22:09 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:22:10 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*ft_new_token_node(char *str, t_ttype type, int join)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->str = ft_strdup(str);
	new->id = 0;
	new->type = type;
	new->join = join;
	new->next = NULL;
	return (new);
}

t_token	*ft_data_entry(char *str, t_minishell *shell)
{
	int		i;
	t_token	*tokens;

	i = 0;
	tokens = NULL;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\n')
			i++;
		else if (str[i] != '\"' && str[i] != '\'' && str[i] != '<'
			&& str[i] != '>' && str[i] != '|' && str[i] != ' '
			&& str[i] != '\n')
			ft_token_word(str, &i, &tokens);
		else if (str[i] == '\"')
			ft_token_dq(str, &i, &tokens, shell);
		else if (str[i] == '\'')
			ft_token_q(str, &i, &tokens, shell);
		else if (str[i] == '>')
			ft_token_out(str, &i, &tokens);
		else if (str[i] == '<')
			ft_token_in(str, &i, &tokens);
		else if (str[i] == '|')
			ft_token_pipe(str, &i, &tokens);
	}
	return (tokens);
}

void	ft_token_word(char *str, int *i, t_token **tokens)
{
	int		join;
	int		start;
	char	*substr;

	join = 0;
	substr = NULL;
	start = *i;
	if (str[*i])
	{
		if (*i > 0 && str[*i - 1] != ' ')
			join = 1;
		while (str[*i] && str[*i] > 32 && str[*i] < 127 && str[*i] != '\''
			&& str[*i] != '\"' && str[*i] != '<' && str[*i] != '>'
			&& str[*i] != '|')
			*i += 1;
		substr = ft_substr(str, start, (*i - start));
		ft_lstadd_back_msh(tokens, ft_new_token_node(substr, T_WORD, join));
		free(substr);
	}
}

void	ft_lstadd_back_msh(t_token **lst, t_token *new)
{
	t_token	*first;

	if ((*lst) == NULL)
	{
		(*lst) = new;
		return ;
	}
	first = *lst;
	while (first->next != NULL)
		first = first->next;
	first->next = new;
}

void	ft_token_dq(char *str, int *i, t_token **tokens, t_minishell *shell)
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
		while (str[*i] && str[*i] != '\"')
			*i += 1;
		if (str[*i] && str[*i] == '\"')
		{
			ft_lstadd_back_msh(tokens, ft_new_token_node(ft_substr(str, start,
						(*i - start)), T_DQUOTE, join));
			*i += 1;
		}
		else
		{
			shell->err_par = 1;
			ft_error_minishell(ERROR_DQ, shell, 2);
		}
	}
}
