/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:01:51 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/04 12:19:22 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static double	set_space(t_map *map)
{
	double	space;
	int total_nums;

	space = 1 + map->space_incr;
	total_nums = map->lines * map->nums_in_line;
	if (total_nums < 700)
		space = 20 + map->space_incr;
	else if (total_nums >= 700 && total_nums <= 5000)
		space = 10 + map->space_incr;
	else if (total_nums > 700 && total_nums <= 20000)
		space = 5 + map->space_incr;
	else if (total_nums > 20000 && total_nums <= 40000)
		space = 2 + map->space_incr;
	return (space);
}

t_point	*fill_image(mlx_image_t *img, t_map *map, t_point *point)
{
	int	i;
	int	j;
	double	pos_x;
	double	pos_y;

	i = 0;
	img->count = (size_t)(map->nums_in_line * map->lines);
	point->space = set_space(map);
	while (i < map->lines)
	{
		if (i > 0)
			pos_y += point->space;
		else
			pos_y = i;
		j = 0;
		while (j < map->nums_in_line)
		{
			if (j > 0)
				pos_x += point->space;
			else
				pos_x = j; 
			point[(i * map->nums_in_line) + j].x = pos_x + point->move_x;
			point[(i * map->nums_in_line) + j].y = pos_y + point->move_y;
			//point[(i * map->nums_in_line) + j].z += point->rot_z;
			j++;
		}
		i++;
	}
	return (point);
}

static t_image	*set_size(mlx_t *obj, mlx_image_t *img, t_point *point, t_map *map)
{
	t_image	*t_img;

	t_img = malloc(sizeof(t_image));
	if (!t_img)
	{
		ft_printf("Error in allocation t_image size struct!\n");
		return (NULL);
	}
	t_img->x = WIN_WIDTH / 4;
	t_img->y = 0;
	t_img->width = img->width;
	t_img->height = img->height;
	t_img->zoom = 1.0f;
	t_img->obj = obj;
	t_img->img = img;
	t_img->point = point;
	t_img->orig_point = copy_point(point, map);
	t_img->map = map;
	return (t_img);
}

void	map_to_mlx(t_map *map, t_point *point)
{
	mlx_t	*obj;
	t_image	*img_size;
	mlx_image_t	*img;
	mlx_image_t	*gui;

	obj = mlx_init(1600, 800, "FDF", 1);
	if (!obj)
		mlx_terminate(obj);
	img = mlx_new_image(obj, WIN_WIDTH, WIN_HEIGHT);
	point = fill_image(img, map, point);
	to_2d(img, map, point);
	img_size = set_size(obj, img, point, map);
	gui = draw_gui(obj);
	mlx_image_to_window(obj, gui, 0, 0);
	draw_instructions(obj);
	mlx_image_to_window(obj, img, img_size->x, img_size->y);
	mlx_scroll_hook(obj, zoom, img_size);
	mlx_loop_hook(obj, fdf_keys, img_size);
	mlx_loop(obj);
	mlx_terminate(obj);
}

