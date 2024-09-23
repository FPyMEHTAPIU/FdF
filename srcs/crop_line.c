/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crop_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:58:05 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/23 14:42:06 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*This function calculates the position of the point in relation to window
0b0000 = INSIDE 0
0b0001 = LEFT	1
0b0010 = RIGHT	2
0b0100 = BOTTOM	4
0b1000 = TOP	8 */
static int	find_pos(int x, int y)
{
	int	pos;

	pos = 0;
	if (x < 0)
		pos |= 1;
	else if (x > WIN_WIDTH)
		pos |= 1 << 1;
	if (y < 0)
		pos |= 1 << 2;
	else if (y > WIN_HEIGHT)
		pos |= 1 << 3;
	return (pos);
}

static t_sides	init_and_find(double *x1, double *x2, double *y1, double *y2)
{
	t_sides	sides;

	sides.x1 = x1;
	sides.x2 = x2;
	sides.y1 = y1;
	sides.y2 = y2;
	sides.start_pos = find_pos(*x1, *y1);
	sides.end_pos = find_pos(*x2, *y2);
	return (sides);
}

static void	recalculate_pos(t_sides *sides)
{
	double	x;
	double	y;
	int		out_pos;

	if (sides->end_pos > sides->start_pos)
		out_pos = sides->end_pos;
	else
		out_pos = sides->start_pos;
	if (out_pos & 8)
	{
		x = *sides->x1 + (*sides->x2 - *sides->x1) * (WIN_HEIGHT - *sides->y1) / (*sides->y2 - *sides->y1);
		y = WIN_HEIGHT;
	}
	else if (out_pos & 4)
	{
		x = *sides->x1 + (*sides->x2 - *sides->x1) * (WIN_WIDTH / 4 - *sides->y1) / (*sides->y2 - *sides->y1);
		y = WIN_WIDTH / 4;
	}
	else if (out_pos & 2)
	{
		y = *sides->y1 + (*sides->y2 - *sides->y1) * (WIN_WIDTH - (WIN_WIDTH / 4) - *sides->x1) / (*sides->x2 - *sides->x1);
		x = WIN_WIDTH - (WIN_WIDTH / 4);
	}
	else if (out_pos & 1)
	{
		y = *sides->y1 + (*sides->y2 - *sides->y1) * (0 - *sides->x1) / (*sides->x2 - *sides->x1);
		x = 0;
	}
	if (out_pos == sides->start_pos)
	{
		*sides->x1 = x;
		*sides->y1 = y;
		sides->start_pos = find_pos(x, y);
	}
	else if (out_pos == sides->end_pos)
	{
		*sides->x2 = x;
		*sides->y2 = y;
		sides->end_pos = find_pos(x, y);
	}
}

void	crop_line(double *x1, double *x2, double *y1, double *y2)
{
	t_sides	sides;

	sides = init_and_find(x1, x2, y1, y2);
	while (1)
	{
		if (!(sides.start_pos | sides.end_pos))
			break;
		else if (sides.start_pos & sides.end_pos)
			break;
		else
			recalculate_pos(&sides);
	}
}
