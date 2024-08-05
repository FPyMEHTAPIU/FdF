/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:57:18 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/05 15:19:49 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
	map->alloc_lines = MAP_LINES;
	map->lines = 0;
	return (map);
}

static t_map	*realloc_map(t_map *map)
{
	char	**strs;
	int		i;

	map->alloc_lines *= 2;
	strs = (char **)malloc(sizeof(char *) * map->alloc_lines);
	if (!strs)
		return (free_map(map));
	i = 0;
	while (i < map->lines)
	{
		strs[i] = map->strs[i];
		i++;
	}
	free(map->strs);
	map->strs = strs;
	return (map);
}

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
		ft_printf("map line: %s", map->strs[i]);
		i++;
		map->lines++;
		temp = get_next_line(fd);
	}
	map->strs[i] = NULL;
	
	if (check_map(map))
		return (free_map(map));
	return (map);
}
