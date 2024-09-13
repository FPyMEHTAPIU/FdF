/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_mlx_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:01:51 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/13 10:55:29 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

t_point	*fill_image(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	map->img->count = (size_t)(map->width * map->height);
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->point[(y * map->width) + x].x = x;
			map->point[(y * map->width) + x].y = y;
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
			map->point[y * map->width + x].z = map->orig_point[y * map->width + x].z * scale * 0.5;
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

	cx = map->point[(map->height * map->width - 1) / 2].x;
	cy = map->point[(map->height * map->width - 1) / 2].y;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->point[y * map->width + x].x -= cx;
			map->point[y * map->width + x].y -= cy;
			map->point[y * map->width + x].x += map->img->width / 2 + GUI_WIDTH;
			map->point[y * map->width + x].y += map->img->height / 2;
			map->point[y * map->width + x].x += cx;//map->move_x;
			map->point[y * map->width + x].y += cy;//map->move_y;
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

	map->obj = mlx_init(WIN_WIDTH, WIN_HEIGHT, "FDF", 1);
	if (!map->obj)
		mlx_terminate(map->obj);
	map->img = mlx_new_image(map->obj, WIN_WIDTH, WIN_HEIGHT);
	map->orig_point = copy_point(map->point, map);
	//mlx_set_setting(MLX_STRETCH_IMAGE, 1);
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
	//mlx_set_instance_depth(map->img->instances, depth - 1);
	mlx_scroll_hook(map->obj, zoom, map);
	mlx_loop_hook(map->obj, fdf_keys, map);
	mlx_loop(map->obj);
	mlx_terminate(map->obj);
	//free_img(img_size);
}
