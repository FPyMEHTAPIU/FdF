/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crop_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:58:05 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/23 14:21:03 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*This function calculates the position of the point in relation to window
0b0000 = INSIDE 
0b0001 = LEFT
0b0010 = RIGHT
0b0100 = BOTTOM
0b1000 = TOP */
static int	find_pos(int x, int y)
{
	int	pos;

	pos = 0;
	if (x < 0)
		pos |= 1;
	else if (x > WIN_WIDTH)
		pos |= 2;
	if (y < 0)
		pos |= 4;
	else if (y > WIN_HEIGHT)
		pos |= 8;
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
		x = *sides->x1 + (*sides->x2 - *sides->x1) * (0 - *sides->y1) / (*sides->y2 - *sides->y1);
		y = 0;
	}
	else if (out_pos & 2)
	{
		y = *sides->y1 + (*sides->y2 - *sides->y1) * (WIN_WIDTH - *sides->x1) / (*sides->x2 - *sides->x1);
		x = WIN_WIDTH;
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
