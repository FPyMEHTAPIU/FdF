/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ret.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:11:30 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/10 11:09:58 by msavelie         ###   ########.fr       */
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
	free(img);
}
