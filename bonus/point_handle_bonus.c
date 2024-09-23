/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_handle_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:40:03 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/23 11:46:00 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

t_point	*copy_point(t_point *point, t_map *map)
{
	t_point	*copy;
	int		i;
	int		total;

	total = map->height * map->width;
	copy = malloc(sizeof(t_point) * total);
	if (!copy)
	{
		ft_printf("Error when trying to copy point struct\n");
		free_ret(map, map->point);
		exit(1);	
	}
	i = 0;
	while (i < total)
	{
		copy[i].x = point[i].x;
		copy[i].y = point[i].y;
		copy[i].z = point[i].z;
		copy[i].color = point[i].color;
		i++;
	}
	return (copy);
}
