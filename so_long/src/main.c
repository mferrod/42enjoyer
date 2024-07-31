/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <marianof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:01:47 by marianof          #+#    #+#             */
/*   Updated: 2024/07/31 19:52:23 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	char	**matrix;
	int		i;

	i = 0;
	if (argc != 2)
		error();
	check_param(argv[1]);
	matrix = make_matrix(argv[1]);
	check_matrix(matrix);
	return (0);
}
