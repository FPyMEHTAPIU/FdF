/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:21:56 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/07 20:45:08 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*static void	draw_row(mlx_image_t *img, t_map *map, int row)
{
	int		col;
	int		step;
	double	dx;
	double	x;
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
		dx /= (double)step--;
		x = (double)(img->instances[index].x) + dx;
		while (step--)
		{
			mlx_put_pixel(img, round(x), img->instances[index].y, 0xFFFFFF);
			x += dx;
		}
		col++;
	}
}

static void	draw_column(mlx_image_t *img, t_map *map, int col)
{
	int		row;
	int		step;
	double	dy;
	double	y;
	int		index;

	row = 0;
	while (row < map->lines - 1)
	{
		index = row * (map->nums_in_line) + col;
		if (index > (map->nums_in_line * map->lines) - 1)
		{
			ft_printf("FUCK YOU in column!\n");
			return ;
		}
		dy = ft_abs(img->instances[index + map->nums_in_line].y - img->instances[index].y);
		step = dy;
		dy /= (double)step--;
		y = (double)(img->instances[index].y) + dy;
		while (step--)
		{
			mlx_put_pixel(img, img->instances[index].x, round(y), 0xFFFFFFF);
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
}*/
// v2
void	draw_line_row(mlx_image_t *img, t_isom *isom)
{
	int		step;
	double	dx;
	double	dy;
	double	x;
	double	y;

	dx = isom[1].x - isom[0].x;
	dy = isom[1].y - isom[0].y;
	if (ft_abs(dx) >= ft_abs(dy))
		step = ft_abs(dx);
	else
		step = ft_abs(dy);
	dx /= (double)step;
	dy /= (double)step;
	x = isom[0].x;
	y = isom[0].y;
	//step++;
	while (step--)
	{
		mlx_put_pixel(img, round(x), round(y), 0xFFFFFFF);
		x += dx;
		y += dy;
	}
}

void	draw_line_col(mlx_image_t *img, t_isom *isom, t_map *map)
{
	int		step;
	double	dx;
	double	dy;
	double	x;
	double	y;

	dx = isom[map->nums_in_line].x - isom[0].x;
	dy = isom[map->nums_in_line].y - isom[0].y;
	if (ft_abs(dx) >= ft_abs(dy))
		step = ft_abs(dx);
	else
		step = ft_abs(dy);
	dx /= (double)step;
	dy /= (double)step;
	x = isom[0].x;
	y = isom[0].y;
	//step++;
	while (step--)
	{
		mlx_put_pixel(img, round(x), round(y), 0xFFFFFFF);
		x += dx;
		y += dy;
	}
}

