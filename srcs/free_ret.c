/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ret.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:11:30 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/23 11:20:02 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_arr(int **arr, int index)
{
	if (!arr)
		return ;
	while (index >= 0)
	{
		free(arr[index]);
		arr[index] = NULL;
		index--;
	}
	free(arr);
	arr = NULL;
}

void	free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->orig_point)
		free(map->orig_point);
	map->orig_point = NULL;
	if (map->alloc_lines > 0)
	{
		ft_free_strs(map->strs, map->alloc_lines - 1);
		*map->strs = NULL;
		map->strs = NULL;
	}
	free(map);
}

int	free_ret(t_map *map, t_point *point)
{
	if (point)
		free(point);
	free_map(map);
	return (1);
}

void	check_realloc(t_map *map, char *gnl_str)
{
	if (!map)
	{
		if (gnl_str)
			free(gnl_str);
		exit(1);
	}	
}
