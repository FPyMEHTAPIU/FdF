/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:37:53 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/25 16:12:51 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	to_isometry(size_t i, t_map *map)
{
	double	temp_x;

	temp_x = map->point[i].x;
	map->point[i].x = (temp_x - map->point[i].y);
	map->point[i].y = (temp_x + map->point[i].y) / 2 - map->point[i].z;
}

void	to_2d(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->img->count)
	{
		to_isometry(i, map);
		i++;
	}
}
