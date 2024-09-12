/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:40:36 by marianof          #+#    #+#             */
/*   Updated: 2024/09/12 15:32:12 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc - 1 != 4 && argc - 1 != 5)
		return (printf("PHILOSOPHERS: INVALID NUMBER OF ARGUMENTS.\n"));
	init_table(&table);
	if (handle_param(argv, argc - 1, &table) == -1)
		return (printf("PHILOSOPHERS: INVALID ARGUMENTS.\n"));
	if (init_global(&table) == 1)
		return (1);
	return (0);
}
