/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:16:52 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/02 15:35:54 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static int	**create_num_arr(t_map *map)
{
	int	**arr;

	arr = (int **)malloc(sizeof(int *) * map->lines);
	if (!arr)
		return (NULL);
	*arr = NULL;
	return (arr);
}

static int *alloc_and_convert(char **strs, int num_count)
{
	int	*sub_arr;
	int	i;

	sub_arr = malloc(sizeof(int) * num_count);
	if (!sub_arr)
		return (NULL);
	i = 0;
	while (i < num_count)
	{
		sub_arr[i] = ft_atoi(strs[i]);
		i++;
	}
	return (sub_arr);
}

int	**convert_map(t_map *map)
{
	char	**strs;
	int		**arr;
	int		i;
	int		num_count;

	i = 0;
	arr = create_num_arr(map);
	strs = ft_split(map->strs[i], ' ');
	num_count = count_nums(strs);
	while (map->strs[i])
	{
		if (count_nums(strs) != num_count)
		{
			ft_free_strs(strs, count_nums(&strs[i]));
			free_arr(arr, i);
			exit (1);
		}
		arr[i] = alloc_and_convert(strs, num_count);
		ft_free_strs(strs, num_count);
		i++;
		if (map->strs[i])
			strs = ft_split(map->strs[i], ' ');
	}
	
	ft_free_strs(map->strs, map->lines);
	return (arr);
}
