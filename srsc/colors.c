/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:26:29 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/08 17:32:48 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static t_color	init_color(int	start_col, int end_col, mlx_image_t *img)
{
	t_color	color;

	color.start_col = start_col;
	color.end_col = end_col;
	//color.a_start = start_col >> 24;
	color.r_start = start_col >> 16;
	color.g_start = start_col >> 8;
	color.b_start = start_col >> 0;
	//color.a_end = start_col >> 24;
	color.r_end = start_col >> 16;
	color.g_end = start_col >> 8;
	color.b_end = start_col >> 0;
	return (color);
}

void	set_default_colors(t_color *color, mlx_image_t *img)
{
	*color = init_color(0xFFFFFF, 0xA020F0, img);
}

int	gradient(int fst_color, int lst_color, mlx_image_t *img, int step)
{
	t_color	color;
	//int	step_a;
	int	step_r;
	int	step_g;
	int	step_b;

	color = init_color(fst_color, lst_color, img);
	//step_a = (color.a_end - color.a_start) / step;
	step_r = (color.r_end - color.r_start) / step;
	step_g = (color.g_end - color.g_start) / step;
	step_b = (color.b_end - color.b_start) / step;
	color.cur_color = 0 |
		/*((color.a_start + step_a) & 255) << 24 |*/
		((color.a_start + step_r) & 255) << 16 |
		((color.a_start + step_g) & 255) << 8 |
		((color.a_start + step_b) & 255) << 0;
	return (color.cur_color);
}
