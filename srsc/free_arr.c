/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:44:29 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/05 15:19:39 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	free_arr(int **arr, int index)
{
	if (!arr)
		return ;
	while (index >= 0)
	{
		free(arr[index]);
		arr[index] = NULL;
		index--;
	}
	free(arr);
	arr = NULL;
}