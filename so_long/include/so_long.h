/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:55:27 by marianof          #+#    #+#             */
/*   Updated: 2024/08/06 20:44:23 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define IMG 64

typedef struct s_map
{
	int				map_h;
	int				map_w;
	int				player_x;
	int				player_y;
	int				player_c;
	int				colec_c;
	int				exit_c;
	char			**map;
	char			**c_map;
	mlx_t			*game_init;
	mlx_image_t		*player_img;
	mlx_image_t		*exit_img;
	mlx_image_t		*colec_img;
	mlx_image_t		*wall_img;
	mlx_image_t		*ground_img;
}					t_data;

//ERRORS
void		error(void);
void		error_and_free(void *c);
void		error_and_free_matrix(char **c);

//FLOOD FILL
void		save_player_pos(t_data *data);
void		valid_map(t_data *data);
void		flood_fill(t_data *data, int x, int y);

//UTILS
int			count_lines_from_file(char *path);
int			matrix_length(char **matrix);
void		init_struct(t_data *data);
void		map_things(t_data *data, char *param);
int			ft_strlen_sl(const char *str);
void		free_flood_map(char **map);

//SETUP GAME
void		setup_game(t_data *data);
void		init_textures(t_data *data);
void		set_texture(mlx_t *game, mlx_image_t **image, char *path);
void		set_textu_on_chars(t_data *data);
void		textu_on_char_two(int i, int j, t_data *data);
void		check_exit(t_data *data);

//INIT CONTROLS
void		init_controls(mlx_key_data_t keydata, void *param);
void		player_mov_up(t_data *data);
void		player_mov_down(t_data *data);
void		player_mov_left(t_data *data);
void		player_mov_right(t_data *data);

//CHECKEER
void		check_param(char *param);
char		**make_matrix(char *path_to_file);
void		check_matrix(char **matrix);

#endif