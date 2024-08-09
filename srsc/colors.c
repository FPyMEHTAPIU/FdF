/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:26:29 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/09 12:36:13 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*static t_color	init_color(int start_col, int end_col) //, mlx_image_t *img)
{
	t_color	color;

	color.start_col = start_col;
	color.end_col = end_col;
	color.a_start = start_col >> 24;
	color.r_start = start_col >> 16;
	color.g_start = start_col >> 8;
	color.b_start = start_col >> 0;
	color.a_end = start_col >> 24;
	color.r_end = start_col >> 16;
	color.g_end = start_col >> 8;
	color.b_end = start_col >> 0;
	return (color);
}

void	set_default_colors(t_color *color)
{
	*color = init_color(0xFFFFFFFF, 0xFFA020F0);
}

uint32_t	gradient(int fst_color, int lst_color, mlx_image_t *img, int step)
{
	t_color		color;
	float	step_a;
	float	step_r;
	float	step_g;
	float	step_b;

	if (step == 0)
		return (lst_color);
	color = init_color(fst_color, lst_color); //, img);
	step_a = (float)(color.a_end - color.a_start) / step;
	step_r = (float)(color.r_end - color.r_start) / step;
	step_g = (float)(color.g_end - color.g_start) / step;
	step_b = (float)(color.b_end - color.b_start) / step;
	color.cur_color = 0 |
		((uint8_t)(color.a_start + step_a) & 0xFF) << 24 |
		((uint8_t)(color.a_start + step_r) & 0xFF) << 16 |
		((uint8_t)(color.a_start + step_g) & 0xFF) << 8 |
		((uint8_t)(color.a_start + step_b) & 0xFF) << 0;
	return (color.cur_color);
}*/

static t_color	init_color(int start_col, int end_col)
{
	t_color	color;

	color.start_col = start_col;
	color.end_col = end_col;
	color.a_start = (start_col >> 24) & 0xFF;
	color.r_start = (start_col >> 16) & 0xFF;
	color.g_start = (start_col >> 8) & 0xFF;
	color.b_start = start_col & 0xFF;
	color.a_end = (end_col >> 24) & 0xFF;
	color.r_end = (end_col >> 16) & 0xFF;
	color.g_end = (end_col >> 8) & 0xFF;
	color.b_end = end_col & 0xFF;
	return (color);
}

uint32_t	gradient(int fst_color, int lst_color, int steps, int cur_step)
{
	t_color	color;
	float	step_a;
	float	step_r;
	float	step_g;
	float	step_b;

	color = init_color(fst_color, lst_color);

	// Вычисление шагов изменения цвета
	step_a = (color.a_end - color.a_start) / (float)steps;
	step_r = (color.r_end - color.r_start) / (float)steps;
	step_g = (color.g_end - color.g_start) / (float)steps;
	step_b = (color.b_end - color.b_start) / (float)steps;

	// Рассчитываем текущий цвет
	color.cur_color = 0 |
		(((uint8_t)(color.a_start + (steps - cur_step) * step_a) & 0xFF) << 24) |
		(((uint8_t)(color.r_start + (steps - cur_step) * step_r) & 0xFF) << 16) |
		(((uint8_t)(color.g_start + (steps - cur_step) * step_g) & 0xFF) << 8) |
		(((uint8_t)(color.b_start + (steps - cur_step) * step_b) & 0xFF) << 0);

	return (color.cur_color);
}

