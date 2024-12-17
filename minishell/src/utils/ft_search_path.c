/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:22:50 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:35:41 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**ft_get_path_ptr(t_minishell *mini)
{
	t_env	*tmp;

	tmp = mini->env_list;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, "PATH", 4))
			return (ft_split(tmp->value, ':'));
		tmp = tmp->next;
	}
	return (NULL);
}

char	*ft_search_path(char *name, char **directories)
{
	int		i;
	char	*tmp;
	char	*exe;

	i = 0;
	if (access(name, F_OK | X_OK) == 0)
		return (ft_strdup(name));
	while (directories[i])
	{
		tmp = ft_strjoin(directories[i], "/");
		exe = ft_strjoin(tmp, name);
		free(tmp);
		if (access(exe, F_OK | X_OK) == 0)
			return (ft_free_double(directories), exe);
		free(exe);
		i++;
	}
	return (ft_free_double(directories), NULL);
}
