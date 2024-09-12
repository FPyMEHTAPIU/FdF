/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_mlx_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:01:51 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/12 13:09:24 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

/*static double	set_space(t_map *map)
{
	double	space;
	int		total_nums;

	space = 1 + map->space_incr;
	total_nums = map->lines * map->nums_in_line;
	if (total_nums < 700)
		space = 20 + map->space_incr;
	else if (total_nums >= 700 && total_nums <= 5000)
		space = 10 + map->space_incr;
	else if (total_nums > 700 && total_nums <= 20000)
		space = 5 + map->space_incr;
	else if (total_nums > 20000 && total_nums <= 40000)
		space = 2.5 + map->space_incr;
	return (space);
}

static void	set_pos(t_point *point, int n, double *pos)
{
	if (n > 0)
		*pos += point->space;
	else
		*pos = n;
}*/

/*static t_image	*set_size(mlx_t *obj, mlx_image_t *img,
	t_point *point, t_map *map)
{
	t_image	*t_img;

	t_img = malloc(sizeof(t_image));
	if (!t_img)
	{
		ft_printf("Error in allocation t_image size struct!\n");
		free_ret(map, point);
		mlx_terminate(obj);
		exit (1);
	}
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	t_img->x = WIN_WIDTH / 4;
	t_img->y = 0;
	t_img->width = img->width;
	t_img->height = img->height;
	t_img->obj = obj;
	t_img->img = img;
	t_img->point = point;
	t_img->orig_point = copy_point(point, map);
	t_img->map = map;
	return (t_img);
}*/

t_point	*fill_image(t_map *map)
{
	int		x;
	int		y;
	//double	pos_x;
	//double	pos_y;

	y = 0;
	map->img->count = (size_t)(map->width * map->height);
	//point->space = set_space(map);
	//double cx = point[(map->height / 2) * (map->width / 2)].x;
	//double cy = point[(map->height / 2) * (map->width / 2)].y;
	while (y < map->height)
	{
		//set_pos(point, i, &pos_y);
		x = 0;
		while (x < map->width)
		{
			//set_pos(point, j, &pos_x);
			map->point[(y * map->width) + x].x = x;//pos_x - cx + point->move_x;
			map->point[(y * map->width) + x].y = y;//pos_y - cy + point->move_y;
			x++;
		}
		y++;
	}
	return (map->point);
}

void	find_min_max_z(t_map *map)
{
	int	x;
	int	y;

	map->max_z = map->orig_point[0].z;
	map->min_z = map->orig_point[0].z;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->orig_point[y * map->width + x].z > map->max_z)
				map->max_z = map->orig_point[y * map->width + x].z;
			if (map->orig_point[y * map->width + x].z < map->min_z)
				map->min_z = map->orig_point[y * map->width + x].z;
			x++;
		}
		y++;
	}
}

void	scale_z(t_map *map)
{
	int	scale;
	int	x;
	int	y;

	map->orig_point = copy_point(map->point, map);
	find_min_max_z(map);
	scale = map->max_z - map->min_z;
	if (scale == 0)
		scale = 1;
	scale = ((map->img->height / 10) + (map->img->width / 10)) / scale;
	if (scale == 0)
		scale = 1;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->point[y * map->width + x].z = map->orig_point[y * map->width + x].z * scale;
			x++;
		}
		y++;
	}
}

void	move_coordinates(t_map *map, double move_x, double move_y)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->point[y * map->width + x].x *= map->zoom;
			map->point[y * map->width + x].y *= map->zoom;
			map->point[y * map->width + x].x += move_x;
			map->point[y * map->width + x].y += move_y;
			x++;
		}
		y++;
	}
}

void	center_map(t_map *map)
{
	int		x;
	int		y;
	double	cx;
	double	cy;

	cx = map->point[map->height / 2 * map->width / 2].x;
	cy = map->point[map->height / 2 * map->width / 2].y;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->point[y * map->width + x].x -= cx;
			map->point[y * map->width + x].y -= cy;
			map->point[y * map->width + x].x += map->img->width / 2;
			map->point[y * map->width + x].y += map->img->height / 2;
			map->point[y * map->width + x].x += map->move_x;
			map->point[y * map->width + x].y += map->move_y;
			x++;
		}
		y++;
	}
}

void	map_to_mlx(t_map *map)
{
	//mlx_t		*obj;
	//t_image		*img_size;
	//mlx_image_t	*img;
	//mlx_image_t	*gui;
	t_point	min;

	map->obj = mlx_init(1600, 800, "FDF", 1);
	if (!map->obj)
		mlx_terminate(map->obj);
	map->img = mlx_new_image(map->obj, WIN_WIDTH, WIN_HEIGHT);
	scale_z(map);
	map->point = fill_image(map);
	set_scale(map);
	rotate_all(map);
	if (!to_2d(map))
	{
		mlx_terminate(map->obj);
		exit (1);
	}
	//img_size = set_size(obj, img, point, map);
	find_min_coordinates(map, &min);
	move_coordinates(map, -min.x, -min.y);
	draw_gui(map);
	//mlx_image_to_window(obj, gui, 0, 0);
	//draw_instructions(obj);
	mlx_image_to_window(map->obj, map->img, GUI_WIDTH, 0);
	mlx_scroll_hook(map->obj, zoom, map);
	mlx_loop_hook(map->obj, fdf_keys, map);
	mlx_loop(map->obj);
	mlx_terminate(map->obj);
	//free_img(img_size);
}
