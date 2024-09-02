/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:06:28 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/02 15:53:57 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>

void	rotate_x(t_point *point, t_map *map, t_image *img)
{
	bool		draw;
	t_matrix	matrix;
	int			i;
	double		angle;

	draw = false;
	if (mlx_is_key_down(img->obj, MLX_KEY_LEFT))
	{
		draw = true;
		angle = -0.01;
		/*if (point[0].angle_x <= -1.5)
			angle = 0.0;*/
	}
	else if (mlx_is_key_down(img->obj, MLX_KEY_RIGHT))
	{
		draw = true;
		angle = 0.01;
		/*if (point[0].angle_x >= 1.5)
			angle = 0.0;*/
	}
	if (draw)
	{
		double center_y;
	   	if (map->lines % 2 == 0) {
            center_y = (img->orig_point[(map->lines / 2) * map->nums_in_line].y +
                        img->orig_point[(map->lines / 2 - 1) * map->nums_in_line].y) / 2.0;
        } else {
            center_y = img->orig_point[(map->lines / 2) * map->nums_in_line].y;
        }
		i = 0;
		while (i < map->nums_in_line * map->lines)
		{
			matrix.i = (double [3]){point[i].x, point[i].y - center_y, point[i].z};
			matrix.j = (double [3]){img->orig_point[i].x, img->orig_point[i].y - center_y, img->orig_point[i].z};
			matrix.k = (double [3]){img->orig_point[i].x, img->orig_point[i].y - center_y, img->orig_point[i].z};
				
			point[i].angle_x += angle;
			point[i].x = matrix.i[0] * 1 + matrix.i[1] * 0 + matrix.i[2] * 0;
			point[i].y = (matrix.j[0] * 0 + matrix.j[1] * cos(point[i].angle_x) + matrix.j[2] * -sin(point[i].angle_x)) + center_y;
			point[i].z = matrix.k[0] * 0 + matrix.k[1] * sin(point[i].angle_x) + matrix.k[2] * cos(point[i].angle_x);
			
			i++;
		}
		printf("point[0].x = %f\tpoint[0].y = %f\tpoint[0].z = %f\n", point[0].x, point[0].y, point[0].z);
		printf("angle_x = %f\n", point[0].angle_x);
		clear_img(img->img);
		img->point = fill_image(img->img, img->map, img->point);
		to_2d(img->img, img->map, img->point);
	}
}

void	rotate_y(t_point *point, t_map *map, t_image *img)
{
	bool	draw;
	double	angle;
	t_matrix	matrix;
	int		i;

	draw = false;
	if (mlx_is_key_down(img->obj, MLX_KEY_LEFT))
	{
		draw = true;
		angle = -0.01;
	}
	else if (mlx_is_key_down(img->obj, MLX_KEY_RIGHT))
	{
		draw = true;
		angle = 0.01;
	}
	if (draw)
	{
		double center_x;
        if (map->nums_in_line % 2 == 0) {
            center_x = (img->orig_point[map->nums_in_line / 2].x + img->orig_point[map->nums_in_line / 2 - 1].x) / 2.0;
        } else {
            center_x = img->orig_point[map->nums_in_line / 2].x;
        }
		i = 0;
		while (i < map->nums_in_line * map->lines)
		{
			matrix.i = (double [3]){img->point[i].x - center_x, img->orig_point[i].y, img->orig_point[i].z};
			matrix.j = (double [3]){point[i].x - center_x, point[i].y, point[i].z};
			matrix.k = (double [3]){img->orig_point[i].x - center_x, img->orig_point[i].y, img->orig_point[i].z};
			point[i].angle_y += angle;
			point[i].x = matrix.i[0] * cos(point[i].angle_y) + matrix.i[1] * 0 + matrix.i[2] * sin(point[i].angle_y) + center_x;
			point[i].y = matrix.j[0] * 0 + matrix.j[1] * 1 + matrix.j[2] * 0;
			point[i].z = matrix.k[0] * -sin(point[i].angle_y) + matrix.k[1] * 0 + matrix.k[2] * cos(point[i].angle_y);
			i++;
		}
        // Вращаем каждую точку вокруг оси Y
        /*for (int i = 0; i < map->lines; i++) {
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
        }*/
	    printf("point[0].x = %f\tpoint[0].y = %f\tpoint[0].z = %f\n", point[0].x, point[0].y, point[0].z);
		printf("angle_y = %f\n", point[0].angle_y);
		clear_img(img->img);
		img->point = fill_image(img->img, img->map, img->point);
		to_2d(img->img, img->map, img->point);
	}
}

void	rotate_z(t_point *point, t_map *map, t_image *img)
{
	bool	draw;
	double	angle;

	draw = false;
	if (mlx_is_key_down(img->obj, MLX_KEY_LEFT))
	{
		draw = true;
		angle = -0.01;
	}
	else if (mlx_is_key_down(img->obj, MLX_KEY_RIGHT))
	{
		draw = true;
		angle = 0.01;
	}
	angle *= M_PI / 180;
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
		to_2d(img->img, img->map, img->point);
	}
}

void	rotate_obj(t_point	*point, t_map *map, char type, t_image *img, double val)
{
	t_matrix	matrix;
	int			i;

	i = 0;
	while (i < map->nums_in_line * map->lines)
	{
		matrix.i = (double [3]){img->orig_point[i].x, img->orig_point[i].y, img->orig_point[i].z};
		matrix.j = (double [3]){img->orig_point[i].x, img->orig_point[i].y, img->orig_point[i].z};
		matrix.k = (double [3]){img->orig_point[i].x, img->orig_point[i].y, img->orig_point[i].z};
		if (type == 'x')
		{
			point[i].angle_x += val;
			point[i].x = matrix.i[0] * 1 + matrix.i[1] * 0 + matrix.i[2] * 0;
			point[i].y = matrix.j[0] * 0 + matrix.j[1] * cos(point[i].angle_x) + matrix.j[2] * -sin(point[i].angle_x);
			point[i].z = matrix.k[0] * 0 + matrix.k[1] * sin(point[i].angle_x) + matrix.k[2] * cos(point[i].angle_x);
		}
		else if (type == 'y')
		{
			point[i].angle_y += val;
			point[i].x = matrix.i[0] * cos(point[i].angle_y) + matrix.i[1] * 0 + matrix.i[2] * sin(point[i].angle_y);
			point[i].y = matrix.j[0] * 0 + matrix.j[1] * 1 + matrix.j[2] * 0;
			point[i].z = matrix.k[0] * -sin(point[i].angle_y) + matrix.k[1] * 0 + matrix.k[2] * cos(point[i].angle_y);
		}
		else if (type == 'z')
		{
			point[i].angle_z += val;
			point[i].x = matrix.i[0] * cos(to_rad(point[i].angle_z)) + matrix.i[1] * -sin(to_rad(point[i].angle_z)) + matrix.i[2] * 0;
			point[i].y = matrix.j[0] * sin(to_rad(point[i].angle_z)) + matrix.j[1] * cos(to_rad(point[i].angle_z)) + matrix.j[2] * 0;
			point[i].z = matrix.k[0] * 0 + matrix.k[1] * 0 + matrix.k[2] * 1;
		}
		i++;
	}
	clear_img(img->img);
	img->point = fill_image(img->img, img->map, img->point);
	to_2d(img->img, img->map, img->point);
}
