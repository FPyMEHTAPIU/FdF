/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:09:21 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/12 11:14:50 by msavelie         ###   ########.fr       */
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
		return (1);
	//ft_printf("size: %d\n", map->lines * map->nums_in_line);
	//point = malloc(sizeof(t_point) * map->lines * map->nums_in_line);
	ft_printf("size: %d\n", map->total_nums);
	point = malloc(sizeof(t_point) * map->total_nums);
	if (!point)
		return (1);
	point = convert_map(map, point);

	/*for (int i = 0; i < map->lines; i++)
	{
		ft_printf("nums line: ");
		for (int j = 0; j < map->nums_in_line; j++)
		{
			ft_printf("%d ", nums[i][j]);
		}
		ft_printf("\n");
	}*/
	//map_to_mlx(map, nums);
	map_to_mlx(map, point);
	free(point);
	free(map->nums_in_line);
	free(map);
	return (0);
}
