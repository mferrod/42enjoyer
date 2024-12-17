/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollar_st.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:21:32 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/16 15:51:38 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_dollar_st_zero(char *str, int *i, t_minishell *mini)
{
	char	*word;
	char	*second;

	(*i) += 1;
	word = ft_substr(str, *i, ft_strlen(str));
	second = ft_itoa(mini->err_state);
	free(str);
	str = ft_strjoin(second, word);
	free(word);
	free(second);
	return (str);
}

char	*ft_dollar_st_pluz(char *str, int *i, t_minishell *mini)
{
	char	*first;
	char	*second;
	char	*third;

	first = ft_substr(str, 0, *i - 1);
	while (str[*i] != '\0' && str[*i] != ' ' && str[*i] != '$')
		*i += 1;
	second = ft_substr(str, *i, ft_strlen(&str[*i]));
	third = ft_itoa(mini->err_state);
	free(str);
	str = ft_strjoin(first, third);
	free(first);
	first = ft_strdup(str);
	free(str);
	str = ft_strjoin(first, second);
	free(second);
	free(first);
	free(third);
	return (str);
}

char	*ft_dollar_dol_zero(char *str, int *i)
{
	char	*word;
	char	*second;

	(*i) += 1;
	word = ft_substr(str, *i, ft_strlen(str));
	second = ft_strdup("699287");
	free(str);
	str = ft_strjoin(second, word);
	free(word);
	free(second);
	return (str);
}

char	*ft_dollar_dol_pluz(char *str, int *i)
{
	char	*first;
	char	*second;
	char	*third;

	first = ft_substr(str, 0, *i - 1);
	while (str[*i] != '\0' && str[*i] != ' ' && str[*i] != '$')
		*i += 1;
	second = ft_substr(str, *i, ft_strlen(&str[*i]));
	third = ft_strdup("699287");
	free(str);
	str = ft_strjoin(first, third);
	free(first);
	first = ft_strdup(str);
	free(str);
	str = ft_strjoin(first, second);
	free(second);
	free(first);
	free(third);
	return (str);
}
