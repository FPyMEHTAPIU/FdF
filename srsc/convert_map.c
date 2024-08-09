/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:16:52 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/09 16:25:53 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	count_nums(char **strs)
{
	int	i;

	if (!strs || !(*strs))
		return (-1);
	i = 0;
	while (strs[i])
		i++;
	return (i);
}

// static char	*choose_base(char *color)
// {
// 	int	i;

// 	i = 'a';
// 	while (i <= 'z')
// 	{
// 		if (ft_strchr(color, i))
// 			return (LOW_HEX_BASE);
// 		i++;
// 	}
// 	return (UP_HEX_BASE);
// }

static t_point *alloc_and_convert(char **strs, int num_count, t_point *point)
{
	//int	*sub_arr;
	int	i;
	char	**num_color;

	i = 0;
	while (i < num_count)
	{
		if (ft_strchr(strs[i], ','))
		{
			num_color = ft_split(strs[i], ',');
			point->z = ft_atoi(num_color[0]);
			point->color = rgb_to_agbr(ft_atoi_base(num_color[1], UP_HEX_BASE));
			ft_free_strs(num_color, 2);
		}
		else
		{
			point->z = ft_atoi(strs[i]);
			if (point->z == 0)
				point->color = 0xFFFFFFFF;
			else if (point->z > 0)
				point->color = 0xFF20F0A0;
			else
				point->color = 0xFFFF00DD;
				//point->color = 0xFFA020F0;
		}
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
		if (count_nums(strs) != map->nums_in_line)
		{
			ft_free_strs(strs, count_nums(&strs[i]));
			//free_arr(arr, i);
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
