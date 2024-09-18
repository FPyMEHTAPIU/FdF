/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:31:15 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/18 12:30:46 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

static void	draw_back(mlx_image_t *image)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			mlx_put_pixel(image, x, y, 0x9003FCFF);
			x++;
		}
		y++;
	}
}

static void	put_fdf(mlx_t *obj)
{
	mlx_image_t	*img;
	int			start_point;

	start_point = 800;
	img = mlx_put_string(obj, "FFFFF DDDDD   FFFFF", 140, start_point);
	mlx_image_to_window(obj, img, 140, start_point);
	start_point += 10;
	img = mlx_put_string(obj, "F     D    D  F", 140, start_point);
	mlx_image_to_window(obj, img, 140, start_point);
	start_point += 10;
	img = mlx_put_string(obj, "F     D     D F", 140, start_point);
	mlx_image_to_window(obj, img, 140, start_point);
	start_point += 10;
	img = mlx_put_string(obj, "FFFF  D     D FFFF", 140, start_point);
	mlx_image_to_window(obj, img, 140, start_point);
	start_point += 10;
	img = mlx_put_string(obj, "F     D     D F", 140, start_point);
	mlx_image_to_window(obj, img, 140, start_point);
	start_point += 10;
	img = mlx_put_string(obj, "F     D    D  F", 140, start_point);
	mlx_image_to_window(obj, img, 140, start_point);
	start_point += 10;
	img = mlx_put_string(obj, "F     DDDDD   F", 140, start_point);
	mlx_image_to_window(obj, img, 140, start_point);
}

void	draw_instructions(mlx_t *obj)
{
	int			line_gap;
	int			start_point;
	mlx_image_t	*img;

	start_point = 50;
	line_gap = 50;
	img = mlx_put_string(obj, "Instructions:", 25, start_point);
	mlx_image_to_window(obj, img, 25, start_point);
	start_point += line_gap;
	img = mlx_put_string(obj, "- Arrows to move", 25, start_point);
	mlx_image_to_window(obj, img, 25, start_point);
	start_point += line_gap;
	img = mlx_put_string(obj, "- '=', '-' and mouse wheel to zoom",
			25, start_point);
	mlx_image_to_window(obj, img, 25, start_point);
	start_point += line_gap;
	img = mlx_put_string(obj, "- Hold 'x' or 'c' and use <- or -> to rotate",
			25, start_point);
	mlx_image_to_window(obj, img, 25, start_point);
	start_point += line_gap;
	img = mlx_put_string(obj, "- Press 'P' or 'I' to change projection",
			25, start_point);
	mlx_image_to_window(obj, img, 25, start_point);
	put_fdf(obj);
}

void	draw_gui(t_map *map)
{
	mlx_image_t	*image;

	image = mlx_new_image(map->obj, WIN_WIDTH / 4, WIN_HEIGHT);
	draw_back(image);
	mlx_image_to_window(map->obj, image, 0, 0);
	draw_instructions(map->obj);
}
