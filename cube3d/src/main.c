/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:35:02 by marianof          #+#    #+#             */
/*   Updated: 2025/04/07 17:55:48 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char const *argv[])
{
	t_data	data;

	(void)data;
	if (argc != 2)
		error("Only one parameters.");
	check_param((char*) argv[1]);
	printf("PASS");
	return (0);
}
