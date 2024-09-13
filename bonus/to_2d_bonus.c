/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_2d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:37:53 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/13 11:56:59 by msavelie         ###   ########.fr       */
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

void	change_perspective(t_map *map)
{
	size_t	i;

	i = 0;
	if (map->persp == 'P')
	{
		while (i < map->img->count)
		{
			map->point[i].x = map->point[i].x;
			map->point[i].y = map->point[i].y;
			map->point[i].color = map->point[i].color;
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

void	draw_lines(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width - 1)
			draw_line_row(map, &map->point[y * map->width + x++]);
		y++;
	}
	y = 0;
	while (y < map->width)
	{
		x = 0;
		while (x < map->height - 1)
			draw_line_col(map, &map->point[y + map->width * x++],
				map->width);
		y++;
	}
}

bool	to_2d(t_map *map)
{
	change_perspective(map);
	return (print_err(map, 1));
}
