/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:18:24 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/12/12 19:59:03 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_delayed_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		usleep(70000);
		i++;
	}
}

void	ft_start_msg(void)
{
	write(1, "    ▄▄▄▄  ▄ ▄▄▄▄  ▄  ▄▄▄ ▐▌   ▗▞▀▚▖█ █ \n", 85);
	usleep(100000);
	write(1, "    █ █ █ ▄ █   █ ▄ ▀▄▄  ▐▌   ▐▛▀▀▘█ █ \n", 79);
	usleep(100000);
	write(1, "    █   █ █ █   █ █ ▄▄▄▀ ▐▛▀▚▖▝▚▄▄▖█ █ \n", 85);
	usleep(100000);
	write(1, "          █       █      ▐▌ ▐▌     █ █ \n\n", 58);
	usleep(100000);
	ft_delayed_str(SHLL_NAME);
	write(1, "\n\n", 2);
}
