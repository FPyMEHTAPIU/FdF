/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:06:28 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/13 11:05:52 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

static void	rotate_z(int x, int y, t_map *map)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = map->point[y * map->width + x].x;
	tmp_y = map->point[y * map->width + x].y;
	map->point[y * map->width + x].x = tmp_x * cos(map->angle_z) - tmp_y * sin(map->angle_z);
	map->point[y * map->width + x].y = tmp_x * sin(map->angle_z) + tmp_y * cos(map->angle_z);
}

static void	rotate_y(int x, int y, t_map *map)
{
	double	tmp_x;

	tmp_x = map->point[y * map->width + x].x;
	map->point[y * map->width + x].x = tmp_x * cos(map->angle_y) + \
		map->point[y * map->width + x].z * sin(map->angle_y);
	map->point[y * map->width + x].z = map->point[y * map->width + x].z * \
		cos(map->angle_y) - tmp_x * sin(map->angle_y);
}

static void	rotate_x(int x, int y, t_map *map)
{
	double	tmp_y;

	tmp_y = map->point[y * map->width + x].y;
	map->point[y * map->width + x].y = tmp_y * cos(map->angle_x) - \
		map->point[y * map->width + x].z * sin(map->angle_x);
	map->point[y * map->width + x].z = tmp_y * sin(map->angle_x) + \
		map->point[y * map->width + x].z * cos(map->angle_x);
}

void	rotate_all(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			rotate_z(x, y, map);
			rotate_x(x, y, map);
			rotate_y(x, y, map);
			x++;
		}
		y++;
	}
}

void	change_angles(t_map *map)
{
	if (mlx_is_key_down(map->obj, MLX_KEY_Z))
	{
		if (mlx_is_key_down(map->obj, MLX_KEY_RIGHT))
			map->angle_z += 0.01;
		else if (mlx_is_key_down(map->obj, MLX_KEY_LEFT))
			map->angle_z -= 0.01;
	}
	else if (mlx_is_key_down(map->obj, MLX_KEY_X))
	{
		if (mlx_is_key_down(map->obj, MLX_KEY_RIGHT))
			map->angle_x += 0.01;
		else if (mlx_is_key_down(map->obj, MLX_KEY_LEFT))
			map->angle_x -= 0.01;
	}
	else if (mlx_is_key_down(map->obj, MLX_KEY_C))
	{
		if (mlx_is_key_down(map->obj, MLX_KEY_RIGHT))
			map->angle_y += 0.01;
		else if (mlx_is_key_down(map->obj, MLX_KEY_LEFT))
			map->angle_y -= 0.01;
	}
	rotate_all(map);
	redraw(map, 'I');
}
