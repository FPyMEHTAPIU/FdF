/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:40:24 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/03 14:11:58 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>

void	clear_img(mlx_image_t *img)
{
	uint32_t	x;
	uint32_t	y;

	if (img)
	{
		y = 0;
		while (y++ < img->height - 1)
		{
			x = 0;
			while (x++ < img->width - 1)
				mlx_put_pixel(img, x, y, 0);
		}
	}
}

static void	move_img(int x, int y, t_image *img)
{
	if (mlx_is_key_down(img->obj, MLX_KEY_Z) || mlx_is_key_down(img->obj, MLX_KEY_X)
		|| mlx_is_key_down(img->obj, MLX_KEY_C))
		return ;
	img->point->move_x += x;
	img->point->move_y += y;
	clear_img(img->img);
	img->point = fill_image(img->img, img->map, img->point);
	to_2d(img->img, img->map, img->point);
}

static void	zoom_img(t_image *img, double space)
{
	if (img->point->space + img->map->space_incr >= 500.0 && space > 0.0) {}
	else if (img->point->space <= 0.4 && space < 0.0) {}
	else
		img->map->space_incr += space;
	clear_img(img->img);
	img->point = fill_image(img->img, img->map, img->point);
	to_2d(img->img, img->map, img->point);
}

static void	redraw(t_image *img, char type)
{
	img->point->type = type;
	clear_img(img->img);
	img->point = fill_image(img->img, img->map, img->point);
	to_2d(img->img, img->map, img->point);
}

void	fdf_keys(void *obj)
{
	t_image	*img;

	img = (t_image *) obj;
	if (mlx_is_key_down(img->obj, MLX_KEY_ESCAPE))
		mlx_close_window(img->obj);
	if (mlx_is_key_down(img->obj, MLX_KEY_UP))
		move_img(-5, -5, img);
	if (mlx_is_key_down(img->obj, MLX_KEY_RIGHT))
		move_img(5, -5, img);
	if (mlx_is_key_down(img->obj, MLX_KEY_DOWN))
		move_img(5, 5, img);
	if (mlx_is_key_down(img->obj, MLX_KEY_LEFT))
		move_img(-5, 5, img);
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
