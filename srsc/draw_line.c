/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:21:56 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/26 10:01:55 by msavelie         ###   ########.fr       */
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
		if (round(x) >= 1 && round(y) >= 1)
			mlx_put_pixel(img, round(x), round(y), gradient(isom[0].color, isom[1].color, isom->steps, step));
		x += dx;
		y += dy;
	}
}

void	draw_line_col(mlx_image_t *img, t_isom *isom, int nums_in_line)
{
	int		step;
	double	dx;
	double	dy;
	double	x;
	double	y;

	dx = isom[nums_in_line].x - isom[0].x;
	dy = isom[nums_in_line].y - isom[0].y;
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
		if ((round(x) >= 1 && round(y) >= 1) && (round(x) <= 1999 && round(y) <= 999))
			mlx_put_pixel(img, round(x), round(y), gradient(isom[0].color, isom[nums_in_line].color, isom->steps, step));
		x += dx;
		y += dy;
	}
}

