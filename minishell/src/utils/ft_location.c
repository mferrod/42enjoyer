/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_location.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:22:18 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:22:19 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_location(t_minishell *mini)
{
	char	*location;

	if (mini->location)
		free (mini->location);
	location = getcwd(NULL, 0);
	if (!location)
		ft_error(mini, "Error getting location.\n");
	mini->location = ft_strjoin(location, " ~ ");
	free(location);
	if (mini->location == NULL)
		ft_error(mini, "Error setting location.\n");
	return (mini->location);
}
