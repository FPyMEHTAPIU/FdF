/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:21:56 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/06 16:04:56 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	draw_row(mlx_image_t *img, t_map *map, int row)
{
	int		col;
	int		step;
	float	dx;
	float	x;
	int		index;

	col = 0;
	while (col < map->nums_in_line - 1)
	{
		index = row + col;
		if (index > (map->nums_in_line * map->lines) - 1)
		{
			ft_printf("FUCK YOU in row!\n");
			return ;
		}
		dx = ft_abs(img->instances[index + 1].x - img->instances[index].x);
		step = dx;
		dx /= (float)step;
		x = (float)(img->instances[index].x);
		while (step--)
		{
			mlx_put_pixel(img, round(x), img->instances[col].y, 0xFFFFFF);
			x += dx;
		}
		col++;
	}
}

static void	draw_column(mlx_image_t *img, t_map *map, int col)
{
	int		row;
	int		step;
	float	dy;
	float	y;
	int		index;

	row = 0;
	while (row < map->lines - 1)
	{
		index = row * map->nums_in_line + col;
		if (index > (map->nums_in_line * map->lines) - 1)
		{
			ft_printf("FUCK YOU in column!\n");
			return ;
		}
		dy = ft_abs(img->instances[index + map->nums_in_line].y - img->instances[index].y);
		step = dy;
		dy /= (float)step;
		y = (float)(img->instances[index].y);
		while (step--)
		{
			mlx_put_pixel(img, img->instances[row].x, round(y), 0xFFFFFFF);
			y += dy;
		}
		row++;
	}
}

void	draw_line(mlx_image_t *img, t_map *map)
{
	int	row;
	int col;

	row = 0;
	while (row < map->lines)
	{
		draw_row(img, map, row * map->nums_in_line);
		row++;
	}
	col = 0;
	while (col < map->nums_in_line)
	{
		draw_column(img, map, col);
		col++;
	}
}