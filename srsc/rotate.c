/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:06:28 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/15 15:03:31 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	rotate_x(t_point *point, t_map *map, t_image *img, double *rot_x)
{
	uint32_t	i;
	uint32_t	total;
	bool		draw;

	draw = false;
	if (mlx_is_key_down(img->obj, MLX_KEY_LEFT) && *rot_x > -360.0)
	{
		draw = true;
		*rot_x -= 0.01;
	}
	else if (mlx_is_key_down(img->obj, MLX_KEY_RIGHT) && *rot_x < 360.0)
	{
		draw = true;
		*rot_x += 0.01;
	}
	if (draw)
	{
		total = map->lines * map->nums_in_line;
		i = 0;
		while (i < total)
		{
			point[i].y = point[i].y * cos(*rot_x) - point[i].z * sin(*rot_x);
			point[i].z = point[i].y * sin(*rot_x) + point[i].z * cos(*rot_x);
			i++;
		}
		clear_img(img->img);
		img->point = fill_image(img->img, img->map, img->point);
		to_isometry(img->img, img->map, img->point);
	}
}

void	rotate_y(t_point *point, t_map *map, t_image *img, double *rot_y)
{
	uint32_t	i;
	uint32_t	total;
	bool		draw;

	draw = false;
	if (mlx_is_key_down(img->obj, MLX_KEY_LEFT) && *rot_y > -360.0)
	{
		draw = true;
		*rot_y -= 0.01;
	}
	else if (mlx_is_key_down(img->obj, MLX_KEY_RIGHT) && *rot_y < 360.0)
	{
		draw = true;
		*rot_y += 0.01;
	}
	if (draw)
	{
		total = map->lines * map->nums_in_line;
		i = 0;
		while (i < total)
		{
			point[i].x = point[i].x * cos(*rot_y) + point[i].z * sin(*rot_y);
			point[i].z = -point[i].x * sin(*rot_y) + point[i].z * cos(*rot_y);
			i++;
		}
		clear_img(img->img);
		img->point = fill_image(img->img, img->map, img->point);
		to_isometry(img->img, img->map, img->point);
	}
}

void	rotate_z(t_point *point, t_map *map, t_image *img, double *rot_z)
{
	uint32_t	i;
	uint32_t	total;
	bool		draw;

	draw = false;
	if (mlx_is_key_down(img->obj, MLX_KEY_LEFT) && *rot_z > -360.0)
	{
		draw = true;
		*rot_z -= 0.01;
	}
	else if (mlx_is_key_down(img->obj, MLX_KEY_RIGHT) && *rot_z < 360.0)
	{
		draw = true;
		*rot_z += 0.01;
	}
	if (draw)
	{
		total = map->lines * map->nums_in_line;
		i = 0;
		while (i < total)
		{
			point[i].x = point[i].x * cos(*rot_z) - point[i].y * sin(*rot_z);
			point[i].y = point[i].x * sin(*rot_z) + point[i].y * cos(*rot_z);
			i++;
		}
		clear_img(img->img);
		img->point = fill_image(img->img, img->map, img->point);
		to_isometry(img->img, img->map, img->point);
	}
}

void	rotate_img(t_image *img, char c)
{
	static double	rot_x;
	static double	rot_y;
	static double	rot_z;
	
	if (c == 'x')
	{
		rotate_x(img->point, img->map, img, &rot_x);
		clear_img(img->img);
		img->point = fill_image(img->img, img->map, img->point);
		to_isometry(img->img, img->map, img->point);
	}
		
	/*{
		if (mlx_is_key_down(img->obj, MLX_KEY_LEFT))
			angle = -1;
		else if (mlx_is_key_down(img->obj, MLX_KEY_RIGHT))
			angle = 1;
		img->point->y = img->point->y * cos(angle) - img->point->z * sin(angle);
		img->point->z = img->point->y * sin(angle) + img->point->z * cos(angle);
	}*/
	else if (c == 'y')
	{
		rotate_y(img->point, img->map, img, &rot_y);
		clear_img(img->img);
		img->point = fill_image(img->img, img->map, img->point);
		to_isometry(img->img, img->map, img->point);
	}
		
	/*{
		if (mlx_is_key_down(img->obj, MLX_KEY_LEFT))
			angle = -1;
		else if (mlx_is_key_down(img->obj, MLX_KEY_RIGHT))
			angle = 1;
		img->point->x = img->point->x * cos(angle) + img->point->z * sin(angle);
		img->point->z = -img->point->x * sin(angle) + img->point->z * cos(angle);
	}*/
	else if (c == 'z')
	{
		rotate_z(img->point, img->map, img, &rot_z);
		clear_img(img->img);
		img->point = fill_image(img->img, img->map, img->point);
		to_isometry(img->img, img->map, img->point);
	}
	/*{
		if (mlx_is_key_down(img->obj, MLX_KEY_LEFT))
			angle = -1;
		else if (mlx_is_key_down(img->obj, MLX_KEY_RIGHT))
			angle = 1;
		img->point->x = img->point->x * cos(angle) - img->point->y * sin(angle);
		img->point->y = img->point->x * sin(angle) + img->point->y * cos(angle);
	}*/
	
}