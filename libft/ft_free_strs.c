/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:39:56 by msavelie          #+#    #+#             */
/*   Updated: 2024/09/05 15:47:51 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free_strs(char **strs, int index)
{
	if (!strs)
		return (1);
	while (index >= 0)
	{
		free(strs[index]);
		strs[index] = NULL;
		index--;
	}
	free(strs);
	strs = NULL;
	return (1);
}
