/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:15:03 by marianof          #+#    #+#             */
/*   Updated: 2025/05/05 18:36:28 by marianof         ###   ########.fr       */
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
	char	*north_tex;
	char	*south_tex;
	char	*east_tex;
	char	*west_tex;
	int		*floor_tex;
	int		*ceiling_tex;
	int		player_x;
	int		player_y;
}				t_data;

void	error(char *str);
void	error_and_free(void *c);
void	check_param(char *param);
void	init_parse(t_data *data, char *param);
void	init_list(t_data *list, char *param);
void	get_textures(t_data *list, char *param);
void	make_matrix(int file, char *param, t_data *list);
void	check_map(t_data *data, int i, int j, char **map);
void	set_textures_on_list(t_data *list, char *tex, int *num);
int		find_char(const char *s, int c);
void	save_player_pos(t_data *data, int i, int j);
int		*parse_numbers(t_data *list, char *param);
int		ft_arraylen(char **array);
char	**free_matrix(char **matrix);
void	error_and_finish(t_data *list, char *txt);
void	free_all(t_data *data);
int		skip_spaces(char *str);
void	check_map_positions(t_data *data);
void	valid_list(t_data *data);
void	set_tex_color(t_data *list, char *tex, int *num);

#endif