/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianof <mariano@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:15:03 by marianof          #+#    #+#             */
/*   Updated: 2025/05/22 20:28:16 by marianof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define M_WIDTH 1920
# define M_HEIGHT 1080
# define M_PI 3.14159265358979323846
# define M_PI_2 1.57079632679489661923
# define FIOV 50.0
# define ANGLE_MOVE 0.1
# define ANGLE_D 1.5
# define PLAYER_SPEED 0.1

typedef struct s_ray
{
	double			ang;
	double			cos;
	double			sin;
	double			distance;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			wall_x;
	int				side;
	int				step_x;
	int				step_y;
	int				map_x;
	int				map_y;
	int				tex_x;
	int				tex_y;
	int				start;
	int				start_two;
	int				end;
	int				end_two;
}					t_ray;

typedef struct s_game
{
	int				flag_dupe;
	int				map_h;
	int				map_w;
	char			**map;
	int				map_count;
	int				file_count;
	int				file_pid;
	char			*north_tex;
	char			*south_tex;
	char			*east_tex;
	char			*west_tex;
	int				*floor_tex;
	int				*ceiling_tex;
	int				player_x;
	int				player_y;
	t_ray			*ray;
	double			radian_view;
	char			player_view;
	mlx_t			*mlx;
	mlx_image_t		*mapi;
	mlx_texture_t	*tex_floor;
	mlx_texture_t	*texture_north;
	mlx_texture_t	*texture_south;
	mlx_texture_t	*texture_east;
	mlx_texture_t	*texture_west;
}					t_data;

void				error(char *str);
void				error_and_free(void *c);
void				check_param(char *param);
void				init_parse(t_data *data, char *param);
void				init_list(t_data *list, char *param);
void				get_textures(t_data *list, char *param);
void				make_matrix(char *param, t_data *list);
void				check_map(t_data *data, int i, int j, char **map);
void				set_textures_on_list(t_data *list, char *tex, int *num);
int					find_char(const char *s, int c);
void				save_player_pos(t_data *data, int i, int j);
int					*parse_numbers(t_data *list, char *param);
int					ft_arraylen(char **array);
char				**free_matrix(char **matrix);
void				error_and_finish(t_data *list, char *txt);
void				free_all(t_data *data);
int					skip_spaces(char *str);
void				check_map_positions(t_data *data);
void				valid_list(t_data *data);
void				set_tex_color(t_data *list, char *tex, int *num);
char				**remake_map(char *str, int count);
void				load_textures(t_data *data);
void				set_texture(mlx_texture_t **image, char *path);
void				modify_less(char ***map, int i, int j);
int					get_max_lenght(char **str);
void				last_text(t_data *list, char *tex, int *num);
int					get_rgb(int r, int g, int b, int a);
void				paint_all(t_data *data);
void				ray_casting(t_data *data, t_ray *ray);
double				set_radian_view(t_data *data);
void				free_mlx_t(t_data *t_data);
#endif