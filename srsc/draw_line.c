/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:21:56 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/06 11:59:00 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_line(mlx_image_t *img, t_map *map)
{
	int	i;
	int	j;
	float	dx;
	float	dy;
	int	step;
	float	x;
	float	y;

	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->nums_in_line - 1)
		{
			dx = ft_abs(img->instances[(i * map->nums_in_line) + j + 1].x - img->instances[(i * map->nums_in_line) + j].x);
			step = dx;
			dx /= (float)step;
			x = (float)img->instances[(i * map->nums_in_line) + j].x;
			while (step--)
			{
				mlx_put_pixel(img, round(x), img->instances[(i * map->nums_in_line)].y, 0xFFFFFF);
				x += dx;
			}
			j++;
		}
		j = 0;
		while (j < map->lines - 1)
		{
			dy = ft_abs(img->instances[i + (j * map->nums_in_line) + 1].y - img->instances[i + (j * map->nums_in_line)].y);
			step = dy;
			dy /= (float)step;
			y = (float)img->instances[i + (j * map->nums_in_line)].y;
			while (step--)
			{
				mlx_put_pixel(img, img->instances[i].x, round(y), 0xFFFFFF);
				y += dy;
			}
			j++;
		}
		i++;
	}
	
}