/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_permission.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:22:21 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:22:22 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_permission(char *cmd)
{
	if (cmd && ft_strchr(cmd, '/') && access(cmd, F_OK) == -1)
	{
		printf("Such file or directory does not exist\n");
		return (0);
	}
	else if (cmd && !ft_strchr(cmd, '/') && access(cmd, F_OK) == -1)
	{
		printf("Command not found\n");
		return (0);
	}
	else if (cmd && access(cmd, X_OK) == -1)
	{
		printf("No execution permission\n");
		return (0);
	}
	return (1);
}
