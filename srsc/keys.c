/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:40:24 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/20 11:25:04 by msavelie         ###   ########.fr       */
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
	to_isometry(img->img, img->map, img->point);
}

static void	zoom_img(t_image *img, double space, double win_size)
{
	printf("space = %f\tspace_incr = %f\n", img->point->space, img->map->space_incr);
	if (img->point->space + img->map->space_incr >= 500.0 && space > 0.0)
	{
		img->point->space = 500.0;
		img->map->space_incr = 0.2;
	}
	else if (img->point->space <= 0.4 && space < 0.0)
	{
		img->point->space = 0.4;
		img->map->space_incr = -0.2;
	}
	else
		img->map->space_incr += space;
	clear_img(img->img);
	if (win_size < 0 && (img->width <= 1000 || img->height <= 500))
	{
		img->width = 1000;
		img->height = 500;
	}
	else
	{
		if (win_size < 0)
		{
			img->width -= win_size * -1 * img->width;
			img->height -= win_size * -1 * img->height;
		}
		else
		{
			img->width += win_size * img->width;
			img->height += win_size * img->height;
		}
		printf("width = %u\theight = %u\n", img->width, img->height);
		mlx_resize_image(img->img, img->width, img->height);
	}
	img->point = fill_image(img->img, img->map, img->point);
	to_isometry(img->img, img->map, img->point);
}

void	fdf_keys(void *obj)
{
	t_image	*img;
	double	rot_x;
	double	rot_y;
	double	rot_z;

	img = (t_image *) obj;
	rot_x = 0;
	rot_y = 0;
	rot_z = 0;
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
		zoom_img(img, 0.2, 0.01);
	if (mlx_is_key_down(img->obj, MLX_KEY_MINUS))
		zoom_img(img, -0.2, -0.01);
	if (mlx_is_key_down(img->obj, MLX_KEY_Z))
		rotate_z(img->point, img->map, img, &rot_z);
	if (mlx_is_key_down(img->obj, MLX_KEY_X))
		rotate_x(img->point, img->map, img, &rot_x);
	if (mlx_is_key_down(img->obj, MLX_KEY_C))
		rotate_y(img->point, img->map, img, &rot_y);
}

void	zoom(double xdelta, double ydelta, void *param)
{
	t_image	*img;

	img = (t_image *) param;
	printf("xdelta = %f\tydelta = %f\n", xdelta, ydelta);
	zoom_img(img, 0.2 * ydelta, 0.01 * ydelta);
}
