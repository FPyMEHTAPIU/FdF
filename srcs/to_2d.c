/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:37:53 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/10 11:09:42 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	to_isometry(t_point *point, t_isom *isom)
{
	isom->x = point->x - point->y + 800;
	isom->y = (point->x + point->y) / 2 - point->z + 150;
	isom->color = point->color;
}

static bool	print_err(t_map *map, t_point *point, t_isom *isom, int n)
{
	if (n == 0)
	{
		ft_printf("Error in creation t_isom!\n");
		free_ret(map, point);
		return (false);
	}
	else
	{
		if (isom)
			free(isom);
		return (true);
	}
}

static void	draw_lines(mlx_image_t *img, t_map *map, t_isom *isom)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->nums_in_line - 1)
			draw_line_row(img, &isom[i * map->nums_in_line + j++]);
		i++;
	}
	i = 0;
	while (i < map->nums_in_line)
	{
		j = 0;
		while (j < map->lines - 1)
			draw_line_col(img, &isom[i + map->nums_in_line * j++],
				map->nums_in_line);
		i++;
	}
}

bool	to_2d(mlx_image_t *img, t_map *map, t_point *point)
{
	t_isom	*isom;
	size_t	i;

	isom = malloc(sizeof(t_isom) * img->count);
	if (!isom)
		return (print_err(map, point, isom, 0));
	i = 0;
	while (i < img->count)
	{
		to_isometry(&point[i], &isom[i]);
		i++;
	}
	draw_lines(img, map, isom);
	return (print_err(map, point, isom, 1));
}
