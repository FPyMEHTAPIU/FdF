/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:37:53 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/12 11:10:55 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	to_2d(t_point *point, t_isom *isom)
{
	isom->x = point->x - point->y + 2000;
	isom->y = (point->x + point->y) / 2 - point->z + 500;
	isom->color = point->color;
}

t_isom	*to_isometry(mlx_image_t *img, t_map *map, t_point *point)
{
	t_isom	*isom;
	int		i;
	int		j;

	isom = malloc(sizeof(t_isom) * img->count);
	if (!isom)
	{
		ft_printf("FUCK YOU in creation t_isom!\n");
		return (NULL);
	}
	i = 0;
	while ((size_t)i < img->count)
	{
		to_2d(&point[i], &isom[i]);
		i++;
	}
	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->nums_in_line[i] - 1)
		{
			draw_line_row(img, &isom[i * map->nums_in_line[i] + j]);
			j++;
		}
		i++;
	}
	
	int k = 0;
	while (k < map->lines - 1)
	{
		i = 0;
		while (i < map->nums_in_line[k])
		{
			j = 0;
			while (j < map->lines - 1)
			{
				draw_line_col(img, &isom[i + map->nums_in_line[k] * j], map->nums_in_line[k]);
				j++;
			}
			i++;
		}
		k++;
	}
	free(isom);
	return (NULL);
}
