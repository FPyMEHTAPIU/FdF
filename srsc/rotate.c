/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:06:28 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/20 14:47:48 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>

void	rotate_x(t_point *point, t_map *map, t_image *img, double *rot_x)
{
	bool		draw;

	draw = false;
	if (mlx_is_key_down(img->obj, MLX_KEY_LEFT))
	{
		draw = true;
		*rot_x -= 0.01;
	}
	else if (mlx_is_key_down(img->obj, MLX_KEY_RIGHT))
	{
		draw = true;
		*rot_x += 0.01;
	}

	const double TWO_PI = 2.0 * M_PI;
    if (*rot_x >= TWO_PI) {
        *rot_x -= TWO_PI;
    } else if (*rot_x < 0) {
        *rot_x += TWO_PI;
    }

	if (draw)
	{
		double center_y;
        if (map->lines % 2 == 0) {
            center_y = (point[(map->lines / 2) * map->nums_in_line].y +
                        point[(map->lines / 2 - 1) * map->nums_in_line].y) / 2.0;
        } else {
            center_y = point[(map->lines / 2) * map->nums_in_line].y;
        }

        // Вращаем каждую точку вокруг оси X
        for (int i = 0; i < map->lines; i++) {
            for (int j = 0; j < map->nums_in_line; j++) {
                int index = i * map->nums_in_line + j;
                double y = point[index].y - center_y;
                double z = point[index].z;

                // Вращаем по оси X
                double rotated_y = y * cos(*rot_x) - z * sin(*rot_x);
                double rotated_z = y * sin(*rot_x) + z * cos(*rot_x);

                point[index].y = rotated_y + center_y;
                point[index].z = rotated_z;
            }
        }
		printf("rot_x = %f\n", *rot_x);
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
	double		x;
	double		z;

	draw = false;
	if (mlx_is_key_down(img->obj, MLX_KEY_LEFT))
	{
		draw = true;
		*rot_y -= 0.01;
	}
	else if (mlx_is_key_down(img->obj, MLX_KEY_RIGHT))
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
			x = point[i].x;
			z = point[i].z;
			point[i].x = x * cos(*rot_y) + z * sin(*rot_y);
			point[i].z = -x * sin(*rot_y) + z * cos(*rot_y);
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
	double		x;
	double		y;

	draw = false;
	if (mlx_is_key_down(img->obj, MLX_KEY_LEFT))
	{
		draw = true;
		*rot_z -= 0.1;
	}
	else if (mlx_is_key_down(img->obj, MLX_KEY_RIGHT))
	{
		draw = true;
		*rot_z += 0.1;
	}
	if (draw)
	{
		total = map->lines * map->nums_in_line;
		i = 0;
		while (i < total)
		{
			x = point[i].x;
			y = point[i].y;
			point[i].x = x * cos(*rot_z) - y * sin(*rot_z);
			point[i].y = x * sin(*rot_z) + y * cos(*rot_z);
			i++;
		}
		clear_img(img->img);
		img->point = fill_image(img->img, img->map, img->point);
		to_isometry(img->img, img->map, img->point);
	}
}

void	rotate_img(t_image *img, char c)
{
	double	rot_x;
	double	rot_y;
	double	rot_z;
	
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