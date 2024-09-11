/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:06:28 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/11 14:07:31 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

static bool	does_rotate_x(double *angle, t_image *img)
{
	if (mlx_is_key_down(img->obj, MLX_KEY_LEFT))
	{
		*angle = -0.01;
		/*if (img->point[0].angle_x <= -3.0)
		{
			img->point[0].angle_x = 0.0;
			*angle = 0.01;
		}
		else if (img->point[0].angle_x <= -1.5)
			*angle = 0.01;*/
		return (true);
	}
	else if (mlx_is_key_down(img->obj, MLX_KEY_RIGHT))
	{
		*angle = 0.01;
		/*if (img->point[0].angle_x >= 3.0)
		{
			img->point[0].angle_x = 0.0;
			*angle = -0.01;
		}
		else if (img->point[0].angle_x >= 1.5)
			*angle = -0.01;*/
		return (true);
	}
	return (false);
}

static bool	does_rotate_y(double *angle, t_image *img)
{
	if (mlx_is_key_down(img->obj, MLX_KEY_LEFT))
	{
		*angle = -0.01;
		/*if (img->point[0].angle_y <= -3.0)
		{
			img->point[0].angle_y = 0.0;
			*angle = 0.01;
		}
		else if (img->point[0].angle_y <= -1.5)
			*angle = 0.01;*/
		return (true);
	}
	else if (mlx_is_key_down(img->obj, MLX_KEY_RIGHT))
	{
		*angle = 0.01;
		/*if (img->point[0].angle_y >= 3.0)
		{
			img->point[0].angle_y = 0.0;
			*angle = -0.01;
		}
		else if (img->point[0].angle_y >= 1.5)
			*angle = -0.01;*/
		return (true);
	}
	return (false);
}

static bool	does_rotate(double *angle, t_image *img, char type)
{
	if (type == 'x')
		return (does_rotate_x(angle, img));
	return (does_rotate_y(angle, img));
}

static void	multiply_mtx(t_point *point, t_image *img, double *center, char t)
{
	int		i;
	double	*mtx;

	i = 0;
	while (i < img->map->nums_in_line * img->map->lines)
	{
		mtx = (double [3]){img->orig_point[i].x,
			img->orig_point[i].y, img->orig_point[i].z};
		if (t == 'x')
			point[i].angle_x += center[2];
		else if (t == 'y')
			point[i].angle_y += center[2];
		point[i].x = mtx[0] * 1 + (mtx[1] - center[1]) * 0 + mtx[2] * 0;
		point[i].y = mtx[0] * 0 + (mtx[1] - center[1]) * cos(point[i].angle_x)
			+ mtx[2] * -sin(point[i].angle_x) + center[1];
		point[i].z = mtx[0] * 0 + (mtx[1] - center[1]) * sin(point[i].angle_x)
			+ mtx[2] * cos(point[i].angle_x);
		mtx = (double [3]){point[i].x, point[i].y, point[i].z};
		point[i].x = (mtx[0] - center[0]) * cos(point[i].angle_y) + mtx[1] * 0
			+ mtx[2] * sin(point[i].angle_y) + center[0];
		point[i].y = (mtx[0] - center[0]) * 0 + mtx[1] * 1 + mtx[2] * 0;
		point[i].z = (mtx[0] - center[0]) * -sin(point[i].angle_y)
			+ mtx[1] * 0 + mtx[2] * cos(point[i].angle_y);
		i++;
	}
}

void	rotate_obj(t_point	*point, t_map *map, char type, t_image *img)
{
	bool		draw;
	double		center[3];

	center[2] = 0.0;
	draw = does_rotate(&center[2], img, type);
	if (draw)
	{
		if (map->nums_in_line % 2 == 0)
		{
			center[0] = (img->orig_point[map->nums_in_line / 2].x \
				+ img->orig_point[map->nums_in_line / 2 - 1].x) / 2.0;
			center[1] = (img->orig_point[(map->lines / 2) * map->nums_in_line].y
					+ img->orig_point[(map->lines / 2 - 1)
					* map->nums_in_line].y) / 2.0;
		}
		else
		{
			center[0] = img->orig_point[map->nums_in_line / 2].x;
			center[1] = img->orig_point[(map->lines / 2) * map->nums_in_line].y;
		}
		multiply_mtx(point, img, center, type);
		clear_img(img->img);
		img->point = fill_image(img->img, img->map, img->point);
		to_2d(img->img, img->map, img->point);
	}
}
