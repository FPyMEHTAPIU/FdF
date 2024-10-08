/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_mlx_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:01:51 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/23 11:46:18 by msavelie         ###   ########.fr       */
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

void	map_to_mlx(t_map *map)
{
	t_point	min;

	map->orig_point = copy_point(map->point, map);
	map->obj = mlx_init(WIN_WIDTH, WIN_HEIGHT, "FDF", 1);
	if (!map->obj)
		mlx_terminate(map->obj);
	map->img = mlx_new_image(map->obj, map->obj->width - \
		WIN_WIDTH / 4, map->obj->height);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	set_z(map);
	map->point = fill_image(map);
	set_xy(map);
	rotate_all(map);
	to_2d(map);
	find_min_xy(map, &min);
	move_boundaries(map, -min.x, -min.y);
	center_map(map);
	draw_lines(map);
	draw_gui(map);
	mlx_image_to_window(map->obj, map->img, WIN_WIDTH / 4, 0);
	mlx_scroll_hook(map->obj, zoom, map);
	mlx_loop_hook(map->obj, fdf_keys, map);
	mlx_loop(map->obj);
	mlx_terminate(map->obj);
}
