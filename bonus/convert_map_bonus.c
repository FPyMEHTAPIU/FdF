/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:16:52 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/26 15:52:19 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

static void	check_range(t_map *map, char **strs, t_point *temp, int i)
{
	if ((map->point->z == -1 && \
		ft_strncmp(strs[i], "-1", ft_strlen(strs[i])) != 0)
		|| (map->point->z == 0 && (/*(ft_strncmp(strs[i], "\n", 1) != 0)
		&& */ft_strncmp(strs[i], "0", 1) != 0)))
	{
		ft_printf("A number in the map is out of range!\n");
		ft_free_strs(strs, map->width);
		free_ret(map, temp);
		exit (1);
	}
}

static t_point	*alloc_and_convert(char **strs, int num_count,
	t_map *map, t_point *temp)
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
			map->point->color = \
				rgb_to_rgba(ft_atoi_base(num_color[1], UP_HEX_BASE));
			ft_free_strs(num_color, 2);
		}
		else
		{
			if (ft_strncmp(strs[i], "\n", 1) != 0)
			{
				map->point->z = ft_atoi(strs[i]);
				map->point->color = set_color(map->point->z);
			}
		}
		check_range(map, strs, temp, i);
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
	char	*trim_str;

	i = 0;
	temp = point;
	trim_str = ft_strtrim(map->strs[i], " \n");
	strs = split_and_check(trim_str, ' ', map);
	if (ft_strlen(map->strs[i]) != ft_strlen(trim_str))
		map->width--;
	while (map->strs[i])
	{
		if (count_nums(trim_str) != map->width)
		{
			ft_printf("Lines aren't equal!\n");
			ft_free_strs(strs, count_nums(trim_str));
			free_ret(map, temp);
			exit (1);
		}
		point = alloc_and_convert(strs, map->width, map, temp);
		if (trim_str)
			free(trim_str);
		ft_free_strs(strs, map->width);
		i++;
		trim_str = ft_strtrim(map->strs[i], " \n");
		if (map->strs[i])
			strs = split_and_check(trim_str, ' ', map);
	}
	ft_free_strs(map->strs, map->height);
	map->alloc_lines = 0;
	return (temp);
}
