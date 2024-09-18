/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_2d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:37:53 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/18 13:42:44 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

static void	to_isometry(size_t i, t_map *map)
{
	double	temp_x;

	temp_x = map->point[i].x;
	map->point[i].x = (temp_x - map->point[i].y);
	map->point[i].y = (temp_x + map->point[i].y) / 2 - map->point[i].z;
}

static void	to_ortography(size_t i, t_map *map)
{
	if (map->side == 't')
	{
		map->point[i].x = map->point[i].x;
		map->point[i].y = map->point[i].y;
	}
	else if (map->side == 'r')
	{
		map->point[i].x = map->point[i].y;
		map->point[i].y = -map->point[i].z;
	}
	else if (map->side == 'f')
	{
		map->point[i].x = map->point[i].x;
		map->point[i].y = -map->point[i].z;
	}
}

void	change_perspective(t_map *map)
{
	size_t	i;

	i = 0;
	if (map->persp == 'O')
	{
		while (i < map->img->count)
		{
			to_ortography(i, map);
			i++;
		}
	}
	else
	{
		while (i < map->img->count)
		{
			to_isometry(i, map);
			i++;
		}
	}
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
	bool	ret;

	change_perspective(map);
	ret = print_err(map, 1);
	if (!ret)
	{
		mlx_terminate(map->obj);
		exit (1);
	}
	return (ret);
}
