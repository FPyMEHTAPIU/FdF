/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:26:29 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/13 10:09:41 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

uint32_t	set_pos_color(int num)
{
	uint32_t	color;

	if (num > 0 && num <= 5)
		color = 0x15FF00FF;
	else if (num > 5 && num <= 10)
		color = 0x00FF00FF;
	else if (num > 10 && num <= 15)
		color = 0x00D9FFFF;
	else if (num > 15 && num <= 30)
		color = 0x2B00FFFF;
	else if (num > 30 && num <= 50)
		color = 0xD900FFFF;
	else if (num > 50)
		color = 0xFF00EAFF;
	return (color);
}

uint32_t	set_neg_color(int num)
{
	uint32_t	color;

	if (num < 0 && num >= -5)
		color = 0xDDFF00FF;
	else if (num < -5 && num >= -10)
		color = 0xFFC800FF;
	else if (num < -10 && num >= -15)
		color = 0xFF9100FF;
	else if (num < -15 && num >= -30)
		color = 0xFF5100FF;
	else if (num < -30 && num >= -50)
		color = 0xFF0400FF;
	else if (num < -50)
		color = 0xFF0000FF;
	return (color);
}

uint32_t	set_color(int num)
{
	uint32_t	color;

	if (num == 0)
		color = 0xFFFFFFFF;
	else if (num > 0)
		color = set_pos_color(num);
	else
		color = set_neg_color(num);
	return (color);
}


uint32_t rgb_to_rgba(uint32_t color)
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint32_t	rgba;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	rgba = r | (g << 16) | (b << 8) | (0xFF << 24);
    return (rgba);
}

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

	step_a = (color.a_end - color.a_start) / (float)steps;
	step_r = (color.r_end - color.r_start) / (float)steps;
	step_g = (color.g_end - color.g_start) / (float)steps;
	step_b = (color.b_end - color.b_start) / (float)steps;

	color.cur_color = 0 |
		(((uint8_t)(color.a_start + (steps - cur_step) * step_a) & 0xFF) << 24) |
		(((uint8_t)(color.r_start + (steps - cur_step) * step_r) & 0xFF) << 16) |
		(((uint8_t)(color.g_start + (steps - cur_step) * step_g) & 0xFF) << 8) |
		(((uint8_t)(color.b_start + (steps - cur_step) * step_b) & 0xFF) << 0);

	return (color.cur_color);
}

