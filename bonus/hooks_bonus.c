/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:51:50 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/13 11:28:13 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	fdf_keys(void *obj)
{
	t_map	*map;

	map = (t_map *) obj;
	if (mlx_is_key_down(map->obj, MLX_KEY_ESCAPE))
		mlx_close_window(map->obj);
	if (mlx_is_key_down(map->obj, MLX_KEY_UP))
		move_img(0, -5, map); //, 'u');
	if (mlx_is_key_down(map->obj, MLX_KEY_RIGHT))
		move_img(5, 0, map); //, 'r');
	if (mlx_is_key_down(map->obj, MLX_KEY_DOWN))
		move_img(0, 5, map); //, 'd');
	if (mlx_is_key_down(map->obj, MLX_KEY_LEFT))
		move_img(-5, 0, map); //, 'l');
	if (mlx_is_key_down(map->obj, MLX_KEY_EQUAL))
		zoom_img(map, 0.2);
	if (mlx_is_key_down(map->obj, MLX_KEY_MINUS))
		zoom_img(map, -0.2);
	if (mlx_is_key_down(map->obj, MLX_KEY_I))
		redraw(map, 'I');
	if (mlx_is_key_down(map->obj, MLX_KEY_P))
		redraw(map, 'P');
	if (mlx_is_key_down(map->obj, MLX_KEY_Z)
		|| mlx_is_key_down(map->obj, MLX_KEY_X)
		|| mlx_is_key_down(map->obj, MLX_KEY_C))
		change_angles(map);
}

void	zoom(double xdelta, double ydelta, void *param)
{
	t_map	*map;

	map = (t_map *) param;
	zoom_img(map, 0.2 * ydelta + xdelta);
}
