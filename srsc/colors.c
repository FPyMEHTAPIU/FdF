/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:26:29 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/08 14:42:28 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static t_color	init_color(unsigned int	start_col, unsigned int end_col, mlx_image_t *img)
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
	color->a_start = 0xFFFFFFFF;
	color->a_end = 0xFFA020F0;
}

void	gradient(uint32_t fst_color, uint32_t lst_color, mlx_image_t *img, uint32_t step)
{
	t_color	color;
	uint32_t	step_a;
	uint32_t	step_r;
	uint32_t	step_g;
	uint32_t	step_b;

	color = init_color(fst_color, lst_color, img);
	step_a = (color.a_end - color.a_start) / step;
	step_r = (color.r_end - color.r_start) / step;
	step_g = (color.g_end - color.g_start) / step;
	step_b = (color.b_end - color.b_start) / step;
	color.cur_color = 0 |
		((color.a_start + step_a) & 0xFF) << 24 |
		((color.a_start + step_r) & 0xFF) << 16 |
		((color.a_start + step_g) & 0xFF) << 8 |
		((color.a_start + step_b) & 0xFF) << 0;
	return (color.cur_color);
}
