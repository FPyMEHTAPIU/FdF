/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:53:35 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/16 11:25:14 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
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

# ifndef GUI_WIDTH
#  define GUI_WIDTH (WIN_WIDTH / 4)
# endif

# ifndef GUI_HEIGHT
#  define GUI_HEIGHT WIN_HEIGHT
# endif

# ifndef HEX_LEN
#  define HEX_LEN 8
# endif

/*--------------------STRUCTS--------------------*/

typedef struct s_point
{
	double		x;
	double		y;
	double		z;
	uint32_t	color;
}	t_point;

typedef struct s_map
{
	char		**strs;
	int			alloc_lines;
	int			height;
	int			width;
	double		space_incr;
	t_point		*point;
	t_point		*orig_point;
	mlx_t		*obj;
	mlx_image_t	*img;
	int			min_z;
	int			max_z;
	double		angle_x;
	double		angle_y;
	double		angle_z;
	double		move_x;
	double		move_y;
	double		zoom;
	char		persp;
	int			steps;
	char		axis;
	char		side;
}	t_map;

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

/*--------------------MAP HANDLING--------------------*/

void		free_map(t_map *map);
t_map		*parse_map(int fd);
int			check_map(t_map *map);
int			count_nums(char *map_str);

/*--------------------POINT HANDLING--------------------*/

t_point		*convert_map(t_map *map, t_point *point);
void		reset_point(t_point *orig_point, t_point *point, t_map *map);
t_point		*copy_point(t_point *point, t_map *map);

/*--------------------CLEANING--------------------*/

void		free_arr(int **arr, int index);
//void		free_map(t_map *img);
int			free_ret(t_map *map, t_point *point);
void		clear_img(mlx_image_t *img);

/*--------------------COLORS--------------------*/

uint32_t	gradient(int fst_color, int lst_color, int steps, int cur_step);
uint32_t	rgb_to_rgba(uint32_t color);
uint32_t	set_pos_color(int num);
uint32_t	set_neg_color(int num);
uint32_t	set_color(int num);

/*--------------------WORK WITH AN IMAGE--------------------*/

void		map_to_mlx(t_map *map);
t_point		*fill_image(t_map *map);
bool		to_2d(t_map *map);
void		draw_line_row(t_map *map, t_point *point);
void		draw_line_col(t_map *map, t_point *point, int width);
//void		draw_line_row(mlx_image_t *img, t_isom *isom);
//void		draw_line_col(mlx_image_t *img, t_isom *isom, int width);
void		draw_gui(t_map *map);
void		draw_instructions(mlx_t *obj);
void		redraw(t_map *map, char type);

/*--------------------HOOKS--------------------*/

void		fdf_keys(void *obj);
void		zoom(double xdelta, double ydelta, void *param);

/*--------------------ACTIONS--------------------*/

void		move_img(t_map *img);
void		zoom_img(t_map *map, double space);

void	rotate_all(t_map *map);
void	change_angles(t_map *map);
void	set_scale(t_map *map);
void	scale_coordinates(t_map *map, double scale);
void	find_min_coordinates(t_map *map, t_point *min);
void	find_max_coordinates(t_map *map, t_point *min);
void	scale_z(t_map *map);
void	move_coordinates(t_map *map, double move_x, double move_y);
void	center_map(t_map *map);
void	draw_lines(t_map *map);
void	set_orto_side(t_map *map);

#endif
