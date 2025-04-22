/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:15:03 by marianof          #+#    #+#             */
/*   Updated: 2025/04/15 13:33:35 by marianof         ###   ########.fr       */
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
	char	**map;
	char	**c_map;
	char	*north_tex;
	char	*south_tex;
	char	*east_tex;
	char	*west_tex;
	int		*floor_tex;
	int		*ceiling_tex;
}				t_data;

void	error(char *str);
void	error_and_free(void *c);
void	check_param(char *param);
void	init_parse(t_data *data, char *param);
void	init_list(t_data *list, char *param);
void	get_textures(t_data *list, char *param);
char	**make_matrix(int file);
void	set_textures_on_list(t_data *list, char *tex);
int		find_char(const char *s, int c);
int		*parse_numbers(t_data *list, char *param);
int		ft_arraylen(char **array);
char	**free_matrix(char **matrix);
void	error_and_finish(t_data *list, char *txt);

#endif