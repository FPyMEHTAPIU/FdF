/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:06:28 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/26 19:01:10 by msavelie         ###   ########.fr       */
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
		printf("pos[0].x = %f\tpos[0].y = %f\tpos[0].z = %f\n", point[0].x, point[0].y, point[0].z);
		clear_img(img->img);
		img->point = fill_image(img->img, img->map, img->point);
		to_isometry(img->img, img->map, img->point);
	}
}

void	rotate_y(t_point *point, t_map *map, t_image *img, double *rot_y)
{
	bool	draw;

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
		double center_x;
        if (map->nums_in_line % 2 == 0) {
            center_x = (point[map->nums_in_line / 2].x + point[map->nums_in_line / 2 - 1].x) / 2.0;
        } else {
            center_x = point[map->nums_in_line / 2].x;
        }

        // Вращаем каждую точку вокруг оси Y
        for (int i = 0; i < map->lines; i++) {
            for (int j = 0; j < map->nums_in_line; j++) {
                int index = i * map->nums_in_line + j;
                double x = point[index].x - center_x;
                double z = point[index].z;

				double rotated_x = x;
				double rotated_z = z;
                // Вращаем по оси Y
				
                rotated_x = x * cos(*rot_y) + z * sin(*rot_y);
               	rotated_z = -x * sin(*rot_y) + z * cos(*rot_y);

                point[index].x = rotated_x + center_x;
                point[index].z = rotated_z;
            }
        }
		printf("pos[0].x = %f\tpos[0].y = %f\tpos[0].z = %f\n", point[0].x, point[0].y, point[0].z);
		clear_img(img->img);
		img->point = fill_image(img->img, img->map, img->point);
		to_isometry(img->img, img->map, img->point);
	}
}

void	rotate_z(t_point *point, t_map *map, t_image *img, double *rot_z)
{
	bool	draw;
	double	angle;

	draw = false;
	angle = 5;
	if (mlx_is_key_down(img->obj, MLX_KEY_LEFT))
	{
		draw = true;
		*rot_z -= angle;
	}
	else if (mlx_is_key_down(img->obj, MLX_KEY_RIGHT))
	{
		draw = true;
		*rot_z += angle;
	}
	angle = *rot_z * M_PI / 180;
	if (draw)
	{
		double center_x = 0;
    	double center_y = 0;
    	int total_points = map->lines * map->nums_in_line;
	
    	for (int i = 0; i < total_points; i++) {
    	    center_x += point[i].x;
    	    center_y += point[i].y;
    	}
	
    	center_x /= total_points;
    	center_y /= total_points;
	
    	// Вращаем каждую точку относительно центра модели
    	for (int i = 0; i < total_points; i++) {
    	    // Перемещаем точку так, чтобы центр вращения был в начале координат
    	    double temp_x = point[i].x - center_x;
    	    double temp_y = point[i].y - center_y;
	
    	    // Применяем стандартное вращение
    	    double rotated_x = temp_x * cos(angle) - temp_y * sin(angle);
    	    double rotated_y = temp_x * sin(angle) + temp_y * cos(angle);
	
    	    // Возвращаем точку обратно, с учётом центра
    	    point[i].x = rotated_x + center_x;
    	    point[i].y = rotated_y + center_y;
		}
		clear_img(img->img);
		img->point = fill_image(img->img, img->map, img->point);
		to_isometry(img->img, img->map, img->point);
	}
}
