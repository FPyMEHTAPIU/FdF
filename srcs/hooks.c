/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:51:50 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/10 11:09:56 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	fdf_keys(void *obj)
{
	t_image	*img;

	img = (t_image *) obj;
	if (mlx_is_key_down(img->obj, MLX_KEY_ESCAPE))
		mlx_close_window(img->obj);
}
