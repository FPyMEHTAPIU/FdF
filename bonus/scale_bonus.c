/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:34:04 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/20 11:19:24 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	scale_xy(t_map *map, double scale)
{
	int	x;
	int	y;

	if (scale / 2 <= 0)
	{
		if (map->img->width / 2 > map->img->height / 2)
			scale = map->img->height / 2;
		else
			scale = map->img->width / 2;
	}
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->point[y * map->width + x].x *= scale;
			map->point[y * map->width + x].y *= scale;
			x++;
		}
		y++;
	}
}

void	set_xy(t_map *map)
{
	t_point	min;
	t_point	max;
	double	scale_x;
	double	scale_y;

	find_min_xy(map, &min);
	find_max_xy(map, &max);
	scale_x = (max.x - min.x) / (map->img->width / 2);
	scale_y = (max.y - min.y) / (map->img->height / 2);
	scale_xy(map, fmin(1 / scale_x, 1 / scale_y));
}

void	set_z(t_map *map)
{
	int	scale;
	int	x;
	int	y;

	find_z_range(map);
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
			map->point[y * map->width + x].z = \
				map->orig_point[y * map->width + x].z * scale * map->z_val;
			x++;
		}
		y++;
	}
}
