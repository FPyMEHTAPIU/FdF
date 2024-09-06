/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:53:35 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/06 12:10:44 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./MLX42/include/MLX42/MLX42.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <math.h>

# ifndef MAP_LINES
#  define MAP_LINES 10
# endif

# ifndef SPACE
#  define SPACE 20
# endif

# ifndef WIN_WIDTH
#  define WIN_WIDTH 2000
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 1000
# endif

# ifndef HEX_LEN
#  define HEX_LEN 8
# endif

/*--------------------STRUCTS--------------------*/

typedef struct s_map
{
	char	**strs;
	int		alloc_lines;
	int		lines;
	int		nums_in_line;
	double	space_incr;
}	t_map;

typedef struct s_point
{
	double		x;
	double		y;
	double		z;
	uint32_t	color;
	double		space;
	double		move_x;
	double		move_y;
	double		angle_x;
	double		angle_y;
	char		type;
}	t_point;

typedef struct s_color
{
	uint32_t	start_col;
	uint32_t	end_col;
	uint8_t		a_start;
	uint8_t		r_start;
	uint8_t		g_start;
	uint8_t		b_start;
	uint8_t		a_end;
	uint8_t		r_end;
	uint8_t		g_end;
	uint8_t		b_end;
	uint32_t	cur_color;
}	t_color;

typedef struct s_isom
{
	double		x;
	double		y;
	uint32_t	color;
	int			steps;
}	t_isom;

typedef struct s_image
{
	int			x;
	int			y;
	uint32_t	width;
	uint32_t	height;
	float		zoom;
	mlx_t		*obj;
	mlx_image_t	*img;
	t_point		*point;
	t_point		*orig_point;
	t_map		*map;
}	t_image;

typedef struct s_matrix
{
	double	*i;
	double	*j;
	double	*k;
}	t_matrix;

/*--------------------MAP HANDLING--------------------*/

void		free_map(t_map *map);
t_map		*parse_map(int fd);
int			check_map(t_map *map);
int			count_nums(char *map_str);
	
void		free_arr(int **arr, int index);
t_point		*convert_map(t_map *map, t_point *point);
void		map_to_mlx(t_map *map, t_point *point);
t_point		*fill_image(mlx_image_t *img, t_map *map, t_point *point);
bool		to_2d(mlx_image_t *img, t_map *map, t_point *point);
void		draw_line_row(mlx_image_t *img, t_isom *isom);
void		draw_line_col(mlx_image_t *img, t_isom *isom, int nums_in_line);
uint32_t	gradient(int fst_color, int lst_color, int steps, int cur_step);
uint32_t	rgb_to_rgba(uint32_t color);
uint32_t	set_pos_color(int num);
uint32_t	set_neg_color(int num);
uint32_t	set_color(int num);
void		fdf_keys(void *obj);
void		clear_img(mlx_image_t *img);
void		zoom(double xdelta, double ydelta, void *param);
void		reset_point(t_point *orig_point, t_point *point, t_map *map);
t_point		*copy_point(t_point *point, t_map *map);
void		rotate_obj(t_point	*point, t_map *map, char type, t_image *img);
double		to_rad(double angle);
mlx_image_t	*draw_gui(mlx_t *obj);
void		draw_instructions(mlx_t *obj);
int			free_ret(t_map *map, t_point *point);
void		move_img(int x, int y, t_image *img, char dir);
void		zoom_img(t_image *img, double space);
void		redraw(t_image *img, char type);
void		free_img(t_image *img);

#endif