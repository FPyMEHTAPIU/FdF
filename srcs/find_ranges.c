/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ranges.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:58:26 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/18 11:59:09 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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

void	find_z_range(t_map *map)
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
