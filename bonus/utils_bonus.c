/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:22:53 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/28 16:57:28 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

int	count_nums(char *map_str)
{
	int		i;
	char	**strs;

	if (!map_str)
		return (-1);
	strs = ft_split(map_str, ' ');
	if (!strs || !(*strs))
		return (-1);
	i = 0;
	while (strs[i])
		i++;
	ft_free_strs(strs, i - 1);
	return (i);
}

char	**split_and_check(char *str, char del, t_map *map)
{
	char	**strs;

	strs = ft_split(str, del);
	if (!strs || !*strs)
	{
		ft_putstr_fd("Split error!\n", 1);
		free_ret(map, map->point);
		exit (1);
	}
	return (strs);
}
