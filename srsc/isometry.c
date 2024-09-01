/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:37:53 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/01 19:14:00 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	to_isometry(t_point *point, t_isom *isom)
{
	
	isom->x = point->x - point->y + 400;
	isom->y = (point->x + point->y) / 2 - point->z + 150;
	isom->color = point->color;
}

/*static void	to_perspective(t_point *point, t_isom *isom)
{
	if (point->z != 0)
	{
		isom->x = point->x / point->z;
		isom->y = point->y / point->z;
	}
	else
	{
		isom->x = 0;
		isom->y = 0;
	}
}*/

t_isom	*to_2d(mlx_image_t *img, t_map *map, t_point *point)
{
	t_isom	*isom;
	int		i;
	int		j;

	isom = malloc(sizeof(t_isom) * img->count);
	if (!isom)
	{
		ft_printf("Error in creation t_isom!\n");
		return (NULL);
	}
	i = 0;
	while ((size_t)i < img->count)
	{
		to_isometry(&point[i], &isom[i]);
		i++;
	}
	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->nums_in_line - 1)
		{
			draw_line_row(img, &isom[i * map->nums_in_line + j]);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < map->nums_in_line)
	{
		j = 0;
		while (j < map->lines - 1)
		{
			draw_line_col(img, &isom[i + map->nums_in_line * j], map->nums_in_line);
			j++;
		}
		i++;
	}
	free(isom);
	return (NULL);
}
