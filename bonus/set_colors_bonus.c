/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:09:35 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/10 11:11:29 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

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
	else
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
	else
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
