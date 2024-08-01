/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:41:04 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/01 14:28:50 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_doubles(t_map *map)
{
	int	i;
	int	lines;
	int	line_len;

	lines = 0;
	while (lines < map->lines)
	{
		i = 0;
		line_len = ft_strlen(map->strs[lines]);
		while (i < line_len)
		{
			if (map->strs[lines][i] == ' ')
			{
				if ((map->strs[lines][i + 1] >= 9 
					&& map->strs[lines][i + 1] <= 13))
					return (1);
			}
			i++;
		}
		lines++;
	}
	return (0);
}

static int	check_chars(t_map *map)
{
	int	i;
	int	lines;
	int	line_len;

	lines = 0;
	while (lines < map->lines)
	{
		line_len = ft_strlen(map->strs[lines]);
		i = 0;
		while (i < line_len)
		{
			if (map->strs[lines][i] == '-')
				if (!ft_isdigit(map->strs[lines][i + 1]))
					return (1);
			if (!ft_isdigit(map->strs[lines][i]) && map->strs[lines][i] != '-' 
				&& map->strs[lines][i] != ' ' && map->strs[lines][i] != '\n')
				return (1);
			i++;
		}
		lines++;
	}
	return (0);
}

int	check_map(t_map *map)
{
	// TODO
		// check double spaces or tabs
	if (check_doubles(map))
		return (1);
	ft_printf("Problem isn't after check_doubles\n");
		// check invalid chars (letters, signs (except of '+' and '-'))
	if (check_chars(map))
		return (1);
	ft_printf("Problem isn't after check_chars\n");
	return (0);	
}