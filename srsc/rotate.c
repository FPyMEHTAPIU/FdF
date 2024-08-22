/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:06:28 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/22 17:39:38 by msavelie         ###   ########.fr       */
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
		printf("rot_x = %f\n", *rot_x);
		clear_img(img->img);
		img->point = fill_image(img->img, img->map, img->point);
		to_isometry(img->img, img->map, img->point);
	}
}

void	rotate_y(t_point *point, t_map *map, t_image *img, double *rot_y)
{
	//uint32_t	i;
	//uint32_t	total;
	bool		draw;
	//double		x;
	//double		z;

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

                // Вращаем по оси Y
                double rotated_x = x * cos(*rot_y) + z * sin(*rot_y);
                double rotated_z = -x * sin(*rot_y) + z * cos(*rot_y);

                point[index].x = rotated_x + center_x;
                point[index].z = rotated_z;
            }
        }
		
		clear_img(img->img);
		img->point = fill_image(img->img, img->map, img->point);
		to_isometry(img->img, img->map, img->point);
	}
}

void	rotate_z(t_point *point, t_map *map, t_image *img, double *rot_z)
{
	//uint32_t	i;
	//uint32_t	total;
	bool		draw;
	//double		x;
	//double		y;
	draw = false;
	if (mlx_is_key_down(img->obj, MLX_KEY_LEFT))
	{
		draw = true;
		*rot_z -= 10;
	}
	else if (mlx_is_key_down(img->obj, MLX_KEY_RIGHT))
	{
		draw = true;
		*rot_z += 10;
	}
	if (draw)
	{
		/*total = map->lines * map->nums_in_line;
		i = 0;
		while (i < total)
		{
			x = point[i].x;
			y = point[i].y;
			point[i].x = x * cos(*rot_z) - y * sin(*rot_z);
			point[i].y = x * sin(*rot_z) + y * cos(*rot_z);
			i++;
		}*/
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
    	    double rotated_x = temp_x * cos(*rot_z) - temp_y * sin(*rot_z);
    	    double rotated_y = temp_x * sin(*rot_z) + temp_y * cos(*rot_z);
	
    	    // Возвращаем точку обратно, с учётом центра
    	    point[i].x = rotated_x + center_x;
    	    point[i].y = rotated_y + center_y;
		}
		printf("rot_z = %f\n", M_PI / 4);
		clear_img(img->img);
		img->point = fill_image(img->img, img->map, img->point);
		to_isometry(img->img, img->map, img->point);
	}
}
