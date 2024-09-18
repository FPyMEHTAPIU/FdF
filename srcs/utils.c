/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:19:27 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/18 12:19:37 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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
