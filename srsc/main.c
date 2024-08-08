/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:09:21 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/08 14:33:23 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	int		**nums;
	int		fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	map = parse_map(fd);
	if (!map)
		return (1);
	nums = convert_map(map);

	for (int i = 0; i < map->lines; i++)
	{
		ft_printf("nums line: ");
		for (int j = 0; j < map->nums_in_line; j++)
		{
			ft_printf("%d ", nums[i][j]);
		}
		ft_printf("\n");
	}
	map_to_mlx(map, nums);
	return (0);
}
