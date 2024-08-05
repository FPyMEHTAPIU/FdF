/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:01:51 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/05 14:12:25 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	//mlx_inst = (mlx_instance_t **)malloc(sizeof(mlx_instance_t *) * map->lines * map->nums_in_line);
	mlx_inst = malloc(sizeof(mlx_instance_t) * map->lines * map->nums_in_line);
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
			/**mlx_inst = malloc(sizeof(mlx_instance_t));
			if (!(*mlx_inst))
				exit (1);
			(*mlx_inst)->x = pos_x;
			(*mlx_inst)->y = pos_y;
			//(*mlx_inst)->z = nums[i][j];
			mlx_set_instance_depth(*mlx_inst, nums[i][j]);*/
			mlx_inst[i + j].x = pos_x;
			mlx_inst[i + j].y = pos_y;
			mlx_set_instance_depth(mlx_inst, nums[i][j]);
			//mlx_put_pixel(img, start_pos_x + pos_x, start_pos_y + pos_y, 0xFFFFF);
			mlx_put_pixel(img, mlx_inst[i + j].x, mlx_inst[i + j].y, 0xFFFFF);
			//mlx_inst++;
			j++;
		}
		i++;
	}
	img->instances = mlx_inst;
}

void	map_to_mlx(t_map *map, int **nums)
{
	mlx_t	*obj;

	obj = mlx_init(1024, 1024, "FDF", 1);
	if (!obj)
		mlx_terminate(obj);

	mlx_image_t	*img = mlx_new_image(obj, 512, 512);
	fill_image(img, map, nums);
	//ft_memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	mlx_image_to_window(obj, img, 200, 200);
	mlx_loop(obj);
}
