/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:37:53 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/07 17:25:43 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	to_2d(mlx_instance_t *instance, t_isom *isom)
{
	isom->x = instance->x - instance->y;
	isom->y = (instance->x + instance->y) / 2 - instance->z;
}

t_isom	*to_isometry(mlx_image_t *img)
{
	t_isom	*isom;
	size_t	i;

	isom = malloc(sizeof(t_isom) * img->count);
	if (!isom)
	{
		ft_printf("FUCK YOU in creation t_isom!\n");
		return (NULL);
	}
	i = 0;
	while (i < img->count)
	{
		to_2d(&img->instances[i], &isom[i]);
		i++;
	}
	i = 0;
	while (i < img->count - 1)
	{
		draw_line(img, isom);
		i++;
	}
	return (isom);
}
