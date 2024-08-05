/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:21:56 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/05 15:37:15 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_line(mlx_image_t *img, t_map *map)
{
	int	i;
	int	j;
	int	dx;
	int	dy;
	int	step;
	int	x;
	int	y;

	i = 0;
	while (i < map->lines - 1)
	{
		j = 0;
		while (j < map->nums_in_line - 1)
		{
			dx = ft_abs(img->instances[i + j].x - img->instances[i + j + 1].x);
			dy = ft_abs(img->instances[i + j].y - img->instances[i + j + 1].y);
			if(dx >= dy)
				step = dx;
			else
				step = dy;
			dx = dx/step;
			dy = dy/step;
			
			x = img->instances[i + j].x;
			y = img->instances[i + j].y;
			while (step--)
			{
				mlx_put_pixel(img, x, y, 0xFFFFF);
				x += dx;
				y += dy;
			}
			j++;
		}
		i++;
	}
}