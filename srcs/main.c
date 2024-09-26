/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:09:21 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/26 10:49:51 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	int		fd;

	if (argc != 2)
		return (0);
	if (!ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])))
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	map = parse_map(fd);
	if (!map || !*map->strs)
		return (free_ret(map, NULL));
	map->point = malloc(sizeof(t_point) * map->height * map->width);
	if (!map->point)
		return (free_ret(map, NULL));
	map->point = convert_map(map, map->point);
	map_to_mlx(map);
	free_ret(map, map->point);
	return (0);
}
