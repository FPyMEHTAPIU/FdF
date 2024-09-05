/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:40:24 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/05 15:26:28 by msavelie         ###   ########.fr       */
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
		while (y++ < img->height)
		{
			x = 0;
			while (x++ < img->width)
				mlx_put_pixel(img, x, y, 0);
		}
	}
}

void	move_img(int x, int y, t_image *img, char dir)
{
	if (mlx_is_key_down(img->obj, MLX_KEY_Z)
		|| mlx_is_key_down(img->obj, MLX_KEY_X)
		|| mlx_is_key_down(img->obj, MLX_KEY_C))
		return ;
	if ((dir == 'u' || dir == 'd') && img->point->type == 'P')
		x = 0;
	else if ((dir == 'l' || dir == 'r') && img->point->type == 'P')
		y = 0;
	img->point->move_x += x;
	img->point->move_y += y;
	clear_img(img->img);
	img->point = fill_image(img->img, img->map, img->point);
	to_2d(img->img, img->map, img->point);
}

void	zoom_img(t_image *img, double space)
{
	if (img->point->space + img->map->space_incr >= 500.0 && space > 0.0)
		;
	else if (img->point->space <= 0.4 && space < 0.0)
		;
	else
		img->map->space_incr += space;
	clear_img(img->img);
	img->point = fill_image(img->img, img->map, img->point);
	to_2d(img->img, img->map, img->point);
}

void	redraw(t_image *img, char type)
{
	img->point->type = type;
	clear_img(img->img);
	img->point = fill_image(img->img, img->map, img->point);
	to_2d(img->img, img->map, img->point);
}
