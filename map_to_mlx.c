/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:01:51 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/02 15:38:54 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_to_mlx(void)//t_map *map)
{
	mlx_t	*obj;

	obj = mlx_init(768, 768, "FDF", 1);
	if (!obj)
		mlx_terminate(obj);

	mlx_image_t	*img = mlx_new_image(obj, 256, 256);
	ft_memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	mlx_image_to_window(obj, img, 0, 0);
	mlx_loop(obj);
}