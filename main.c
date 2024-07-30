/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:09:21 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/30 20:25:45 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	int		fd;

	if (argc != 2)
		return (0);
	ft_printf("Before open\n");
	ft_printf("argv[1] = %s\n", argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	ft_printf("After open fd = %d\n", fd);
	map = parse_map(fd);
	if (!map)
		return (1);
	map->lines = 1;
	
	return (0);
}
