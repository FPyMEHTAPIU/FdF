/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:01:51 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/08 18:01:52 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static t_point	*fill_image(mlx_image_t *img, t_map *map, t_point *point)//int **nums)
{
	//int	space;
	int	i;
	int	j;
	int	pos_x;
	int	pos_y;
	//t_point	*point;

	//space = 20;
	i = 0;
	img->count = (size_t)(map->nums_in_line * map->lines);
	//point = malloc(sizeof(t_point) * img->count);
	//if (!point)
	//{
	//	ft_printf("ERROR!ERROR!ERROR!!!1\n");
	//	exit (1);
	//}
	while (i < map->lines)
	{
		if (i > 0)
			pos_y += SPACE; //space;
		else
			pos_y = i;
		j = 0;
		while (j < map->nums_in_line)
		{
			if (j > 0)
				pos_x += SPACE; // space;
			else
				pos_x = j; 
			point[(i * map->nums_in_line) + j].x = pos_x;
			point[(i * map->nums_in_line) + j].y = pos_y;
			point[(i * map->nums_in_line) + j].z *= 2;
			//point[(i * map->nums_in_line) + j].z = nums[i][j] * 2;
			//mlx_put_pixel(img, mlx_inst[(i * map->nums_in_line) + j].x, mlx_inst[(i * map->nums_in_line) + j].y, 0xFFFFF);
			j++;
		}
		i++;
	}
	return (point);
}

void	map_to_mlx(t_map *map, t_point *point) // int **nums)
{
	mlx_t	*obj;
	//t_point	*point;

	obj = mlx_init(2000, 2000, "FDF", 1);
	if (!obj)
		mlx_terminate(obj);
	mlx_image_t	*img = mlx_new_image(obj, 2000, 2000);
	point = fill_image(img, map, point); // nums);
	to_isometry(img, map, point);
	mlx_image_to_window(obj, img, 0, 0);
	mlx_loop(obj);
}
