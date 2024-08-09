/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:21:56 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/09 12:35:04 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
	step++;
	isom->steps = step;
	while (step--)
	{
		mlx_put_pixel(img, round(x), round(y), gradient(isom[0].color, isom[1].color, isom->steps, step));
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
	step++;
	isom->steps = step;
	while (step--)
	{
		mlx_put_pixel(img, round(x), round(y), gradient(isom[0].color, isom[map->nums_in_line].color, isom->steps, step));
		x += dx;
		y += dy;
	}
}

