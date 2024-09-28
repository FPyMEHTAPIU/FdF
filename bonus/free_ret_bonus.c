/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ret_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:11:30 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/28 14:32:05 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

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
		ft_free_strs(map->strs, map->height);
		*map->strs = NULL;
		map->strs = NULL;
		map->alloc_lines = 0;
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

void	convert_error(t_map *map, char **strs, t_point *temp, char *trim_str)
{
	ft_printf("Lines aren't equal!\n");
	ft_free_strs(strs, count_nums(trim_str));
	if (trim_str)
		free(trim_str);
	free_ret(map, temp);
	exit (1);
}
