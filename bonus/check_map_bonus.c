/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:41:04 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/28 16:55:52 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

static int	compare_base(char c)
{
	char	*upcase;
	char	*lowcase;
	int		i;
	int		base_len;
	int		match;

	upcase = UP_HEX_BASE;
	lowcase = LOW_HEX_BASE;
	base_len = ft_strlen(upcase);
	match = 0;
	i = 0;
	while (i < base_len)
	{
		if (c == upcase[i] || c == lowcase[i] || c == 'x')
			match++;
		i++;
	}
	if (match == 0)
		return (1);
	return (0);
}

static int	check_color(char **strs, int lines, int *i)
{
	int		j;

	j = 0;
	if (strs[lines][*i] != ',')
		return (0);
	(*i)++;
	while (j < HEX_LEN && strs[lines][*i] != ' ' && strs[lines][*i] != '\n')
	{
		if (compare_base(strs[lines][*i]))
			return (1);
		(*i)++;
	}
	return (0);
}

static int	check_chars(t_map *map)
{
	int	i;
	int	lines;
	int	line_len;

	lines = 0;
	while (lines < map->height)
	{
		line_len = ft_strlen(map->strs[lines]);
		i = 0;
		while (i < line_len)
		{
			if (map->strs[lines][i] == '-')
				if (!ft_isdigit(map->strs[lines][i + 1]))
					return (1);
			if (check_color(map->strs, lines, &i))
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
	if (check_chars(map))
	{
		ft_putstr_fd("The map is not properly formatted\n", 1);
		return (1);
	}
	return (0);
}
