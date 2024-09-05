/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ret.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:11:30 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/05 15:05:40 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
	/*if (map->strs && *map->strs && map->alloc_lines > 0)
		ft_free_strs(map->strs, map->alloc_lines - 1);*/
	free(map);
}

int	free_ret(t_map *map, t_point *point)
{
	if (point)
		free(point);
	free_map(map);
	return (1);
}

void	free_img(t_image *img)
{
	if (!img)
		return ;
	if (img->orig_point)
		free(img->orig_point);
	free(img);
}
