/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:06:28 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/06 12:45:29 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static bool	does_rotate_x(double *angle, t_image *img)
{
	if (mlx_is_key_down(img->obj, MLX_KEY_LEFT))
	{
		*angle = -0.01;
		if (img->point[0].angle_x <= -3.0)
		{
			img->point[0].angle_x = 0.0;
			*angle = 0.01;
		}
		else if (img->point[0].angle_x <= -1.5)
			*angle = 0.01;
		return (true);
	}
	else if (mlx_is_key_down(img->obj, MLX_KEY_RIGHT))
	{
		*angle = 0.01;
		if (img->point[0].angle_x >= 3.0)
		{
			img->point[0].angle_x = 0.0;
			*angle = -0.01;
		}
		else if (img->point[0].angle_x >= 1.5)
			*angle = -0.01;
		return (true);
	}
	return (false);
}

static bool	does_rotate_y(double *angle, t_image *img)
{
	if (mlx_is_key_down(img->obj, MLX_KEY_LEFT))
	{
		*angle = -0.01;
		if (img->point[0].angle_y <= -3.0)
		{
			img->point[0].angle_y = 0.0;
			*angle = 0.01;
		}
		else if (img->point[0].angle_y <= -1.5)
			*angle = 0.01;
		return (true);
	}
	else if (mlx_is_key_down(img->obj, MLX_KEY_RIGHT))
	{
		*angle = 0.01;
		if (img->point[0].angle_y >= 3.0)
		{
			img->point[0].angle_y = 0.0;
			*angle = -0.01;
		}
		else if (img->point[0].angle_y >= 1.5)
			*angle = -0.01;
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

static void	multiply_matrix(t_point *point, t_image *img, t_matrix mtx, double *center, char type)
{
	int	i;

	i = 0;
	while (i < img->map->nums_in_line * img->map->lines)
	{
		mtx.i = (double [3]){img->orig_point[i].x, img->orig_point[i].y, img->orig_point[i].z};
		mtx.j = (double [3]){img->orig_point[i].x, img->orig_point[i].y, img->orig_point[i].z};
		mtx.k = (double [3]){img->orig_point[i].x, img->orig_point[i].y, img->orig_point[i].z};
		if (type == 'x')
			point[i].angle_x += center[2];
		else if (type == 'y')
			point[i].angle_y += center[2];
		point[i].x = mtx.i[0] * 1 + (mtx.i[1] - center[1]) * 0 + mtx.i[2] * 0;
		point[i].y = mtx.j[0] * 0 + (mtx.j[1] - center[1]) * cos(point[i].angle_x) + mtx.j[2] * -sin(point[i].angle_x) + center[1];
		point[i].z = mtx.k[0] * 0 + (mtx.k[1] - center[1]) * sin(point[i].angle_x) + mtx.k[2] * cos(point[i].angle_x);
		mtx.i = (double [3]){point[i].x, point[i].y, point[i].z};
		mtx.j = (double [3]){point[i].x, point[i].y, point[i].z};
		mtx.k = (double [3]){point[i].x, point[i].y, point[i].z};
		point[i].x = (mtx.i[0] - center[0]) * cos(point[i].angle_y) + mtx.i[1] * 0 + mtx.i[2] * sin(point[i].angle_y) + center[0];
		point[i].y = (mtx.j[0] - center[0]) * 0 + mtx.j[1] * 1 + mtx.j[2] * 0;
		point[i].z = (mtx.k[0] - center[0]) * -sin(point[i].angle_y) + mtx.k[1] * 0 + mtx.k[2] * cos(point[i].angle_y);
		i++;
	}
}

void	rotate_obj(t_point	*point, t_map *map, char type, t_image *img)
{
	t_matrix	matrix;
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
			center[1] = (img->orig_point[(map->lines / 2) * map->nums_in_line].y \
				+ img->orig_point[(map->lines / 2 - 1) * map->nums_in_line].y) / 2.0;
		}
		else
		{
			center[0] = img->orig_point[map->nums_in_line / 2].x;
			center[1] = img->orig_point[(map->lines / 2) * map->nums_in_line].y;
		}
		multiply_matrix(point, img, matrix, center, type);
		clear_img(img->img);
		img->point = fill_image(img->img, img->map, img->point);
		to_2d(img->img, img->map, img->point);
	}
}
