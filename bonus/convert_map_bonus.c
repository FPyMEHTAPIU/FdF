/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:16:52 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/23 11:32:43 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

static t_point	*alloc_and_convert(char **strs, int num_count, t_map *map)
{
	int		i;
	char	**num_color;

	i = 0;
	while (i < num_count)
	{
		if (ft_strchr(strs[i], ','))
		{
			num_color = split_and_check(strs[i], ',', map);
			map->point->z = ft_atoi(num_color[0]);
			map->point->color = rgb_to_rgba(ft_atoi_base(num_color[1], UP_HEX_BASE));
			ft_free_strs(num_color, 2);
		}
		else
		{
			map->point->z = ft_atoi(strs[i]);
			map->point->color = set_color(map->point->z);
		}
		i++;
		(map->point)++;
	}
	return (map->point);
}

t_point	*convert_map(t_map *map, t_point *point)
{
	char	**strs;
	int		i;
	t_point	*temp;

	i = 0;
	temp = point;
	strs = split_and_check(map->strs[i], ' ', map);
	while (map->strs[i])
	{
		if (count_nums(map->strs[i]) != map->width)
		{
			ft_printf("Lines aren't equal!\n");
			ft_free_strs(strs, count_nums(map->strs[i]));
			ft_free_strs(map->strs, map->height);
			free_ret(map, temp);
			exit (1);
		}
		point = alloc_and_convert(strs, map->width, map);
		ft_free_strs(strs, map->width);
		i++;
		if (map->strs[i])
			strs = split_and_check(map->strs[i], ' ', map);
	}
	ft_free_strs(map->strs, map->height);
	return (temp);
}
