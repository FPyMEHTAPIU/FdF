/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:53:35 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/09 12:35:18 by msavelie         ###   ########.fr       */
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

# define SPACE 20

/*--------------------STRUCTS--------------------*/

typedef struct	s_map
{
	char	**strs;
	int		alloc_lines;
	int		lines;
	int		nums_in_line;
	//int		*colors;
}	t_map;

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	uint32_t	color;
	//t_color	*color;
}	t_point;

typedef struct	s_color
{
	uint32_t	start_col;
	uint32_t	end_col;
	uint8_t	a_start;
	uint8_t	r_start;
	uint8_t	g_start;
	uint8_t	b_start;
	uint8_t	a_end;
	uint8_t	r_end;
	uint8_t	g_end;
	uint8_t	b_end;
	uint32_t	cur_color;
}	t_color;


typedef struct s_isom
{
	double		x;
	double		y;
	uint32_t	color;
	int			steps;
}	t_isom;

/*--------------------MAP HANDLING--------------------*/

t_map		*free_map(t_map *map);
t_map		*parse_map(int fd);
int			check_map(t_map *map);
	
void		free_arr(int **arr, int index);
//int			**convert_map(t_map *map);
t_point		*convert_map(t_map *map, t_point *point);
//void		map_to_mlx(t_map *map, int **nums);
void		map_to_mlx(t_map *map, t_point *point);
t_isom		*to_isometry(mlx_image_t *img, t_map *map, t_point *point);
void		draw_line_row(mlx_image_t *img, t_isom *isom);
void		draw_line_col(mlx_image_t *img, t_isom *isom, t_map *map);
uint32_t	gradient(int fst_color, int lst_color, int steps, int cur_step);

#endif