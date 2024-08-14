/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:40:24 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/14 13:47:56 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	clear_img(mlx_image_t *img)
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
	img->point->move_x += x;
	img->point->move_y += y;
	clear_img(img->img);
	img->point = fill_image(img->img, img->map, img->point);
	to_isometry(img->img, img->map, img->point);
	//mlx_delete_image(img->obj, img->img);
	//mlx_image_to_window(img->obj, img->img, img->x, img->y);
}

static void	zoom_img(t_image *img, float val)
{
	//uint32_t	width;
	//uint32_t	height;

	if (img->zoom <= 0.01 && val < 0)
		img->zoom = 0.01;
	else
		img->zoom += val;
	if (val > 0)
	{
		img->point->space++;
		img->width++;
		img->height++;
	}
	else
	{
		if (img->width > 1 && img->height > 1)
		{
			img->width--;
			img->height--;
		}
		if (img->point->space <= 1)
			img->point->space = 1;
		else
			img->point->space--;
	}
	clear_img(img->img);
	mlx_resize_image(img->img, img->width, img->height);
	img->point = fill_image(img->img, img->map, img->point);
	to_isometry(img->img, img->map, img->point);
}

void	fdf_keys(void *obj)
{
	t_image	*img;

	img = (t_image *) obj;
	if (mlx_is_key_down(img->obj, MLX_KEY_ESCAPE))
		mlx_close_window(img->obj);
	if (mlx_is_key_down(img->obj, MLX_KEY_UP))
		move_img(0, -1, img);
	if (mlx_is_key_down(img->obj, MLX_KEY_RIGHT))
		move_img(1, 0, img);
	if (mlx_is_key_down(img->obj, MLX_KEY_DOWN))
		move_img(0, 1, img);
	if (mlx_is_key_down(img->obj, MLX_KEY_LEFT))
		move_img(-1, 0, img);
	if (mlx_is_key_down(img->obj, MLX_KEY_KP_ADD))
		zoom_img(img, 0.01);
	if (mlx_is_key_down(img->obj, MLX_KEY_KP_SUBTRACT))
		zoom_img(img, -0.01);
}
