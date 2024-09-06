/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:09:21 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/06 12:15:35 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	int		fd;
	t_point	*point;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	map = parse_map(fd);
	if (!map)
		return (free_ret(map, NULL));
	point = malloc(sizeof(t_point) * map->lines * map->nums_in_line);
	if (!point)
	{
		ft_free_strs(map->strs, map->alloc_lines - 1);
		return (free_ret(map, NULL));
	}
	point = convert_map(map, point);
	map_to_mlx(map, point);
	free_ret(map, point);
	return (0);
}
