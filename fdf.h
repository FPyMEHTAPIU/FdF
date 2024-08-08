/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:53:35 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/08 17:22:23 by msavelie         ###   ########.fr       */
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
	int		x;
	int		y;
	int		z;
	int		color;
	//t_color	*color;
}	t_point;

typedef struct	s_color
{
	int	start_col;
	int	end_col;
	int	a_start;
	int	r_start;
	int	g_start;
	int	b_start;
	int	a_end;
	int	r_end;
	int	g_end;
	int	b_end;
	int	cur_color;
}	t_color;


typedef struct s_isom
{
	double	x;
	double	y;
}	t_isom;

/*--------------------MAP HANDLING--------------------*/

t_map	*free_map(t_map *map);
t_map	*parse_map(int fd);
int		check_map(t_map *map);

void	free_arr(int **arr, int index);
//int		**convert_map(t_map *map);
t_point	*convert_map(t_map *map, t_point *point);
//void	map_to_mlx(t_map *map, int **nums);
void	map_to_mlx(t_map *map, t_point *point);
t_isom	*to_isometry(mlx_image_t *img, t_map *map, t_point *point);
void	draw_line_row(mlx_image_t *img, t_isom *isom);
void	draw_line_col(mlx_image_t *img, t_isom *isom, t_map *map);

#endif