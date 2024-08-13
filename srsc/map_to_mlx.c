/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:01:51 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/13 13:12:00 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	set_space(t_map *map)
{
	int	space;
	int total_nums;

	space = 1;
	total_nums = map->lines * map->nums_in_line;
	if (total_nums < 700)
		space = 20;
	else if (total_nums >= 700 && total_nums <= 5000)
		space = 10;
	else if (total_nums > 700 && total_nums <= 20000)
		space = 5;
	else if (total_nums > 20000 && total_nums <= 40000)
		space = 2;
	return (space);
}

static t_point	*fill_image(mlx_image_t *img, t_map *map, t_point *point)
{
	int	i;
	int	j;
	int	pos_x;
	int	pos_y;
	int space;

	i = 0;
	img->count = (size_t)(map->nums_in_line * map->lines);
	//img->count = (size_t)(map->total_nums);
	space = set_space(map);
	while (i < map->lines)
	{
		if (i > 0)
			pos_y += space;
		else
			pos_y = i;
		j = 0;
		while (j < map->nums_in_line)
		{
			if (j > 0)
				pos_x += space;
			else
				pos_x = j; 
			point[(i * map->nums_in_line) + j].x = pos_x;
			point[(i * map->nums_in_line) + j].y = pos_y;
			point[(i * map->nums_in_line) + j].z *= 2;
			j++;
		}
		i++;
	}
	return (point);
}

void	map_to_mlx(t_map *map, t_point *point)
{
	mlx_t	*obj;

	obj = mlx_init(800, 600, "FDF", 1);
	if (!obj)
		mlx_terminate(obj);
	mlx_image_t	*img = mlx_new_image(obj, 3000, 2000);
	point = fill_image(img, map, point);
	to_isometry(img, map, point);
	mlx_image_to_window(obj, img, 0, 0);
	mlx_loop_hook(obj, fdf_keys, obj);
	mlx_loop(obj);
	//mlx_key_hook(obj, 256);
	//mlx_delete_image(obj, img);
	mlx_terminate(obj);
}

