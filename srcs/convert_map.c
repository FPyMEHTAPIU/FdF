/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:16:52 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/05 15:21:47 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	set_def_values(t_point *point)
{
	point->move_x = 0.0;
	point->move_y = 0.0;
	point->angle_x = 0.0;
	point->angle_y = 0.0;
}

static t_point	*alloc_and_convert(char **strs, int num_count, t_point *point)
{
	int		i;
	char	**num_color;

	i = 0;
	while (i < num_count)
	{
		if (ft_strchr(strs[i], ','))
		{
			num_color = ft_split(strs[i], ',');
			point->z = ft_atoi(num_color[0]);
			point->color = rgb_to_rgba(ft_atoi_base(num_color[1], UP_HEX_BASE));
			ft_free_strs(num_color, 2);
		}
		else
		{
			point->z = ft_atoi(strs[i]);
			point->color = set_color(point->z);
		}
		set_def_values(point);
		i++;
		point++;
	}
	return (point);
}

t_point	*convert_map(t_map *map, t_point *point)
{
	char	**strs;
	int		i;
	t_point	*temp;

	i = 0;
	temp = point;
	strs = ft_split(map->strs[i], ' ');
	while (map->strs[i])
	{
		if (count_nums(map->strs[i]) != map->nums_in_line)
		{
			ft_printf("Lines aren't equal!\n");
			ft_free_strs(strs, count_nums(map->strs[i]));
			free_ret(map, point);
			exit (1);
		}
		point = alloc_and_convert(strs, map->nums_in_line, point);
		ft_free_strs(strs, map->nums_in_line);
		i++;
		if (map->strs[i])
			strs = ft_split(map->strs[i], ' ');
	}
	ft_free_strs(map->strs, map->lines);
	return (temp);
}
