/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollar_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:21:34 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/16 15:52:13 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	*ft_dollar_zero(char *str, int **i, t_minishell *mini)
{
	int		start;
	char	*word;
	char	*second;

	start = **i;
	while (str[**i] != '\0' && str[**i] != ' ' && str[**i] != '$')
		**i += 1;
	word = ft_substr(str, **i, ft_strlen(str));
	second = ft_substr(str, start, (size_t)(**i) - 1);
	free(str);
	str = ft_strjoin(ft_get_env(&mini->env_list, second), word);
	free(word);
	free(second);
	return (str);
}

static char	*ft_dollar_pluz(char *str, int *i, t_minishell *mini)
{
	char	*first;
	char	*second;
	char	*third;
	int		start;

	start = *i;
	first = ft_substr(str, 0, *i - 1);
	while (str[*i] != '\0' && str[*i] != ' ' && str[*i] != '$')
		*i += 1;
	second = ft_substr(str, *i, ft_strlen(&str[*i]));
	third = ft_substr(str, start, (size_t)(*i) - start);
	free(str);
	str = ft_strjoin(first, ft_get_env(&mini->env_list, third));
	free(first);
	first = ft_strdup(str);
	free(str);
	str = ft_strjoin(first, second);
	free(second);
	free(first);
	free(third);
	return (str);
}

static char	*ft_dollar_pluz_cor(char *str, int *i, t_minishell *mini)
{
	int		start;
	char	*var;

	var = NULL;
	if (str[*i] == '{')
	{
		start = *i;
		(*i)++;
		while (str[*i] != '}' && str[*i] != '\0')
			(*i)++;
		if (str[*i] == '}')
		{
			var = ft_operation(mini, i, str, start);
			(*i)++;
		}
	}
	return (var);
}

static char	*ft_dollar_zero_cor(char *str, int *i, t_minishell *mini)
{
	int		start;
	char	*var;
	char	*words;
	char	*aux;

	words = NULL;
	if (str[*i] == '{')
	{
		start = *i;
		(*i)++;
		while (str[*i] != '}' && str[*i] != '\0')
			(*i)++;
		if (str[*i] == '}')
		{
			aux = ft_substr(str, *i + 1, ft_strlen(str));
			var = ft_substr(str, start + 1, *i - start - 1);
			words = ft_strjoin(ft_get_env(&mini->env_list, var), aux);
			(*i)++;
			free(aux);
			free(var);
			free(str);
		}
	}
	return (words);
}

char	*ft_dollar_util(int *i, char *str, t_minishell *mini)
{
	(*i) += 1;
	if (str[*i] == '$' && *i > 1)
		return (ft_dollar_dol_pluz(str, i));
	else if (str[*i] == '$')
		return (ft_dollar_dol_zero(str, i));
	if (str[*i] == '?' && *i > 1)
		return (ft_dollar_st_pluz(str, i, mini));
	else if (str[*i] == '?')
		return (ft_dollar_st_zero(str, i, mini));
	if (str[*i] == '{' && *i > 1)
		return (ft_dollar_pluz_cor(str, i, mini));
	else if (str[*i] == '{')
		return (ft_dollar_zero_cor(str, i, mini));
	if (*i > 1)
		return (ft_dollar_pluz(str, i, mini));
	return (ft_dollar_zero(str, &i, mini));
}
