/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:09:21 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/18 10:49:10 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	int		fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	map = parse_map(fd);
	if (!map)
		return (free_ret(map, NULL));
	map->point = malloc(sizeof(t_point) * map->height * map->width);
	if (!map->point)
	{
		ft_free_strs(map->strs, map->alloc_lines - 1);
		return (free_ret(map, NULL));
	}
	map->point = convert_map(map, map->point);
	map_to_mlx(map);
	free_ret(map, map->point);
	return (0);
}
