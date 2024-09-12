/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:40:24 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/12 13:23:43 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	clear_img(mlx_image_t *img)
{
	uint32_t	x;
	uint32_t	y;

	if (img)
	{
		y = 0;
		while (y++ < img->height - 1)
		{
			x = 0;
			while (x++ < img->width - 1)
				mlx_put_pixel(img, x, y, 0);
		}
	}
}

void	move_img(int x, int y, t_map *map, char dir)
{
	if (mlx_is_key_down(map->obj, MLX_KEY_Z)
		|| mlx_is_key_down(map->obj, MLX_KEY_X)
		|| mlx_is_key_down(map->obj, MLX_KEY_C))
		return ;
	if ((dir == 'u' || dir == 'd') && map->persp == 'P')
		x = 0;
	else if ((dir == 'l' || dir == 'r') && map->persp == 'P')
		y = 0;
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
	mlx_resize_image(map->img, map->img->width + 50, map->img->height + 50);
	redraw(map, map->persp);
}

void	redraw(t_map *map, char type)
{
	t_point	min;

	map->point->type = type;
	clear_img(map->img);
	map->point = fill_image(map);
	scale_z(map);
	rotate_all(map);
	to_2d(map);
	find_min_coordinates(map, &min);
	move_coordinates(map, -min.x, -min.y);
	center_map(map);
}
