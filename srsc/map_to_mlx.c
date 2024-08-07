/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:01:51 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/07 13:38:13 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	fill_image(mlx_image_t *img, t_map *map, int **nums)
{
	int	space;
	int	i;
	int	j;
	int	pos_x;
	int	pos_y;
	mlx_instance_t *mlx_inst;

	space = 20;
	i = 0;
	img->count = (size_t)(map->nums_in_line * map->lines);
	mlx_inst = malloc(sizeof(mlx_instance_t) * img->count);
	if (!mlx_inst)
	{
		ft_printf("ERROR!ERROR!ERROR!!!1\n");
		exit (1);
	}
	//*mlx_inst = NULL;
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
			mlx_inst[(i * map->nums_in_line) + j].x = pos_x;
			mlx_inst[(i * map->nums_in_line) + j].y = pos_y;
			mlx_set_instance_depth(&mlx_inst[(i * map->nums_in_line) + j], nums[i][j]);
			mlx_put_pixel(img, mlx_inst[(i * map->nums_in_line) + j].x, mlx_inst[(i * map->nums_in_line) + j].y, 0xFFFFF);
			/*ft_printf("mlx_inst[%d].x = %d\nmlx_inst[%d].y = %d\nmlx_inst[%d].z = %d\n\n", 
				i + j, mlx_inst[i + j].x, i + j, mlx_inst[i + j].y, i + j, mlx_inst[i + j].z);*/
			j++;
		}
		i++;
	}
	img->instances = mlx_inst;

	/*for (int i = 0; i < map->nums_in_line * map->lines; i++)
	{
		ft_printf("img->instances[%d].x = %d\nimg->instances[%d].y = %d\nimg->instances[%d].z = %d\n\n", \
			i, img->instances[i].x, i, img->instances[i].y, i, img->instances[i].z);
	}*/
}

void	map_to_mlx(t_map *map, int **nums)
{
	mlx_t	*obj;

	obj = mlx_init(1024, 1024, "FDF", 1);
	if (!obj)
		mlx_terminate(obj);
	mlx_image_t	*img = mlx_new_image(obj, 512, 512);
	fill_image(img, map, nums);
	draw_line(img, map);
	mlx_image_to_window(obj, img, 200, 200);
	mlx_loop(obj);
}
