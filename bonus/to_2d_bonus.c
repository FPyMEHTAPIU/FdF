/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_2d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:37:53 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/12 13:23:20 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

static void	to_isometry(size_t i, t_map *map)//, t_isom *isom)
{
	double	temp_x;

	temp_x = map->point[i].x;
	map->point[i].x = (temp_x - map->point[i].y) * \
		cos(0.523599);
	map->point[i].y = (temp_x + map->point[i].y) * \
		sin(0.523599) - map->point[i].z;
	//isom->x = map->point[i].x;
	//isom->y = map->point[i].y;
	/*isom->x = point->x - point->y;// + 550;
	isom->y = (point->x + point->y) / 2 - point->z; // + 150;*/
	//isom->color = map->point[i].color;
}

void	change_perspective(t_map *map)//, t_isom *isom)
{
	size_t	i;

	i = 0;
	if (map->persp == 'P')
	{
		while (i < map->img->count)
		{
			/*isom[i].x = map->point[i].x; // + 400;
			isom[i].y = map->point[i].y; // + 150;
			isom[i].color = map->point[i].color;*/
			i++;
		}
	}
	else
	{
		while (i < map->img->count)
		{
			to_isometry(i, map);//, &isom[i]);
			i++;
		}
	}
}

static bool	print_err(t_map *map, /*t_isom *isom,*/ int n)
{
	if (n == 0)
	{
		ft_printf("Error in creation t_isom!\n");
		free_ret(map, map->point);
		return (false);
	}
	/*if (isom)
		free(isom);*/
	return (true);
}

static void	draw_lines(t_map *map)//, t_isom *isom)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width - 1)
			draw_line_row(map, &map->point[y * map->width + x++]);
		y++;
	}
	y = 0;
	while (y < map->width)
	{
		x = 0;
		while (x < map->height - 1)
			draw_line_col(map, &map->point[y + map->width * x++],
				map->width);
		y++;
	}
}

bool	to_2d(t_map *map)
{
	/*t_isom	*isom;

	isom = malloc(sizeof(t_isom) * map->img->count);
	if (!isom)
		return (print_err(map, isom, 0));*/
	change_perspective(map);//, isom);
	draw_lines(map);//, isom);
	return (print_err(map, 1));
}
