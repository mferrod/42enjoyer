/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:15:03 by marianof          #+#    #+#             */
/*   Updated: 2025/04/07 17:56:46 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_game
{
	int		map_h;
	int		map_w;
	char	*north_tex;
	char	*south_tex;
	char	*east_tex;
	char	*west_tex;
}				t_data;

void	error(char *str);
void	error_and_free(void *c);
void	check_param(char *param);

#endif