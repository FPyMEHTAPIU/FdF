/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:01:51 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/09 12:50:43 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static t_point	*fill_image(mlx_image_t *img, t_map *map, t_point *point)
{
	int	i;
	int	j;
	int	pos_x;
	int	pos_y;

	i = 0;
	img->count = (size_t)(map->nums_in_line * map->lines);
	while (i < map->lines)
	{
		if (i > 0)
			pos_y += SPACE;
		else
			pos_y = i;
		j = 0;
		while (j < map->nums_in_line)
		{
			if (j > 0)
				pos_x += SPACE;
			else
				pos_x = j; 
			point[(i * map->nums_in_line) + j].x = pos_x;
			point[(i * map->nums_in_line) + j].y = pos_y;
			point[(i * map->nums_in_line) + j].z *= 3;
			j++;
		}
		i++;
	}
	return (point);
}

void	map_to_mlx(t_map *map, t_point *point)
{
	mlx_t	*obj;

	obj = mlx_init(4000, 2000, "FDF", 1);
	if (!obj)
		mlx_terminate(obj);
	mlx_image_t	*img = mlx_new_image(obj, 4000, 2000);
	point = fill_image(img, map, point);
	to_isometry(img, map, point);
	mlx_image_to_window(obj, img, 0, 0);
	mlx_loop(obj);
}
