/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:21:56 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/13 12:36:19 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

static int	set_step(double dx, double dy)
{
	if (ft_abs(dx) >= ft_abs(dy))
		return (ft_abs(dx));
	else
		return (ft_abs(dy));
}

void	draw_line_row(t_map *map, t_point *point)
{
	int		step;
	double	dx;
	double	dy;
	double	x;
	double	y;

	dx = point[1].x - point[0].x;
	dy = point[1].y - point[0].y;
	step = set_step(dx, dy);
	dx /= (double)step;
	dy /= (double)step;
	x = point[0].x;
	y = point[0].y;
	step++;
	map->steps = step;
	while (step--)
	{
		if ((round(x) >= 0 && round(y) >= 0)
			&& (round(x) < map->img->width && round(y) < map->img->height))
			mlx_put_pixel(map->img, round(x), round(y),
				gradient(point[0].color, point[1].color, map->steps, step));
		x += dx;
		y += dy;
	}
}

void	draw_line_col(t_map *map, t_point *point, int width)
{
	int		step;
	double	dx;
	double	dy;
	double	x;
	double	y;

	dx = point[width].x - point[0].x;
	dy = point[width].y - point[0].y;
	step = set_step(dx, dy);
	dx /= (double)step;
	dy /= (double)step;
	x = point[0].x;
	y = point[0].y;
	step++;
	map->steps = step;
	while (step--)
	{
		if ((round(x) >= 0 && round(y) >= 0)
			&& (round(x) < map->img->width && round(y) < map->img->height))
			mlx_put_pixel(map->img, round(x), round(y),
				gradient(point[0].color, point[width].color,
					map->steps, step));
		x += dx;
		y += dy;
	}
}
