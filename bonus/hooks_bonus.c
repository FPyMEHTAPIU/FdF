/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:51:50 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/16 11:26:52 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	fdf_keys(void *obj)
{
	t_map	*map;

	map = (t_map *) obj;
	if (mlx_is_key_down(map->obj, MLX_KEY_ESCAPE))
		mlx_close_window(map->obj);
	if (mlx_is_key_down(map->obj, MLX_KEY_UP)
		|| mlx_is_key_down(map->obj, MLX_KEY_RIGHT)
		|| mlx_is_key_down(map->obj, MLX_KEY_DOWN)
		|| mlx_is_key_down(map->obj, MLX_KEY_LEFT))
		move_img(map);
	if (mlx_is_key_down(map->obj, MLX_KEY_EQUAL))
		zoom_img(map, 0.2);
	if (mlx_is_key_down(map->obj, MLX_KEY_MINUS))
		zoom_img(map, -0.2);
	if (mlx_is_key_down(map->obj, MLX_KEY_I))
		redraw(map, 'I');
	if (mlx_is_key_down(map->obj, MLX_KEY_T)
		|| mlx_is_key_down(map->obj, MLX_KEY_R)
		|| mlx_is_key_down(map->obj, MLX_KEY_F))
		set_orto_side(map);
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
