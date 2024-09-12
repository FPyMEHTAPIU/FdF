/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:21:56 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/12 13:20:34 by msavelie         ###   ########.fr       */
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

void	draw_line_row(t_map *map, t_point *point) //, t_isom *isom)
{
	int		step;
	double	dx;
	double	dy;
	double	x;
	double	y;

	//dx = isom[1].x - isom[0].x;
	//dy = isom[1].y - isom[0].y;
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
			&& (round(x) <= 2000 && round(y) <= 1000))
			mlx_put_pixel(map->img, round(x), round(y),
				gradient(point[0].color, point[1].color, map->steps, step));
		x += dx;
		y += dy;
	}
}

void	draw_line_col(t_map *map, t_point *point,/*t_isom *isom,*/ int width)
{
	int		step;
	double	dx;
	double	dy;
	double	x;
	double	y;

	//dx = isom[nums_in_line].x - isom[0].x;
	//dy = isom[nums_in_line].y - isom[0].y;
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
			&& (round(x) <= 2000 && round(y) <= 1000))
			mlx_put_pixel(map->img, round(x), round(y),
				gradient(point[0].color, point[width].color,
					map->steps, step));
		x += dx;
		y += dy;
	}
}
