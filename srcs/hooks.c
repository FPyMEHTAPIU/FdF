/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:51:50 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/18 11:11:34 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	fdf_keys(void *obj)
{
	t_map	*map;

	map = (t_map *) obj;
	if (mlx_is_key_down(map->obj, MLX_KEY_ESCAPE))
		mlx_close_window(map->obj);
}
