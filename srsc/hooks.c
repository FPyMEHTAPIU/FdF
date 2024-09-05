/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:51:50 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/05 14:52:19 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	fdf_keys(void *obj)
{
	t_image	*img;

	img = (t_image *) obj;
	if (mlx_is_key_down(img->obj, MLX_KEY_ESCAPE))
		mlx_close_window(img->obj);
	if (mlx_is_key_down(img->obj, MLX_KEY_UP))
		move_img(-5, -5, img, 'u');
	if (mlx_is_key_down(img->obj, MLX_KEY_RIGHT))
		move_img(5, -5, img, 'r');
	if (mlx_is_key_down(img->obj, MLX_KEY_DOWN))
		move_img(5, 5, img, 'd');
	if (mlx_is_key_down(img->obj, MLX_KEY_LEFT))
		move_img(-5, 5, img, 'l');
	if (mlx_is_key_down(img->obj, MLX_KEY_EQUAL))
		zoom_img(img, 0.2);
	if (mlx_is_key_down(img->obj, MLX_KEY_MINUS))
		zoom_img(img, -0.2);
	if (mlx_is_key_down(img->obj, MLX_KEY_I))
		redraw(img, 'I');
	if (mlx_is_key_down(img->obj, MLX_KEY_P))
		redraw(img, 'P');
	if (mlx_is_key_down(img->obj, MLX_KEY_X))
		rotate_obj(img->point, img->map, 'x', img);
	if (mlx_is_key_down(img->obj, MLX_KEY_C))
		rotate_obj(img->point, img->map, 'y', img);
}

void	zoom(double xdelta, double ydelta, void *param)
{
	t_image	*img;

	img = (t_image *) param;
	zoom_img(img, 0.2 * ydelta + xdelta);
}
