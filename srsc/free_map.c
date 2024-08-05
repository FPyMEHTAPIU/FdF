/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:11:30 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/05 15:19:41 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_map	*free_map(t_map *map)
{
	if (!map)
		return (NULL);
	if (map->alloc_lines > 0)
		// free strs
	free(map);
	return (NULL);
}
