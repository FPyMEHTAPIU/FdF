/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:31:15 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/20 11:21:28 by msavelie         ###   ########.fr       */
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

	img = mlx_put_string(obj, "FFFFF DDDDD   FFFFF", 145, 800);
	img = mlx_put_string(obj, "F     D    D  F", 145, 810);
	img = mlx_put_string(obj, "F     D     D F", 145, 820);
	img = mlx_put_string(obj, "FFFF  D     D FFFF", 145, 830);
	img = mlx_put_string(obj, "F     D     D F", 145, 840);
	img = mlx_put_string(obj, "F     D    D  F", 145, 850);
	img = mlx_put_string(obj, "F     DDDDD   F", 145, 860);
	mlx_image_to_window(obj, img, 145, 860);
}

void	draw_instructions(mlx_t *obj)
{
	mlx_image_t	*img;

	img = mlx_put_string(obj, "Instructions:", 25, 50);
	img = mlx_put_string(obj, "- Arrows to move", 25, 125);
	img = mlx_put_string(obj, "- '=', '-' or mouse wheel to zoom",
			25, 175);
	img = mlx_put_string(obj, "- Hold 'z', 'x' or 'c' and use <- or ->",
			25, 225);
	img = mlx_put_string(obj, "to rotate around 'z', 'x' or 'y' axies",
			25, 250);
	img = mlx_put_string(obj, "- Press 'T' to see the map in top-down view",
			25, 300);
	img = mlx_put_string(obj, "- Press 'R' to see the map in ride-side view",
			25, 325);
	img = mlx_put_string(obj, "- Press 'F' to see the map in front-side view",
			25, 350);
	img = mlx_put_string(obj, "- Press 'I' to return in isometric projection",
			25, 375);
	img = mlx_put_string(obj, "- Hold SPACE and press UP or DOWN arrows",
			25, 425);
	img = mlx_put_string(obj, "to change map height",
			25, 450);
	mlx_image_to_window(obj, img, 25, 450);
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
