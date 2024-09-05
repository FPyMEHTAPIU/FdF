/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:31:15 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/05 15:36:09 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	draw_back(mlx_image_t *image)
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (i < image->height)
	{
		j = 0;
		while (j < image->width)
		{
			mlx_put_pixel(image, j, i, 0x9003FCFF);
			j++;
		}
		i++;
	}
}

static void	put_fdf(mlx_t *obj)
{
	mlx_image_t	*img;
	int			start_point;

	start_point = 600;
	img = mlx_put_string(obj, "FFFFF DDDDD   FFFFF", 135, start_point);
	mlx_image_to_window(obj, img, 135, start_point);
	start_point += 10;
	img = mlx_put_string(obj, "F     D    D  F", 135, start_point);
	mlx_image_to_window(obj, img, 135, start_point);
	start_point += 10;
	img = mlx_put_string(obj, "F     D     D F", 135, start_point);
	mlx_image_to_window(obj, img, 135, start_point);
	start_point += 10;
	img = mlx_put_string(obj, "FFFF  D     D FFFF", 135, start_point);
	mlx_image_to_window(obj, img, 135, start_point);
	start_point += 10;
	img = mlx_put_string(obj, "F     D     D F", 135, start_point);
	mlx_image_to_window(obj, img, 135, start_point);
	start_point += 10;
	img = mlx_put_string(obj, "F     D    D  F", 135, start_point);
	mlx_image_to_window(obj, img, 135, start_point);
	start_point += 10;
	img = mlx_put_string(obj, "F     DDDDD   F", 135, start_point);
	mlx_image_to_window(obj, img, 135, start_point);
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

mlx_image_t	*draw_gui(mlx_t *obj)
{
	int			gui_width;
	int			gui_height;
	mlx_image_t	*image;

	gui_width = WIN_WIDTH / 4;
	gui_height = WIN_HEIGHT;
	image = mlx_new_image(obj, gui_width, gui_height);
	draw_back(image);
	return (image);
}
