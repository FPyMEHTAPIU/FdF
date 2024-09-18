/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:57:18 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/18 12:23:14 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

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
	map->height = 0;
	return (map);
}

static t_map	*realloc_map(t_map *map)
{
	char	**strs;
	int		i;

	map->alloc_lines *= 2;
	strs = (char **)malloc(sizeof(char *) * map->alloc_lines);
	if (!strs)
	{
		free_map(map);
		return (NULL);
	}
	i = 0;
	while (i < map->height)
	{
		strs[i] = map->strs[i];
		i++;
	}
	free(map->strs);
	map->strs = strs;
	return (map);
}

static t_map	*check_ret(t_map *map, int i)
{
	if (check_map(map))
	{
		ft_free_strs(map->strs, --i);
		free_ret(map, NULL);
		return (NULL);
	}
	return (map);
}

void	init_map(t_map *map)
{
	map->space_incr = 0.0;
	map->point = NULL;
	map->orig_point = NULL;
	map->obj = NULL;
	map->img = NULL;
	map->angle_x = 0.0;
	map->angle_y = 0.0;
	map->angle_z = 0.0;
	map->zoom = 1.0;
	map->move_x = 0.0;
	map->move_y = 0.0;
	map->persp = 'I';
	map->axis = 'z';
	map->side = 't';
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
	map->width = count_nums(temp);
	while (temp)
	{
		if (map->alloc_lines == map->height)
			map = realloc_map(map);
		map->strs[i] = temp;
		i++;
		map->height++;
		temp = get_next_line(fd);
	}
	map->strs[i] = NULL;
	init_map(map);
	return (check_ret(map, i));
}
