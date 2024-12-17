/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_cmd_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:21:52 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:21:53 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_is_cmd_token(int type)
{
	return (type != T_DIN && type != T_DOUT && type != T_IN && type != T_OUT);
}

char	**ft_allocate_cmd_str(t_token *tkn)
{
	int		count;

	count = ft_count_args(tkn) + 1;
	return ((char **)malloc(sizeof(char *) * count));
}

char	*ft_dup_token_str(t_token *tkn)
{
	if (!tkn || !tkn->str)
		return (ft_strdup(""));
	return (ft_strdup(tkn->str));
}

char	**ft_free_cmd_str(char **str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	*ft_operation(t_minishell *m, int *i, char *str, int s)
{
	char	*aux;
	char	*var;
	char	*words;

	aux = ft_substr(str, 0, s - 1);
	var = ft_substr(str, s + 1, *i - s - 1);
	words = ft_strjoin(aux, ft_get_env(&m->env_list, var));
	free(aux);
	free(var);
	aux = ft_substr(str, *i + 1, ft_strlen(str));
	var = ft_strjoin(words, aux);
	free(aux);
	free(str);
	free(words);
	return (var);
}
