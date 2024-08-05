/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:01:51 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/05 10:59:31 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fill_image(mlx_image_t *img, t_map *map) //, int **nums)
{
	int	start_pos_x;
	int	start_pos_y;
	int	space;
	int	i;
	int	j;

	start_pos_x = 30;
	start_pos_y = 30;
	space = 5;
	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->nums_in_line)
		{
			if (i == 0 && j == 0)
				mlx_put_pixel(img, start_pos_x + i, start_pos_y + j, 255);
			else if (j > 0 && i == 0)
				mlx_put_pixel(img, start_pos_x + i, start_pos_y + j + space, 255);
			else if (j > 0 && i > 0)
				mlx_put_pixel(img, start_pos_x + i + space, start_pos_y + j + space, 255);
			else if (j == 0 && i > 0)
				mlx_put_pixel(img, start_pos_x + i + space, start_pos_y + j, 255);
			j++;
		}
		i++;
	}
}

void	map_to_mlx(t_map *map) //, int **nums)
{
	mlx_t	*obj;

	obj = mlx_init(1024, 1024, "FDF", 1);
	if (!obj)
		mlx_terminate(obj);

	mlx_image_t	*img = mlx_new_image(obj, 512, 512);
	fill_image(img, map); //, nums);
	//ft_memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	mlx_image_to_window(obj, img, 200, 200);
	mlx_loop(obj);
}
