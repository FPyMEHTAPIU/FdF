/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:57:18 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/12 11:15:56 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	count_nums(char *map_str)
{
	int		i;
	char	**strs;

	if (!map_str)
		return (-1);
	strs = ft_split(map_str, ' ');
	if (!strs || !(*strs))
		return (-1);
	i = 0;
	while (strs[i])
		i++;
	ft_free_strs(strs, i - 1);
	return (i);
}

static t_map	*create_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->strs = (char **)malloc(sizeof(char *) * MAP_LINES);
	if (!map->strs)
	{
		free(map);
		return (NULL);
	}
	map->nums_in_line = malloc(sizeof(int) * MAP_LINES);
	if (!map->nums_in_line)
	{
		free(map);
		return (NULL);
	}
	map->alloc_lines = MAP_LINES;
	map->lines = 0;
	map->total_nums = 0;
	return (map);
}

static t_map	*realloc_map(t_map *map)
{
	char	**strs;
	int		*num_arr;
	int		i;

	map->alloc_lines *= 2;
	strs = (char **)malloc(sizeof(char *) * map->alloc_lines);
	num_arr = malloc(sizeof(int) * map->alloc_lines);
	if (!strs || !num_arr)
		return (free_map(map));
	i = 0;
	while (i < map->lines)
	{
		strs[i] = map->strs[i];
		num_arr[i] = map->nums_in_line[i];
		i++;
	}
	free(map->strs);
	free(map->nums_in_line);
	map->strs = strs;
	map->nums_in_line = num_arr;
	return (map);
}
/*static int	total_nums(t_map *map)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (map->strs[i])
		total += map->nums_in_line[i++];
	return (total);
}*/

t_map	*parse_map(int fd)
{
	t_map	*map;
	char	*temp;
	int		i;

	map = create_map();
	if (!map)
		return (NULL);
	i = 0;
	temp = get_next_line(fd);
	while (temp)
	{
		if (map->alloc_lines == map->lines)
			map = realloc_map(map);
		map->strs[i] = temp;
		map->nums_in_line[i] = count_nums(temp);
		map->total_nums += map->nums_in_line[i];
		//ft_printf("map line: %s", map->strs[i]);
		i++;
		map->lines++;
		temp = get_next_line(fd);
	}
	map->strs[i] = NULL;
	//map->nums_in_line = count_nums(map->strs[0]);
	/*if (check_map(map))
		return (free_map(map));*/
	return (map);
}
