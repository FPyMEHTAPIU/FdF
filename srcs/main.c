/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:09:21 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/28 16:49:26 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
	1 - Incorrect number of args
	2 - Opening file has failed
	3 - Reading map error
	4 - Point allocation fail
*/
static void	print_err(int type)
{
	if (type == 1)
		ft_putstr_fd("Incorrect number of arguments! \
Provide only one \".fdf\" argument!\n", 1);
	else if (type == 2)
		ft_putstr_fd("Incorrect file extension! \
Provide a file with \".fdf\" extension!\n", 1);
	else if (type == 3)
		ft_putstr_fd("Opening file has failed\n", 1);
	else if (type == 4)
		ft_putstr_fd("Reading map error\n", 1);
	else if (type == 5)
		ft_putstr_fd("Point allocation fail\n", 1);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	int		fd;

	if (argc != 2)
		return (print_err(1), 1);
	if (!ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])))
		return (print_err(2), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (print_err(3), 1);
	map = parse_map(fd);
	if (!map || !*map->strs)
		return (print_err(4), free_ret(map, NULL));
	map->point = malloc(sizeof(t_point) * map->height * map->width);
	if (!map->point)
		return (print_err(5), free_ret(map, NULL));
	map->point = convert_map(map, map->point);
	map_to_mlx(map);
	free_ret(map, map->point);
	return (0);
}
