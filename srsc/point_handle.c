/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:40:03 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/27 12:42:17 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	reset_point(t_point *orig_point, t_point *point, t_map *map)
{
	int	i;
	int	total;

	i = 0;
	total = map->lines * map->nums_in_line;
	while (i < total)
	{
		orig_point[i].x = point[i].x;
		orig_point[i].y = point[i].y;
		orig_point[i].z = point[i].z;
		orig_point[i].color = point[i].color;
		orig_point[i].space = point[i].space;
		orig_point[i].move_x = point[i].move_x;
		orig_point[i].move_y = point[i].move_y;
		i++;
	}
}

t_point	*copy_point(t_point *point, t_map *map)
{
	t_point	*copy;
	int		i;
	int		total;
	
	total = map->lines * map->nums_in_line;
	copy = malloc(sizeof(t_point) * total);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < total)
	{
		copy[i].x = point[i].x;
		copy[i].y = point[i].y;
		copy[i].z = point[i].z;
		copy[i].color = point[i].color;
		copy[i].space = point[i].space;
		copy[i].move_x = point[i].move_x;
		copy[i].move_y = point[i].move_y;
		i++;
	}
	return (copy);
}