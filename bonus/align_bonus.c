/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:31:43 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/23 11:38:05 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	move_boundaries(t_map *map, double move_x, double move_y)
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

static void	set_center(t_map *map, double *cx, double *cy)
{
	int	total;

	total = map->height * map->width;
	if (total % 2 == 0)
	{
		*cx = map->point[total / 2 + (map->width / 2)].x;
		*cy = map->point[total / 2 + (map->width / 2)].y;
	}
	else
	{
		*cx = map->point[total / 2].x;
		*cy = map->point[total / 2].y;
	}
}

void	center_map(t_map *map)
{
	int		x;
	int		y;
	double	cx;
	double	cy;

	cx = 0;
	cy = 0;
	set_center(map, &cx, &cy);
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
