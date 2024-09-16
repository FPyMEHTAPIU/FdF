/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:34:04 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/16 12:47:29 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	scale_coordinates(t_map *map, double scale)
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
			map->point[y * map->width + x].x *= scale;// / 2;
			map->point[y * map->width + x].y *= scale;// / 2;
			x++;
		}
		y++;
	}
}

void	set_scale(t_map *map)
{
	t_point	min;
	t_point	max;
	double	scale_x;
	double	scale_y;

	find_min_coordinates(map, &min);
	find_max_coordinates(map, &max);
	scale_x = (max.x - min.x) / (map->img->width / 2);
	scale_y = (max.y - min.y) / (map->img->height / 2);
	scale_coordinates(map, fmin(1 / scale_x, 1 / scale_y));
}

void	find_min_coordinates(t_map *map, t_point *min)
{
	int	x;
	int	y;

	y = 0;
	min->x = map->point[0].x;
	min->y = map->point[0].y;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->point[y * map->width + x].x < min->x)
				min->x = map->point[y * map->width + x].x;
			if (map->point[y * map->width + x].y < min->y)
				min->y = map->point[y * map->width + x].y;
			x++;
		}
		y++;
	}
}

void	find_max_coordinates(t_map *map, t_point *max)
{
	int	x;
	int	y;

	max->x = map->point[0].x;
	max->y = map->point[0].y;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->point[y * map->width + x].x > max->x)
				max->x = map->point[y * map->width + x].x;
			if (map->point[y * map->width + x].y > max->y)
				max->y = map->point[y * map->width + x].y;
			x++;
		}
		y++;
	}
}
