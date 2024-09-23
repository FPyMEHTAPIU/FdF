/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:37:53 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/23 12:52:30 by msavelie         ###   ########.fr       */
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

static bool	print_err(t_map *map, int n)
{
	if (n == 0)
	{
		ft_printf("Error in creation t_isom!\n");
		free_ret(map, map->point);
		return (false);
	}
	return (true);
}

bool	to_2d(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->img->count)
	{
		to_isometry(i, map);
		i++;
	}
	return (print_err(map, 1));
}
