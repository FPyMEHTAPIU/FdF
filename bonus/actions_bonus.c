/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:40:24 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/13 12:41:19 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"
#include <stdio.h>

void	clear_img(mlx_image_t *img)
{
	uint32_t	x;
	uint32_t	y;

	if (img)
	{
		y = 0;
		while (y < img->height)
		{
			x = 0;
			while (x < img->width)
			{
				mlx_put_pixel(img, x, y, 0);
				x++;
			}
			y++;
		}
	}
}

void	move_img(int x, int y, t_map *map)
{
	if (mlx_is_key_down(map->obj, MLX_KEY_Z)
		|| mlx_is_key_down(map->obj, MLX_KEY_X)
		|| mlx_is_key_down(map->obj, MLX_KEY_C))
		return ;
	map->move_x += x;
	map->move_y += y;
	redraw(map, map->persp);
}

void	zoom_img(t_map *map, double incr_zoom)
{
	if (map->zoom >= 500.0 && incr_zoom > 0.0)
		;
	else if (map->zoom <= 0.4 && incr_zoom < 0.0)
		;
	else
		map->zoom += incr_zoom;
	redraw(map, map->persp);
}

void	redraw(t_map *map, char type)
{
	t_point	min;

	map->persp = type;
	clear_img(map->img);
	scale_z(map);
	map->point = fill_image(map);
	set_scale(map);
	rotate_all(map);
	to_2d(map);
	find_min_coordinates(map, &min);
	move_coordinates(map, -min.x, -min.y);
	center_map(map);
	draw_lines(map);
}
